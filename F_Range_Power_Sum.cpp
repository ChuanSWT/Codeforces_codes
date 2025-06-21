#include <iostream>
#include <vector>
#include <numeric>  
using namespace std;

class FenwickTree {
public:
    FenwickTree(int n) : data(n + 1, 0) {}

    void add(int i, long long x) {
        ++i;
        while (i < data.size()) {
            data[i] += x;
            i += i & -i;
        }
    }

    // sum of [0, i)
    long long sum(int i) const {
        long long s = 0;
        while (i > 0) {
            s += data[i];
            i -= i & -i;
        }
        return s;
    }

    // sum of [l, r)
    long long sum(int l, int r) const {
        return sum(r) - sum(l);
    }

private:
    vector<long long> data;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> S(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        S[i + 1] = (S[i] + A[i]*A[i]) % M;
    }

    FenwickTree ft(M);
    long long s = 0;
    long long ans = 0;

    for (int r = 0; r <= N; ++r) {
        ans += static_cast<long long>(S[r]) * r - s + ft.sum(S[r] + 1, M) * static_cast<long long>(M);
        s += S[r];
        ft.add(S[r], 1);
    }

    cout << ans << endl;
    return 0;
}
