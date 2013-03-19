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

struct AgeEncoding {
    double getRadix( int age, string candlesLine );
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

    typedef long double LD;
   
    struct Solution {
        LD get( LD f, string s ) {
            int n = s.size();
            LD res = 0.0;
            if ( abs(f) < 1e-9 )
                return 0.0;
            LD b = 1.0;
            for ( int i = 0; i < n; ++ i ) {
                res += ( s[i] - '0' ) * b;
                b *= f;
            }
            return res;
        }
        bool check( int k, LD f, string s ) {
            return get( f, s ) >= k;
        }
        bool equal( LD a, LD b ) {
            return abs( a - b ) < 1e-9;
        }
        double solve( int age, string candlesLine ) {
            string s = candlesLine;
            reverse( s.begin(), s.end() );
            if ( age == 1 && s[0] == '1' && count( s.begin()+1, s.end(), '1' ) == 0 )
                return -2.0;
            if ( age == 1 && count( s.begin(), s.end(), '1' ) == 1 )
                return 1.0;
            LD lb = 0.0, ub = age;
            for ( int i = 0; i < 100; ++ i ) {
                LD mid = ( lb + ub ) / 2.0;
                if ( check( age, mid, s ) ) {
                    ub = mid;
                } else {
                    lb = mid;
                }
            }
            return equal( get(lb,s), age ) ? lb : -1;
        }
    };
}

double AgeEncoding::getRadix( int age, string candlesLine ) {
    return solution::Solution().solve( age, candlesLine );
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
void verify_case(const int caseno, const int&age, const string&candlesLine, const double& Expected, bool verbose = false) {
  double Received = AgeEncoding().getRadix(age, candlesLine);
  cerr << "Test Case #" << caseno << "...";
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tage: " << age<< endl;
  if (verbose) cerr << "\tcandlesLine: " << candlesLine<< endl;
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
#define RUN_TEST()	 verify_case(caseno, age, candlesLine, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        int age = 10;
        string candlesLine = "00010";
        double _ = 10.0;
        RUN_TEST();
    }
    CASE(1){
        int age = 21;
        string candlesLine = "10101";
        double _ = 2.0;
        RUN_TEST();
    }
    CASE(2){
        int age = 6;
        string candlesLine = "10100";
        double _ = 1.414213562373095;
        RUN_TEST();
    }
    CASE(3){
        int age = 21;
        string candlesLine = "10111111110111101111111100111111110111111111111100";
        double _ = 0.9685012944510603;
        RUN_TEST();
    }
    CASE(4){
        int age = 16;
        string candlesLine = "1";
        double _ = -1.0;
        RUN_TEST();
    }
    CASE(5){
        int age = 1;
        string candlesLine = "1";
        double _ = -2.0;
        RUN_TEST();
    }
    CASE(6){
        int age = 1;
        string candlesLine = "001000";
        double _ = 1.0;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
