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

struct BunnyComputer { int getMaximum( vector <int> preference, int k ); };

// @snippet<sh19910711/contest:solution/typedef.cpp>
namespace solution {
    typedef std::istringstream ISS;
    typedef std::ostringstream OSS;
    typedef std::vector<std::string> VS;
    typedef long long LL;
    typedef int INT;
    typedef std::vector<INT> VI;
    typedef std::vector<VI> VVI;
    typedef std::pair<INT,INT> II;
    typedef std::vector<II> VII;
}

namespace solution {
    const int SIZE = 101;
    enum STEP_STATE { OK, WAIT };
    struct Solution {
        int solve( vector <int> preference, int k ) {
            VI A = preference;
            int n = A.size();
            int dp[SIZE][SIZE][2];
            for ( int i = 0; i < SIZE; ++ i )
                for ( int j = 0; j < SIZE; ++ j )
                    for ( int t = 0; t < 2; ++ t )
                        dp[i][j][t] = 0;
            for ( int i = 0; i <= k; ++ i ) {
                for ( int j = i; j + k + 1 < n; j += k + 1 ) {
                    dp[i][j+k+1][WAIT] = dp[i][j][OK] + A[j] + A[j+k+1];
                    dp[i][j+k+1][OK] = max(dp[i][j][OK], dp[i][j][WAIT]);
                }
            }
            int res = 0;
            for ( int i = 0; i <= k; ++ i ) {
                int cand = 0;
                for ( int j = 0; j < SIZE; ++ j )
                    for ( int t = 0; t < 2; ++ t )
                        cand = max(cand, dp[i][j][t]);
                res += cand;
            }
            return res;
        }
    };
}

int BunnyComputer::getMaximum( vector <int> preference, int k ) {
    return solution::Solution().solve(preference, k);
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
        void verify_case(const int caseno, const vector <int>&preference, const int&k, const int& Expected, bool verbose = false) {
            int Received = BunnyComputer().getMaximum(preference, k);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tpreference: " << preference<< endl;
                if (verbose) cerr << "\tk: " << k<< endl;
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
#define RUN_TEST()	 verify_case(caseno, preference, k, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int preference_[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
        vector <int> preference(preference_, preference_+sizeof(preference_)/sizeof(*preference_)); 
        int k = 2;
        int _ = 28;
        RUN_TEST();
    }
    CASE(1){
        int preference_[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
        vector <int> preference(preference_, preference_+sizeof(preference_)/sizeof(*preference_)); 
        int k = 1;
        int _ = 31;
        RUN_TEST();
    }
    CASE(2){
        int preference_[] = { 1, 2, 3, 4, 5, 6 };
        vector <int> preference(preference_, preference_+sizeof(preference_)/sizeof(*preference_)); 
        int k = 3;
        int _ = 14;
        RUN_TEST();
    }
    CASE(3){
        int preference_[] = { 487, 2010 };
        vector <int> preference(preference_, preference_+sizeof(preference_)/sizeof(*preference_)); 
        int k = 2;
        int _ = 0;
        RUN_TEST();
    }
    CASE(4){
        int preference_[] = { 1,1,1,1,1,1 };
        vector <int> preference(preference_, preference_+sizeof(preference_)/sizeof(*preference_)); 
        int k = 2;
        int _ = 6;
        RUN_TEST();
    }
    CASE(5) {
        int preference_[] = {979595, 979675, 980007, 980772, 981772, 985833, 999837, 979596, 979680, 980189, 980806, 981824, 986226, 987304, 979597, 979686, 980265, 981198, 981846, 981923, 987725, 979603, 979692, 980306, 981205, 981381, 982048, 988845, 979615, 979755, 980342, 980444, 981519, 983358, 989670, 979634, 979841, 979929, 980548, 981550, 984182, 989691, 979661, 979675, 979973, 980705, 981551, 985581, 999309};
        vector <int> preference(preference_, preference_+sizeof(preference_)/sizeof(*preference_));
        int k = 6;
        int _ = 41274115;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

