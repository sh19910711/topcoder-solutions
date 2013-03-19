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

struct ArrayHash {
    int getHash( vector <string> input );
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
   
    struct Solution {
        int solve(  vector <string> input  ) {
            int res = 0;
            VS I = input;
            int n = I.size();
            for ( int i = 0; i < n; ++ i ) {
                int len = I[i].size();
                for ( int j = 0; j < len; ++ j ) {
                    res += i + j;
                    res += I[i][j] - 'A';
                }
            }
            return res;
        }
    };
}

int ArrayHash::getHash( vector <string> input ) {
    return solution::Solution().solve( input );
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
void verify_case(const int caseno, const vector <string>&input, const int& Expected, bool verbose = false) {
  int Received = ArrayHash().getHash(input);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tinput: " << input<< endl;
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
#define RUN_TEST()	 verify_case(caseno, input, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        string input_[] = {"CBA",
 "DDD"};
        vector <string> input(input_, input_+sizeof(input_)/sizeof(*input_)); 
        int _ = 21;
        RUN_TEST();
    }
    CASE(1){
        string input_[] = {"Z"};
        vector <string> input(input_, input_+sizeof(input_)/sizeof(*input_)); 
        int _ = 25;
        RUN_TEST();
    }
    CASE(2){
        string input_[] = {"A",
 "B",
 "C",
 "D",
 "E",
 "F"};
        vector <string> input(input_, input_+sizeof(input_)/sizeof(*input_)); 
        int _ = 30;
        RUN_TEST();
    }
    CASE(3){
        string input_[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
;
        vector <string> input(input_, input_+sizeof(input_)/sizeof(*input_)); 
        int _ = 4290;
        RUN_TEST();
    }
    CASE(4){
        string input_[] = {"ZZZZZZZZZZ"};
        vector <string> input(input_, input_+sizeof(input_)/sizeof(*input_)); 
        int _ = 295;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
