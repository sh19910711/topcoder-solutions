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

struct TeamContest {
    int worstRank( vector <int> strength );
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
   
    VI S;
    int n;
    int me;

    struct Solution {
        int calc( int x, int y, int z ) {
            return max( x, max( y, z ) ) + min( x, min( y, z ) );
        }
        int solve(  vector <int> strength  ) {
            me = calc( strength[0], strength[1], strength[2] );
            S = VI( strength.begin()+3, strength.end() );
            n = S.size();
            sort( S.begin(), S.end() );

            int res = 1;
            bool used[n];
            fill( used, used+n, false );
            for ( int i = n-1; i >= 0; -- i ) {
                int x = S[i];
                for ( int j = 0; j < n; ++ j ) {
                    int y = S[j];
                    if ( x + y > me ) {
                        for ( int k = 0; k < n; ++ k ) {
                            if ( used[i] || used[j] || used[k] )
                                continue;
                            if ( i == j || j == k || k == i )
                                continue;
                            int z = S[k];
                            if ( z >= y ) {
                                used[i] = used[j] = used[k] = true;
                                res ++;
                            }
                        }
                    }
                }
            }
            return res;
        }
    };
}

int TeamContest::worstRank( vector <int> strength ) {
    return solution::Solution().solve( strength );
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
void verify_case(const int caseno, const vector <int>&strength, const int& Expected, bool verbose = false) {
  int Received = TeamContest().worstRank(strength);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tstrength: " << strength<< endl;
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
#define RUN_TEST()	 verify_case(caseno, strength, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        int strength_[] = {5, 7, 3, 5, 7, 3, 5, 7, 3};
        vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
        int _ = 2;
        RUN_TEST();
    }
    CASE(1){
        int strength_[] = {5, 7, 3}
;
        vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
        int _ = 1;
        RUN_TEST();
    }
    CASE(2){
        int strength_[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
        int _ = 1;
        RUN_TEST();
    }
    CASE(3){
        int strength_[] = {3,9,4,6,2,6,1,6,9,1,4,1,3,8,5}
;
        vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
        int _ = 3;
        RUN_TEST();
    }
    CASE(4){
        int strength_[] = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43}
;
        vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
        int _ = 3;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
