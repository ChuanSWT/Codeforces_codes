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
        int n,k;
        cin>>n>>k;
        vector<vector<int>> bottles(k,vector<int>(2));
        for(auto&arr:bottles)
        cin>>arr[0]>>arr[1];

        map<int,int> mp;
        for(auto arr:bottles)
        mp[arr[0]]+=arr[1];
        vector<int> rst;
        for(auto p:mp)
        rst.push_back(p.second);
        sort(rst.rbegin(),rst.rend());
        long long ans=0;
        for(int i=0;i<rst.size()&&i<n;++i)
        ans+=rst[i];
        cout<<ans<<endl;
        
        

        
    }