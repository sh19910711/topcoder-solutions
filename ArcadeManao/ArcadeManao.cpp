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

struct ArcadeManao { int shortestLadder( vector <string> level, int coinRow, int coinColumn ); };

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

    const char BLOCK = 'X';
    const int SIZE = 101;

    VS L;
    int h, w;
    int gr, gc;

    typedef pair<int, II> Node;
    typedef priority_queue<Node, vector<Node>, greater<Node> > Queue;

    Queue Q;
    bool V[SIZE][SIZE][SIZE];

    bool check_invalid_pos( int r, int c ) {
        return r < 0 || r >= h || c < 0 || c >= w;
    }

    int search( int sr, int sc ) {
        Q = Queue();
        for ( int i = 0; i < SIZE; ++ i )
            for ( int j = 0; j < SIZE; ++ j )
                for ( int k = 0; k < SIZE; ++ k )
                    V[i][j][k] = false;

        Q.push(Node(0, II(sr, sc)));
        V[0][sr][sc] = true;

        while ( ! Q.empty() ) {
            Node node = Q.top();
            Q.pop();

            int len = node.first;
            int r = node.second.first;
            int c = node.second.second;

            if ( r == gr && c == gc )
                return len;

            for ( int i = 0; i < w; ++ i ) {
                int nr = r;
                int nc = c - i;
                if ( check_invalid_pos(nr, nc) )
                    continue;
                if ( L[nr][nc] != BLOCK )
                    break;
                if ( V[len][nr][nc] )
                    continue;
                V[len][nr][nc] = true;
                Q.push(Node(len, II(nr, nc)));
            }

            for ( int i = 0; i < w; ++ i ) {
                int nr = r;
                int nc = c + i;
                if ( check_invalid_pos(nr, nc) )
                    continue;
                if ( L[nr][nc] != BLOCK )
                    break;
                if ( V[len][nr][nc] )
                    continue;
                V[len][nr][nc] = true;
                Q.push(Node(len, II(nr, nc)));
            }

            for ( int i = 0; i < h; ++ i ) {
                int nr = i;
                int nc = c;
                int nlen = max(len, abs(r - nr));
                if ( nr == gr && nc == gc ) {
                    if ( V[nlen][nr][nc] )
                        continue;
                    V[nlen][nr][nc] = true;
                    Q.push(Node(nlen, II(nr, nc)));
                }
                if ( check_invalid_pos(nr, nc) ) 
                    continue;
                if ( L[nr][nc] != BLOCK )
                    continue;
                if ( V[nlen][nr][nc] )
                    continue;
                V[nlen][nr][nc] = true;
                Q.push(Node(nlen, II(nr, nc)));
            }
        }

        return -1;
    }

    struct Solution {
        int solve( vector <string> level, int coinRow, int coinColumn ) {
            L = level;
            h = L.size();
            w = L[0].size();
            gr = coinRow - 1;
            gc = coinColumn - 1;
            for ( int i = 0; i < w; ++ i )
                if ( L[h-1][i] == BLOCK )
                    return search( h-1, 0 );
            return 0;
        }
    };
}

int ArcadeManao::shortestLadder( vector <string> level, int coinRow, int coinColumn ) {
    return solution::Solution().solve(level, coinRow, coinColumn);
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
        void verify_case(const int caseno, const vector <string>&level, const int&coinRow, const int&coinColumn, const int& Expected, bool verbose = false) {
            int Received = ArcadeManao().shortestLadder(level, coinRow, coinColumn);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tlevel: " << level<< endl;
                if (verbose) cerr << "\tcoinRow: " << coinRow<< endl;
                if (verbose) cerr << "\tcoinColumn: " << coinColumn<< endl;
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
#define RUN_TEST()	 verify_case(caseno, level, coinRow, coinColumn, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string level_[] = {"XXXX....",
            "...X.XXX",
            "XXX..X..",
            "......X.",
            "XXXXXXXX"};
        vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
        int coinRow = 2;
        int coinColumn = 4;
        int _ = 2;
        RUN_TEST();
    }
    CASE(1){
        string level_[] = {"XXXX",
            "...X",
            "XXXX"};
        vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
        int coinRow = 1;
        int coinColumn = 1;
        int _ = 1;
        RUN_TEST();
    }
    CASE(2){
        string level_[] = {"..X..",
            ".X.X.",
            "X...X",
            ".X.X.",
            "..X..",
            "XXXXX"};
        vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
        int coinRow = 1;
        int coinColumn = 3;
        int _ = 4;
        RUN_TEST();
    }
    CASE(3){
        string level_[] = {"X"};
        vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
        int coinRow = 1;
        int coinColumn = 1;
        int _ = 0;
        RUN_TEST();
    }
    CASE(4){
        string level_[] = {"XXXXXXXXXX",
            "...X......",
            "XXX.......",
            "X.....XXXX",
            "..XXXXX..X",
            ".........X",
            ".........X",
            "XXXXXXXXXX"};
        vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
        int coinRow = 1;
        int coinColumn = 1;
        int _ = 2;
        RUN_TEST();
    }
    CASE(5){
        string level_[] = {
            "X....",
            "X...X",
            "....X",
            "....X",
            "XXXXX"};
        vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
        int coinRow = 1;
        int coinColumn = 1;
        int _ = 3;
        RUN_TEST();
    }
    CASE(6){
        string level_[] = {
            "X.XXX",
            "X.X.X",
            "X.X..",
            "XXX.X",
            "....X",
            "....X",
            "....X",
            "XXXXX"};
        vector <string> level(level_, level_+sizeof(level_)/sizeof(*level_)); 
        int coinRow = 1;
        int coinColumn = 1;
        int _ = 2;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

