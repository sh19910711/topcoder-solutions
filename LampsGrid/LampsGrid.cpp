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

struct LampsGrid {
    int mostLit( vector <string> initial, int K );
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
    typedef set<string> Set;

    VS I;
    Set S;

    struct Solution {
        bool check( const string& s, int k ) {
            int zeros = count( s.begin(), s.end(), '0' );
            if ( k < zeros )
                return false;
            if ( k == zeros )
                return true;
            k -= zeros;
            return k % 2 == 0;
        }
        int solve(  vector <string> initial, int K  ) {
            int res = 0;
            I = initial;
            S = Set( I.begin(), I.end() );
            for ( Set::iterator it_i = S.begin(); it_i != S.end(); ++ it_i ) {
                const string& s = *it_i;
                if ( check(s,K) ) {
                    res = max( res, (int)count( I.begin(), I.end(), s ) );
                }
            }
            return res;
        }
    };
}

int LampsGrid::mostLit( vector <string> initial, int K ) {
    return solution::Solution().solve( initial, K );
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
void verify_case(const int caseno, const vector <string>&initial, const int&K, const int& Expected, bool verbose = false) {
  int Received = LampsGrid().mostLit(initial, K);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tinitial: " << initial<< endl;
  if (verbose) cerr << "\tK: " << K<< endl;
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
#define RUN_TEST()	 verify_case(caseno, initial, K, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        string initial_[] = {"01",
 "10",
 "10"};
        vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
        int K = 1;
        int _ = 2;
        RUN_TEST();
    }
    CASE(1){
        string initial_[] = {"101010"};
        vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
        int K = 2;
        int _ = 0;
        RUN_TEST();
    }
    CASE(2){
        string initial_[] = {"00", "11"};
        vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
        int K = 999;
        int _ = 0;
        RUN_TEST();
    }
    CASE(3){
        string initial_[] = {"0", "1", "0", "1", "0"}
;
        vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
        int K = 1000;
        int _ = 2;
        RUN_TEST();
    }
    CASE(4){
        string initial_[] = {"001", "101", "001", "000", "111", "001", "101", "111", "110", "000", "111", "010", "110", "001"};
        vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
        int K = 6;
        int _ = 4;
        RUN_TEST();
    }
    CASE(5){
        string initial_[] = {"01", "10", "01", "01", "10"};
        vector <string> initial(initial_, initial_+sizeof(initial_)/sizeof(*initial_)); 
        int K = 1;
        int _ = 3;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
