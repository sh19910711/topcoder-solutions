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

struct Badgers { int feedMost( vector <int> hunger, vector <int> greed, int totalFood ); };

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
    
    VI H, G;
    int n;
    int T;
    
    bool check( int k ) {
        VI L(n);
        for ( int i = 0; i < n; ++ i ) {
            L[i] = H[i] + ( k - 1 ) * G[i];
        }
        sort(L.begin(), L.end());
        int sum = accumulate(L.begin(), L.begin() + k, 0);
        return sum <= T;
    }
    
    struct Solution {
        int solve( vector <int> hunger, vector <int> greed, int totalFood ) {
            H = hunger, G = greed;
            n = H.size();
            T = totalFood;
            for ( int i = n; i > 0; -- i ) {
                if ( check(i) )
                    return i;
            }
            return 0;
        }
    };
}

int Badgers::feedMost( vector <int> hunger, vector <int> greed, int totalFood ) {
    return solution::Solution().solve(hunger, greed, totalFood);
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
        void verify_case(const int caseno, const vector <int>&hunger, const vector <int>&greed, const int&totalFood, const int& Expected, bool verbose = false) {
            int Received = Badgers().feedMost(hunger, greed, totalFood);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\thunger: " << hunger<< endl;
                if (verbose) cerr << "\tgreed: " << greed<< endl;
                if (verbose) cerr << "\ttotalFood: " << totalFood<< endl;
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
#define RUN_TEST()	 verify_case(caseno, hunger, greed, totalFood, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        int hunger_[] = {1,2,3};
        vector <int> hunger(hunger_, hunger_+sizeof(hunger_)/sizeof(*hunger_)); 
        int greed_[] = {2,2,1};
        vector <int> greed(greed_, greed_+sizeof(greed_)/sizeof(*greed_)); 
        int totalFood = 7;
        int _ = 2;
        RUN_TEST();
    }
    CASE(1){
        int hunger_[] = {5,2,1,5};
        vector <int> hunger(hunger_, hunger_+sizeof(hunger_)/sizeof(*hunger_)); 
        int greed_[] = {0,2,4,1};
        vector <int> greed(greed_, greed_+sizeof(greed_)/sizeof(*greed_)); 
        int totalFood = 19;
        int _ = 3;
        RUN_TEST();
    }
    CASE(2){
        int hunger_[] = {1,1,1,1,1};
        vector <int> hunger(hunger_, hunger_+sizeof(hunger_)/sizeof(*hunger_)); 
        int greed_[] = {1000,1000,1000,1000,1000};
        vector <int> greed(greed_, greed_+sizeof(greed_)/sizeof(*greed_)); 
        int totalFood = 10;
        int _ = 1;
        RUN_TEST();
    }
    CASE(3){
        int hunger_[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> hunger(hunger_, hunger_+sizeof(hunger_)/sizeof(*hunger_)); 
        int greed_[] = {10,9,8,7,6,5,4,3,2,1};
        vector <int> greed(greed_, greed_+sizeof(greed_)/sizeof(*greed_)); 
        int totalFood = 100;
        int _ = 5;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

