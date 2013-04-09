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
#include <limits>
#include <complex>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

struct BunnyExamAfter { int getMaximum( string black, string gray, string white ); };
// @snip <sh19910711/contest:solution/typedef.cpp>

namespace solution {
    struct Solution {
        int solve( string black, string gray, string white ) {
            string B = black, G = gray, W = white;
            int n = B.size();
            int res = 0;
            for ( int i = 0; i < n; ++ i ) {
                if ( B[i] != G[i] && G[i] == W[i] ) {
                    res += 2;
                } else if ( B[i] != G[i] ) {
                    res ++;
                } else if ( B[i] != W[i] ) {
                    res ++;
                }
            }
            return res;
        }
    };
}

int BunnyExamAfter::getMaximum( string black, string gray, string white ) {
    return solution::Solution().solve(black, gray, white);
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
void verify_case(const int caseno, const string&black, const string&gray, const string&white, const int& Expected, bool verbose = false) {
  int Received = BunnyExamAfter().getMaximum(black, gray, white);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tblack: " << black<< endl;
  if (verbose) cerr << "\tgray: " << gray<< endl;
  if (verbose) cerr << "\twhite: " << white<< endl;
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
#define RUN_TEST()	 verify_case(caseno, black, gray, white, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        string black = "ABC";
        string gray = "ABC";
        string white = "ABC";
        int _ = 0;
        RUN_TEST();
    }
    CASE(1){
        string black = "A";
        string gray = "B";
        string white = "B";
        int _ = 2;
        RUN_TEST();
    }
    CASE(2){
        string black = "ABC";
        string gray = "PQR";
        string white = "XYZ";
        int _ = 3;
        RUN_TEST();
    }
    CASE(3){
        string black = "AAAAA";
        string gray = "AABBB";
        string white = "BBBAA";
        int _ = 6;
        RUN_TEST();
    }
    CASE(4){
        string black = "TOPCODER";
        string gray = "TOPBUNNY";
        string white = "THEHONEY";
        int _ = 9;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
