// Refered to: http://community.topcoder.com/stat?c=problem_solution&rm=299962&rd=13694&pm=10178&cr=10574855
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

struct BuildersCountry {
    long long minCost( vector <int> before, vector <int> after, vector <int> houseCost, vector <string> g, int roadCost );
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

    const int SIZE = 101;
    VI before, after, houseCost;
    VS g;
    int roadCost;
    LL afterBuild[SIZE][SIZE];
    LL build[SIZE][SIZE];

    class Edge {
    public:
        int start;
        int end;
        Edge( int start, int end ): start(start), end(end) {}
    };

    bool operator <( const Edge o1, const Edge o2 ) {
        LL z1 = build[o1.start][o1.end] + afterBuild[o1.start][o1.end];
        LL z2 = build[o2.start][o2.end] + afterBuild[o2.start][o2.end];
        return z1 < z2;
    }
   
    struct Solution {
        long long solve( vector <int> before_, vector <int> after_, vector <int> houseCost_, vector <string> g_, int roadCost_ ) {
            before = before_;
            after = after_;
            houseCost = houseCost_;
            g = g_;
            roadCost = roadCost_;

            int n = before.size();
            LL res = 0;

            for ( int i = 0; i < n; ++ i ) {
                LL cur = houseCost[i];
                cur *= ( before[i] + after[i] - 1 );
                cur *= ( after[i] - before[i] );
                cur /= 2;
                res += cur;
            }

            for ( int i = 0; i < SIZE; ++ i )
                for ( int j = 0; j < SIZE; ++ j ) {
                    afterBuild[i][j] = 0;
                    build[i][j] = 0;
                }

            for ( int i = 0; i < n; ++ i ) {
                for ( int j = 0; j < n; ++ j ) {
                    if ( i != j ) {
                        int b1 = before[i];
                        int a1 = after[i];
                        int b2 = before[j];
                        int a2 = after[j];
                        LL c1 = houseCost[i];
                        LL c2 = houseCost[j];
                        if ( houseCost[i] < houseCost[j] ) {
                            swap( b1, b2 );
                            swap( a1, a2 );
                            swap( c1, c2 );
                        }
                        LL cur = c1 * b2 * ( a1 - b1 ) + c2 * a1 * ( a2 - b2 );
                        afterBuild[i][j] = cur;
                        cur = roadCost;
                        cur *= ( b1 + b2 );
                        build[i][j] = cur;
                    }
                }
            }

            int comp[n];
            for ( int i = 0; i < n; ++ i )
                comp[i] = i;

            vector<Edge> edges;
            for ( int i = 0; i < n; ++ i ) {
                for ( int j = i + 1; j < n; ++ j ) {
                    if ( g[i][j] == 'Y' ) {
                        res += afterBuild[i][j];
                        if ( comp[i] != comp[j] ) {
                            int a = comp[i];
                            int b = comp[j];
                            for ( int k = 0; k < n; ++ k ) {
                                if ( comp[k] == a )
                                    comp[k] = b;
                            }
                        }
                    } else {
                        edges.push_back(Edge( i, j ) );
                    }
                }
            }

            sort( edges.begin(), edges.end() );

            for ( vector<Edge>::iterator it_i = edges.begin(); it_i != edges.end(); ++ it_i ) {
                Edge& e = *it_i;
                if ( comp[e.start] != comp[e.end] ) {
                    int a = comp[e.start];
                    int b = comp[e.end];
                    for ( int k = 0; k < n; ++ k )
                        if ( comp[k] == a )
                            comp[k] = b;
                    res += build[e.start][e.end] + afterBuild[e.start][e.end];
                }
            }

            return res;
        }
    };
}

long long BuildersCountry::minCost( vector <int> before, vector <int> after, vector <int> houseCost, vector <string> g, int roadCost ) {
    return solution::Solution().solve( before, after, houseCost, g, roadCost );
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
void verify_case(const int caseno, const vector <int>&before, const vector <int>&after, const vector <int>&houseCost, const vector <string>&g, const int&roadCost, const long long& Expected, bool verbose = false) {
  long long Received = BuildersCountry().minCost(before, after, houseCost, g, roadCost);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tbefore: " << before<< endl;
  if (verbose) cerr << "\tafter: " << after<< endl;
  if (verbose) cerr << "\thouseCost: " << houseCost<< endl;
  if (verbose) cerr << "\tg: " << g<< endl;
  if (verbose) cerr << "\troadCost: " << roadCost<< endl;
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
#define RUN_TEST()	 verify_case(caseno, before, after, houseCost, g, roadCost, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        int before_[] = {2, 1, 3, 5};
        vector <int> before(before_, before_+sizeof(before_)/sizeof(*before_)); 
        int after_[] = {2, 1, 3, 5};
        vector <int> after(after_, after_+sizeof(after_)/sizeof(*after_)); 
        int houseCost_[] = {4, 5, 3, 2};
        vector <int> houseCost(houseCost_, houseCost_+sizeof(houseCost_)/sizeof(*houseCost_)); 
        string g_[] = {"NNNN", "NNNN", "NNNN", "NNNN"};
        vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
        int roadCost = 1000;
        long long _ = 13000LL;
        RUN_TEST();
    }
    CASE(1){
        int before_[] = {1, 1, 1, 1};
        vector <int> before(before_, before_+sizeof(before_)/sizeof(*before_)); 
        int after_[] = {1, 3, 1, 2};
        vector <int> after(after_, after_+sizeof(after_)/sizeof(*after_)); 
        int houseCost_[] = {8, 5, 3, 2};
        vector <int> houseCost(houseCost_, houseCost_+sizeof(houseCost_)/sizeof(*houseCost_)); 
        string g_[] = {"NYNN", "YNYN", "NYNY", "NNYN"};
        vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
        int roadCost = 100000;
        long long _ = 39LL;
        RUN_TEST();
    }
    CASE(2){
        int before_[] = {9, 11};
        vector <int> before(before_, before_+sizeof(before_)/sizeof(*before_)); 
        int after_[] = {10, 11};
        vector <int> after(after_, after_+sizeof(after_)/sizeof(*after_)); 
        int houseCost_[] = {5, 1};
        vector <int> houseCost(houseCost_, houseCost_+sizeof(houseCost_)/sizeof(*houseCost_)); 
        string g_[] = {"NN", "NN"};
        vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
        int roadCost = 15;
        long long _ = 400LL;
        RUN_TEST();
    }
    CASE(3){
        int before_[] = {1};
        vector <int> before(before_, before_+sizeof(before_)/sizeof(*before_)); 
        int after_[] = {1000};
        vector <int> after(after_, after_+sizeof(after_)/sizeof(*after_)); 
        int houseCost_[] = {2};
        vector <int> houseCost(houseCost_, houseCost_+sizeof(houseCost_)/sizeof(*houseCost_)); 
        string g_[] = {"N"};
        vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
        int roadCost = 888;
        long long _ = 999000LL;
        RUN_TEST();
    }
    CASE(4){
        int before_[] = {99, 23, 44, 55, 32};
        vector <int> before(before_, before_+sizeof(before_)/sizeof(*before_)); 
        int after_[] = {99, 23, 44, 55, 32};
        vector <int> after(after_, after_+sizeof(after_)/sizeof(*after_)); 
        int houseCost_[] = {39, 32, 11, 23, 89};
        vector <int> houseCost(houseCost_, houseCost_+sizeof(houseCost_)/sizeof(*houseCost_)); 
        string g_[] = {"NYNNN", "YNNNY", "NNNYY", "NNYNY", "NYYYN"};
        vector <string> g(g_, g_+sizeof(g_)/sizeof(*g_)); 
        int roadCost = 54;
        long long _ = 0LL;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
