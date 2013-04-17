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

struct DateFormat { string fromEuropeanToUs( vector <string> dateList ); };

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

    typedef set<string> Set;
    const int day_of_month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    VS split( string s ) {
        VS res;
        ISS iss(s);
        string word;
        while ( iss >> word )
            res.push_back(word);
        return res;
    }

    bool is_valid( string s ) {
        replace(s.begin(), s.end(), '/', ' ');
        ISS iss(s);
        int mm, dd;
        iss >> mm >> dd;
        if ( mm < 1 || mm > 12 )
            return false;
        return dd >= 1 && dd <= day_of_month[mm];
    }

    string rotate( string s ) {
        replace(s.begin(), s.end(), '/', ' ');
        ISS iss(s);
        int hh, mm;
        iss >> hh >> mm;
        OSS oss;
        oss << setw(2) << setfill('0') << mm << "/" << setw(2) << setfill('0') << hh;
        return oss.str();
    }
    
    VS calc( VS s ) {
        Set S;
        for ( VS::iterator it_i = s.begin(); it_i != s.end(); ++ it_i ) {
            string a = *it_i;
            string b = rotate(a);
            cout << a << ", " << b << endl;
            if ( ! is_valid(a) ) {
                if ( is_valid(b) ) {
                    S.insert(b);
                }
            } else if ( ! is_valid(b) ) {
                if ( is_valid(a) ) {
                    S.insert(a);
                }
            } else {
                if ( S.count(a) )
                    S.insert(b);
                else if ( S.count(b) )
                    S.insert(a);
                else
                    S.insert(min(a, b));
            }
        }
        if ( S.size() != s.size() )
            return VS();
        VS res(S.begin(), S.end());
        return res;
    }

    string convert( VS list ) {
        OSS oss;
        for ( VS::iterator it_i = list.begin(); it_i != list.end(); ++ it_i ) {
            oss << *it_i;
            if ( it_i + 1 != list.end() )
                oss << " ";
        }
        return oss.str();
    }

    struct Solution {
        string solve( vector <string> dateList ) {
            string s = accumulate(dateList.begin(), dateList.end(), string(""));
            return convert(calc(split(s)));
        }
    };
}

string DateFormat::fromEuropeanToUs( vector <string> dateList ) {
    return solution::Solution().solve(dateList);
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
        void verify_case(const int caseno, const vector <string>&dateList, const string& Expected, bool verbose = false) {
            string Received = DateFormat().fromEuropeanToUs(dateList);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tdateList: " << dateList<< endl;
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
#define RUN_TEST()	 verify_case(caseno, dateList, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string dateList_[] = {"16/01"};
        vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
        string _ = "01/16";
        RUN_TEST();
    }
    CASE(1){
        string dateList_[] = {"02/01 08/02 08/02 21/09 06/11"};
        vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
        string _ = "01/02 02/08 08/02 09/21 11/06";
        RUN_TEST();
    }
    CASE(2){
        string dateList_[] = {"08/02 08/02 03/04"};
        vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
        string _ = "";
        RUN_TEST();
    }
    CASE(3){
        string dateList_[] = {"2", "9/02", " 08/", "03 01/08"};
        vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
        string _ = "02/29 03/08 08/01";
        RUN_TEST();
    }
    CASE(4){
        string dateList_[] = {"17/01 05/05 03/07 07/24 23/09 09/30 01/11 11/11"};
        vector <string> dateList(dateList_, dateList_+sizeof(dateList_)/sizeof(*dateList_)); 
        string _ = "01/17 05/05 07/03 07/24 09/23 09/30 11/01 11/11";
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

