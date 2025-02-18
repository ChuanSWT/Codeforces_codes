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
        map<int,int> mp;
        for(int num:nums)
        if(num==1)
        ++mp[num+1];
        else
        ++mp[num];
        long long ans=0;
        for(auto p:mp)
        {
            if(p.second==1)
            continue;
            long long sum=p.second;
            sum*=p.second-1;
            sum/=2;
            ans+=sum;

        }
        cout<<ans<<endl;

 
        
    }