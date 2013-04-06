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

struct TheSwap { int findMax( int n, int k ); };

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
    
    string to_string( int n ) {
        OSS oss;
        oss << n;
        return oss.str();
    }

    int to_int( string s ) {
        ISS iss(s);
        int res;
        iss >> res;
        return res;
    }

    string swap_to_max( string s ) {
        int n = s.size();
        if ( n == 1 )
            return "-1";
        for ( int i = 0; i < n; ++ i ) {
            int cand = i;
            for ( int j = i+1; j < n; ++ j ) {
                if ( s[j] == '0' )
                    continue;
                if ( s[cand] <= s[j] ) {
                    cand = j;
                }
            }
            if ( cand != i && s[cand] != '0' ) {
                swap( s[cand], s[i] );
                return s;
            }
        }
        swap( s[n-2], s[n-1] );
        if ( s[0] == '0' )
            return "-1";
        return s;
    }
    
    struct Solution {
        int solve( int n, int k ) {
            string s = to_string(n);
            for ( int i = 0; i < k; ++ i ) {
                s = swap_to_max(s);
                if ( s == "-1" )
                    return to_int(s);
            }
            return to_int(s);
        }
    };
}

int TheSwap::findMax( int n, int k ) {
    return solution::Solution().solve(n, k);
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
        void verify_case(const int caseno, const int&n, const int&k, const int& Expected, bool verbose = false) {
            int Received = TheSwap().findMax(n, k);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tn: " << n<< endl;
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
#define RUN_TEST()	 verify_case(caseno, n, k, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int n = 16375;
        int k = 1;
        int _ = 76315;
        RUN_TEST();
    }
    CASE(1){
        int n = 432;
        int k = 1;
        int _ = 423;
        RUN_TEST();
    }
    CASE(2){
        int n = 90;
        int k = 4;
        int _ = -1;
        RUN_TEST();
    }
    CASE(3){
        int n = 5;
        int k = 2;
        int _ = -1;
        RUN_TEST();
    }
    CASE(4){
        int n = 436659;
        int k = 2;
        int _ = 966354;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

