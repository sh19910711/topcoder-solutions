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

struct OrderedNim {
    string winner( vector <int> layout );
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

    const string YES = "Alice";
    const string NO = "Bob";
   
    VI L;
    int n;

    struct Solution {
        bool solve() {
            bool res = true;
            for ( int i = 0; i < n; ++ i ) {
                if ( L[i] == 1 ) {
                    if ( i == n - 1 )
                        return res;
                    res = !res;
                } else {
                    return res;
                }
            }
            return res;
        }
        string solve(  vector <int> layout  ) {
            L = layout;
            n = L.size();
            return solve() ? YES : NO;
        }
    };
}

string OrderedNim::winner( vector <int> layout ) {
    return solution::Solution().solve( layout );
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
void verify_case(const int caseno, const vector <int>&layout, const string& Expected, bool verbose = false) {
  string Received = OrderedNim().winner(layout);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tlayout: " << layout<< endl;
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
#define RUN_TEST()	 verify_case(caseno, layout, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        int layout_[] = {5};
        vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
        string _ = "Alice";
        RUN_TEST();
    }
    CASE(1){
        int layout_[] = {1,2};
        vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
        string _ = "Bob";
        RUN_TEST();
    }
    CASE(2){
        int layout_[] = {2,1};
        vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
        string _ = "Alice";
        RUN_TEST();
    }
    CASE(3){
        int layout_[] = {10,9,8,7,6,5,4,3,2,1};
        vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
        string _ = "Alice";
        RUN_TEST();
    }
    CASE(4){
        int layout_[] = {1,1,1,1};
        vector <int> layout(layout_, layout_+sizeof(layout_)/sizeof(*layout_)); 
        string _ = "Bob";
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
