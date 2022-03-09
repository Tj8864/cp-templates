#include<bits/stdc++.h>
using namespace std;

template<typename T, T (*func)(int)>
class range {
    int startIndex, endIndex;
    public:
    class iterator {
        int index;
        public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;
        using reference         = T;
        iterator(int idx) {
            index = idx;
        }
        T operator*() const {
            return func(index);
        }
        iterator &operator++(){
            this->index++;
            return *this;
        }
        iterator &operator--(){
            this->index--;
            return *this;
        }
        iterator operator++(int32_t) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        iterator operator--(int32_t) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }
        iterator operator+(int x) {
            return iterator(index+x);
        }
        iterator operator+=(int x) {
            this->index += x;
            return *this;
        }
        iterator operator-(int x) {
            return iterator(index+x);
        }
        difference_type operator-(const iterator &a) {
            return this->index-a.index;
        }
        iterator operator-=(int x) {
            this->index -= x;
            return *this;
        }
        int position() {
            return index;
        }
        difference_type distance(iterator a, iterator b) {
            return b.index-a.index;
        }
        friend bool operator!=(const iterator &a, const iterator &b) {
            return a.index != b.index;
        }
        friend bool operator==(const iterator &a, const iterator &b) {
            return a.index == b.index;
        }
    };
    range(int st, int en) {
        startIndex = st;
        endIndex = en;
    }
 
    iterator begin() {
        return iterator(startIndex);
    }
 
    iterator end() {
        return iterator(endIndex);
    }
};

long long sq(int x) {
    return (long long)x*x;
}

int main()
{
    range<long long, sq> r(0,1000000000);
    cout << boolalpha << endl;
    cout << binary_search(r.begin(), r.end(), 30625) << endl;
    cout << binary_search(r.begin(), r.end(), 625) << endl;
    cout << binary_search(r.begin(), r.end(), 25) << endl;
    cout << binary_search(r.begin(), r.end(), 5) << endl;
}