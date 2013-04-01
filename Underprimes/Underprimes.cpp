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

struct Underprimes { int howMany( int A, int B ); };
// @snip <sh19910711/contest:solution/typedef.cpp>

namespace solution {
    
    const int SIZE = 100011;
    const int NONE = -1;

    bool P[SIZE];
    int T[SIZE];
    int TC;
    int memo[SIZE];

    bool is_underprime( int x ) {
        if ( memo[x] != NONE )
            return memo[x] ? true : false;
        int cnt = 0;
        int y = x;
        for ( int i = 0; y > 1 && T[i] <= x && i < TC; ++ i ) {
            while ( y % T[i] == 0 ) {
                y /= T[i];
                cnt ++;
            }
        }
        memo[x] = P[cnt] ? 1 : 0;
        return P[cnt];
    }

    // 1からxまでのunderprimeの個数
    int f( int x ) {
        int res = 0;
        for ( int i = 1; i <= x; ++ i ) {
            if ( ! P[i] && is_underprime(i) )
                res ++;
        }
        return res;
    }

    struct Solution {
        int solve( int A, int B ) {
            fill( P, P+SIZE, false );
            for ( int i = 3; i < SIZE; i += 2 )
                P[i] = true;
            TC = 0;
            T[TC++] = 2;
            P[1] = true;
            P[2] = true;
            for ( int i = 3; i < SIZE; i += 2 ) {
                if ( ! P[i] )
                    continue;
                T[TC++] = i;
                for ( int j = i + i; j < SIZE; j += i ) {
                    P[j] = false;
                }
            }

            fill( memo, memo+SIZE, NONE );
            return f(B) - f(A-1);
        }
    };
}

int Underprimes::howMany( int A, int B ) {
    return solution::Solution().solve(A, B);
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
void verify_case(const int caseno, const int&A, const int&B, const int& Expected, bool verbose = false) {
  int Received = Underprimes().howMany(A, B);
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
        int A = 2;
        int B = 10;
        int _ = 5;
        RUN_TEST();
    }
    CASE(1){
        int A = 100;
        int B = 105;
        int _ = 2;
        RUN_TEST();
    }
    CASE(2){
        int A = 17;
        int B = 17;
        int _ = 0;
        RUN_TEST();
    }
    CASE(3){
        int A = 123;
        int B = 456;
        int _ = 217;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
