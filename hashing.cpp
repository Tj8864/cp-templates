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

constexpr int largeprimes[] = {1000000007,1000000009,1000000021,1000000033,1000000087,1000000093,1000000097,1000000103,1000000123,1000000181,1000000207,1000000223,1000000241};
template<const int mod1, const int mod2, const int base = 31>
struct Hash{
    private:
    long long baseInverse1, baseInverse2;
    long long lenPow1, lenPow2;
    public:
    long long hash1, hash2;
    int length;
    Hash(string s){
        baseInverse1 = binPow(base,mod1-2,mod1);
        baseInverse2 = binPow(base,mod2-2,mod2);
        hash1 = hash2 = length = 0;
        for(auto i:s){
            hash1 *= (base);
            hash2 *= (base);
            hash1 += (i-'a'+1);
            hash2 += (i-'a'+1);
            hash1 %= mod1;
            hash2 %= mod2;
            length++;
        }
        lenPow1 = binPow(base,length,mod1);
        lenPow2 = binPow(base,length,mod2);
    }
    Hash(){
        baseInverse1 = binPow(base,mod1-2,mod1);
        baseInverse2 = binPow(base,mod2-2,mod2);
        lenPow1 = lenPow2 = 1;
        hash1 = hash2 = length = 0;
    }
    bool operator==(const Hash h){
        return (this->hash1==h.hash1 and this->hash2==h.hash2 and this->length == h.length);
    }
    void push_back(char c){
        hash1 *= (base);
        hash2 *= (base);
        hash1 += (c-'a'+1);
        hash2 += (c-'a'+1);
        hash1 %= mod1;
        hash2 %= mod2;
        lenPow1 = (lenPow1*base)%mod1;
        lenPow2 = (lenPow2*base)%mod2;
        length++;
    }
    void push_front(char c){
        hash1 += (c-'a'+1)*lenPow1;
        hash1 %= mod1;
        hash2 += (c-'a'+1)*lenPow2;
        hash2 %= mod2;
        lenPow1 = (lenPow1*base)%mod1;
        lenPow2 = (lenPow2*base)%mod2;
        length++;
    }
    void pop_back(char c){
        hash1 -= (c-'a'+1);
        hash1 *= baseInverse1;
        hash1 %= mod1;
        hash2 -= (c-'a'+1);
        hash2 *= baseInverse2;
        hash2 %= mod2;
        lenPow1 = (lenPow1*baseInverse1)%mod1;
        lenPow2 = (lenPow2*baseInverse2)%mod2;
        length--;
    }
    void pop_front(char c){
        lenPow1 = (lenPow1*baseInverse1)%mod1;
        lenPow2 = (lenPow2*baseInverse2)%mod2;
        hash1 -= ((c-'a'+1)*lenPow1)%mod1;
        hash1 %= mod1;
        hash1 += mod1;
        hash1 %= mod1;
        hash2 -= ((c-'a'+1)*lenPow2)%mod2;
        hash2 %= mod2;
        hash2 += mod2;
        hash2 %= mod2;
        length--;
    }
};

template<const int m1, const int m2>
ostream &operator<<(ostream &ost, Hash<m1,m2> h){
    ost << "{" << h.hash1 << ", " << h.hash2 << "}\n";
    return ost;
}

template<const int m1, const int m2>
bool operator<(Hash<m1,m2> h1, Hash<m1,m2> h2){
    return make_pair(h1.hash1, make_pair(h1.hash2,h1.length)) < make_pair(h2.hash1, make_pair(h2.hash2,h2.length));
}


void solve()
{
    Hash<largeprimes[2],largeprimes[5]> h1("heythereitsme");  
    cout << h1 << endl; 
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