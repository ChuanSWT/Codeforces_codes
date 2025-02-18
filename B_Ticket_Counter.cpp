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
    #include <queue>
    using namespace std;
    void compete_solution();
    int main()
    {
        int roundc=1;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<int> nums(n,0);
        for(int i=0;i<nums.size();++i)
        cin>>nums[i];
        for(int i=1;i<nums.size();++i)
        if(nums[i]-m<nums[i-1])
        nums[i]=nums[i-1]+m;
        for(int num:nums)
        cout<<num+m<<endl;


        
        
    }