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
#include <iomanip>
#include <numeric>
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int roundc = 1;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
}
long long my_pow(long long base, long long k)
{
    long long ans = 1;
    while (k--)
        ans *= base;
    return ans;
}
void compete_solution()
{
    long long n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << k << endl;
        return;
    }
    long long ans = 0;
    for (int j = 0; j <= 30; ++j)
    {
        if (ans + (1ll << j) <= k)
            ans += (1ll << j);
    }
    cout << ans << " " << k - ans << " ";
    for (int j = 0; j < n - 2; ++j)
        cout << 0 << " ";
    cout << endl;
    return;
}