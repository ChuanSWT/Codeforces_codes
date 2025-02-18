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
        //cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        long long n;
        cin>>n;
        vector<long long> nums(n);
        for(auto&x:nums)
        cin>>x;
        map<int,int> mp;
        for(auto x:nums)
        ++mp[x];
        set<long long> pre,nxt;
        for(int x:nums)
        nxt.insert(x);
        long long ans=n*n;
        for(long long i=0;i<nums.size();++i)
        {
            pre.insert(nums[i]);
            --mp[nums[i]];
            if(mp[nums[i]]==0)
            nxt.erase(nums[i]);

            if(*pre.rbegin()<=*nxt.begin())
            ans=min(ans,(ans-i-1)*(ans-i-1)+i*i);
        }
        cout<<ans<<endl;
        
    }