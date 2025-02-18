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
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto &x:nums)
        cin>>x;

        int minv=0x3f3f3f3f;
        vector<int> nxt_min=nums;
        for(int i=n-2;i>=0;--i)
        nxt_min[i]=min(nxt_min[i],nxt_min[i+1]);

        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>minv||nums[i]>nxt_min[i])
            {
                ++nums[i];
                minv=min(minv,nums[i]);
            }
        }
        sort(nums.begin(),nums.end());
        print(nums);
        
        

        
    }