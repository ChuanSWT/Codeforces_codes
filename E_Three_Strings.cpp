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
        string a,b,c;
        cin>>a>>b>>c;
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0x3f3f3f3f));
        dp[0][0]=0;
        //可以记忆深搜。吗？
        for(int x=0;x<dp.size();++x)
        {
            for(int y=0;y<dp[0].size();++y)
            {
                char cc=c[x+y-1];
                //选a
                if(x!=0)
                {
                    char ac=a[x-1];
                    dp[x][y]=min(dp[x][y],dp[x-1][y]+(cc!=ac));
                }
                if(y!=0)//选b
                {
                    char bc=b[y-1];
                    dp[x][y]=min(dp[x][y],dp[x][y-1]+(cc!=bc));
                }
            }
        }
        //for(auto arr:dp)
        //print(arr);
        cout<<dp.back().back()<<endl;
        
        

        
    }