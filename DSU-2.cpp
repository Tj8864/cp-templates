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
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " = " << arg1<<endl;
        __f(comma+1, args...);
    }
#define seed 127
#else
#define trace(...) 42
#define seed chrono::steady_clock::now().time_since_epoch().count()
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
#define repeat(n) for(int _=0;_<n;_++)
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
typedef __int128_t xll;
const int intmax = 2147483647;
const int intmin = -2147483648;
const int mod = 1000000007;
const int mod2 = 998244353;
mt19937 rng(seed);

//IO operators for vectors, pairs, sets, maps and __int128
template <typename T>istream &operator>>(istream &in, vector<T> &v){for (auto &i : v)in >> i;return in;}
template <typename T>ostream &operator<<(ostream &ost, vector<T> v){if(&ost == &cerr){cerr <<"{";int cnt = v.size();for(auto x:v){cerr << x;cnt--;if(cnt) cerr << ", ";}cerr << "}";}else for(auto i:v)ost << i << " ";return ost;}
template <typename T>ostream &operator<<(ostream &ost, set<T> s){if(&ost == &cerr){cerr <<"{";int cnt = s.size();for(auto x:s){cerr << x;cnt--;if(cnt) cerr << ", ";}cerr << "}";}else for(auto i:s)ost << i << " ";return ost;}
template <typename U, typename V>ostream &operator<<(ostream &ost, map<U,V> &m){if(&ost == &cerr){cerr <<"{";int cnt = m.size();for(auto x:m){cerr << x; cnt--;if(cnt) cerr << ", ";}cerr << "}";}else for(auto i:m)ost << i;return ost;}
template <typename U, typename V>istream &operator>>(istream &in, pair<U, V> &p){in>>p.first>>p.second;return in;}
template <typename U, typename V>ostream &operator<<(ostream &ost, pair<U, V> p){if (&ost == &cerr)ost << "{" << p.first << ": " << p.second << "}";else ost << p.first << " " << p.second << " ";return ost;}
ostream &operator<<(ostream &ost, __int128_t x){string output = "";while(x)output += '0'+x%10, x /= 10;reverse(all(output)); ost << output;  return ost;}
istream &operator>>(istream &in, __int128_t &x){x=0;string num;cin >> num;for(char c:num) x *= 10, x += c-'0';return in;}
//Variadic IO
template <typename... T>void read(T &...args){((cin >> args), ...);}
template <typename... T>void print(T... args){((cout << args << " "), ...);cout << endl;}



template<typename T>
class DSU {
    map<T,T> root;
    map<T,int> sz;
public:
    DSU() {}
    void init(T val) {
        if(!root.count(val)) {
            root[val] = val;
            sz[val] = 1;
        }
    }

    T find(T val, bool create = true) {
        if(!root.count(val)) {
            if(!create) return T();
            init(val);
            return val;
        }
        if(root[val] == val) return val;
        return root[val] = find(root[val], false);
    }

    void join(T a, T b, bool create = true) {
        a = find(a,create);
        b = find(b,create);
        if(a == b) return;
        if(sz[a] > sz[b]) {
            swap(a, b);
        }
        root[b] = a;
        sz[a] += sz[b];
        sz[a] = 0;
    }
};


void solve()
{
    DSU<pair<int,int>> dsu;
    int n;
    cin >> n;
    vector<pair<int,int>> v(n); 
    cin >> v;
    for(auto &p:v) dsu.init(p);
    trace(dsu.find(v[0]),dsu.find(v[1]));
    dsu.join(v[0],v[1]);
    trace(dsu.find(v[0]),dsu.find(v[1]));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    rep(var,1,t+1)
        // cout << "Case #" << var << ": ",
        solve();
    Tj out;
}