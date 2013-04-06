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

struct BestView { int numberOfBuildings( vector <int> heights ); };

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
    VI H;
    int n;
    
    int calc( int k ) {
        int res = 0;
        for ( int i = 0; i < k; ++ i ) {
            bool ok = true;
            for ( int j = i + 1; j < k; ++ j ) {
                LL y1 = H[i] - H[k];
                LL x1 = i - k;
                LL y2 = H[j] - H[k];
                LL x2 = j - k;
                if ( x1 * y2 - x2 * y1 <= 0 ) {
                    ok = false;
                    break;
                }
            }
            if ( ok )
                res ++;
        }
        for ( int i = k + 1; i < n; ++ i ) {
            bool ok = true;
            for ( int j = k + 1; j < i; ++ j ) {
                LL y1 = H[i] - H[k];
                LL x1 = i - k;
                LL y2 = H[j] - H[k];
                LL x2 = j - k;
                if ( x1 * y2 - x2 * y1 >= 0 ) {
                    ok = false;
                    break;
                }
            }
            if ( ok )
                res ++;
        }

        return res;
    }
    
    struct Solution {
        int solve( vector <int> heights ) {
            int res = 0;
            H = heights;
            n = H.size();
            for ( int i = 0; i < n; ++ i ) {
                res = max( res, calc(i) );
            }
            return res;
        }
    };
}

int BestView::numberOfBuildings( vector <int> heights ) {
    return solution::Solution().solve(heights);
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
        void verify_case(const int caseno, const vector <int>&heights, const int& Expected, bool verbose = false) {
            int Received = BestView().numberOfBuildings(heights);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\theights: " << heights<< endl;
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
#define RUN_TEST()	 verify_case(caseno, heights, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int heights_[] = {10};
        vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
        int _ = 0;
        RUN_TEST();
    }
    CASE(1){
        int heights_[] = {5,5,5,5};
        vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
        int _ = 2;
        RUN_TEST();
    }
    CASE(2){
        int heights_[] = {1,2,7,3,2};
        vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
        int _ = 4;
        RUN_TEST();
    }
    CASE(3){
        int heights_[] = {1,5,3,2,6,3,2,6,4,2,5,7,3,1,5};
        vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
        int _ = 7;
        RUN_TEST();
    }
    CASE(4){
        int heights_[] = {1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5};
        vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
        int _ = 6;
        RUN_TEST();
    }
    CASE(5){
        int heights_[] = {244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317};
        vector <int> heights(heights_, heights_+sizeof(heights_)/sizeof(*heights_)); 
        int _ = 7;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

