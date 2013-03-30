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

struct SwitchesAndLamps { int theMin( vector <string> switches, vector <string> lamps ); };

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

    const int SIZE = 101;
    const int NONE = -1;

    int n;
    int m;
    int len;
    bool G[SIZE][SIZE];
    VS S, L;
    int pairs;
    int conn[SIZE]; // i <-> conn[i]
    bool V[SIZE];

    void init() {
        for ( int i = 0; i < SIZE; ++ i )
            for ( int j = 0; j < SIZE; ++ j )
                G[i][j] = false;
    }

    bool is_isolated( int from ) {
        for ( int i = 0; i < n + m; ++ i )
            if ( G[from][i] )
                return false;
        return true;
    }

    bool update() {
        for ( int i = 0; i < n + m; ++ i ) {
            int cnt = 0;
            int prev = NONE;
            for ( int j = 0; j < n + m; ++ j ) {
                if ( G[i][j] ) {
                    cnt ++;
                    prev = j;
                }
            }
            // 移動先が1つしかないときは、それをペアとして確定する
            if ( cnt == 1 ) {
                pairs ++;
                G[i][prev] = G[prev][i] = false;
                return true;
            }
        }
        return false;
    }

    void dfs_init() {
        for ( int i = 0; i < n + m; ++ i )
            V[i] = false;
    }

    bool dfs( int from ) {
        if ( from == NONE )
            return true;
        for ( int i = 0; i < n + m; ++ i ) {
            if ( V[i] )
                continue;
            if ( ! G[from][i] )
                continue;
            V[i] = true;
            if ( dfs(conn[i]) ) {
                conn[i] = from;
                conn[from] = i;
                return true;
            }
        }
        return false;
    }
    
    struct Solution {
        int solve( vector <string> switches, vector <string> lamps ) {
            S = switches;
            L = lamps;
            n = S[0].size();
            m = L[0].size();
            len = S.size();
            init();
            pairs = 0;

            // それぞれのスイッチとすべてのランプを接続する
            for ( int i = 0; i < n; ++ i )
                for ( int j = 0; j < n; ++ j )
                    G[i][j+n] = G[j+n][i] = true;

            // それぞれの実験について、状態が異なるスイッチとランプの接続を解除する
            for ( int i = 0; i < len; ++ i )
                for ( int j = 0; j < n; ++ j )
                    for ( int k = 0; k < m; ++ k )
                        if ( S[i][j] != L[i][k] )
                            G[j][k+n] = G[k+n][j] = false;

            // すべて頂点について、1つでも孤立している頂点が存在するときは矛盾しているものとする
            for ( int i = 0; i < n + m; ++ i )
                if ( is_isolated(i) )
                    return NONE;

            // すでに確定できる状態にあるペアをグラフから削除しておく
            while( update() );

            // あまりの部分についてペアを作っていく
            for ( int i = 0; i < n + m; ++ i )
                conn[i] = NONE;
            for ( int i = 0; i < n + m; ++ i ) {
                if ( conn[i] == NONE ) {
                    dfs_init();
                    if ( dfs(i) ) pairs ++;
                }
            }
            if ( pairs != n )
                return NONE;

            for ( int k = 0; k < n + m; ++ k )
                for ( int i = 0; i < n + m; ++ i )
                    for ( int j = 0; j < n + m; ++ j )
                        if ( G[i][k] && G[k][j] )
                            G[i][j] = true;

            for ( int i = 0; i < n + m; ++ i )
                V[i] = false;

            // 必要な実験回数の最大値を求める
            // 分割したグラフについて独立な部分については同時に確かめていくことができる
            int res = 0;
            for ( int i = 0; i < n + m; ++ i ) {
                if ( V[i] )
                    continue;
                int vertices = 1;

                // ここで孤立している頂点は既に確定済みの頂点
                if ( is_isolated(i) )
                    continue;

                V[i] = true;
                for ( int j = 0; j < n + m; ++ j ) {
                    if ( V[j] )
                        continue;
                    if ( ! G[i][j] )
                        continue;

                    V[j] = true;
                    if ( ! is_isolated(j) )
                        vertices ++;
                }
                vertices /= 2;
                res = max( res, (int)ceil(log2(vertices)) );
            }
            return res;
        }
    };
}

int SwitchesAndLamps::theMin( vector <string> switches, vector <string> lamps ) {
    return solution::Solution().solve(switches, lamps);
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
        void verify_case(const int caseno, const vector <string>&switches, const vector <string>&lamps, const int& Expected, bool verbose = false) {
            int Received = SwitchesAndLamps().theMin(switches, lamps);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tswitches: " << switches<< endl;
                if (verbose) cerr << "\tlamps: " << lamps<< endl;
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
#define RUN_TEST()	 verify_case(caseno, switches, lamps, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string switches_[] = {"NYNN", "NNYN"};
        vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
        string lamps_[] = {"NNNY", "NNYN"};
        vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
        int _ = 1;
        RUN_TEST();
    }
    CASE(1){
        string switches_[] = {"YYN", "YNY", "YYN"};
        vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
        string lamps_[] = {"YNY", "NYY", "YNY"};
        vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
        int _ = 0;
        RUN_TEST();
    }
    CASE(2){
        string switches_[] = {"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"};
        vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
        string lamps_[] = {"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"};
        vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
        int _ = -1;
        RUN_TEST();
    }
    CASE(3){
        string switches_[] = {"YYNNN", "NNYYN"};
        vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
        string lamps_[] = {"NYNNY", "NNNYY"};
        vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
        int _ = -1;
        RUN_TEST();
    }
    CASE(4){
        string switches_[] = {"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"};
        vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
        string lamps_[] = {"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"};
        vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
        int _ = 2;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

