//ChuanSWT is looking at you
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
        int n;
        cin>>n;
        vector<long long> s(n);//任务到达的时时刻
        vector<long long> f(n);//任务执行完的时刻
        for(auto&x:s)
        cin>>x;
        for(auto&x:f)
        cin>>x;
        
        vector<long long> ans;
        ans.push_back(f[0]-s[0]);
        for(int i=1;i<n;++i)
        {
            long long rst=min(f[i]-s[i],f[i]-f[i-1]);
            ans.push_back(rst);
        }
        print(ans);
        

        
    }