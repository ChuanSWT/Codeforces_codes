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
    string ts(int n)
    {
        string ans;
        while(n)
        {
            ans+=n%10+'0';
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<vector<int>> grid(n,vector<int>(n,0));
        long long ans=0;
        for(int i=1;i<=n;++i)
        ans+=i*(i*2-1);
        cout<<ans<<" "<<2*n<<endl;
        for(int i=n;i>=1;--i)
        {
            cout<<"1 "<<i<<" ";
            for(int j=1;j<=n;++j)
            {
            cout<<j<<" ";
            }
            cout<<endl;
            cout<<"2 "<<i<<" ";
            for(int j=1;j<=n;++j)
            {
            cout<<j<<" ";
            }
            cout<<endl;
        }
        
        
    }