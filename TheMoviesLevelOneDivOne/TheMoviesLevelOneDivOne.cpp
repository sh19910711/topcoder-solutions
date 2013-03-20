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

struct TheMoviesLevelOneDivOne {
    long long find( int n, int m, vector <int> row, vector <int> seat );
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
    typedef set<int> Set;
    typedef map<int, VI> Map;

    class Dec {
    public:
        int operator ()( const int& v ) {
            return v - 1;
        }
    };

    struct Solution {
        long long solve( LL n, LL m, vector <int> row, vector <int> seat  ) {
            VI R = row;
            VI C = seat;
            transform( R.begin(), R.end(), R.begin(), Dec() );
            transform( C.begin(), C.end(), C.begin(), Dec() );
            int num = R.size();
            Set S( R.begin(), R.end() );
            Map T;

            for ( int i = 0; i < num; ++ i ) {
                T[R[i]].push_back(C[i]);
            }
            for ( Set::iterator it_i = S.begin(); it_i != S.end(); ++ it_i ) {
                VI& v = T[*it_i];
                sort( v.begin(), v.end() );
            }

            LL res = ( n - (int)S.size() ) * ( m - 1 );
            for ( Set::iterator it_i = S.begin(); it_i != S.end(); ++ it_i ) {
                VI& v = T[*it_i];
                if ( v.size() > 0 ) {
                    LL f = *v.begin();
                    if ( f >= 2 )
                        res += f - 1;
                }
                if ( v.size() > 0 ) {
                    LL l = *v.rbegin();
                    if ( m - l - 1 >= 2 )
                        res += m - l - 2;
                }
                for ( VI::iterator it_j = v.begin(); it_j + 1 != v.end(); ++ it_j ) {
                    LL a = *it_j;
                    LL b = *(it_j+1);
                    if ( b - a - 1 >= 2 )
                        res += b - a - 2;
                }
            }
            return res;
        }
    };
}

long long TheMoviesLevelOneDivOne::find( int n, int m, vector <int> row, vector <int> seat ) {
    return solution::Solution().solve( n, m, row, seat );
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
void verify_case(const int caseno, const int&n, const int&m, const vector <int>&row, const vector <int>&seat, const long long& Expected, bool verbose = false) {
  long long Received = TheMoviesLevelOneDivOne().find(n, m, row, seat);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tn: " << n<< endl;
  if (verbose) cerr << "\tm: " << m<< endl;
  if (verbose) cerr << "\trow: " << row<< endl;
  if (verbose) cerr << "\tseat: " << seat<< endl;
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
#define RUN_TEST()	 verify_case(caseno, n, m, row, seat, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(100){
        int n = 1;
        int m = 6;
        int row_[] = {1,1};
        vector <int> row(row_, row_+sizeof(row_)/sizeof(*row_)); 
        int seat_[] = {2,5};
        vector <int> seat(seat_, seat_+sizeof(seat_)/sizeof(*seat_)); 
        long long _ = -1LL;
        RUN_TEST();
    }
    CASE(0){
        int n = 2;
        int m = 3;
        int row_[] = {1, 2};
        vector <int> row(row_, row_+sizeof(row_)/sizeof(*row_)); 
        int seat_[] = {2, 3};
        vector <int> seat(seat_, seat_+sizeof(seat_)/sizeof(*seat_)); 
        long long _ = 1LL;
        RUN_TEST();
    }
    CASE(1){
        int n = 2;
        int m = 3;
        int row_[] = {1, 1, 1, 2, 2, 2};
        vector <int> row(row_, row_+sizeof(row_)/sizeof(*row_)); 
        int seat_[] = {1, 2, 3, 1, 2, 3};
        vector <int> seat(seat_, seat_+sizeof(seat_)/sizeof(*seat_)); 
        long long _ = 0LL;
        RUN_TEST();
    }
    CASE(2){
        int n = 4;
        int m = 7;
        int row_[] = {1};
        vector <int> row(row_, row_+sizeof(row_)/sizeof(*row_)); 
        int seat_[] = {1};
        vector <int> seat(seat_, seat_+sizeof(seat_)/sizeof(*seat_)); 
        long long _ = 23LL;
        RUN_TEST();
    }
    CASE(3){
        int n = 10;
        int m = 8;
        int row_[] = {1, 9, 6, 10, 6, 7, 9, 3, 9, 2};
        vector <int> row(row_, row_+sizeof(row_)/sizeof(*row_)); 
        int seat_[] = {7, 7, 3, 3, 7, 1, 5, 1, 6, 2};
        vector <int> seat(seat_, seat_+sizeof(seat_)/sizeof(*seat_)); 
        long long _ = 54LL;
        RUN_TEST();
    }
    notify_memory_usage();

}
// END CUT HERE
// END CUT HERE
