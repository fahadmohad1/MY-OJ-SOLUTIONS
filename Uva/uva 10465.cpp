#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;


template <typename T>using ordered_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;

#define PI              acos(-1.0)
#define en '\n'
#define Infi 0x3f3f3f3f
#define LInfi 0x3f3f3f3f3f3f3f3f

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))


#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);


const int dx[] = {+1,-1,+0,+0};                         // 4 X directions
const int dy[] = {+0,+0,+1,-1};                         // 4 Y directions
const int dx8[] = {+0,+0,+1,-1,-1,+1,-1,+1};            // King X Moves
const int dy8[] = {-1,+1,+0,+0,+1,+1,-1,-1};            // King Y Moves
const int kx[] = {-2, -2, -1, -1,  1,  1,  2,  2};      // Knight X Moves
const int ky[] = {-1,  1, -2,  2, -2,  2, -1,  1};      // Knight Y Moves



int  Set    (int N,int pos) {return N=N | (1<<pos);}    /// turn a bit on
int  reset  (int N,int pos) {return N= N & ~(1<<pos);}  /// turn a bit off
bool check  (int N,int pos) {return (bool)(N & (1<<pos));} /// check, if a bit is on or not

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define trace(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define trace(x...)
#endif

typedef long long int  ll;
typedef unsigned long long int llu;

int m,n,t;
int o;

int dp[10005];

int make(int t){

    if(t==0)return 0;
    if(t<0)return -Infi;

    if(dp[t]!=-1)return dp[t];

    int p1 = make(t-m)+1;
    int p2 = make(t-n)+1;

    return dp[t] = max(p1,p2);
}
int P;
int makes(int t,int par){

    if(t<0){
        return P;
    }

    if(dp[t]!=-1)return dp[t];
    P = t;
    int p1 = makes(t-m,m);

    int p2 = makes(t-n,n);
    return dp[t] = min(p1,p2);
}



int main(void){

    //READ_IN;
   // READ_OUT;

    while(cin >> m >> n >> t){

        memset(dp,-1,sizeof(dp));

        int ans = make(t);

        int x2 = 0;
        int x1 = 0;

        if(ans<0){

        memset(dp,-1,sizeof(dp));
       // mine = Infi;

        int b = makes(t,0);


        x1 = make(t-b);

        cout << x1 << " " << b << endl;
        }
        else{
            cout << ans << endl;
        }
    }

    return 0;
}