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

struct PolygonTraversal {
    long long count( int N, vector <int> points );
};


// @snippet<sh19910711/contest:io/config.cpp>
namespace io {
    const std::string OUTPUT_VECTOR_DELIMITER = ",";
}

// @snippet<sh19910711/contest:io/vector.cpp>
namespace io {
    template <typename T> std::ostream& operator <<( std::ostream& os, const std::vector<T>& v ) {
        typedef typename std::vector<T>::const_iterator Iterator;
        for ( Iterator it_i = v.begin(); it_i != v.end(); ++ it_i ) {
            os << *it_i;
            if ( it_i + 1 != v.end() )
                os << OUTPUT_VECTOR_DELIMITER;
        }
        return os;
    }
    template <typename T> std::istream& operator >>( std::istream& is, std::vector<T>& v ) {
        int n = v.size();
        for ( int i = 0; i < n; ++ i ) {
            is >> v[i];
        }
        return is;
    }
}

namespace solution {
    using namespace std;
    using namespace io;
    
    typedef istringstream ISS;
    typedef ostringstream OSS;
    typedef vector<string> VS;
    typedef long long LL;
    typedef int INT;
    typedef vector<INT> VI;
    typedef vector<VI> VVI;
    typedef pair<INT, INT> II;
    
    const int SIZE = 18;
    const int BIT_SIZE = 1 << SIZE;
    const LL NONE = -1;
    LL res[SIZE][BIT_SIZE];
    int n;
    int first_node;
    int goal_state;
    
    void init() {
        fill( (LL*)res, (LL*)res+SIZE*BIT_SIZE, NONE );
    }
    
    class Dec {
    public:
        int operator ()( int k ) {
            return k - 1;
        }
    };

    void dec_all( VI& P ) {
        transform(P.begin(), P.end(), P.begin(), Dec());
    }
    
    bool check_intersect( int from, int to, int state ) {
        if ( from > to )
            swap( from, to );
        bool inner = false;
        bool outer = false;
        for ( int i = 0; i < n; ++ i ) {
            int bi = 1 << i;
            if ( state & bi ) {
                if ( i < from || i > to ) {
                    outer = true;
                } else if ( i > from && i < to ) {
                    inner = true;
                }
            }
        }
        return outer & inner;
    }
    
    LL rec( int current, int state ) {
        if ( res[current][state] != NONE )
            return res[current][state];
        res[current][state] = 0;
        if ( state == goal_state ) {
            if ( check_intersect( current, first_node, state ) ) 
                res[current][state] = 1;
        }
        for ( int i = 0; i < n; ++ i ) {
            int bi = 1 << i;
            if ( ( state & bi ) == 0 )
                if ( check_intersect( current, i, state ) )
                    res[current][state] += rec( i, state | bi );
        }
        return res[current][state];
    }
    
    struct Solution {
        long long solve( int N, vector <int> points ) {
            n = N;
            goal_state = ( 1 << n ) - 1;
            VI P = points;
            int m = P.size();
            dec_all(P);
            init();
            int start_state = 0;
            for ( VI::iterator it_i = P.begin(); it_i != P.end(); ++ it_i ) {
                int bi = 1 << *it_i;
                start_state |= bi;
            }
            first_node = P[0];
            return rec( P[m-1], start_state );
        }
    };
}

long long PolygonTraversal::count( int N, vector <int> points ) {
    return solution::Solution().solve( N, points );
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
        void verify_case(const int caseno, const int&N, const vector <int>&points, const long long& Expected, bool verbose = false) {
            long long Received = PolygonTraversal().count(N, points);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tN: " << N<< endl;
                if (verbose) cerr << "\tpoints: " << points<< endl;
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
#define RUN_TEST()	 verify_case(caseno, N, points, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int N = 5;
        int points_[] = {1, 3, 5};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        long long _ = 1LL;
        RUN_TEST();
    }
    CASE(1){
        int N = 6;
        int points_[] = {1, 4, 2};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        long long _ = 1LL;
        RUN_TEST();
    }
    CASE(2){
        int N = 7;
        int points_[] = {2, 4, 7};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        long long _ = 2LL;
        RUN_TEST();
    }
    CASE(3){
        int N = 7;
        int points_[] = {1, 2, 3, 4, 6, 5};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        long long _ = 0LL;
        RUN_TEST();
    }
    CASE(4){
        int N = 18;
        int points_[] = {1, 7, 18};
        vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
        long long _ = 4374612736LL;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

