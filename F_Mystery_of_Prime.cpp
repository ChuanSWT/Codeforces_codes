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
    bool is_prime(int n)
    {
        for(int i=2;i*i<=n;++i)
        if(n%i==0)
        return false;
        return true;
    }
    int main()
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
        int roundc=1;
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
        vector<int> nums(n,0);
        for(int &x:nums)
        cin>>x;
        int inf=0x3f3f3f3f;
        vector<vector<int>> dp(n,vector<int>(4,inf));
        //保持绝对不变
        //变为任意奇数>1
        //变为任意偶数
        //变为1
        dp[0][0]=0;
        if(nums[0]==1)
        {
            dp[0][1]=1;
            dp[0][2]=1;
            dp[0][3]=0;
        }
        else
        {
            if(nums[0]%2==1)//奇数
            {
                dp[0][1]=1;
                dp[0][2]=1;
                dp[0][3]=1;
            }
            else//偶数
            {
                dp[0][1]=1;
                dp[0][2]=1;
                dp[0][3]=1;
            }
        }
        for(int i=1;i<nums.size();++i)
        {
            int stay=dp[i-1][0];//保持
            //int odd=dp[i-1][1];//变奇数>1
            //int even=dp[i-1][2];//变偶数
            //int one=dp[i-1][3];//变1

            int pre=nums[i-1];
            int cur=nums[i];
            //0 0
            if(is_prime(cur+pre))
                dp[i][0]=min(dp[i][0],dp[i-1][0]);
            //0 1
            if(pre%2==0)
            dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
            //0 2
            if(pre%2!=0)
            dp[i][2]=min(dp[i][2],dp[i-1][0]+1);
            //0 3
            if(is_prime(pre+1))
            dp[i][3]=min(dp[i][3],dp[i-1][0]+1);

            //1 0
            if(cur%2==0)
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
            //1 1
            //不能转移
            //1 2
            dp[i][2]=min(dp[i][2],dp[i-1][1]+1);
            //1 3
            //不能转移

            //2 0
            if(cur%2!=0)
            dp[i][0]=min(dp[i][0],dp[i-1][2]);
            //2 1
            dp[i][1]=min(dp[i][1],dp[i-1][2]+1);
            //2 2
            //不能转移
            //2 3
            
            dp[i][3]=min(dp[i][3],dp[i-1][2]+1);

            //3 0
            if(is_prime(cur+1))
            dp[i][0]=min(dp[i][0],dp[i-1][3]);
            //3 1
            //不能转移
            //3 2
            dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
            //3 3
            dp[i][3]=min(dp[i][3],dp[i-1][3]+1);

            if(cur==1)
            {
                //0 3
                if(is_prime(pre+1))
                dp[i][3]=min(dp[i][3],dp[i-1][0]);
                //2 3
                dp[i][3]=min(dp[i][3],dp[i-1][2]);
                //3 3
                dp[i][3]=min(dp[i][3],dp[i-1][3]);
            }
        }
        //for(auto arr:dp)
        //print(arr);
        int minv=0x3f3f3f3f;
        for(int x:dp.back())
        minv=min(minv,x);
        cout<<minv<<endl;

        
    }