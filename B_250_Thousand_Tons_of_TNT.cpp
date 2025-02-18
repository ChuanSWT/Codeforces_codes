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
    vector<long long> cal(int n)
    {
        vector<long long> ans;
        for(int i=1;i*i<=n;++i)
        {
            if(n%i==0)
            {
                ans.push_back(i);
                ans.push_back(n/i);
            }
        }
        return ans;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<long long> nums(n,0);
        for(int i=0;i<nums.size();++i)
        cin>>nums[i];
        if(n==1)
        {
            cout<<0<<endl;
            return;
        }
        vector<long long> trucks=cal(n);
        long long ans=0;
        for(auto num:trucks)
        {   
            vector<long long> temp;
            for(long long i=0;i<n/num;++i)
            {
                long long sum=0;
                for(long long j=i*num;j<(i+1)*num;++j)
                {
                    sum+=nums[j];
                }
                temp.push_back(sum);
                
            }
            long long maxv=0,minv= LLONG_MAX;
            for(auto num:temp)
                {
                    maxv=max(maxv,num);
                    minv=min(minv,num);
                }
            ans=max(ans,maxv-minv);
        }   
        cout<<ans<<endl;
        
    }