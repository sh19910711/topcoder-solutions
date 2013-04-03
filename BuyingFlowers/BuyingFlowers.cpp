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

struct BuyingFlowers { int buy( vector <int> roses, vector <int> lilies ); };

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

    const int NONE = -1;
    const int INF = std::numeric_limits<int>::max();

    VI R, L;
    int n;

    struct Solution {
        int solve( vector <int> roses, vector <int> lilies ) {
            R = roses;
            L = lilies;
            n = R.size();

            int res = INF;
            int bn = 1 << n;
            for ( int i = 0; i < bn; ++ i ) {
                int sr = 0, sl = 0;
                for ( int j = 0; j < n; ++ j ) {
                    int bj = 1 << j;
                    if ( i & bj ) {
                        sr += R[j];
                        sl += L[j];
                    }
                }
                if ( sl > sr )
                    swap(sl, sr);
                if ( sr - sl <= 1 ) {
                    int area = sl + sr;
                    for ( int h = 1; h * h <= area; ++ h ) {
                        if ( area % h )
                            continue;
                        int w = area / h;
                        res = min(res, abs(h - w));
                    }
                }
            }

            return res == INF ? NONE : res;
        }
    };
}

int BuyingFlowers::buy( vector <int> roses, vector <int> lilies ) {
    return solution::Solution().solve(roses, lilies);
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
        void verify_case(const int caseno, const vector <int>&roses, const vector <int>&lilies, const int& Expected, bool verbose = false) {
            int Received = BuyingFlowers().buy(roses, lilies);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\troses: " << roses<< endl;
                if (verbose) cerr << "\tlilies: " << lilies<< endl;
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
#define RUN_TEST()	 verify_case(caseno, roses, lilies, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int roses_[] = {2, 4};
        vector <int> roses(roses_, roses_+sizeof(roses_)/sizeof(*roses_)); 
        int lilies_[] = {4, 2};
        vector <int> lilies(lilies_, lilies_+sizeof(lilies_)/sizeof(*lilies_)); 
        int _ = 1;
        RUN_TEST();
    }
    CASE(1){
        int roses_[] = {2, 7, 3};
        vector <int> roses(roses_, roses_+sizeof(roses_)/sizeof(*roses_)); 
        int lilies_[] = {3, 4, 1};
        vector <int> lilies(lilies_, lilies_+sizeof(lilies_)/sizeof(*lilies_)); 
        int _ = 0;
        RUN_TEST();
    }
    CASE(2){
        int roses_[] = {4, 5, 2, 1};
        vector <int> roses(roses_, roses_+sizeof(roses_)/sizeof(*roses_)); 
        int lilies_[] = {6, 10, 5, 9};
        vector <int> lilies(lilies_, lilies_+sizeof(lilies_)/sizeof(*lilies_)); 
        int _ = -1;
        RUN_TEST();
    }
    CASE(3){
        int roses_[] = {1, 208, 19, 0, 3, 234, 1, 106, 99, 17};
        vector <int> roses(roses_, roses_+sizeof(roses_)/sizeof(*roses_)); 
        int lilies_[] = {58, 30, 3, 5, 0, 997, 9, 615, 77, 5};
        vector <int> lilies(lilies_, lilies_+sizeof(lilies_)/sizeof(*lilies_)); 
        int _ = 36;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

