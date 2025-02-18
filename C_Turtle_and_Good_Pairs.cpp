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
        string s;
        cin>>s;
        map<char,int> mp;
        for(char c:s)
        ++mp[c];
        for(auto p:mp)
        {
            for(int i=0;i<p.second;++i)
            s+=p.first;
        }
        reverse(s.begin(),s.end());
        priority_queue<pair<int,char>> pq;
        for(auto p:mp)
        pq.emplace(p.second,p.first);
        int index=1;
        string ans;
        while(ans.size()!=n)
        {
            auto p=pq.top();
            pq.pop();
            --p.first;
            pq.emplace(p.first,p.second);
            ans+=p.second;
            index+=2;
            if(index>=n)
            index=0;
        }
        cout<<ans<<endl;
        

        
    }