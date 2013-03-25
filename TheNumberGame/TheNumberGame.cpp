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

struct TheNumberGame {
    string determineOutcome( int A, int B );
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

    const string YES = "Manao wins";
    const string NO = "Manao loses";
   
    string to_string( int k ) {
        OSS oss;
        oss << k;
        return oss.str();
    }

    void reverse( string& s ) {
        std::reverse( s.begin(), s.end() );
    }

    bool check( string a, string b ) {
        if ( a.size() < b.size() )
            return false;
        int n = a.size();
        string rb = b;
        reverse(rb);
        for ( int i = 0; i < n; ++ i ) {
            for ( int j = i; j < n; ++ j ) {
                string s = a.substr( i, j - i + 1 );
                if ( s == b || s == rb )
                    return true;
            }
        }
        return false;
    }

    struct Solution {
        string solve(  int A, int B  ) {
            string a = to_string(A);
            string b = to_string(B);
            return ( check(a,b) ? YES : NO );
        }
    };
}

string TheNumberGame::determineOutcome( int A, int B ) {
    return solution::Solution().solve( A, B );
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
void verify_case(const int caseno, const int&A, const int&B, const string& Expected, bool verbose = false) {
  string Received = TheNumberGame().determineOutcome(A, B);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tA: " << A<< endl;
  if (verbose) cerr << "\tB: " << B<< endl;
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
#define RUN_TEST()	 verify_case(caseno, A, B, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        int A = 45;
        int B = 4;
        string _ = "Manao wins";
        RUN_TEST();
    }
    CASE(1){
        int A = 45;
        int B = 5;
        string _ = "Manao wins";
        RUN_TEST();
    }
    CASE(2){
        int A = 99;
        int B = 123;
        string _ = "Manao loses";
        RUN_TEST();
    }
    CASE(3){
        int A = 2356236;
        int B = 5666;
        string _ = "Manao loses";
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
