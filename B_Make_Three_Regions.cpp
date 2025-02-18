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
        string s1,s2;
        cin>>s1;
        cin>>s2;
        int ans=0;
        for(int i=1;i<n-1;++i)
        {
            if(s2[i-1]=='x'&&s2[i+1]=='x'&&s2[i]=='.'&&s1[i]=='.'&&s1[i-1]=='.'&&s1[i+1]=='.')
            ++ans;
        }
        swap(s1,s2);
        for(int i=1;i<n-1;++i)
        {
            if(s2[i-1]=='x'&&s2[i+1]=='x'&&s2[i]=='.'&&s1[i]=='.'&&s1[i-1]=='.'&&s1[i+1]=='.')
            ++ans;
        }
        cout<<ans<<endl;
        

        
    }