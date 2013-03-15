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

struct MagicWords {
    int count( vector <string> S, int K );
};

// @snippet<sh19910711/contest:table/trie.cpp>
namespace table {
    // @desc トライ木の実装
    template <class ValueType> class Trie {
    public:
        typedef std::string::const_iterator StringIterator;
        static const int SIZE = 256;
        ValueType value;
        Trie *next[SIZE];
        Trie() { clear(); }
        void clear() { std::fill( next, next+SIZE, (Trie*)NULL ); }
        Trie& find( const std::string& s ) {
            Trie* res = this;
            for ( StringIterator it_i = s.begin(); it_i != s.end(); ++ it_i ) {
                const int& c = *it_i;
                if ( ! res->next[c] ) res->next[c] = new Trie;
                res = res->next[c];
            }
            return *res;
        }
        Trie* find_ptr( const std::string& s ) {
            Trie* res = this;
            for ( StringIterator it_i = s.begin(); it_i != s.end(); ++ it_i ) {
                const int& c = *it_i;
                if ( ! res->next[c] ) res->next[c] = new Trie;
                res = res->next[c];
            }
            return res;
        }

        int count( const std::string& s ) {
            Trie* res = this;
            for ( StringIterator it_i = s.begin(); it_i != s.end(); ++ it_i ) {
                const int& c = *it_i;
                if ( ! res->next[c] ) return 0;
                res = res->next[c];
            }
            return 1;
        }
        ValueType& operator []( const std::string& s ) { return find(s).value; }
    };
}


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

    map<string, bool> T;
    
    struct Solution {
        string rotate( const string& s, int k ) {
            return s.substr(k) + s.substr(0,k);
        }
        
        bool check( const string& s, int k ) {
            if ( T.count(s) )
                return T[s];
            int n = s.size();
            int cnt = 0;
            for ( int i = 0; i < n; ++ i ) {
                string t = rotate( s, i );
                if ( s == t ) cnt ++;
            }
            return T[s] = ( cnt == k );
        }
        
        int solve(  vector <string> S, int K  ) {
            T.clear();

            int n = S.size();
            for ( int i = 0; i < n; ++ i ) {
                int m = S[i].size();
                for ( int j = 0; j < m; ++ j ) {
                }
            }

            VI P(n);
            for ( int i = 0; i < n; ++ i )
                P[i] = i;

            int res = 0;
            do {
                string s;
                for ( int i = 0; i < n; ++ i )
                    s += S[P[i]];
                if ( check(s, K) )
                    res ++;
            } while ( next_permutation( P.begin(), P.end() ) );

            return res;
        }
    };
}

int MagicWords::count( vector <string> S, int K ) {
    return solution::Solution().solve( S, K );
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
        void verify_case(const int caseno, const vector <string>&S, const int&K, const int& Expected, bool verbose = false) {
            int Received = MagicWords().count(S, K);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tS: " << S<< endl;
                if (verbose) cerr << "\tK: " << K<< endl;
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
#define RUN_TEST()	 verify_case(caseno, S, K, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string S_[] = {"CAD","ABRA","ABRA"};
        vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
        int K = 1;
        int _ = 6;
        RUN_TEST();
    }
    CASE(1){
        string S_[] = {"AB","RAAB","RA"};
        vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
        int K = 2;
        int _ = 3;
        RUN_TEST();
    }
    CASE(2){
        string S_[] = {"AA","AA","AAA","A"};
        vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
        int K = 1;
        int _ = 0;
        RUN_TEST();
    }
    CASE(3){
        string S_[] = {"AA","AA","AAA","A","AAA","AAAA"};
        vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
        int K = 15;
        int _ = 720;
        RUN_TEST();
    }
    CASE(4){
        string S_[] = {"ABC","AB","ABC","CA"};
        vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
        int K = 3;
        int _ = 0;
        RUN_TEST();
    }
    CASE(5){
        string S_[] = {"A","B","C","A","B","C"};
        vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
        int K = 1;
        int _ = 672;
        RUN_TEST();
    }
    CASE(6){if(false) {
        string S_[] = {"AAAAAAAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAAAAAAA",
            "AAAAAAAAAAAAAAAAAAAB"};
        vector <string> S(S_, S_+sizeof(S_)/sizeof(*S_)); 
        int K = 1;
        int _ = 40320;
        RUN_TEST();
    }}
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

