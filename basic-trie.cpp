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

struct trieNode{
    char ch;
    int ending;
    map<char, trieNode*> pointers;
    trieNode* parent;
    trieNode(){
        ch = '\0';
        ending = 0;
        pointers.clear();
        parent = nullptr;
    }
};

class trie{
    public:
    trieNode *root;
    trie()
    {
        root = new trieNode;
        root->ending = 0;
        root->ch = '\0';
        root->parent = nullptr;
    }
    int count(string s){
        trieNode *ptr = root;
        int p = 0;
        while(p < s.size() and ptr->pointers.find(s[p])!=ptr->pointers.end()){
            ptr = ptr->pointers[s[p]];
            p++;
        }
        if(p < s.size()) return 0;
        else return ptr->ending;
    }
    void insert(string s){
        trieNode *ptr = root;
        for(int i=0;i<s.size();i++){
            if(ptr->pointers.find(s[i]) == ptr->pointers.end())
                ptr->pointers[s[i]] = new trieNode,
                ptr->pointers[s[i]]->ch = s[i];
                ptr->pointers[s[i]]->parent = ptr;
                ptr = ptr->pointers[s[i]];
        }
        ptr->ending++;
    }

    void remove(string s){
        if(count(s) == 0) return;
        trieNode *ptr = root;
        for(char c:s){
            ptr = ptr->pointers[c];
        }
        ptr->ending--;
        while(ptr->parent != nullptr){
            char c;
            if(ptr->pointers.empty() and ptr->ending == 0){
                c = ptr->ch;
                ptr = ptr->parent;
                delete ptr->pointers[c];
                ptr->pointers[c] = nullptr;
                ptr->pointers.erase(c);
            }
            else break;
        }
    }
};


void solve()
{
    trie t;
    t.insert("randomstring");
    t.insert("randomstring");
    t.insert("randomstring");
    cout << t.count("randomstring");
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