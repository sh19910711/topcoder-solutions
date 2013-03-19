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

struct InternetSecurity {
    vector <string> determineWebsite( vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold );
};

// @snippet<sh19910711/contest:set/get_set_intersection.cpp>
namespace set {
    template<class T> std::set<T> GetSetIntersection( const std::set<T>& a, const std::set<T>& b ) {
        std::set<T> c;
        set_intersection( a.begin(), a.end(), b.begin(), b.end(), inserter( c, c.begin() ) );
        return c;
    }
}


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
    typedef std::set<string> Set;
    
    const int SIZE = 51;
    VS A, K, D;
    int n;
    int T;
    bool ok[SIZE];
    Set R[SIZE];
    Set U; // dangerous
    
    struct Solution {
        bool check( Set r ) {
            return (int)::set::GetSetIntersection( r, U ).size() >= T;
        }
        void add_dangerous( Set r ) {
            for ( Set::iterator it_i = r.begin(); it_i != r.end(); ++ it_i ) {
                U.insert(*it_i);
            }
        }
        bool update() {
            for ( int i = 0; i < n; ++ i ) {
                if ( ok[i] && check(R[i]) ) {
                    ok[i] = false;
                    add_dangerous(R[i]);
                    return true;
                }
            }
            return false;
        }
        VS get_dangerous() {
            VS res;
            for ( int i = 0; i < n; ++ i )
                if ( ! ok[i] )
                    res.push_back(A[i]);
            return res;
        }
        Set get_keywords( string s ) {
            Set res;
            string w;
            ISS iss(s);
            while ( iss >> w )
                res.insert(w);
            return res;
        }
        vector <string> solve(  vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold  ) {
            A = address;
            n = A.size();
            K = keyword;
            D = dangerous;
            T = threshold;
            fill( ok, ok+SIZE, true );
            for ( int i = 0; i < n; ++ i )
                R[i] = get_keywords(K[i]);
            U = Set( D.begin(), D.end() );
            while ( update() );
            return get_dangerous();
        }
    };
}

vector <string> InternetSecurity::determineWebsite( vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold ) {
    return solution::Solution().solve( address, keyword, dangerous, threshold );
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
        void verify_case(const int caseno, const vector <string>&address, const vector <string>&keyword, const vector <string>&dangerous, const int&threshold, const vector <string>& Expected, bool verbose = false) {
            vector <string> Received = InternetSecurity().determineWebsite(address, keyword, dangerous, threshold);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\taddress: " << address<< endl;
                if (verbose) cerr << "\tkeyword: " << keyword<< endl;
                if (verbose) cerr << "\tdangerous: " << dangerous<< endl;
                if (verbose) cerr << "\tthreshold: " << threshold<< endl;
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
#define RUN_TEST()	 verify_case(caseno, address, keyword, dangerous, threshold, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string address_[] = {"www.topcoder.com",
            "www.sindicate_of_evil.com",
            "www.happy_citizens.com"};
        vector <string> address(address_, address_+sizeof(address_)/sizeof(*address_)); 
        string keyword_[] = {"hack encryption decryption internet algorithm",
            "signal interference evil snake poison algorithm",
            "flower baloon topcoder blue sky sea"};
        vector <string> keyword(keyword_, keyword_+sizeof(keyword_)/sizeof(*keyword_)); 
        string dangerous_[] = {"hack","encryption","decryption","interference","signal","internet"};
        vector <string> dangerous(dangerous_, dangerous_+sizeof(dangerous_)/sizeof(*dangerous_)); 
        int threshold = 3;
        string __[] = {"www.topcoder.com", "www.sindicate_of_evil.com" };
        vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
        RUN_TEST();
    }
    CASE(1){
        string address_[] = {"brokenlink","flowerpower.net","purchasedomain.com"};
        vector <string> address(address_, address_+sizeof(address_)/sizeof(*address_)); 
        string keyword_[] = {"broken","rose tulips","cheap free domain biggest greatest"};
        vector <string> keyword(keyword_, keyword_+sizeof(keyword_)/sizeof(*keyword_)); 
        string dangerous_[] = {"biggest","enemy","hideout"};
        vector <string> dangerous(dangerous_, dangerous_+sizeof(dangerous_)/sizeof(*dangerous_)); 
        int threshold = 2;
        vector <string> _; 
        RUN_TEST();
    }
    CASE(2){
        string address_[] = {"a..a.ab.","...aa.b"};
        vector <string> address(address_, address_+sizeof(address_)/sizeof(*address_)); 
        string keyword_[] = {"a bc def","def ghij klmno"};
        vector <string> keyword(keyword_, keyword_+sizeof(keyword_)/sizeof(*keyword_)); 
        string dangerous_[] = {"a","b","c","d","e"};
        vector <string> dangerous(dangerous_, dangerous_+sizeof(dangerous_)/sizeof(*dangerous_)); 
        int threshold = 1;
        string __[] = {"a..a.ab.", "...aa.b" };
        vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
        RUN_TEST();
    }
    CASE(3){
        string address_[] = {"www.tsa.gov"};
        vector <string> address(address_, address_+sizeof(address_)/sizeof(*address_)); 
        string keyword_[] = {"information assurance signal intelligence research"};
        vector <string> keyword(keyword_, keyword_+sizeof(keyword_)/sizeof(*keyword_)); 
        string dangerous_[] = {"signal","assurance","penguin"};
        vector <string> dangerous(dangerous_, dangerous_+sizeof(dangerous_)/sizeof(*dangerous_)); 
        int threshold = 2;
        string __[] = {"www.tsa.gov" };
        vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

