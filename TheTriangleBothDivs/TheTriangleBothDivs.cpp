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

struct TheTriangleBothDivs {
    string fix( string time );
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

    const string INF = "99:99";

    string calc( string t, string o ) {
        if ( o[0] == '-' && o[1] == '0' )
            return INF;
        replace(t.begin(), t.end(), ':', ' ');
        ISS iss1(t);
        int hh, mm;
        iss1 >> hh >> mm;
        if ( hh >= 24 )
            return INF;
        if ( mm >= 60 )
            return INF;
        ISS iss2(o);
        int oo;
        iss2 >> oo;

        hh = ( hh - oo + 24 * 5 ) % 24;
        OSS oss;
        oss << setw(2) << setfill('0') << hh << ":";
        oss << setw(2) << setfill('0') << mm;
        return oss.str();
    }
   
    string rec( int k, string& s ) {
        if ( k >= 11 ) {
            string t = s.substr(0,5);
            string o = s.substr(9);
            return calc( t, o );
        }
        if ( ( k >= 0 && k < 2 ) || ( k >= 3 && k < 5 ) || k == 10 ) {
            if ( s[k] == '?' ) {
                string res = INF;
                for ( char c = '0'; c <= '9'; ++ c ) {
                    s[k] = c;
                    res = min( res, rec(k+1,s) );
                    s[k] = '?';
                }
                return res;
            } else {
                return rec(k+1, s);
            }
        } else if ( k == 2 || ( k >= 5 && k < 9 ) ) {
            return rec(k+1, s);
        } else if ( k == 9 ) {
            if ( s[k] == '?' ) {
                string res = INF;
                s[k] = '-';
                res = min( res, rec(k+1, s) );
                s[k] = '+';
                res = min( res, rec(k+1, s) );
                s[k] = '?';
                return res;
            } else {
                return rec(k+1, s);
            }
        }
        return "";
    }

    struct Solution {
        string solve( string time ) {
            return rec(0,time);
        }
    };
}

string TheTriangleBothDivs::fix( string time ) {
    return solution::Solution().solve( time );
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
void verify_case(const int caseno, const string&time, const string& Expected, bool verbose = false) {
  string Received = TheTriangleBothDivs().fix(time);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\ttime: " << time<< endl;
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
#define RUN_TEST()	 verify_case(caseno, time, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        string time = "17:45 GMT-4";
        string _ = "21:45";
        RUN_TEST();
    }
    CASE(1){
        string time = "16:?? GMT??";
        string _ = "00:00";
        RUN_TEST();
    }
    CASE(2){
        string time = "?1:34 GMT-9";
        string _ = "06:34";
        RUN_TEST();
    }
    CASE(3){
        string time = "??:?? GMT??";
        string _ = "00:00";
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
