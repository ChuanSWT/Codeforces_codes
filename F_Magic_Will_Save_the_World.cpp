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
    //考虑水系主攻，或火系主攻
    bool check(vector<int>& nums,long long w,long long f)
    {
        long long sum=0;
        for(auto &x:nums)
        sum+=x;
        vector<int> dp(min(1000001ll,w+1),0);
        dp[0]=1;
        for(int &val:nums)
        {
            for(int i=dp.size()-1;i>=0;--i)
            {
                if(i-val>=0&&dp[i-val]==1)
                dp[i]=1;
            }
        }
        long long maxv=0;
        for(int i=0;i<dp.size();++i)
        if(dp[i])
        maxv=i;
        if(f>=sum-maxv)
        return true;
        else
        return false;

    }
    void compete_solution()
    {
        long long w,f;
        cin>>w>>f;
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto& x:nums)
        cin>>x;
        long long sum=0;
        for(auto p:nums)
        sum+=p;

        long long left=0,right=1e6+1;
        while((left+1)*(w+f)<sum)
        ++left;
        while((right-1)*w>sum||(right-1)*f>sum)
        --right;
        while(left<right)
        {
            long long mid=(left+right)/2;
            if(!(check(nums,w*mid,f*mid)||check(nums,f*mid,w*mid)))
            left=mid+1;
            else
            right=mid;
        }
        cout<<left<<endl;
        
        

        
    }