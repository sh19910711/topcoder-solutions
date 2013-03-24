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

struct UnluckyIntervals {
    vector <int> getLuckiest( vector <int> luckySet, int n );
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
    typedef vector<II> VII;

    typedef pair <LL, int> LI;
    typedef vector<LI> VLI;

    const LL INF = 1000000000000000011LL;
    VI S;
    int n;
   
    struct Solution {
        vector <int> solve(  vector <int> luckySet, int n  ) {
            S = luckySet;
            S.push_back(0);
            std::sort( S.begin(), S.end() );

            set<int> SC;
            for ( VI::iterator it_i = S.begin(); it_i != S.end(); ++ it_i ) {
                for ( int i = -105; i <= 105; ++ i ) {
                    int k = *it_i + i;
                    if ( k <= 0 )
                        continue;
                    SC.insert(k);
                }
            }
            VI C = VI( SC.begin(), SC.end() );

            VLI res;
            int last = *C.rbegin();
            for ( VI::iterator it_i = C.begin(); it_i != C.end(); ++ it_i ) {
                int k = *it_i;
                if ( k > last ) {
                    res.push_back( LI( INF, k ) );
                    continue;
                }

                for ( VI::iterator it_j = S.begin(); it_j != S.end(); ++ it_j ) {
                    LL good1 = *it_j;
                    if ( k <= good1 ) {
                        if ( good1 == k ) {
                            res.push_back( LI( 0, k ) );
                        } else {
                            LL good2 = *(it_j-1);
                            res.push_back( LI( ( good1 - k ) * ( k - good2 ) - 1, k ) );
                        }
                        goto out_of_loop_1;
                    }
                }
                res.push_back( LI( INF, k ) );
out_of_loop_1:;
            }

            sort( res.begin(), res.end() );
            VI tmp(n);
            for ( int i = 0; i < n; ++ i )
                tmp[i] = res[i].second;
            return tmp;
        }
    };
}

vector <int> UnluckyIntervals::getLuckiest( vector <int> luckySet, int n ) {
    return solution::Solution().solve( luckySet, n );
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
void verify_case(const int caseno, const vector <int>&luckySet, const int&n, const vector <int>& Expected, bool verbose = false) {
  vector <int> Received = UnluckyIntervals().getLuckiest(luckySet, n);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tluckySet: " << luckySet<< endl;
  if (verbose) cerr << "\tn: " << n<< endl;
  cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
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
#define RUN_TEST()	 verify_case(caseno, luckySet, n, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        int luckySet_[] = {3};
        vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
        int n = 6;
        int __[] = {3, 1, 2, 4, 5, 6 };
        vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
        RUN_TEST();
    }
    CASE(1){
        int luckySet_[] = {5, 11, 18};
        vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
        int n = 9;
        int __[] = {5, 11, 18, 1, 4, 6, 10, 2, 3 };
        vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
        RUN_TEST();
    }
    CASE(2){
        int luckySet_[] = {7, 13, 18};
        vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
        int n = 9;
        int __[] = {7, 13, 18, 14, 17, 8, 12, 1, 6 };
        vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
        RUN_TEST();
    }
    CASE(3){
        int luckySet_[] = {1000, 1004, 4000, 4003, 5000};
        vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
        int n = 19;
        int __[] = {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 };
        vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
        RUN_TEST();
    }
    CASE(4){
        int luckySet_[] = {1000000000};
        vector <int> luckySet(luckySet_, luckySet_+sizeof(luckySet_)/sizeof(*luckySet_)); 
        int n = 8;
        int __[] = {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 };
        vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
