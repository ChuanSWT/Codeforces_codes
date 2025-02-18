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
    int main()
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
    bool is_prime(int n)
    {
        for(int i=2;i*i<=n;++i)
        if(n%i==0)
        return false;
        return true;
    }
    void compete_solution()
    {
        long long mod=1000000009ll;
        int n;
        cin>>n;
        vector<long long> dp(100,0);
        for(int i=100;i<=999;++i)
        {
            if(is_prime(i))
            {
                dp[i%100]++;
            }
        }

        n-=3;
        while(n--)
        {
            vector<long long> temp(100,0);
            for(int i=0;i<=9;++i)
            {
                for(int j=10;j<dp.size();++j)
                {
                    if(is_prime(j*10+i))
                    {
                        int val=j%10;
                        temp[val*10+i]+=dp[j];
                        temp[val*10+i]%=mod;
                    }
                }
            }
            dp=temp;
            
        }
        int sum=0;
        for(int x:dp)
        {
        sum+=x;
        sum%=mod;
        }
        cout<<sum<<endl;        

        
    }