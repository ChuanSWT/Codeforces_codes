    #include<iostream>
    #include<vector>
    #include<string>
    #include<map>
    #include<unordered_map>
    #include<cmath>
    #include<algorithm>
    #include<set>
    #include<tuple>
    #include<cmath>
    #include<queue>
    #include<iomanip>
    using namespace std;
    void compete_solution();
    template <typename T>
    void print(const std::vector<T>& vec) {
    for (auto element : vec) {
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
    cin.tie(NULL) ;
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
const long long MOD = 1000000007;

// 快速幂函数，用于计算 a^b % mod
__int128 power(__int128 a, __int128 b, __int128 mod) {
    __int128 result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

// 费马小定理的乘法逆元计算：a^(mod-2) % mod
__int128 modInverse(__int128 a, __int128 mod) {
    return power(a, mod - 2, mod);
}

void compete_solution() {
    __int128 mod = 1000000007;
    int n;
    cin >> n;
    vector<long long> nums_old(n);
    for (auto& x : nums_old)
        cin >> x;

    vector<__int128> nums;
    for (auto x : nums_old)
        nums.push_back(x);

    __int128 total_sum=0;
    __int128 sum = 0;

    for (auto x : nums) {
        sum += x;
    }
    for(auto x:nums)
    {
        total_sum+=x*(sum-x);
    }
    __int128 denominator = (__int128(n - 1) * n / 2) % mod;
    total_sum>>=1;
    __int128 rst = (total_sum * modInverse(denominator, mod)) % mod;

    cout << (long long)rst << endl;
}