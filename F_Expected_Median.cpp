#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
#include <queue>
using namespace std;
void compete_solution();
template <typename T>
void print(const std::vector<T> &vec)
{
    for (auto element : vec)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
long long MOD = 1000000007;
vector<long long> fact, inv_fact;

long long mod_exp(long long base, long long exp, long long mod)
{
    long long rst = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            rst = (rst * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return rst;
}

void cal(int max_n)
{
    fact.resize(max_n + 1);
    inv_fact.resize(max_n + 1);

    fact[0] = 1;
    for (int i = 1; i <= max_n; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv_fact[max_n] = mod_exp(fact[max_n], MOD - 2, MOD);
    for (int i = max_n - 1; i >= 0; --i)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

long long combination(long long n, long long k)
{
    if (k > n)
        return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

void compete_solution();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int roundc;
    cin >> roundc;

    int maxv = 200000;
    cal(maxv);

    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
}
void compete_solution()
{
    long long n, k;
    cin >> n >> k;
    string s(n, ' ');
    for (char &c : s)
        cin >> c;

    long long cnt0 = 0;
    long long cnt1 = 0;
    for (char c : s)
    {
        if (c == '0')
            ++cnt0;
        else
            ++cnt1;
    }

    long long ans = 0;
    for (int i = k / 2 + 1; i <= k; ++i)
    {
        long long x = i;
        long long y = k - i;
        if (x > cnt1 || y > cnt0)
            continue;

        long long rst = combination(cnt1, x) * combination(cnt0, y) % MOD;
        ans = (ans + rst) % MOD;
    }
    cout << ans << endl;
}
