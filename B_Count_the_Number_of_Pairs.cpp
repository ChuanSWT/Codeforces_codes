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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> mp(300);
        for(char c:s)
        mp[c]++;
        long long ans=0;
        long long left=0;
        for(char i='a';i<='z';++i)
        {
            int t1=mp[i];
            int t2=mp[i-'a'+'A'];
            ans+=min(t1,t2);
            left+=abs(t1-t2)/2;
        } 
        while(left>0&&k>0)
        {
            ++ans;
            --left;
            --k;
        }
        cout<<ans<<endl;
        
        

        
    }