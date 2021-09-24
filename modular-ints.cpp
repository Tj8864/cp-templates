#include <bits/stdc++.h>
using namespace std;
//#pragma GCC target ("avx2")
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("unroll-loops")

// #include<bits/extc++.h>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define ook order_of_key
// #define fbo find_by_order

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#define dbg(x)                \
    {                         \
        cerr << #x << " = {"; \
        int cnt = x.size();   \
        for (auto i : x)      \
        {                     \
            cerr << i;        \
            cnt--;            \
            if (cnt)          \
                cerr << ", "; \
        }                     \
        cerr << "}"<< endl;   \
    }
#else
#define debug(x) 1
#define dbg(x) 1
#endif
#define makegraph(adj, num)       \
    for (int i = 0; i < num; i++) \
    {                             \
        int u, v;                 \
        cin >> u >> v;            \
        adj[u].push_back(v);      \
        adj[v].push_back(u);      \
    }
#define rep(i, k, n) for (int i = k; i < n; i++)
#define rept(i, k, n) for (auto i = k; i != n; ++i)
#define drep(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define all(a) a.begin(), a.end()
#define endl '\n'
#define ld long double
#define ll long long
#define clr(s) memset(s, 0, sizeof(s))
#define valset(arr, size, val) rep(i, 0, size) arr[i] = val;
#define newint(...) int __VA_ARGS__;read(__VA_ARGS__);
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define Tj return
#define out 0
// #define segtree
#ifdef segtree
#define mid (st + en) / 2
#define lidx 2 * ind + 1
#define ridx 2 * ind + 2
#define left st, mid, lidx, seg
#define right mid + 1, en, ridx, seg
#endif
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef set<int> si;
typedef vector<vector<int>> vvi;
const int intmax = 2147483647;
const int intmin = -2147483648;
const int mod = 1000000007;
const int mod2 = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>istream &operator>>(istream &in, vector<T> &v){for (auto &i : v)in >> i;return in;}
template <typename T>ostream &operator<<(ostream &ost, vector<T> v){if(&ost == &cerr){cerr <<"{";int cnt = v.size();for(auto x:v){cerr << x;cnt--;if(cnt) cerr << ", ";}cerr << "}";}else for(auto i:v)ost << i << " ";return ost;}
template <typename U, typename V>istream &operator>>(istream &in, pair<U, V> &p){in>>p.first>>p.second;return in;}
template <typename U, typename V>ostream &operator<<(ostream &ost, pair<U, V> p){if (&ost == &cerr)ost << "{" << p.first << ": " << p.second << "}";else ost << p.first << " " << p.second << " ";return ost;}
template <typename... T>void read(T &...args){((cin >> args), ...);}
template <typename... T>void print(T... args){((cout << args << " "), ...);cout << endl;}

long long binExpp(long long a,long long b,long long modulo)
{
    long long prod = a;
    long long ans = 1;
    while(b){
        if(b%2) ans = (ans*prod)%modulo;
        b /= 2;
        prod = (prod*prod)%modulo;
    }
    return ans;
}

template<const int mod>
class Mint{
    long long val;

    public: 
    Mint(long long _val){
        val = (_val%mod+mod)%mod;
    }
    Mint(){
        val = 0;
    }
    Mint operator+(Mint b){
        return Mint((this->val+b.val)%mod);
    }
    Mint operator-(Mint b){
        return Mint(this->val-b.val+mod)%mod;
    }
    Mint operator*(Mint b){
        return Mint((this->val*b.val)%mod);
    }
    Mint operator/(Mint b){
        return (Mint(binExpp(b(), mod-2, mod))*(*this));
    }
    long long &operator()(){
        return val;
    }
    Mint operator+=(Mint b){
        return *this = *this+b;
    }
    Mint operator-=(Mint b){
        return *this = *this-b;
    }
    Mint operator*=(Mint b){
        return *this = *this*b;
    }
    Mint operator/=(Mint b){
        return *this = *this/b;
    }
    int operator%(int modulo){
        return val%modulo;
    }
    int operator%(Mint modulo){
        return val%(modulo());
    }
    Mint operator++(){
        return *this = *this+Mint(1);
    }
    Mint operator= (int x){
        return (*this).val = (x%mod+mod)%mod;
    }
    Mint operator^(Mint pow){
        return Mint(binExpp((*this)(),pow(),mod));
    }
};
template<const int mod>
istream &operator>>(istream &in, Mint<mod> &a)
{
    return in >> a();
}
template<const int mod>
ostream &operator<<(ostream &outt, Mint<mod> a)
{
    return outt<<a();
}
template<const int mod>
Mint<mod> operator+(int mul, Mint<mod> m){
    return m+mul;
}
template<const int mod>
Mint<mod> operator*(int mul, Mint<mod> m){
    return m*Mint<mod>(mul);
}
template<const int mod>
vector<Mint<mod>> Factorial(int n)
{
    vector<Mint<mod>> fact(n+1);
    fact[0] = 1;
    for(int i=1;i<=n;i++) fact[i] = i*fact[i-1];
    return fact;
}

using mint = Mint<1000000007>;
using mint2 = Mint<998244353>;
using vmi = vector<mint>;

void solve()
{
    mint x = 1024;
    mint y = 32;
    cout << y/x;   
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    rep(var,0,t)
        solve();
    Tj out;
}