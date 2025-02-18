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
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    class fast_pow
    {
        public:
        map<long long,long long> mp;
    long long cal(long long base,long long x)
    {
        //cout<<x<<endl;
        if(mp.find(x)!=mp.end())
        return mp[x];
        if(x>=8)
        {
            long long temp=x%2;
            long long ans= cal(base,x/2)*cal(base,x/2+temp);
            ans%=(long long)(1e9+7);
            mp[x]=ans;
            return mp[x];
        }
        mp[x]=(long long)(pow(base,x)+0.5);
        return mp[x];
    }
    };
    void compete_solution()
    {
        int l,r,k;
        cin>>l>>r>>k;
        fast_pow test;
        long long comb=0;
        if(k>=10)
        {
            cout<<0<<endl;
            return;
        }
        if(k==1)
        comb=10;
        if(k==2)
        comb=5;
        if(k==3)
        comb=4;
        if(k==4)
        comb=3;
        if(k>=5&&k<=9)
        comb=2;
        cout<<(test.cal(comb,r)-test.cal(comb,l)+(long long)(1e9+7))%(long long)(1e9+7)<<endl;
        
        

        
    }