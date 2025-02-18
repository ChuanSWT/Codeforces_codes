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
        long long n;
        cin>>n;
        vector<vector<int>> points(n,vector<int>(2,0));
        for(auto&arr:points)
        cin>>arr[0]>>arr[1];

        map<int,long long> mp0;
        map<int,long long> mp1;
        set<int> st;
        for(auto arr:points)
        {
            if(arr[1]==0)
                ++mp0[arr[0]];
            else
                ++mp1[arr[0]];
            st.insert(arr[0]);
        }
        long long ans=0;
        for(int x:st)
        {
            long long t1=mp0[x];
            long long t2=mp1[x];
            long long left=n-t1-t2;
            ans+=t1*t2*left;

            ans+=t1*mp1[x+1]*mp1[x-1];
            ans+=t2*mp0[x+1]*mp0[x-1];

        }
        cout<<ans<<endl;



        

        
    }