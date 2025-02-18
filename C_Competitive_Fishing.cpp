// n g m i :(

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll; 
typedef long double ld;
typedef pair<ll, ll> pl;

#define N 300069 // 2e5 
#define L 20
//#define MOD 1000000007
//#define MOD 998244353
#define LLMX LONG_LONG_MAX
#define LLMN LONG_LONG_MIN

#define pb(i) push_back((i))
#define mp(i, j) make_pair((i), (j))

#define f(i, s, e, inc) for(ll i = (s); i < (e); i += (inc)) 
#define fd(i, s, e, dec) for(ll i = (s); i >= (e); i -= (dec))
#define fer(i, x) for(auto &i : x)

#define p(x) cout << x << '\n'
#define tf(x) cout << ((x) ? "Yes" : "No") << '\n'

template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) { cin >> x; }
void read(double& d) { string t; read(t); d=stod(t); }
void read(long double& d) {string t; read(t); d=stold(t); }
template<class H, class... T> void read(H& h, T&... t) { read(h); read(t...); }
template<class A> void read(vector<A>& x) { for(A &a : x){ read(a); }}
template<class A, size_t S> void read(array<A, S>& x) { for(A &a : x){ read(a); } }

template<class A> void print(vector<A> x) { for(A &a : x){ cout << a << " "; } }
template<class A> void print(A x) { cout << x << " "; }
template<class A> void printl(A x) { cout << x << '\n'; }
template<class H, class... T> void print(const H& h, const T&... t) {
	print(h); print(t...);
    if((sizeof...(t)) == 1){
        cout << '\n';
    }
}

void ra(ll arr[], ll size)
{ for(ll i = 0; i < size; i++) cin >> arr[i]; }

void pa(ll arr[], ll size)
{ for(ll i = 0; i < size; i++) cout << arr[i] << " "; cout << '\n'; }

struct segtree{
    typedef pl T; //replace this

    T id = {LLMN, 0}, t[2 * N]; 
    // id is identity: 1 for mult, 0 for add, ll max for min, ll min for max
    // Make sure N is >= siz of array
    
    T func(T a, T b) { 
        if(a.first == b.first){
            return mp(a.first, min(a.second, b.second));
        }
        else return max(a, b);
    } // replace this
 
    void modify(ll p, T v) { //set value v at position p
        for(t[p += N] = v; p /= 2;) t[p] = func(t[2 * p], t[2 * p + 1]);
    }
 
    T query(ll l, ll r) { //query on interval [l, r)
        T resl = id, resr = id;
        for(l += N, r += N; l < r; l /= 2, r /= 2) {
            if(l & 1) resl = func(resl, t[l++]);
            if(r & 1) resr = func(t[--r], resr);
        }
        return func(resl, resr);
    }
};

struct segtree sg;

void solve() 
{
    ll n, k; read(n, k); string s; cin >> s;
    ll ptr = 1; ll currSeg = 1; ll score = 0;

    ll csum = 0; vector<ll> suffixes;
    fd(i, n-1, 1, 1){
        if(s[i] == '1') csum++;
        else csum--;
        suffixes.pb(csum);
    }

    sort(suffixes.begin(), suffixes.end()); 
    fd(i, ((ll) suffixes.size()) - 1, 0, 1){
        score += suffixes[i];
        currSeg++;
        if(score >= k) break;

    }
   
    if(score >= k) p(currSeg);
    else p(-1);
}  

int main()
{
    ios::sync_with_stdio(false); 
        cin.tie(NULL); 
    ll tt = 1; cin >> tt; 
        f(i, 0, tt, 1) solve();
}