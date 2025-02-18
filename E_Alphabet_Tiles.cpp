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
    #define MOD 998244353
    void compete_solution();
    int main()
    {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL) ;
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
        int n;
        cin>>n;
        vector<int> nums(26,0);
        for(int i=0;i<nums.size();++i)
        cin>>nums[i];
        vector<long long> dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();++i)//每个字母
        {
            if(nums[i]==0)
            continue;
            for(int j=1;j<=nums[i];++j)//添加几个相同字母？
            {
                for(int k=dp.size()-1;k>=0;--k)//状态转移
                {
                    if(k-j>=0)
                    {
                        long long temp=dp[k-j];
                        for(int a=k-j+1;a<=k;++a)
                        {
                        temp*=(a);
                        temp%=MOD;
                        }
                        for(int a=1;a<=k;++a)
                        {
                            temp/=a;
                            temp%=MOD;
                        }
                    dp[k]+=temp;
                    dp[k]%=MOD;
                    }
                }
            }
        }
        long long sum=0;
        for(auto num:dp)
        cout<<num<<" ";
        cout<<endl;
        for(auto num:dp)
        sum+=num;
        sum%=MOD;
        cout<<sum<<endl;
    }