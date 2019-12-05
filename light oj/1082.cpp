#include<bits/stdc++.h>
 
using  namespace  std;
 
#define PI              acos(-1.0)
#define lcm(a,b)        (a * (b / __gcd(a,b)))
#define en '\n'
 
#define READ_IN freopen("Input.txt","r",stdin);
#define READ_OUT freopen("Output.txt","w",stdout);
 
 
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
 
typedef long long int           ll;
typedef unsigned long long int  llu;
 
 
const int maxe = 100005;
vector<int> ar(maxe);
vector<int> tree(maxe*3);
 
void make(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=ar[b];
        return;
    }
 
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
 
    make(left,b,mid);
    make(right,mid+1,e);
 
    tree[node]= min(tree[left],tree[right]);
}
int ck(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return maxe;
 
    if(b>=i && e<=j)
        return tree[node];
 
    int left = node*2;
    int right = node*2+1;
    int mid  = (b+e)/2;
    int p1 = ck(left,b,mid,i,j);
    int p2 = ck(right,mid+1,e,i,j);
 
    return min(p1,p2);
}
 
//void update(int node ,int b,int e,int i,int j)
//{
//    if(i>e || j<b)
//        return ;
//
//    if(b>=i && e<=j)
//    {
//        tree[node]=newvalue;
//        return;
//    }
//
//     int left = node*2;
//    int right = node*2+1;
//    int mid = (b+e)/2;
//
//    update(left,b,mid,i,newvalue);
//    update(right,mid+1,e,i,newvalue);
//
//    tree[node]=tree[left]+tree[right];
//
//}
 
 
int main(void)
{
    //READ_IN;
 
 
    int tt;scanf("%d",&tt);
 
    for(int i=1;i<=tt;i++)
    {
 
        int n,q;
        scanf("%d %d",&n,&q);
 
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&ar[j]);
        }
        make(1,1,n);
        printf("Case ");
        printf("%d",i);
        printf(":");
        printf("\n");
//        cout << "Case " <<  i << ":" << '\n';
        while(q--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",ck(1,1,n,a,b));
 
 
        }
 
        tree.clear();
        ar.clear();
 
    }
 
 
 
return 0;
}
 