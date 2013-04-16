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

struct RoughStrings { int minRoughness( string s, int n ); };
// @snip <sh19910711/contest:solution/typedef.cpp>

namespace solution {
    string s;
    int len;
    int n;
    map <char, int> cnt;
    struct Solution {

        bool check( int k1, int k2 ) {
            int cost = 0;
            for ( char c = 'a'; c <= 'z'; ++ c ) {
                int t = cnt[c];
                if ( t > k1 ) {
                    cost += t - k1;
                } else if ( t < k2 ) {
                    cost += t;
                }
            }
            return cost <= n;
        }

        int solve( string s__, int n__ ) {
            s = s__;
            n = n__;
            len = s.size();
            cnt.clear();
            for ( int i = 0; i < len; ++ i )
                cnt[s[i]] ++;

            int res = std::numeric_limits<int>::max();
            for ( int k2 = 1; k2 <= len; ++ k2 ) {
                for ( int k1 = k2; k1 <= len; ++ k1 ) {
                    if ( check( k1, k2 ) )
                        res = min( res, k1 - k2 );
                }
            }
            return res;
        }

    };
}

int RoughStrings::minRoughness( string s, int n ) {
    return solution::Solution().solve(s, n);
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
void verify_case(const int caseno, const string&s, const int&n, const int& Expected, bool verbose = false) {
  int Received = RoughStrings().minRoughness(s, n);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\ts: " << s<< endl;
  if (verbose) cerr << "\tn: " << n<< endl;
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
#define RUN_TEST()	 verify_case(caseno, s, n, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        string s = "aaaaabbc";
        int n = 1;
        int _ = 3;
        RUN_TEST();
    }
    CASE(1){
        string s = "aaaabbbbc";
        int n = 5;
        int _ = 0;
        RUN_TEST();
    }
    CASE(2){
        string s = "veryeviltestcase";
        int n = 1;
        int _ = 2;
        RUN_TEST();
    }
    CASE(3){
        string s = "gggggggooooooodddddddllllllluuuuuuuccckkk";
        int n = 5;
        int _ = 3;
        RUN_TEST();
    }
    CASE(4){
        string s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        int n = 17;
        int _ = 0;
        RUN_TEST();
    }
    CASE(5){
        string s = "bbbccca";
        int n = 2;
        int _ = 0;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
