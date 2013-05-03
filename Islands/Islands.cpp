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

struct Islands { int beachLength( vector <string> kingdom ); };

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
    
    const int dr1[3] = {0, 1, 1};
    const int dc1[3] = {1, 0, -1};
    const int dr2[3] = {0, 1, 1};
    const int dc2[3] = {1, 1, 0};
    
    VS K;
    int H, W;
    
    int calc( int r, int c ) {
        int res = 0;
        for ( int i = 0; i < 3; ++ i ) {
            int nr, nc;
            if ( r % 2 == 1 ) {
                nr = r + dr2[i];
                nc = c + dc2[i];
            } else {
                nr = r + dr1[i];
                nc = c + dc1[i];
            }
            if ( nr < 0 || nr >= H || nc < 0 || nc >= W )
                continue;
            if ( K[nr][nc] == K[r][c] )
                continue;
            res ++;
        }
        return res;
    }
    
    struct Solution {
        int solve( vector <string> kingdom ) {
            K = kingdom;
            H = K.size();
            W = K[0].size();
            
            int res = 0;
            for ( int i = 0; i < H; ++ i ) {
                for ( int j = 0; j < W; ++ j ) {
                    res += calc(i, j);
                }
            }
            return res;
        }
    };
}

int Islands::beachLength( vector <string> kingdom ) {
    return solution::Solution().solve(kingdom);
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
        void verify_case(const int caseno, const vector <string>&kingdom, const int& Expected, bool verbose = false) {
            int Received = Islands().beachLength(kingdom);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tkingdom: " << kingdom<< endl;
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
#define RUN_TEST()	 verify_case(caseno, kingdom, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string kingdom_[] = {".#...#.."};
        vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
        int _ = 4;
        RUN_TEST();
    }
    CASE(1){
        string kingdom_[] = {"..#.##", 
            ".##.#.", 
            "#.#..."};
        vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
        int _ = 19;
        RUN_TEST();
    }
    CASE(2){
        string kingdom_[] = {"#...#.....",
            "##..#...#."};
        vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
        int _ = 15;
        RUN_TEST();
    }
    CASE(3){
        string kingdom_[] = {"....#.",
            ".#....",
            "..#..#",
            "####.."};
        vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
        int _ = 24;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

