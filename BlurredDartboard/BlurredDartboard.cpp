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

struct BlurredDartboard { int minThrows( vector <int> points, int P ); };

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
    struct Solution {
        int solve( vector <int> points, int P ) {
            int n = points.size();
            bool used[n+1];
            fill( used, used+n+1, false );
            int unknown = 0, unknownSum = n * (n+1) / 2, ret = std::numeric_limits<int>::max();
            for ( int i = 0; i < n; ++ i ) {
                if ( points[i] > 0 ) {
                    used[points[i]] = true;
                    unknownSum -= points[i];
                } else {
                    unknown ++;
                }
            }

            int bestvalue = n;
            for ( ; bestvalue > 0; -- bestvalue ) {
                if ( used[bestvalue] )
                    break;
            }

            if ( unknown == 0 )
                return ceil((double)P / bestvalue);

            int uses = P / unknownSum;
            int remainder = P - uses * unknownSum;

            int sum = 0, counter = 0;
            for ( int i = 1; sum < remainder; ++ i ) {
                if ( ! used[i] ) {
                    sum += i;
                    counter ++;
                }
            }

            ret = min( ret, uses * unknown + counter );

            if ( bestvalue > 0 ) {
                ret = min( ret, uses * unknown + (int)ceil((double)remainder / bestvalue ));
                ret = min( ret, (int)ceil( (double)P / bestvalue ));
                cout << ret << endl;
            }

            return ret;
        }
    };
}

int BlurredDartboard::minThrows( vector <int> points, int P ) {
    return solution::Solution().solve(points, P);
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
        void verify_case(const int caseno, const vector <int>&points, const int&P, const int& Expected, bool verbose = false) {
            int Received = BlurredDartboard().minThrows(points, P);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tpoints: " << points<< endl;
                if (verbose) cerr << "\tP: " << P<< endl;
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
#define RUN_TEST()	 verify_case(caseno, points, P, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int points_[] = {0, 3, 4, 0, 0};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        int P = 8;
        int _ = 2;
        RUN_TEST();
    }
    CASE(1){
        int points_[] = {0, 0, 0, 0, 0};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        int P = 15;
        int _ = 5;
        RUN_TEST();
    }
    CASE(2){
        int points_[] = {4, 7, 8, 1, 3, 2, 6, 5};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        int P = 2012;
        int _ = 252;
        RUN_TEST();
    }
    CASE(3){
        int points_[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        int P = 2012;
        int _ = 307;
        RUN_TEST();
    }
    CASE(4){
        int points_[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        int P = 1000000000;
        int _ = 84656087;
        RUN_TEST();
    }
    CASE(4){
        int points_[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        int P = 1000000000;
        int _ = 38461539;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE


