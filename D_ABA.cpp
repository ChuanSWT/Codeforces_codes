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
    #define int long long
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
    signed main()
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
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
        string s;
        cin>>s;
        int n=s.size();
        //匹配程度 起始数字 对应个数
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(4,vector<int>(26,0)));
        for(auto&x:dp[0][0])
        x=1;
        for(int i=1;i<dp.size();++i)
        {
            int cur=s[i-1]-'A';
            dp[i]=dp[i-1];
            ++dp[i][1][cur];
            for(int j=0;j<dp[i][2].size();++j)
                dp[i][2][j]+=dp[i-1][1][j];
                //cout<<cur<<endl;
            dp[i][3][cur]+=dp[i-1][2][cur];
            //for(auto arr:dp[i])
            //print(arr);
            //cout<<endl;
        }
        long long ans=0;
        for(auto x:dp.back()[3])
        ans+=x;
        cout<<ans<<endl;
        

        
    }