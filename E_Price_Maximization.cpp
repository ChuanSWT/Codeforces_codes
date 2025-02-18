//ChuanSWT is looking at you
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
    #include<numeric>
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
        int roundc=1;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        int n,k;
        cin>>n>>k;
        vector<long long> nums(n);
        for(auto&x:nums)
        cin>>x;
        
        long long ans=0;
        for(auto &x:nums)
        {
            ans+=x/k;
            x%=k;
        }
        sort(nums.begin(),nums.end());
        //双指针
        int left=0,right=n-1;
        while(left<right)
        {
            int val=nums[left]+nums[right];
            if(val>=k)
            {
                ++ans;
                ++left;
                --right;
            }
            else
            {
                ++left;
            }

        }
        cout<<ans<<endl;
        

        
    }