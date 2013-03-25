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

struct SequenceOfCommands {
    string whatHappens( vector <string> commands );
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

    typedef pair <II, II> IIII;
    set <IIII> V;
    const string YES = "bounded";
    const string NO = "unbounded";

    int k;

    struct Solution {
        bool judge( const string& s ) {
            int n = s.size();
            int r = 0;
            int c = 0;
            int d = 0;
            V.insert( IIII( II( 0, d ), II( r, c ) ) );
            const int dr[4] = { 1, 0, -1, 0 };
            const int dc[4] = { 0, 1, 0, -1 };
            for ( int i = 0; i < n; ++ i ) {
                if ( s[i] == 'S' ) {
                    r += dr[d];
                    c += dc[d];
                } else if ( s[i] == 'R' ) {
                    d = ( d + 1 ) % 4;
                } else if ( s[i] == 'L' ) {
                    d = ( d - 1 + 4 ) % 4;
                }
            }
            return r == 0 && c == 0;
        }
        string solve( vector <string> commands ) {
            string s = accumulate( commands.begin(), commands.end(), string("") );
            k = s.size();
            s = s + s + s + s;
            V.clear();
            return judge(s) ? YES : NO;
        }
    };
}

string SequenceOfCommands::whatHappens( vector <string> commands ) {
    return solution::Solution().solve( commands );
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
void verify_case(const int caseno, const vector <string>&commands, const string& Expected, bool verbose = false) {
  string Received = SequenceOfCommands().whatHappens(commands);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tcommands: " << commands<< endl;
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
#define RUN_TEST()	 verify_case(caseno, commands, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        string commands_[] = {"L"};
        vector <string> commands(commands_, commands_+sizeof(commands_)/sizeof(*commands_)); 
        string _ = "bounded";
        RUN_TEST();
    }
    CASE(1){
        string commands_[] = {"SRSL"};
        vector <string> commands(commands_, commands_+sizeof(commands_)/sizeof(*commands_)); 
        string _ = "unbounded";
        RUN_TEST();
    }
    CASE(2){
        string commands_[] = {"SSSS","R"};
        vector <string> commands(commands_, commands_+sizeof(commands_)/sizeof(*commands_)); 
        string _ = "bounded";
        RUN_TEST();
    }
    CASE(3){
        string commands_[] = {"SRSL","LLSSSSSSL","SSSSSS","L"};
        vector <string> commands(commands_, commands_+sizeof(commands_)/sizeof(*commands_)); 
        string _ = "unbounded";
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
