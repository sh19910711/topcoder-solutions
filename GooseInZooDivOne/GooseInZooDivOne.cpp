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

typedef long long LL;
const LL MOD = 1000000000 + 7;
const int SIZE = 61;

struct GooseInZooDivOne { int count( vector <string> field, int dist ); };

// @snippet<sh19910711/contest:solution/typedef.cpp>
namespace solution {
    typedef std::istringstream ISS;
    typedef std::ostringstream OSS;
    typedef std::vector<std::string> VS;
    typedef int INT;
    typedef std::vector<INT> VI;
    typedef std::vector<VI> VVI;
    typedef std::pair<INT,INT> II;
    typedef std::vector<II> VII;
}

// @snippet<sh19910711/contest:math/mod_pow.cpp>
namespace math {
    template<class T> T mod_pow( T x, T n, T mod ) {
        if ( n == 0 ) return 1;
        T res = mod_pow( x * x % mod, n / 2, mod );
        if ( n & 1 ) res = res * x % mod;
        return res;
    }
}

// @snippet<sh19910711/contest:math/extgcd.cpp>
namespace math {
    template <class T> T extgcd( T a, T b, T& x, T& y ) {
        for ( T u = y = 1, v = x = 0; a; ) {
            T q = b / a;
            std::swap( x -= q * u, u );
            std::swap( y -= q * v, v );
            std::swap( b -= q * a, a );
        }
        return b;
    }
}

// @snippet<sh19910711/contest:math/mod_inverse.cpp>
namespace math {
    template <class T> T mod_inverse( T a, T m ) {
        T x, y;
        extgcd( a, m, x, y );
        x %= m;
        while ( x < 0 )
            x += m;
        return x;
    }
}

namespace math {
    LL fact[SIZE * SIZE];
    LL mod_fact( LL n, LL p, LL &e ) {
        e = 0;
        if ( n == 0 )
            return 1;
        LL res = mod_fact(n / p, p, e);
        if ( n / p % 2 != 0 )
            return res * ( p - fact[n % p] ) % p;
        return res * fact[n % p] % p;
    }
    LL mod_comb( LL n, LL k, LL p ) {
        if ( n < 0 || k < 0 || n < k )
            return 0;
        LL e1, e2, e3;
        LL a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);
        if ( e1 > e2 + e3 )
            return 0;
        return a1 * mod_inverse(a2 * a3 % p, p) % p;
    }
}

namespace solution {
    using namespace math;
    
    typedef map <int, int> Map;
    
    const char BIRD = 'v';
    
    VS F;
    int H;
    int W;
    int D;
    int N;
    bool V[SIZE][SIZE];
    
    inline int mapping( int r, int c ) {
        return r * W + c;
    }
    
    int calc_dist( int r1, int c1, int r2, int c2 ) {
        return abs(r2 - r1) + abs(c2 - c1);
    }

    int dfs( int r, int c ) {
        if ( F[r][c] != BIRD )
            return 0;
        int res = 1;
        V[r][c] = true;
        for ( int nr = 0; nr < H; ++ nr ) {
            for ( int nc = 0; nc < W; ++ nc ) {
                if ( ! V[nr][nc] && F[nr][nc] == BIRD && calc_dist(r, c, nr, nc) <= D ) {
                    res += dfs(nr, nc);
                }
            }
        }
        return res;
    }
    
    VI calc_groups() {
        VI res;
        for ( int r = 0; r < H; ++ r ) {
            for ( int c = 0; c < W; ++ c ) {
                if ( ! V[r][c] && F[r][c] == BIRD )
                    res.push_back(dfs(r, c));
            }
        }
        return res;
    }
    
    int calc() {
        VI groups = calc_groups();
        int n = groups.size();
        LL odds = 0, evens = 0;
        for ( int i = 0; i < n; ++ i ) {
            if ( groups[i] % 2 == 0 ) {
                evens ++;
            } else {
                odds ++;
            }
        }

        LL res = ( mod_pow(2LL, evens, MOD) * mod_pow(2LL, max(0LL, odds - 1), MOD) ) % MOD;
        return ( res - 1 + MOD ) % MOD;
    }

    void pre_calc() {
        fact[0] = fact[1] = 1;
        for ( int i = 2; i < SIZE * SIZE; ++ i )
            fact[i] = ( fact[i - 1] * i ) % MOD;
    }
    
    struct Solution {
        int solve( vector <string> field, int dist ) {
            pre_calc();
            F = field;
            H = F.size();
            W = F[0].size();
            D = dist;
            return calc();
        }
    };
}

int GooseInZooDivOne::count( vector <string> field, int dist ) {
    return solution::Solution().solve(field, dist);
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
        void verify_case(const int caseno, const vector <string>&field, const int&dist, const int& Expected, bool verbose = false) {
            int Received = GooseInZooDivOne().count(field, dist);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tfield: " << field<< endl;
                if (verbose) cerr << "\tdist: " << dist<< endl;
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
#define RUN_TEST()	 verify_case(caseno, field, dist, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string field_[] = {"vvv"};
        vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
        int dist = 0;
        int _ = 3;
        RUN_TEST();
    }
    CASE(1){
        string field_[] = {"."};
        vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
        int dist = 100;
        int _ = 0;
        RUN_TEST();
    }
    CASE(2){
        string field_[] = {"vvv"};
        vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
        int dist = 1;
        int _ = 0;
        RUN_TEST();
    }
    CASE(3){
        string field_[] = {"v.v..................v............................"
            ,".v......v..................v.....................v"
                ,"..v.....v....v.........v...............v......v..."
                ,".........vvv...vv.v.........v.v..................v"
                ,".....v..........v......v..v...v.......v..........."
                ,"...................vv...............v.v..v.v..v..."
                ,".v.vv.................v..............v............"
                ,"..vv.......v...vv.v............vv.....v.....v....."
                ,"....v..........v....v........v.......v.v.v........"
                ,".v.......v.............v.v..........vv......v....."
                ,"....v.v.......v........v.....v.................v.."
                ,"....v..v..v.v..............v.v.v....v..........v.."
                ,"..........v...v...................v..............v"
                ,"..v........v..........................v....v..v..."
                ,"....................v..v.........vv........v......"
                ,"..v......v...............................v.v......"
                ,"..v.v..............v........v...............vv.vv."
                ,"...vv......v...............v.v..............v....."
                ,"............................v..v.................v"
                ,".v.............v.......v.........................."
                ,"......v...v........................v.............."
                ,".........v.....v..............vv.................."
                ,"................v..v..v.........v....v.......v...."
                ,"........v.....v.............v......v.v............"
                ,"...........v....................v.v....v.v.v...v.."
                ,"...........v......................v...v..........."
                ,"..........vv...........v.v.....................v.."
                ,".....................v......v............v...v...."
                ,".....vv..........................vv.v.....v.v....."
                ,".vv.......v...............v.......v..v.....v......"
                ,"............v................v..........v....v...."
                ,"................vv...v............................"
                ,"................v...........v........v...v....v..."
                ,"..v...v...v.............v...v........v....v..v...."
                ,"......v..v.......v........v..v....vv.............."
                ,"...........v..........v........v.v................"
                ,"v.v......v................v....................v.."
                ,".v........v................................v......"
                ,"............................v...v.......v........."
                ,"........................vv.v..............v...vv.."
                ,".......................vv........v.............v.."
                ,"...v.............v.........................v......"
                ,"....v......vv...........................v........."
                ,"....vv....v................v...vv..............v.."
                ,".................................................."
                ,"vv........v...v..v.....v..v..................v...."
                ,".........v..............v.vv.v.............v......"
                ,".......v.....v......v...............v............."
                ,"..v..................v................v....v......"
                ,".....v.....v.....................v.v......v......."};
        vector <string> field(field_, field_+sizeof(field_)/sizeof(*field_)); 
        int dist = 3;
        int _ = 898961330;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE



