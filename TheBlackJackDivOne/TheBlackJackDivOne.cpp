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

struct TheBlackJackDivOne { double expected( vector <string> cards ); };

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

    typedef pair <VI, int> State;
    typedef map <State, double> Map;

    Map memo;

    int mapping( string card ) {
        char c = card[0];
        if ( c == 'A' )
            return 11;
        if ( '2' <= c && c <= '9' )
            return c - '0';
        return 10;
    }

    double rec( VI A, int sum ) {
        State s(A, sum);
        if ( memo.count(s) )
            return memo[s];

        if ( sum >= 21 )
            return memo[s] = 0.0;

        double res = 0.0;
        int remains = 0;
        for ( int i = 0; i < 12; ++ i )
            remains += A[i];
        for ( int i = 0; i < 12; ++ i ) {
            if ( A[i] > 0 ) {
                A[i] --;
                res += ( A[i] + 1.0 ) / (double)remains * ( rec(A, sum+i) + 1.0 );
                A[i] ++;
            }
        }

        return memo[s] = res;
    }
    
    struct Solution {
        double solve( vector <string> cards ) {
            memo.clear();

            int sum = 0;
            VI A(12);
            for ( int i = 0; i < 12; ++ i ) {
                if ( i == 11 )
                    A[i] = 4;
                else if ( i >= 2 && i <= 9 )
                    A[i] = 4;
                else if ( i == 10 )
                    A[i] = 16;
                else
                    A[i] = 0;
            }

            for ( VS::iterator it_i = cards.begin(); it_i != cards.end(); ++ it_i ) {
                int k = mapping(*it_i);
                A[k] --;
                sum += k;
            }

            return rec(A, sum);
        }
    };
}

double TheBlackJackDivOne::expected( vector <string> cards ) {
    return solution::Solution().solve(cards);
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
        void verify_case(const int caseno, const vector <string>&cards, const double& Expected, bool verbose = false) {
            double Received = TheBlackJackDivOne().expected(cards);
            cerr << "Test Case #" << caseno << "...";
            double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tcards: " << cards<< endl;
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
#define RUN_TEST()	 verify_case(caseno, cards, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string cards_[] = {"JS"};
        vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
        double _ = 2.105854341736695;
        RUN_TEST();
    }
    CASE(1){
        string cards_[] = {"KD", "8S"};
        vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
        double _ = 1.08;
        RUN_TEST();
    }
    CASE(2){
        string cards_[] = {"KD", "2S", "2C", "2D", "2H"};
        vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
        double _ = 1.0;
        RUN_TEST();
    }
    CASE(3){
        string cards_[] = {"AS", "KS", "9S", "JC", "2D"};
        vector <string> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
        double _ = 0.0;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

