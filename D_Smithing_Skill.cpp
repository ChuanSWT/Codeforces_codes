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
    #include<iterator>
    using namespace std;
    void compete_solution();
    
    int main()
    {
        
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;


            compete_solution();
        return 0;
    }
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    //检查后者是否差值较小
    bool check(pair<int,int> &bk,pair<int,int> &other)
    {
        return other.second<=bk.second;
    }
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<int> dp(1e6+1,0);
        vector<int> cost(n,0);
        vector<int> ret(n,0);
        vector<int> metal(m,0);
        for(int i=0;i<n;++i)
        cin>>cost[i];
        for(int i=0;i<n;++i)
        cin>>ret[i];
        for(int i=0;i<m;++i)
        cin>>metal[i];

        vector<long long> mp(1e6+1,0);
        for(int i=0;i<n;++i)
        {
        if(mp[cost[i]]==0)
        mp[cost[i]]=0x3f3f3f3f;
        mp[cost[i]]=(long long)min((long long)mp[cost[i]],(long long)cost[i]-ret[i]);
        }
//reverse(newComp.begin(),newComp.end());
        vector<pair<int,int>> jobs;
        for(int i=1e6;i>=0;--i)
        {
            if(mp[i]==0)
            continue;
            while(!jobs.empty())
            {
                if(mp[i]<=jobs.back().second)
                jobs.pop_back();
                else
                {
                    jobs.push_back(make_pair(i,mp[i]));
                break;
                }
            }
            if(jobs.empty())
            {
            jobs.push_back(make_pair(i,mp[i]));
            }

        }
      
        reverse(jobs.begin(),jobs.end());
        int index=0;
 int prime=jobs.back().second; 
     for(int i=0;i<dp.size();++i)
     {
        while(index+1<jobs.size()&&i>=jobs[index+1].first)
        ++index;
        if(i+1>jobs[index].first&&i>=jobs[index].second)
        dp[i]=dp[i-jobs[index].second]+1;
     }

long long sum=0;
for(int &num:metal)
{
    if(num>1e6)
    {
        sum+=(num-1e6)/prime;
        num-=(num-1e6)/prime*prime;
        while(num>1e6)
        {
            num-=prime;
            ++sum;
        }
        
    }
    sum+=dp[num];
}
cout<<(sum<<1)<<endl; 
    }