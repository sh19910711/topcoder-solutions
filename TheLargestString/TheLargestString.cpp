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

struct TheLargestString { string find( string s, string t ); };

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
    string s, t;
    int n;
    bool used[SIZE];
    
    void f( int start ) {
        if ( start >= n ) {
            return;
        }
        
        int cand = start;
        for ( int i = start; i < n; ++ i ) {
            if ( s[i] > s[cand] ) {
                cand = i;
            }
        }
        
        fill( used+start, used+cand, false );
        f(cand+1);
    }
    
    int g( int start ) {
        if ( start >= n ) {
            return n;
        }
        
        int cand = start;
        for ( int i = start; i < n; ++ i ) {
            if ( ! used[i] )
                continue;
            if ( t[i] > t[cand] ) {
                cand = i;
            }
        }
        
        fill( used+start, used+cand, false );
        return cand+1;
    }
    
    struct Solution {
        void init() {
            fill( used, used+SIZE, true );
        }

        string solve( string s__, string t__ ) {
            init();
            s = s__;
            t = t__;
            n = s.size();
            
            f(0);
            int beg = 0;
            while ( beg < n && used[beg] )
                beg ++;

            string res;
            
            for ( int i = 0; i < n; ++ i ) {
                res = max( res, string() + s[i] + t[i] );
            }
            
            for ( int k = 0; k < n; ) {
                while ( k < n && ! used[k] )
                    k ++;
                string tmp;
                for ( int i = 0; i < n; ++ i )
                    if ( used[i] )
                        tmp += s[i];
                for ( int i = 0; i < n; ++ i )
                    if ( used[i] )
                        tmp += t[i];
                res = max( res, tmp );
                k = g(k);
            }
            return res;
        }
    };
}

string TheLargestString::find( string s, string t ) {
    return solution::Solution().solve(s, t);
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
        void verify_case(const int caseno, const string&s, const string&t, const string& Expected, bool verbose = false) {
            string Received = TheLargestString().find(s, t);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\ts: " << s<< endl;
                if (verbose) cerr << "\tt: " << t<< endl;
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
#define RUN_TEST()	 verify_case(caseno, s, t, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string s = "ab";
        string t = "zy";
        string _ = "by";
        RUN_TEST();
    }
    CASE(1){
        string s = "abacaba";
        string t = "zzzaaaa";
        string _ = "cbaaaa";
        RUN_TEST();
    }
    CASE(2){
        string s = "x";
        string t = "x";
        string _ = "xx";
        RUN_TEST();
    }
    CASE(3){
        string s = "abbabbabbababaaaabbababab";
        string t = "bababbaabbbababbbbababaab";
        string _ = "bbbbbbbbbbbbbbbbbbaaab";
        RUN_TEST();
    }
    CASE(4) {
        string s = "a";
        string t = "z";
        string _ = "az";
        RUN_TEST();
    }
    CASE(5) { // コーナーケース1つめ。aの辞書順最大でしか見ていないときはこれで落とせるはず
        string s = "aa";
        string t = "zz";
        string _ = "az";
        RUN_TEST();
    }
    CASE(6) {
        string s = "zz";
        string t = "aa";
        string _ = "zzaa";
        RUN_TEST();
    }
    CASE(7) {
        string s = "za";
        string t = "az";
        string _ = "zaaz";
        RUN_TEST();
    }
    CASE(8) {
        string s = "aaz";
        string t = "zzz";
        string _ = "zz";
        RUN_TEST();
    }
    CASE(9) {
        string s = "aaaaa";
        string t = "aaaaa";
        string _ = "aaaaaaaaaa";
        RUN_TEST();
    }
    CASE(10) {
        string s = "zzzzz";
        string t = "zzzza";
        string _ = "zzzzzzzzza";
        RUN_TEST();
    }
    CASE(11) {
        string s = "zzzzz";
        string t = "azzzz";
        string _ = "zzzzzzzz";
        RUN_TEST();
    }
    CASE(12) {
        string s = "zzzzz";
        string t = "zazzz";
        string _ = "zzzzzzzz";
        RUN_TEST();
    }
    CASE(13) {
        string s = "zzzzz";
        string t = "zazzz";
        string _ = "zzzzzzzz";
        RUN_TEST();
    }
    CASE(14) {
        string s = "zzzaaa";
        string t = "aaazzz";
        string _ = "zzzaaaaaazzz";
        RUN_TEST();
    }
    CASE(15) {
        string s = "aba";
        string t = "bab";
        string _ = "baab";
        RUN_TEST();
    }


    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE


