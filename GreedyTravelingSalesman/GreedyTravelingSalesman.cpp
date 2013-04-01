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

struct GreedyTravelingSalesman { int worstDistance( vector <string> thousands, vector <string> hundreds, vector <string> tens, vector <string> ones ); };

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
    struct Info {
        VS TH;
        VS HU;
        VS TE;
        VS ON;
    };

    typedef set<int> Set;

    const int SIZE = 51;
    const int INF = std::numeric_limits<int>::max();
    Info I;
    int n;
    int L[SIZE][SIZE];
    int LB[SIZE][SIZE];

    int to_int( const string& s ) {
        ISS iss(s);
        int res;
        iss >> res;
        return res;
    }

    // a -> b
    string get_length( int a, int b ) {
        return string() + I.TH[a][b] + I.HU[a][b] + I.TE[a][b] + I.ON[a][b];
    }

    void parse() {
        for ( int i = 0; i < n; ++ i ) {
            for ( int j = 0; j < n; ++ j ) {
                string s = get_length( i, j );
                int len = to_int(s);
                L[i][j] = len;
            }
        }
    }

    int dfs( int from, int state ) {
        int cand = from;
        int min_len = INF;
        int goal = ( 1 << n ) - 1;
        if ( state == goal )
            return 0;
        for ( int i = 0; i < n; ++ i ) {
            int bi = 1 << i;
            if ( from == i )
                continue;
            if ( state & bi )
                continue;
            if ( L[from][i] < min_len ) {
                cand = i;
                min_len = L[from][i];
            }
        }
        int b_cand = 1 << cand;
        return min_len + dfs( cand, state | b_cand );
    }

    struct Solution {
        int solve( vector <string> thousands, vector <string> hundreds, vector <string> tens, vector <string> ones ) {
            I.TH = thousands;
            I.HU = hundreds;
            I.TE = tens;
            I.ON = ones;
            n  = I.TH.size();
            parse();

            Set S;
            for ( int i = 0; i < n; ++ i ) {
                for ( int j = 0; j < n; ++ j ) {
                    if ( i == j )
                        continue;
                    S.insert(L[i][j]);
                }
            }
            
            int res = 0;
            for ( int i = 0; i < n; ++ i ) {
                for ( int j = 0; j < n; ++ j ) {
                    if ( i == j )
                        continue;
                    int backup = L[i][j];
                    for ( int k = 0; k < n; ++ k ) {
                        if ( i == k || j == k )
                            continue;
                        int len = L[i][k];
                        if ( len - 1 >= 1 ) {
                            L[i][j] = len - 1;
                            res = max( res, dfs( 0, 1 ) );
                        }
                        {
                            L[i][j] = len;
                            res = max( res, dfs( 0, 1 ) );
                        }
                    }
                    L[i][j] = 9999;
                    res = max( res, dfs( 0, 1 ) );
                    L[i][j] = backup;
                }
            }

            return res;
        }
    };
}

int GreedyTravelingSalesman::worstDistance( vector <string> thousands, vector <string> hundreds, vector <string> tens, vector <string> ones ) {
    return solution::Solution().solve(thousands, hundreds, tens, ones);
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
        void verify_case(const int caseno, const vector <string>&thousands, const vector <string>&hundreds, const vector <string>&tens, const vector <string>&ones, const int& Expected, bool verbose = false) {
            int Received = GreedyTravelingSalesman().worstDistance(thousands, hundreds, tens, ones);
            cerr << "Test Case #" << caseno << "...";
            bool ok = (Expected == Received);
            if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
                if (verbose) cerr << "\tthousands: " << thousands<< endl;
                if (verbose) cerr << "\thundreds: " << hundreds<< endl;
                if (verbose) cerr << "\ttens: " << tens<< endl;
                if (verbose) cerr << "\tones: " << ones<< endl;
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
#define RUN_TEST()	 verify_case(caseno, thousands, hundreds, tens, ones, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);
    
    CASE(0){
        string thousands_[] = {"055", "505", "550"};
        vector <string> thousands(thousands_, thousands_+sizeof(thousands_)/sizeof(*thousands_)); 
        string hundreds_[] = {"000", "000", "000"};
        vector <string> hundreds(hundreds_, hundreds_+sizeof(hundreds_)/sizeof(*hundreds_)); 
        string tens_[] = {"000", "000", "000"};
        vector <string> tens(tens_, tens_+sizeof(tens_)/sizeof(*tens_)); 
        string ones_[] = {"000", "000", "000"};
        vector <string> ones(ones_, ones_+sizeof(ones_)/sizeof(*ones_)); 
        int _ = 14999;
        RUN_TEST();
    }
    CASE(1){
        string thousands_[] = {"018", "101", "990"};
        vector <string> thousands(thousands_, thousands_+sizeof(thousands_)/sizeof(*thousands_)); 
        string hundreds_[] = {"000", "000", "990"};
        vector <string> hundreds(hundreds_, hundreds_+sizeof(hundreds_)/sizeof(*hundreds_)); 
        string tens_[] = {"000", "000", "990"};
        vector <string> tens(tens_, tens_+sizeof(tens_)/sizeof(*tens_)); 
        string ones_[] = {"000", "000", "990"};
        vector <string> ones(ones_, ones_+sizeof(ones_)/sizeof(*ones_)); 
        int _ = 17999;
        RUN_TEST();
    }
    CASE(2){
        string thousands_[] = {"00888", "00999", "00099", "00009", "00000"}
        ;
        vector <string> thousands(thousands_, thousands_+sizeof(thousands_)/sizeof(*thousands_)); 
        string hundreds_[] = {"00000", "00999", "00099", "00009", "00000"}
        ;
        vector <string> hundreds(hundreds_, hundreds_+sizeof(hundreds_)/sizeof(*hundreds_)); 
        string tens_[] = {"00000", "10999", "11099", "11109", "11110"}
        ;
        vector <string> tens(tens_, tens_+sizeof(tens_)/sizeof(*tens_)); 
        string ones_[] = {"01000", "00999", "00099", "00009", "00000"}
        ;
        vector <string> ones(ones_, ones_+sizeof(ones_)/sizeof(*ones_)); 
        int _ = 37997;
        RUN_TEST();
    }
    CASE(3){
        string thousands_[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
        vector <string> thousands(thousands_, thousands_+sizeof(thousands_)/sizeof(*thousands_)); 
        string hundreds_[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
        vector <string> hundreds(hundreds_, hundreds_+sizeof(hundreds_)/sizeof(*hundreds_)); 
        string tens_[] = {"000000", "000000", "990999", "999099", "999909", "999990"};
        vector <string> tens(tens_, tens_+sizeof(tens_)/sizeof(*tens_)); 
        string ones_[] = {"011111", "101111", "990998", "999099", "999809", "999980"};
        vector <string> ones(ones_, ones_+sizeof(ones_)/sizeof(*ones_)); 
        int _ = 39994;
        RUN_TEST();
    }
    CASE(4){
        string thousands_[] = {"00", "00"};
        vector <string> thousands(thousands_, thousands_+sizeof(thousands_)/sizeof(*thousands_)); 
        string hundreds_[] = {"00", "00"};
        vector <string> hundreds(hundreds_, hundreds_+sizeof(hundreds_)/sizeof(*hundreds_)); 
        string tens_[] = {"00", "00"};
        vector <string> tens(tens_, tens_+sizeof(tens_)/sizeof(*tens_)); 
        string ones_[] = {"01", "10"};
        vector <string> ones(ones_, ones_+sizeof(ones_)/sizeof(*ones_)); 
        int _ = 9999;
        RUN_TEST();
    }
    CASE(5){
        string thousands_[] = {"0930", "1064", "0104", "1070"};
        vector <string> thousands(thousands_, thousands_+sizeof(thousands_)/sizeof(*thousands_)); 
        string hundreds_[] = {"0523", "1062", "6305", "0810"};
        vector <string> hundreds(hundreds_, hundreds_+sizeof(hundreds_)/sizeof(*hundreds_)); 
        string tens_[] = {"0913", "0087", "3109", "1500"};
        vector <string> tens(tens_, tens_+sizeof(tens_)/sizeof(*tens_)); 
        string ones_[] = {"0988", "2030", "6103", "5530"};
        vector <string> ones(ones_, ones_+sizeof(ones_)/sizeof(*ones_)); 
        int _ = 14124;
        RUN_TEST();
    }
    CASE(6){
        string thousands_[] = {"0329", "2036", "2502", "8970"};
        vector <string> thousands(thousands_, thousands_+sizeof(thousands_)/sizeof(*thousands_)); 
        string hundreds_[] = {"0860", "5007", "0404", "2770"};
        vector <string> hundreds(hundreds_, hundreds_+sizeof(hundreds_)/sizeof(*hundreds_)); 
        string tens_[] = {"0111", "2087", "2009", "2670"};
        vector <string> tens(tens_, tens_+sizeof(tens_)/sizeof(*tens_)); 
        string ones_[] = {"0644", "1094", "7703", "7550"};
        vector <string> ones(ones_, ones_+sizeof(ones_)/sizeof(*ones_)); 
        int _ = 17785;
        RUN_TEST();
    }
    CASE(7){
        string thousands_[] = {"098444156277392825243100607342", "200097656837707947798866622385",
            "290231695687128834848596019656", "407026565077650435591867333275",
            "843401002617957470339040852874", "349970591997218853400632158696",
            "419933000593511123878416328483", "696294503254214847884399055978",
            "641473980706392541888675375279", "936720077098054565078142449625",
            "203476089500970673371115103717", "511071853860312304204656816567",
            "347105714685052402147763392257", "125122220860203856679947732062",
            "121462979669220132944063071653", "928254504048223043681383050365",
            "502607124708785202536036594373", "793596587517012870906900400361",
            "712360060935346182084840996318", "761671392040312345002273366240",
            "812935320276738878200716148806", "228506917464479046839069740872",
            "755395721473881083093906155745", "192597782177910118061710039501",
            "721382839206745793530453013267", "076061794267810491768114700256",
            "857528357758085424372388710251", "173322450800442594145600093043",
            "761667192345925280210514410800", "521229810525064090301842864060"};
        vector <string> thousands(thousands_, thousands_+sizeof(thousands_)/sizeof(*thousands_)); 
        string hundreds_[] = {"098270581534726237580246464451", "108829763716747148395013332067",
            "830061279541380758964430491222", "431005058477371114834129826284",
            "601807314489142917339949914290", "330640126699733151822328009407",
            "851821069798846354566780680271", "648888407535627630663351884365",
            "051398660825518466890170447894", "631934884097214069747147155777",
            "768071219404930950472885304916", "924954163330715847561718395488",
            "189910033179029204426829479070", "960645776060701332402794474433",
            "244875842263950931884758650019", "528470075229660077692189442311",
            "752198673046476808978058423064", "899325998610605600525587569431",
            "965750123741820904031880230236", "121658852172052167706008445728",
            "556199378085507717770434101126", "864838242791403197110088834005",
            "593435343245223500439707230479", "622529771475840345624500421425",
            "503486612623475041392122088159", "518334626169655694269507400008",
            "967091631529233593414345370288", "300474162107271438029222620086",
            "010527691044447729596127150108", "742822904991333205419603623270"};
        vector <string> hundreds(hundreds_, hundreds_+sizeof(hundreds_)/sizeof(*hundreds_)); 
        string tens_[] = {"029421809872798033258029765788", "705135039569772524273274786652",
            "170567418260893393020344098265", "401043354947659563658581268242",
            "746709065616595245635350557925", "739570024549618413776557843034",
            "184597012262496958610853505745", "689811400727818703807051112784", 
            "894453010121164288965541305235", "323145029073008946088869964941", 
            "834269564400729646453274750586", "538976762970745472202055589093", 
            "765511399939087047106252621388", "906733295711605356366138410423", 
            "107653940551700559321642810836", "428402693021051075533830345295", 
            "386782660475155103347385287948", "936626025836194580089064628716", 
            "718522629491464055045890912121", "370656945845300237607868352243", 
            "951908186614186444840337711498", "535178875249889835014025850038", 
            "505970047705717604298603983975", "484398304612602344941130624527", 
            "048342694079170795987835013947", "860331019262176299872846206272", 
            "549663926438975145562538360932", "329735455392841851511474791078", 
            "711755200061373546828858448100", "778808866574640894148527759780"};
        vector <string> tens(tens_, tens_+sizeof(tens_)/sizeof(*tens_)); 
        string ones_[] = {"050738147930236727719964251439", "804492562859282318664226330103", 
            "610197568193830684654773608216", "279000416545607314567843085541", 
            "782201171759873927350740022455", "043370803444176631019883186675", 
            "566092086050401228622782761449", "469598907881602996036692882305", 
            "116923500417992303845370254124", "796876115092839169954790509461", 
            "783836410405270687557924090071", "095144151150833738671751747749", 
            "354474585664039135189964700948", "328968176148004939648962631420", 
            "829651915384290848347221555092", "170980383407813034573738951375", 
            "728655435703349509419725538350", "121896684176286430427852435647", 
            "315710894574884960021671476788", "592177839598531202003634382961", 
            "876587919610157913350259498196", "505517243779897451333006271744", 
            "618607877753891664471800511372", "826358757330233811836040764274", 
            "206641252044293046424432092833", "704519364781672964993499009545", 
            "624793571592392775564426440338", "571938479010503551295729304078", 
            "077967252884369103891335711508", "870185204806328841827105139840"};
        vector <string> ones(ones_, ones_+sizeof(ones_)/sizeof(*ones_)); 
        int _ = 39896;
        RUN_TEST();
    }
    notify_memory_usage();
    
}
// END CUT HERE
// END CUT HERE

