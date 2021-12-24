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
#define segtree
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

#define func max

vvi parent;
vi depth, label, toc, subsize, seg, vals;
int mxN = 20;

void dfsone(int src, int par, vi *adj, int dep=0){
    depth[src] = dep;
    parent[src][0] = par;
    subsize[src] = 1;
    for(int i=1;i<mxN;i++){
        parent[src][i] = parent[parent[src][i-1]][i-1];
    }
    for(auto i:adj[src]){
        if(i == par) continue;
        dfsone(i,src,adj,dep+1);
        subsize[src] += subsize[i];
    }
}

int timer = 0;

void dfstwo(int src, int parent, vi *adj, bool heavy){
    label[src] = timer++;
    toc[src] = ((heavy)?toc[parent]:src);
    int mx=0,pos=-1;
    for(auto i:adj[src]) {
        if(i == parent) continue;
        if(subsize[i] > mx){
            mx = subsize[i];
            pos = i;
        }
    }
    if(pos != -1)dfstwo(pos,src,adj,1);
    for(auto i:adj[src]) {
        if(i == parent) continue;
        if(i == pos) continue;
        else {
            dfstwo(i,src,adj,0);
        }
    }
}

void update(int pos, int val, int st, int en, int ind, vi &seg)
{
    if(pos > en or pos < st) return;
    else if(st==en){
        seg[ind] = val;
    }
    else{
        update(pos,val,left);
        update(pos,val,right);
        seg[ind] = func(seg[ridx], seg[lidx]);
    }
}

int getans(int l, int r, int st, int en, int ind, vi &seg)
{
    if(l > r) swap(l,r);
    if(r < st or l > en) return intmin;
    else if(r >= en and l <= st) return seg[ind];
    else{
        if(st==en) return seg[ind];
        auto a = getans(l,r,left);
        auto b = getans(l,r,right);
        auto c = func(a,b);
        return c;
    }
}


auto lca = [](int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    drep(i,mxN-1,0) if(depth[u]-(1<<i) >= depth[v]) u = parent[u][i];
    if(u == v) return v;
    drep(i,mxN-1,0) {
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vi adj[n+1];
    vals.resize(n+1);
    rep(i,1,n+1) cin >> vals[i];
    makegraph(adj,n-1);
    parent.assign(n+1, vi(mxN, 0));
    depth.resize(n+1);
    label.resize(n+1);
    toc.resize(n+1);
    subsize.resize(n+1);
    seg.resize(4*n);
    dfsone(1,0,adj);
    dfstwo(1,0,adj,false);
    trace(label);trace(vals);trace(depth);trace(subsize);
    rep(i,1,n+1) {
        update(label[i],vals[i],0,n-1,0,seg);
    }
    while(q--) {
        newint(type,x,y);
        if(type == 1) {
            update(label[x],y,0,n-1,0,seg);
            vals[x] = y;
        } else {
            int l = lca(x,y);
            trace(x,y,l);
            int ans1 = vals[x], ans2 = vals[y];
            int node1 = x, node2 = y;
            while(node1 != l) {
                if(toc[node1] == node1) {
                    node1 = parent[node1][0];
                    ans1 = func(ans1, vals[node1]);
                }
                else if(depth[toc[node1]] >= depth[l]) {
                    ans1 = func(ans1, getans(label[toc[node1]],label[node1],0,n-1,0,seg));
                    node1 = toc[node1];
                } else {
                    ans1 = func(ans1, getans(label[l], label[node1], 0, n-1, 0, seg));
                    node1 = l;
                }
            }
            while(node2 != l) {
                if(toc[node2] == node2) {
                    node2 = parent[node2][0];
                    ans2 = func(ans2, vals[node2]);
                }
                else if(depth[toc[node2]] >= depth[l]) {
                    ans2 = func(ans2, getans(label[toc[node2]],label[node2],0,n-1,0,seg));
                    node2 = toc[node2];
                } else {
                    ans2 = func(ans2, getans(label[l], label[node2],0,n-1,0,seg));
                    node2 = l;
                }
            }
            cout << func(ans1,ans2) << endl;
        }
    }
    cout << endl;
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