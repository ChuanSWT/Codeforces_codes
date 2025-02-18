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
        vector<int> nums(n-1,0);
        for(int &x:nums)
        cin>>x;
        vector<int> ans(n,0);
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i)
        {
            if(i==0)
            {
                ans[i]=nums[i];
                ans[i+1]=nums[i];
                continue;
            }
            if(nums[i]>nums[i-1])
            {
                ans[i+1]=nums[i];
            }
            else
            {
                ans[i]=nums[i];
                ans[i+1]=nums[i];
            }
        }
        reverse(ans.begin(),ans.end());
        print(ans);
        

        
    }