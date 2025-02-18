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
    int main()
    {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL) ;
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
        vector<long long> nums(n,0);
        for(int i=0;i<nums.size();++i)
        cin>>nums[i];
        vector<vector<int>> parts;
        nums.push_back(nums.back());

        int left=0;
        for(int i=1;i<nums.size();++i)
        {
            if((nums[i]+100000)%2==(nums[i-1]+100000)%2)
            {
                vector<int> temp;
                for(int j=left;j<i;++j)
                temp.push_back(nums[j]);
                left=i;
                parts.push_back(temp);
            }
        }
        int ans=INT_MIN;
        for(int num:nums)
        ans=max(ans,num);
        for(auto arr:parts)
        {
            /*for(int num:arr)
            cout<<num<<" ";
            cout<<endl;*/
            vector<int> dp=arr;
            for(int i=1;i<dp.size();++i)
                dp[i]=max(dp[i]+dp[i-1],dp[i]);
            int maxv=INT_MIN;
            for(int num:dp)
            maxv=max(num,maxv);
            ans=max(ans,maxv);
        }
        cout<<ans<<endl;
        
    }