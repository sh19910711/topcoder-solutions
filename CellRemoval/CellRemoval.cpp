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

struct CellRemoval { int cellsLeft( vector <int> parent, int deletedCell ); };

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
    const int SIZE = 51;
    VI P;
    int d;
    int n;
    bool G[SIZE][SIZE];

    void get_child() {
        for ( int i = 0; i < n; ++ i ) {
            for ( int j = 0; j < n; ++ j ) {
                if ( i == P[j] )
                    G[i][j] = true;
            }
        }
    }

    int calc( int from ) {
        if ( from == d )
            return 0;
        int res = 0;
        bool ok = true;
        for ( int i = 0; i < n; ++ i ) {
            if ( G[from][i] ) {
                if ( i == d )
                    continue;
                ok = false;
                res += calc( i );
            }
        }
        if ( ok )
            res ++;
        return res;
    }

    struct Solution {
        int solve( vector <int> parent, int deletedCell ) {
            P = parent;
            d = deletedCell;
            n = P.size();
            fill( (bool*)G, (bool*)G+SIZE*SIZE, false );
            get_child();
            for ( int i = 0; i < n; ++ i )
                if ( P[i] == -1 )
                    return calc(i);
            return -1;
        }
    };
}

int CellRemoval::cellsLeft( vector <int> parent, int deletedCell ) {
    return solution::Solution().solve(parent, deletedCell);
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
        void verify_case(const int caseno, const vector <int>&parent, const int&deletedCell, const int& Expected, bool verbose = false) {
            int Received = CellRemoval().cellsLeft(parent, deletedCell);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tparent: " << parent<< endl;
                if (verbose) cerr << "\tdeletedCell: " << deletedCell<< endl;
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
#define RUN_TEST()	 verify_case(caseno, parent, deletedCell, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int parent_[] = {-1,0,0,1,1};
        vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
        int deletedCell = 2;
        int _ = 2;
        RUN_TEST();
    }
    CASE(1){
        int parent_[] = {-1,0,0,1,1};
        vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
        int deletedCell = 1;
        int _ = 1;
        RUN_TEST();
    }
    CASE(2){
        int parent_[] = {-1,0,0,1,1};
        vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
        int deletedCell = 0;
        int _ = 0;
        RUN_TEST();
    }
    CASE(3){
        int parent_[] = {-1,0,0,2,2,4,4,6,6};
        vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
        int deletedCell = 4;
        int _ = 2;
        RUN_TEST();
    }
    CASE(4){
        int parent_[] = {26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43,
            35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14};
        vector <int> parent(parent_, parent_+sizeof(parent_)/sizeof(*parent_)); 
        int deletedCell = 24;
        int _ = 14;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

