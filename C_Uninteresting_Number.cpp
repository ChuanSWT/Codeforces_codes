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
    int cal(string s)
    {
        int cur=0;
        for(int i=0;i<s.size();++i)
        {
            cur*=10;
            cur+=s[i]-'0';
            cur%=9;
        }
        return cur;
    }
    void compete_solution()
    {
        string s;
        cin>>s;
        int two=0;
        for(char c:s)
        if(c=='2')
            ++two;
        int three=0;
        for(char c:s)
        if(c=='3')
            ++three;
        
        int base=cal(s);
        if(base==0)
        {
            cout<<"YES"<<endl;
            return;
        }
        //2..+2
        //3..+6
        vector<int> dp(501,0);
        dp[base]=1;
        for(int i=0;i<two;++i)
        {
            for(int j=dp.size()-1;j>=0;--j)
            {
                if(j-2<0)
                break;
                dp[j]|=dp[j-2];
            }
        }
        for(int i=0;i<three;++i)
        {
            for(int j=dp.size()-1;j>=0;--j)
            {
                if(j-6<0)
                break;
                dp[j]|=dp[j-6];
            }
        }
        //print(dp);
        for(int i=1;i<dp.size();++i)
        if(i%9==0&&dp[i])
        {
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl;
    }