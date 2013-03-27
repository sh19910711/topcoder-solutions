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

struct RouteIntersection {
    string isValid( int N, vector <int> coords, string moves );
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
    typedef vector<II> VII;
    typedef set<VI> Set;

    const string YES = "VALID";
    const string NO = "NOT VALID";

    int N;
    VI C;
    string M;
    map<int,int> T;
    set<VI> S;
    int TC;
   
    struct Solution {
        bool check() {
            int k = C.size();

            T.clear();
            TC = 0;
            for ( int i = 0; i < k; ++ i ) {
                if ( T.count(C[i]) )
                    continue;
                T[C[i]] = TC ++;
            }

            VI D(TC);
            S.clear();
            S.insert(D);
            for ( int i = 0; i < k; ++ i ) {
                int tid = T[C[i]];
                if ( M[i] == '+' ) {
                    D[tid] ++;
                } else {
                    D[tid] --;
                }
                if ( ! S.insert(D).second )
                    return false;
            }
            return true;
        }
        string solve(  int N_, vector <int> coords, string moves  ) {
            N = N_;
            C = coords;
            M = moves;
            return check() ? YES : NO;
        }
    };
}

string RouteIntersection::isValid( int N, vector <int> coords, string moves ) {
    return solution::Solution().solve( N, coords, moves );
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
void verify_case(const int caseno, const int&N, const vector <int>&coords, const string&moves, const string& Expected, bool verbose = false) {
  string Received = RouteIntersection().isValid(N, coords, moves);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tN: " << N<< endl;
  if (verbose) cerr << "\tcoords: " << coords<< endl;
  if (verbose) cerr << "\tmoves: " << moves<< endl;
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
#define RUN_TEST()	 verify_case(caseno, N, coords, moves, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        int N = 1;
        int coords_[] = {1};
        vector <int> coords(coords_, coords_+sizeof(coords_)/sizeof(*coords_)); 
        string moves = "+";
        string _ = "VALID";
        RUN_TEST();
    }
    CASE(1){
        int N = 2;
        int coords_[] = {1,2,1,2};
        vector <int> coords(coords_, coords_+sizeof(coords_)/sizeof(*coords_)); 
        string moves = "++--";
        string _ = "NOT VALID";
        RUN_TEST();
    }
    CASE(2){
        int N = 3;
        int coords_[] = {1,2,3,1,2};
        vector <int> coords(coords_, coords_+sizeof(coords_)/sizeof(*coords_)); 
        string moves = "+++--";
        string _ = "VALID";
        RUN_TEST();
    }
    CASE(3){
        int N = 344447;
        int coords_[] = {132,51717,628,344447,628,51717,344447,2};
        vector <int> coords(coords_, coords_+sizeof(coords_)/sizeof(*coords_)); 
        string moves = "+-++-+--";
        string _ = "NOT VALID";
        RUN_TEST();
    }
    CASE(4){
        int N = 1;
        int coords_[] = {1,1};
        vector <int> coords(coords_, coords_+sizeof(coords_)/sizeof(*coords_)); 
        string moves = "+-";
        string _ = "NOT VALID";
        RUN_TEST();
    }
    CASE(5){
        int N = 990630;
        int coords_[] = {833196,524568,361663,108056,28026,824639,269315,440977,440977,765458,
988451,242440,948414,130873,773990,765458,130873,28026,853121,553636,
581069,82254,735536,833196,898562,898562,940783,988451,540613,317306,
623194,940783,571384,988451,108056,514374,97664};
        vector <int> coords(coords_, coords_+sizeof(coords_)/sizeof(*coords_)); 
        string moves = "--+---+-+++-+-+---++-++-+---+-+--+-++";
        string _ = "NOT VALID";
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
