#include<bits/stdc++.h>
using namespace std;

// codeforces.com/contest/319/problem/C

const double inf = 100000000000000.0;

template<typename T>
struct Line {
    T m,c;
    Line() {
        m = c = 0;
    }
    Line(T m, T c) {
        this->m = m;
        this->c = c;
    }
    auto at(auto x) {
        return m*x + c;
    }
};

template<typename T, typename U> 
double intersection(Line<T> l1, Line<U> l2) {
    return double(l2.c - l1.c)/double(l1.m - l2.m);
}

struct Interval {
    double start,end;
    Interval(){
        start = end = 0;
    }
    Interval(double s, double e) {
        start = s, end = e;
    }
};

template<typename T>
struct Convex_Hull {
    vector<Line<T>> lines;
    vector<Interval> bounds;
    Convex_Hull() {}

    T at(T point) {
        int index = lower_bound(bounds.begin(), bounds.end(), point, [](Interval i, T point) {
            return i.end < point;
        })-bounds.begin();
        return lines[index].m*point + lines[index].c;
    }

    void addLine(Line<T> l) {
        while(!lines.empty()) {
            Line<T> line = lines.back();
            if(line.at(bounds.back().start) >= l.at(bounds.back().start)) {
                lines.pop_back();
                bounds.pop_back();
            }
            else break;
        }

        if(lines.empty()) {
            lines.push_back(l);
            bounds.push_back(Interval(0,inf));
        } 
        else {
            double new_start = intersection(l, lines.back());
            bounds.back().end = new_start;
            lines.push_back(l);
            bounds.push_back(Interval(new_start,inf));
        }
    }
};

template<typename T>
using CH = Convex_Hull<T>;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;
 
    CH<int> hull;
 
    vector<int> dp(n);
    int mincost = b.back();
    dp[0] = -mincost;
    hull.addLine(Line(b[0],dp[0]));
 
    for(int i=1;i<n;i++) {
        dp[i] = hull.at(a[i]);
        dp[i] -= mincost*a[i];
        hull.addLine(Line(b[i],dp[i]));
    }
 
    cout << dp[n-1] + mincost*accumulate(a.begin(), a.end(), 0ll) << endl;
}