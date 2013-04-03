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

struct BadVocabulary { int count( string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary ); };

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
    string pre, suf, sub;
    
    bool check_pre( string s ) {
        return pre == s.substr(0, pre.size());
    }

    bool check_suf( string s ) {
        reverse( s.begin(), s.end() );
        return suf == s.substr(0, suf.size());
    }

    bool check_sub( string s ) {
        int n = s.size();
        return s.substr(1, max(0, n-2)).find(sub) != string::npos;
    }

    bool check( string s ) {
        if ( check_pre(s) )
            return true;
        else if ( check_suf(s) )
            return true;
        else if ( check_sub(s) )
            return true;
        return false;
    }
    
    struct Solution {
        int solve( string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary ) {
            pre = badPrefix;
            suf = badSuffix;
            reverse(suf.begin(), suf.end());
            sub = badSubstring;
            VS A = vocabulary;
            return count_if(A.begin(), A.end(), check);
        }
    };
}

int BadVocabulary::count( string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary ) {
    return solution::Solution().solve(badPrefix, badSuffix, badSubstring, vocabulary);
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
        void verify_case(const int caseno, const string&badPrefix, const string&badSuffix, const string&badSubstring, const vector <string>&vocabulary, const int& Expected, bool verbose = false) {
            int Received = BadVocabulary().count(badPrefix, badSuffix, badSubstring, vocabulary);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tbadPrefix: " << badPrefix<< endl;
                if (verbose) cerr << "\tbadSuffix: " << badSuffix<< endl;
                if (verbose) cerr << "\tbadSubstring: " << badSubstring<< endl;
                if (verbose) cerr << "\tvocabulary: " << vocabulary<< endl;
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
#define RUN_TEST()	 verify_case(caseno, badPrefix, badSuffix, badSubstring, vocabulary, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string badPrefix = "bug";
        string badSuffix = "bug";
        string badSubstring = "bug";
        string vocabulary_[] = {"buggy", "debugger", "debug"};
        vector <string> vocabulary(vocabulary_, vocabulary_+sizeof(vocabulary_)/sizeof(*vocabulary_)); 
        int _ = 3;
        RUN_TEST();
    }
    CASE(1){
        string badPrefix = "a";
        string badSuffix = "b";
        string badSubstring = "c";
        string vocabulary_[] = {"a", "b", "tco"};
        vector <string> vocabulary(vocabulary_, vocabulary_+sizeof(vocabulary_)/sizeof(*vocabulary_)); 
        int _ = 3;
        RUN_TEST();
    }
    CASE(2){
        string badPrefix = "cut";
        string badSuffix = "sore";
        string badSubstring = "scar";
        string vocabulary_[] = {"scary", "oscar"};
        vector <string> vocabulary(vocabulary_, vocabulary_+sizeof(vocabulary_)/sizeof(*vocabulary_)); 
        int _ = 0;
        RUN_TEST();
    }
    CASE(3){
        string badPrefix = "bar";
        string badSuffix = "else";
        string badSubstring = "foo";
        string vocabulary_[] = {"foofoofoo", "foobar", "elsewhere"};
        vector <string> vocabulary(vocabulary_, vocabulary_+sizeof(vocabulary_)/sizeof(*vocabulary_)); 
        int _ = 1;
        RUN_TEST();
    }
    CASE(4){
        string badPrefix = "pre";
        string badSuffix = "s";
        string badSubstring = "all";
        string vocabulary_[] = {"all", "coders", "be", "prepared", "for", "the", "challenge", "phase"};
        vector <string> vocabulary(vocabulary_, vocabulary_+sizeof(vocabulary_)/sizeof(*vocabulary_)); 
        int _ = 3;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

