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
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<long long> nums(n);
        for(auto &x:nums)
        cin>>x;
        string s;
        cin>>s;
        vector<long long> left=nums;
        for(int i=1;i<left.size();++i)
        left[i]+=left[i-1];
        int l=0,r=n-1;
        long long ans=0;
        while(l<r)
        {
            while(l<r&&s[l]=='R')
            ++l;
            while(l<r&&s[r]=='L')
            --r;
            if(!(l<r))
            break;
            long long apd=left[r];
            if(l!=0)
            apd-=left[l-1];
            ans+=apd;
            ++l;
            --r;
        }
        cout<<ans<<endl;
        

        
    }