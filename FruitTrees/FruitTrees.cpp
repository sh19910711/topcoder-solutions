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

struct FruitTrees { int maxDist( int apple, int kiwi, int grape ); };

// @snippet<sh19910711/contest:solution/typedef.cpp>
namespace solution {
    typedef std::istringstream ISS;
    typedef std::ostringstream OSS;
    typedef std::vector<std::string> VS;
    typedef long long LL;
    typedef vector<LL> VLL;
    typedef int INT;
    typedef std::vector<INT> VI;
    typedef std::vector<VI> VVI;
    typedef std::pair<INT,INT> II;
    typedef std::vector<II> VII;
}

// @snippet<sh19910711/contest:math/gcd.cpp>
namespace math {
    template <class T> T gcd( T a, T b ) {
        T i, j;
        for ( i = 0; ! ( a & 1 ); ++ i ) a >>= 1;
        for ( j = 0; ! ( b & 1 ); ++ j ) b >>= 1;
        while ( b != a ) {
            b -= a;
            if ( b < 0 ) a += b, b = -b;
            while ( ! ( b & 1 ) ) b >>= 1;
        }
        return a << std::min( i, j );
    }
}

// @snippet<sh19910711/contest:math/lcm.cpp>
namespace math {
    template <class T> T lcm( T a, T b ) {
        T larger = a > b ? a : b;
        T smaller = a > b ? b : a;
        T res = larger;
        while ( res % smaller != 0 )
            res += larger;
        return res;
    }
}

namespace solution {
    using namespace math;
    
    struct Solution {
        LL A, B, C;
        
        int calc( LL A, LL B, LL C ) {
            LL ab = gcd(A, B);
            LL bc = gcd(B, C);
            LL ca = gcd(C, A);
            if ( ab == bc && bc == ca )
                return ab / 3;
            return min(ab, min(bc, ca)) / 2;
        }
        
        int solve( int apple, int kiwi, int grape ) {
            A = apple;
            B = kiwi;
            C = grape;
            return calc(A, B, C);
        }
    };
}

int FruitTrees::maxDist( int apple, int kiwi, int grape ) {
    return solution::Solution().solve(apple, kiwi, grape);
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
        void verify_case(const int caseno, const int&apple, const int&kiwi, const int&grape, const int& Expected, bool verbose = false) {
            int Received = FruitTrees().maxDist(apple, kiwi, grape);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tapple: " << apple<< endl;
                if (verbose) cerr << "\tkiwi: " << kiwi<< endl;
                if (verbose) cerr << "\tgrape: " << grape<< endl;
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
#define RUN_TEST()	 verify_case(caseno, apple, kiwi, grape, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int apple = 1;
        int kiwi = 5;
        int grape = 8;
        int _ = 0;
        RUN_TEST();
    }
    CASE(1){
        int apple = 3;
        int kiwi = 3;
        int grape = 6;
        int _ = 1;
        RUN_TEST();
    }
    CASE(2){
        int apple = 40;
        int kiwi = 30;
        int grape = 20;
        int _ = 5;
        RUN_TEST();
    }
    CASE(3){
        int apple = 899;
        int kiwi = 1073;
        int grape = 1147;
        int _ = 14;
        RUN_TEST();
    }
    CASE(4){
        int apple = 2000;
        int kiwi = 2000;
        int grape = 2000;
        int _ = 666;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE





