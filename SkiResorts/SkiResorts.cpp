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
#include <limits>
using namespace std;

struct SkiResorts {
    long long minCost( vector <string> road, vector <int> altitude );
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
    
    const int SIZE = 51;
    VI A;
    VS R;
    int n;
    
    typedef pair<int, int> State;
    typedef pair<LL, State> Node;
    typedef priority_queue<Node, vector<Node>, greater<Node> > Queue;
    
    const LL INF = std::numeric_limits<LL>::max() / 2;
    LL MC[SIZE][SIZE];
    Queue Q;
    
    struct Solution {
        LL dist( LL a, LL b ) {
            return abs( a - b );
        }

        void init() {
            fill( (LL*)MC, (LL*)MC+SIZE*SIZE, INF );
            Q = Queue();
        }

        void dijkstra() {
            // 地点iを地点jの高さに揃える
            for ( int i = 0; i < n; ++ i ) {
                MC[0][i] = dist( A[0], A[i] );
                Q.push( Node( MC[0][i], State( 0, i ) ) );
            }
            while ( ! Q.empty() ) {
                Node node = Q.top();
                Q.pop();

                LL cost = node.first;
                int v = node.second.first;
                int p = node.second.second;

                for ( int i = 0; i < n; ++ i ) {
                    if ( R[v][i] == 'N' )
                        continue;
                    for ( int j = 0; j < n; ++ j ) {
                        if ( A[p] < A[j] )
                            continue;
                        LL new_cost = cost + dist( A[i], A[j] );
                        if ( new_cost >= MC[i][j] )
                            continue;
                        MC[i][j] = new_cost;
                        Q.push( Node( new_cost, State( i, j ) ) );
                    }
                }
            }
        }

        long long solve(  vector <string> road, vector <int> altitude  ) {
            A = altitude;
            R = road;
            n = A.size();

            init();
            dijkstra();

            LL res = INF;
            for ( int i = 0; i < n; ++ i )
                res = min( res, MC[n-1][i] );

            return res == INF ? -1 : res;
        }
    };
}

long long SkiResorts::minCost( vector <string> road, vector <int> altitude ) {
    return solution::Solution().solve( road, altitude );
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
        void verify_case(const int caseno, const vector <string>&road, const vector <int>&altitude, const long long& Expected, bool verbose = false) {
            long long Received = SkiResorts().minCost(road, altitude);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\troad: " << road<< endl;
                if (verbose) cerr << "\taltitude: " << altitude<< endl;
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
#define RUN_TEST()	 verify_case(caseno, road, altitude, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string road_[] = {"NYN",
            "YNY",
            "NYN"};
        vector <string> road(road_, road_+sizeof(road_)/sizeof(*road_)); 
        int altitude_[] = {30, 20, 10};
        vector <int> altitude(altitude_, altitude_+sizeof(altitude_)/sizeof(*altitude_)); 
        long long _ = 0LL;
        RUN_TEST();
    }
    CASE(1){
        string road_[] = {"NY",
            "YN"};
        vector <string> road(road_, road_+sizeof(road_)/sizeof(*road_)); 
        int altitude_[] = {10, 20};
        vector <int> altitude(altitude_, altitude_+sizeof(altitude_)/sizeof(*altitude_)); 
        long long _ = 10LL;
        RUN_TEST();
    }
    CASE(2){
        string road_[] = {"NYN",
            "YNN",
            "NNN"};
        vector <string> road(road_, road_+sizeof(road_)/sizeof(*road_)); 
        int altitude_[] = {573, 573, 573};
        vector <int> altitude(altitude_, altitude_+sizeof(altitude_)/sizeof(*altitude_)); 
        long long _ = -1LL;
        RUN_TEST();
    }
    CASE(3){
        string road_[] = {"NNYNNYYYNN",
            "NNNNYNYNNN",
            "YNNNNYYNNN",
            "NNNNNNYNYY",
            "NYNNNNNNYY",
            "YNYNNNNYNN",
            "YYYYNNNYNN",
            "YNNNNYYNNN",
            "NNNYYNNNNN",
            "NNNYYNNNNN"};
        vector <string> road(road_, road_+sizeof(road_)/sizeof(*road_)); 
        int altitude_[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
        vector <int> altitude(altitude_, altitude_+sizeof(altitude_)/sizeof(*altitude_)); 
        long long _ = 12LL;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

