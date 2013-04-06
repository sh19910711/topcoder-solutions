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

struct FindingSquareInTable { int findMaximalSquare( vector <string> table ); };

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
    
    const int NONE = -1;
    const int INF = std::numeric_limits<int>::max();
    VS T;
    int H, W;

    int to_int( const string& s ) {
        ISS iss(s);
        int res;
        iss >> res;
        return res;
    }

    bool is_number( double k ) {
        return fabs( ceil(k) - floor(k) ) < 1e-9;
    }

    bool is_square( int k ) {
        double sk = sqrt(k);
        if ( ! is_number(sk) )
            return false;
        int nsk = (int)sk;
        return nsk * nsk == k;
    }

    int rec( int r, int c, int dr, int dc, string cur ) {
        int res = NONE;
        if ( cur != "" ) {
            reverse(cur.begin(), cur.end());
            int k1 = to_int(cur);
            if ( is_square(k1) )
                res = max(res, k1);
            reverse(cur.begin(), cur.end());
            int k2 = to_int(cur);
            if ( is_square(k2) )
                res = max(res, k2);
        }
        int nr = r + dr;
        int nc = c + dc;
        if ( nr < 0 || nr >= H || nc < 0 || nc >= W )
            return res;
        string next = cur + T[nr][nc];
        return max(res, rec(nr, nc, dr, dc, next));
    }

    struct Solution {
        int solve( vector <string> table ) {
            int res = NONE;
            T = table;
            H = T.size();
            W = T[0].size();
            for ( int sr = 0; sr < H; ++ sr ) {
                for ( int sc = 0; sc < W; ++ sc ) {
                    for ( int dr = -9; dr <= 9; ++ dr ) {
                        for ( int dc = -9; dc <= 9; ++ dc ) {
                            if ( dr == 0 && dc == 0 )
                                continue;
                            res = max( res, rec( sr, sc, dr, dc, string()+T[sr][sc] ) );
                        }
                    }
                }
            }
            return res;
        }
    };
}

int FindingSquareInTable::findMaximalSquare( vector <string> table ) {
    return solution::Solution().solve(table);
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
        void verify_case(const int caseno, const vector <string>&table, const int& Expected, bool verbose = false) {
            int Received = FindingSquareInTable().findMaximalSquare(table);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\ttable: " << table<< endl;
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
#define RUN_TEST()	 verify_case(caseno, table, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string table_[] = {"123",
            "456"};
        vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
        int _ = 64;
        RUN_TEST();
    }
    CASE(1){
        string table_[] = {"00000",
            "00000",
            "00200",
            "00000",
            "00000"};
        vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
        int _ = 0;
        RUN_TEST();
    }
    CASE(2){
        string table_[] = {"3791178",
            "1283252",
            "4103617",
            "8233494",
            "8725572",
            "2937261"};
        vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
        int _ = 320356;
        RUN_TEST();
    }
    CASE(3){
        string table_[] = {"135791357",
            "357913579",
            "579135791",
            "791357913",
            "913579135"}
        ;
        vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
        int _ = 9;
        RUN_TEST();
    }
    CASE(4){
        string table_[] = {"553333733",
            "775337775",
            "777537775",
            "777357333",
            "755553557",
            "355533335",
            "373773573",
            "337373777",
            "775557777"};
        vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
        int _ = -1;
        RUN_TEST();
    }
    CASE(5){
        string table_[] = {"257240281",
            "197510846",
            "014345401",
            "035562575",
            "974935632",
            "865865933",
            "684684987",
            "768934659",
            "287493867"};
        vector <string> table(table_, table_+sizeof(table_)/sizeof(*table_)); 
        int _ = 95481;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

