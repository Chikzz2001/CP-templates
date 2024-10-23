#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
#define int long long int
#define pbds tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>//less_equal
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pr pair<int, int>
#define ff first
#define ss second
#define pie 3.1415926535898
#define inf LLONG_MAX
#define co(n) __builtin_popcountll(n)
#define cz(n) __builtin_ctzll(n)
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
const int MAXN=500100;
const int M=1e9+7;
const int dx[16] = {1,0,0,-1,1,1,-1,-1,2,2,1,1,-1,-1,-2,-2};
const int dy[16] = {0,-1,1,0,-1,1,-1,1,-1,1,-2,2,-2,2,-1,1};
vector<int>fact(MAXN,1);
vector<bool>sieve(MAXN,1);
vector<int>dsieve(MAXN,0);

void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
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
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#endif

bool isPrime(int n){for(int i=2;i*i<=n;i++){if(n%i==0)return 0;}return 1;}
void primeSieve(){sieve[0]=sieve[1]=0;for (int i=2;i*i<MAXN;i++){if(sieve[i]){for(int j=i*i;j<MAXN;j+=i)sieve[j]=0;}}}
void divSieve(){for(int i=1;i<MAXN;i++){for(int j=i;j<MAXN;j=j+i){++dsieve[j];}}}
void factSieve(){for(int i=1;i<MAXN;i++)fact[i]=(fact[i-1]%M*1LL*i%M)%M;}
map<int,int> primeFactorise(int n){map<int,int> m;for(int i=2;i*i<=n;i++){if(n%i==0){int cnt=0;while(n%i==0){++cnt;n=n/i;}m[i]=cnt;}}if(n>1)m[n]=1;return m;}
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
int binexp(int x,int n){int a=x;int prod=1;while(n){if(n%2==1)prod=prod*a;a=a*a;n=n/2;}return prod;}
int modexp(int a, int b, int m) {a%=m;int res=1LL;while(b>0){if(b&1) res=(res%m*1LL*a%m)%m;a=(a%m*1LL*a%m)%m;b>>=1;}return res%m;}
int modadd(int a,int b,int m){return (a%m+b%m)%m;}
int modsub(int a,int b,int m){return (a%m-b%m+m)%m;}
int modmul(int a,int b,int m){return (a%m*1LL*b%m)%m;}
int modinv(int a,int m){return modexp(a,m-2,m);}
int moddiv(int a,int b,int m){return (a%m*1LL*modinv(b,m)%m)%m;}
int nCr(int n,int r){if(n<r||r<0)return 0;if(r==1)return n;int nmr=fact[n]%M;int dmr=(fact[r]%M*1LL*fact[n-r]%M)%M;return (nmr%M*1LL*modinv(dmr,M)%M)%M;}
 
const int N=200100;
void solve() {
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
}

signed main()
{
    fio
    //primeSieve();
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++) {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}