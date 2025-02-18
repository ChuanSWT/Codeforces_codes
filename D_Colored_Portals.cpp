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
        int n,q;
        cin>>n>>q;
        vector<string> strs(n);
        for(auto &s:strs)
        cin>>s;
        vector<vector<int>> query(q,vector<int>(2));
        for(auto&arr:query)
        cin>>arr[0]>>arr[1];
        vector<int> left(n,-1);
        map<string,vector<int>> mp;
        for(int i=0;i<strs.size();++i)
        {
            for(auto& p:mp)
            if(p.first!=strs[i])
            {
            for(int x:p.second)
            }
        }
        

        

        
    }