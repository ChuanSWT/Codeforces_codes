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
        vector<int> nums(n);
        for(auto& x:nums)
        cin>>x;
        map<int,int> mp;
        for(auto x:nums)
        ++mp[x];
        nums.push_back(0);
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]<nums[i-1])
            {
                mp[i]-=nums[i-1]-nums[i];
            }
        }
        for(auto p:mp)
        if(p.second!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;

        
    }