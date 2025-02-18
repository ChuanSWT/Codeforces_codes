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
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto&x:nums)
        cin>>x;
        
        map<int,int> mp;
        for(int x:nums)
        ++mp[x];

        int left=0;
        int right=1;
        int maxv=nums[0];
        --mp[nums[0]];
        if(mp[nums[0]]==0)
        mp.erase(nums[0]);
        vector<vector<int>> ops;

        while(right<nums.size())
        {
            if(nums[right]>=maxv&&maxv<=mp.begin()->first)
            {
                ops.push_back({left,right});
                left=right;
            }
            maxv=max(maxv,nums[right]);
            --mp[nums[right]];
            if(mp[nums[right]]==0)
            mp.erase(nums[right]);
            ++right;
        }
        ops.push_back({left,right});
        for(auto arr:ops)
        {
            //print(arr);
            int maxV=0;
            for(int i=arr[0];i<arr[1];++i)
            {
                maxV=max(maxV,nums[i]);
            }
            for(int i=arr[0];i<arr[1];++i)
            {
                nums[i]=maxV;
            }
        }
        print(nums);

        

        
    }