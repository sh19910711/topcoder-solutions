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

struct GroupedWord {
    string restore( vector <string> parts );
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
    
    typedef set<char> Set;
    const string NONE = "IMPOSSIBLE";
    VS P;
    int n;
    
    bool is_invalid( const string& s ) {
        int n = s.size();
        for ( int i = 0; i < n; ++ i )
            for ( int j = i+1; j < n; ++ j )
                if ( s[i] == s[j] )
                    for ( int k = i+1; k < j; ++ k )
                        if ( s[i] != s[k] )
                            return true;
        return false;
    }
    
    bool join_same_end( VS& P ) {
        int n = P.size();
        for ( int i = 0; i < n; ++ i ) {
            char c = *P[i].rbegin();
            for ( int j = 0; j < n; ++ j ) {
                if ( i != j ) {
                    if ( c == *P[j].begin() && c == *P[j].rbegin() ) {
                        P[i] += P[j];
                        P.erase(P.begin()+j);
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool join( VS& P ) {
        int n = P.size();
        for ( int i = 0; i < n; ++ i ) {
            char c = *P[i].rbegin();
            for ( int j = 0; j < n; ++ j ) {
                if ( i != j ) {
                    if ( c == *P[j].begin() ) {
                        P[i] += P[j];
                        P.erase(P.begin()+j);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    template<class T> std::set<T> GetSetIntersection( const std::set<T>& a, const std::set<T>& b ) {
        std::set<T> c;
        set_intersection( a.begin(), a.end(), b.begin(), b.end(), inserter( c, c.begin() ) );
        return c;
    }
    
    struct Solution {
        void init() {
        }
        bool is_valid( const VS& P ) {
            return find_if( P.begin(), P.end(), is_invalid ) != P.end();
        }
        string solve(  vector <string> parts  ) {
            VS& P = parts;

            if ( is_valid(P) )
                return NONE;
            while(join_same_end(P));
            while(join(P));
            if ( is_valid(P) )
                return NONE;
            
            int n = P.size();
            for ( int i = 0; i < n; ++ i ) {
                for ( int j = i+1; j < n; ++ j ) {
                    Set si( P[i].begin(), P[i].end() );
                    Set sj( P[j].begin(), P[j].end() );
                    Set common = GetSetIntersection( si, sj );
                    if ( common.size() )
                        return NONE;
                }
            }

            if ( P.size() > 1 )
                return "MANY";
            return P[0];
        }
    };
}

string GroupedWord::restore( vector <string> parts ) {
    return solution::Solution().solve( parts );
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
        void verify_case(const int caseno, const vector <string>&parts, const string& Expected, bool verbose = false) {
            string Received = GroupedWord().restore(parts);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tparts: " << parts<< endl;
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
#define RUN_TEST()	 verify_case(caseno, parts, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string parts_[] = {"aaa", "a", "aa"};
        vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
        string _ = "aaaaaa";
        RUN_TEST();
    }
    CASE(1){
        string parts_[] = {"ab", "bba"};
        vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
        string _ = "IMPOSSIBLE";
        RUN_TEST();
    }
    CASE(2){
        string parts_[] = {"te", "st"};
        vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
        string _ = "stte";
        RUN_TEST();
    }
    CASE(3){
        string parts_[] = {"te", "s", "t"};
        vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
        string _ = "MANY";
        RUN_TEST();
    }
    CASE(4){
        string parts_[] = {"orr", "rd", "woo", "www"};
        vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
        string _ = "wwwwooorrrd";
        RUN_TEST();
    }
    CASE(5){
        string parts_[] = {"abcb"};
        vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
        string _ = "IMPOSSIBLE";
        RUN_TEST();
    }
    CASE(5){
        string parts_[] = {"aba"};
        vector <string> parts(parts_, parts_+sizeof(parts_)/sizeof(*parts_)); 
        string _ = "IMPOSSIBLE";
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

