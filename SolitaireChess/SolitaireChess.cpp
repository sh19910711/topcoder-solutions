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

const int INF = std::numeric_limits<int>::max();

struct SolitaireChess { int transform( vector <string> board1, vector <string> board2 ); };

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


// @snippet<sh19910711/contest:table/trie.cpp>
namespace table {
    // @desc トライ木の実装
    template <class ValueType> class Trie {
    public:
        typedef std::vector<int>::const_iterator StringIterator;
        static const int SIZE = 3;
        ValueType value;
        Trie *next[SIZE];
        Trie() { value = INF; clear(); }
        void clear() { std::fill( next, next+SIZE, (Trie*)NULL ); }
        Trie& find( const std::vector<int>& s ) {
            Trie* res = this;
            for ( StringIterator it_i = s.begin(); it_i != s.end(); ++ it_i ) {
                const int& c = *it_i;
                if ( ! res->next[c] ) res->next[c] = new Trie;
                res = res->next[c];
            }
            return *res;
        }
        ValueType& operator []( const std::vector<int>& s ) { return find(s).value; }
    };
}

namespace solution {
    
    typedef pair<int, VI> Node;
    typedef queue <Node> Queue;
    typedef table::Trie<int> MinCost;
    const int SIZE = 8;
    const int BOARD_SIZE = SIZE * SIZE;
    const char EMPTY_CHAR = '.';
    const char KNIGHT_CHAR = 'N';
    const char PAWN_CHAR = 'P';
    const int NONE = -1;
    enum CHESS_TYPE { EMPTY, KNIGHT, PAWN };
    const int dr[8] = { 1, 2, 2, 1,     -1, -2, -2, -1 };
    const int dc[8] = { 2, 1, -1, -2,   2, 1, -1, -2 };
    
    VI B1;
    VI B2;
    Queue Q;
    MinCost MC;
    
    int mapping( int r, int c ) {
        return r * SIZE + c;
    }

    void bfs_init() {
        Q = Queue();
        MC.clear();
    }

    bool exist_knight( const VI& board, int r, int c ) {
        return board[mapping(r-1, c)] == KNIGHT;
    }

    bool exist_pawn( const VI& board, int r, int c ) {
        return board[mapping(r-1, c)] == PAWN;
    }

    void debug( const VI& board ) {
        for ( int i = 0; i < SIZE; ++ i ) {
            for ( int j = 0; j < SIZE; ++ j ) {
                cout << board[mapping(i, j)];
            }
            cout << endl;
        }
        cout << endl;
    }
    
    int bfs() {
        bfs_init();

        VI start = B1;
        VI goal = B2;
        MC[start] = 0;
        Q.push(Node(0, start));

        while ( ! Q.empty() ) {
            Node node = Q.front();
            Q.pop();

            int steps = node.first;
            VI board = node.second;

            if ( board == goal )
                return steps;

            VI backup = board;

            for ( int i = 0; i < 64; ++ i ) {
                board = backup;
                int r = i / SIZE;
                int c = i % SIZE;
                int k = mapping(r, c);
                if ( board[k] == PAWN && board[k] != goal[k] ) {
                    if ( exist_knight(board, r, c) ) {
                        int kr = r - 1;
                        int kc = c;
                        for ( int j = 0; j < 8; ++ j ) {
                            int nkr = kr + dr[j];
                            int nkc = kc + dc[j];
                            if ( nkr < 0 || nkr >= SIZE || nkc < 0 || nkc >= SIZE )
                                continue;
                            if ( exist_knight(board, nkr, nkc) || exist_pawn(board, nkr, nkc) )
                                continue;
                            board = backup;
                            board[mapping(nkr, nkc)] = board[mapping(kr, kc)];
                            board[mapping(kr, kc)] = board[mapping(r, c)];
                            board[mapping(r, c)] = EMPTY;
                            if ( kr == 0 )
                                board[mapping(0, kc)] = KNIGHT;
                            int next_steps = steps + 2;
                            if ( next_steps >= MC[board] )
                                continue;
                            MC[board] = next_steps;
                            Q.push(Node(next_steps, board));
                        }
                    } else if ( exist_pawn(board, r, c) ) {
                    } else {
                        board[mapping(r-1, c)] = board[mapping(r, c)];
                        board[mapping(r, c)] = EMPTY;
                        if ( r - 1 == 0 )
                            board[mapping(0, c)] = KNIGHT;
                        int next_steps = steps + 1;
                        if ( next_steps >= MC[board] )
                            continue;
                        MC[board] = next_steps;
                        Q.push(Node(next_steps, board));
                    }
                }
            }

            for ( int i = 0; i < 64; ++ i ) {
                board = backup;
                int r = i / SIZE;
                int c = i % SIZE;
                int k = mapping(r, c);
                if ( board[k] == KNIGHT && board[k] != goal[k] ) {
                    for ( int j = 0; j < 8; ++ j ) {
                        int nr = r + dr[j];
                        int nc = c + dc[j];
                        if ( nr < 0 || nr >= SIZE || nc < 0 || nc >= SIZE )
                            continue;
                        if ( board[mapping(nr, nc)] != EMPTY )
                            continue;
                        board[mapping(nr, nc)] = board[mapping(r, c)];
                        board[mapping(r, c)] = EMPTY;
                        int next_steps = steps + 1;
                        if ( next_steps >= MC[board] )
                            continue;
                        MC[board] = next_steps;
                        Q.push(Node(next_steps, board));
                    }
                }
            }
        }

        return NONE;
    }
    
    int get_type( char c ) {
        if ( c == EMPTY_CHAR )
            return EMPTY;
        if ( c == KNIGHT_CHAR )
            return KNIGHT;
        if ( c == PAWN_CHAR )
            return PAWN;
        return -1;
    }
    
    VI convert( VS board ) {
        VI res(BOARD_SIZE);
        for ( int i = 0; i < SIZE; ++ i )
            for ( int j = 0; j < SIZE; ++ j )
                res[mapping(i, j)] = get_type(board[i][j]);
        return res;
    }
    
    struct Solution {
        int solve( vector <string> board1, vector <string> board2 ) {
            B1 = convert(board1);
            B2 = convert(board2);
            return bfs();
        }
    };
}

int SolitaireChess::transform( vector <string> board1, vector <string> board2 ) {
    return solution::Solution().solve(board1, board2);
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
        void verify_case(const int caseno, const vector <string>&board1, const vector <string>&board2, const int& Expected, bool verbose = false) {
            int Received = SolitaireChess().transform(board1, board2);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tboard1: " << board1<< endl;
                if (verbose) cerr << "\tboard2: " << board2<< endl;
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
#define RUN_TEST()	 verify_case(caseno, board1, board2, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string board1_[] = {"...N....",
            "........",
            "........",
            "........",
            "........",
            "........",
            "...P....",
            "........"};
        vector <string> board1(board1_, board1_+sizeof(board1_)/sizeof(*board1_)); 
        string board2_[] = {"...N....",
            ".....N..",
            "........",
            "........",
            "........",
            "........",
            "........",
            "........"};
        vector <string> board2(board2_, board2_+sizeof(board2_)/sizeof(*board2_)); 
        int _ = 7;
        RUN_TEST();
    }
    CASE(1){
        string board1_[] = {"........",
            "........",
            "...P....",
            "........",
            "........",
            "........",
            "........",
            "........"};
        vector <string> board1(board1_, board1_+sizeof(board1_)/sizeof(*board1_)); 
        string board2_[] = {"........",
            "........",
            "........",
            "........",
            "........",
            "........",
            "........",
            "...P...."};
        vector <string> board2(board2_, board2_+sizeof(board2_)/sizeof(*board2_)); 
        int _ = -1;
        RUN_TEST();
    }
    CASE(2){
        string board1_[] = {"........",
            "........",
            "........",
            "........",
            "........",
            "........",
            "........",
            ".N...P.."};
        vector <string> board1(board1_, board1_+sizeof(board1_)/sizeof(*board1_)); 
        string board2_[] = {"........",
            "........",
            "........",
            "........",
            "........",
            "........",
            ".....P..",
            ".......N"};
        vector <string> board2(board2_, board2_+sizeof(board2_)/sizeof(*board2_)); 
        int _ = 5;
        RUN_TEST();
    }
    CASE(3){
        string board1_[] = {"N.......",
            "........",
            "N.......",
            "........",
            "........",
            "........",
            "........",
            "........"};
        vector <string> board1(board1_, board1_+sizeof(board1_)/sizeof(*board1_)); 
        string board2_[] = {"........",
            "..N.....",
            "........",
            "........",
            "........",
            "........",
            "........",
            "........"};
        vector <string> board2(board2_, board2_+sizeof(board2_)/sizeof(*board2_)); 
        int _ = -1;
        RUN_TEST();
    }
    CASE(4){
        string board1_[] = {"..N.N...",
            "PPP....N",
            "..N..N..",
            "N...N...",
            "...NNNNN",
            "N.......",
            "...NN...",
            "..N...N."};
        vector <string> board1(board1_, board1_+sizeof(board1_)/sizeof(*board1_)); 
        string board2_[] = {"..N....N",
            "P....N..",
            "..N..N..",
            "N..NNN.N",
            "N.....N.",
            "N.N.....",
            "...NNN..",
            ".....N.N"};
        vector <string> board2(board2_, board2_+sizeof(board2_)/sizeof(*board2_)); 
        int _ = 23;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE


