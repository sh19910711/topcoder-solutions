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

struct TheCardShufflingDivOne { int shuffle( int n, int left, int right ); };

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
        int solve( int n, int left, int right ) {
            int pos = 0;
            int size = 2 - n % 2;
            while ( size < n ) {
                int sl = ( size + 1 ) / 2 + 1;
                int sr = size / 2 + 1;
                if ( pos < sl - 1 ) {
                    pos = sl - pos - 2;
                    pos = ( sl + ( pos - left ) % sl ) % sl;
                    pos *= 2;
                } else {
                    pos -= sl - 1;
                    pos = sr - pos - 2;
                    pos = ( sr + ( pos - right ) % sr ) % sr;
                    pos = 2 * pos + 1;
                }
                size += 2;
                pos = ( size - pos - 1 );
            }
            return n - pos;
        }
    };
}

int TheCardShufflingDivOne::shuffle( int n, int left, int right ) {
    return solution::Solution().solve(n, left, right);
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
        void verify_case(const int caseno, const int&n, const int&left, const int&right, const int& Expected, bool verbose = false) {
            int Received = TheCardShufflingDivOne().shuffle(n, left, right);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tn: " << n<< endl;
                if (verbose) cerr << "\tleft: " << left<< endl;
                if (verbose) cerr << "\tright: " << right<< endl;
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
#define RUN_TEST()	 verify_case(caseno, n, left, right, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int n = 3;
        int left = 0;
        int right = 0;
        int _ = 1;
        RUN_TEST();
    }
    CASE(1){
        int n = 3;
        int left = 1;
        int right = 1;
        int _ = 3;
        RUN_TEST();
    }
    CASE(2){
        int n = 5;
        int left = 0;
        int right = 0;
        int _ = 2;
        RUN_TEST();
    }
    CASE(3){
        int n = 17;
        int left = 12;
        int right = 21;
        int _ = 17;
        RUN_TEST();
    }
    CASE(4) {
        int n = 10;
        int left = 0;
        int right = 0;
        int _ = 8;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

