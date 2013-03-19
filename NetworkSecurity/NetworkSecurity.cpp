#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

struct NetworkSecurity {
    int secureNetwork( vector <string> clientCable, vector <string> serverCable );
};

namespace solution {
    using namespace std;
   
    typedef istringstream ISS;
    typedef ostringstream OSS;
    typedef vector<string> VS;
    typedef long long LL;
    typedef int INT;
    typedef vector<INT> VI;
    typedef vector<VI> VVI;
    typedef pair<INT, INT> II;
   
    const int SIZE = 101;
    VS C, S;
    bool G[SIZE][SIZE];
    bool F[SIZE][SIZE];

    struct Solution {
        int solve( vector <string> clientCable, vector <string> serverCable ) {
            for ( int i = 0; i < SIZE; ++ i )
                for ( int j = 0; j < SIZE; ++ j )
                    G[i][j] = false, F[i][j] = false;

            C = clientCable;
            S = serverCable;
            int cn = C.size();
            int sn = S[0].size();

            for ( int i = 0; i < cn; ++ i ) {
                for ( int j = 0; j < cn; ++ j ) {
                    G[i][j] = C[i][j] == 'Y';
                }
            }

            for ( int i = 0; i < cn; ++ i ) {
                for ( int j = 0; j < sn; ++ j ) {
                    G[i][j+cn] = S[i][j] == 'Y';
                }
            }

            int n = cn + sn;

            for ( int k = 0; k < n; ++ k )
                for ( int i = 0; i < n; ++ i )
                    for ( int j = 0; j < n; ++ j )
                        G[i][j] = G[i][j] || ( G[i][k] && G[k][j] );

            for ( int i = cn; i < n; ++ i ) {
                bool can[SIZE];
                fill( can, can+SIZE, false );
                for ( int j = 0; j < cn; ++ j )
                    can[j] = G[j][i];
                for ( int j = 0; j < cn; ++ j ) {
                    if ( can[j] ) {
                        bool flag = false;
                        for ( int k = 0; k < cn; ++ k ) {
                            if ( G[j][k] ) {
                                flag |= can[k];
                            }
                        }
                        if ( ! flag ) {
                            F[j][i] = true;
                        }
                    }
                }
            }

            int res = 0;
            for ( int i = 0; i < n; ++ i )
                for ( int j = 0; j < n; ++ j )
                    if ( F[i][j] )
                        res ++;
            return res;
        }
    };
}

int NetworkSecurity::secureNetwork( vector <string> clientCable, vector <string> serverCable ) {
    return solution::Solution().solve( clientCable, serverCable );
}

// BEGIN CUT HERE
// BEGIN CUT HERE
#include <ctime>
#include <sstream>
#include <fstream>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int caseno, const vector <string>&clientCable, const vector <string>&serverCable, const int& Expected, bool verbose = false) {
  int Received = NetworkSecurity().secureNetwork(clientCable, serverCable);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tclientCable: " << clientCable<< endl;
  if (verbose) cerr << "\tserverCable: " << serverCable<< endl;
  cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
void notify_memory_usage(){
#ifndef _WIN32
  std::ifstream ifs("/proc/self/status",std::ios_base::in);
  std::string str;
  for(;;){std::getline(ifs, str);
    if(str.find("VmPeak") != std::string::npos){cout << str << " (< 64MB)" << endl;}
    if(str.find("VmStk") != std::string::npos){cout << str << " (< 8MB)" << endl;break;} }
#endif
}
#define CASE(N) if (N==runno_ || (runno_<0 && N+1>=-runno_)) {int caseno=N; start_time=clock();
#define RUN_TEST()	 verify_case(caseno, clientCable, serverCable, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        string clientCable_[] = {"NYN"
,"NNN"
,"NYN"};
        vector <string> clientCable(clientCable_, clientCable_+sizeof(clientCable_)/sizeof(*clientCable_)); 
        string serverCable_[] = {"YN"
,"YN"
,"NY"};
        vector <string> serverCable(serverCable_, serverCable_+sizeof(serverCable_)/sizeof(*serverCable_)); 
        int _ = 2;
        RUN_TEST();
    }
    CASE(1){
        string clientCable_[] = {"NN"
,"NN"};
        vector <string> clientCable(clientCable_, clientCable_+sizeof(clientCable_)/sizeof(*clientCable_)); 
        string serverCable_[] = {"NNN"
,"NNN"};
        vector <string> serverCable(serverCable_, serverCable_+sizeof(serverCable_)/sizeof(*serverCable_)); 
        int _ = 0;
        RUN_TEST();
    }
    CASE(2){
        string clientCable_[] = {"NYNN"
,"NNNN"
,"NNNY"
,"NNNN"};
        vector <string> clientCable(clientCable_, clientCable_+sizeof(clientCable_)/sizeof(*clientCable_)); 
        string serverCable_[] = {"YYN"
,"NNN"
,"NNY"
,"NNN"};
        vector <string> serverCable(serverCable_, serverCable_+sizeof(serverCable_)/sizeof(*serverCable_)); 
        int _ = 3;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
