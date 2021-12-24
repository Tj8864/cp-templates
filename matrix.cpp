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

template<long long modulo>
struct matrix{
    vector<vector<long long>> mat;
    int row, col;
    matrix(long long _row, long long _col){
        row = _row, col = _col;
        mat.assign(row, vector<long long>(col,0));
    }
    vector<long long> &operator[](long long r){
        if(r >= mat.size()) throw;
        return mat[r];
    }

    matrix operator*(matrix &m){
        if(m.row != this->col){
            throw;
        }
        matrix res(this->row, m.col);
        for(int i=0;i<this->row;i++){
            for(int j=0;j<m.col;j++){
                for(int k=0;k<m.row;k++){
                    res[i][j] = (res[i][j] + (((*this)[i][k])*m[k][j])%modulo)%modulo;
                }
            }
        }
        return res;
    }

    vector<vector<long long>>::iterator begin(){
        return mat.begin();
    }

    vector<vector<long long>>::iterator end(){
        return mat.end();
    }

    void operator=(matrix m){
        this->mat = m.mat;
        this->row = m.row;
        this->col = m.col;
    }
};

template<long long modulo>
matrix<modulo> identity(int sz){
    matrix<modulo> res(sz,sz);
    for(int i=0;i<sz;i++){
        res[i][i] = 1;
    }
    return res;
}

template<long long modulo> ostream &operator<<(ostream &ost, matrix<modulo> m){for(auto &i:m){for(auto &j:i) ost << j << " ";ost << endl;}return ost;}
template<long long modulo> istream &operator>>(istream &ist, matrix<modulo> &m){for(auto &i:m)for(auto &j:i) ist>>j;return ist;}


template<long long modulo>
matrix<modulo> matrixExpo(matrix<modulo> &m, long long power){
    if(m.row != m.col) throw;
    matrix<modulo> res = identity<modulo>(m.row);
    auto prod = m;
    while(power){
        if((power&1)) res = res*prod;
        prod = (prod*prod);
        power /= 2;
    }
    return res;
}


// struct matrix{
//     vector<vector<double>> mat;
//     int row, col;
//     matrix(long long _row, long long _col){
//         row = _row, col = _col;
//         mat.assign(row, vector<double>(col,0));
//     }
//     vector<double> &operator[](long long r){
//         if(r >= mat.size()) throw;
//         return mat[r];
//     }

//     matrix operator*(matrix &m){
//         if(m.row != this->col){
//             throw;
//         }
//         matrix res(this->row, m.col);
//         for(int i=0;i<this->row;i++){
//             for(int j=0;j<m.col;j++){
//                 for(int k=0;k<m.row;k++){
//                     res[i][j] += (((*this)[i][k])*m[k][j]);
//                 }
//             }
//         }
//         return res;
//     }

//     vector<vector<double>>::iterator begin(){
//         return mat.begin();
//     }

//     vector<vector<double>>::iterator end(){
//         return mat.end();
//     }

//     void operator=(matrix m){
//         this->mat = m.mat;
//         this->row = m.row;
//         this->col = m.col;
//     }
// };

// matrix identity(int sz){
//     matrix res(sz,sz);
//     for(int i=0;i<sz;i++){
//         res[i][i] = 1;
//     }
//     return res;
// }
// ostream &operator<<(ostream &ost, matrix m){for(auto &i:m){for(auto &j:i) ost << j << " ";ost << endl;}return ost;}
// istream &operator>>(istream &ist, matrix &m){for(auto &i:m)for(auto &j:i) ist>>j;return ist;}


// matrix matrixExpo(matrix &m, long long power){
//     if(m.row != m.col) throw;
//     matrix res = identity(m.row);
//     auto prod = m;
//     while(power){
//         if((power&1)) res = res*prod;
//         prod = (prod*prod);
//         power /= 2;
//     }
//     return res;
// }


void solve()
{
    matrix<mod> base(2,1);
    base.mat = {{1},{0}};
    matrix<mod> mat(2,2);
    mat.mat = {{1,1},{1,0}};
    int n;
    cin >> n;
    mat = matrixExpo<mod>(mat, n);
    cout << (mat*base)[0][0] << endl;
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