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
    map<long long,long double> mp;

    int main()
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
        int roundc;
        cin >> roundc;
        long double d=1;
        for(int i=1;i<=1e6;++i)
        {
            d*=2;
            mp[i]=1.0-(1.0/d);
        }
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        long long n,m;
        double mod=998244353;
        cin>>n>>m;
        if(n<m)
        {
            cout<<0<<endl;
            return;
        }
        long long ans=mp[n]*mod+0.5;
        cout<<ans<<endl;

        
    }