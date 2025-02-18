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
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<long long> nums(n);
        for(auto&x:nums)
        cin>>x;
        vector<vector<long long>> dp(n,vector<long long>(2,0));
        dp[0][0]=nums[0];
        dp[0][1]=abs(nums[0]);
        for(int i=1;i<nums.size();++i)
        {
            dp[i][0]=dp[i-1][0]+nums[i];
            dp[i][1]=max(abs(dp[i][0]),dp[i-1][1]+nums[i]);
        }
        long long target=dp.back()[1];
        
        

        
    }