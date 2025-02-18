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
        long long x,m;
        cin>>x>>m;
        int cnt=0;
        
        set<long long> st;
        for(long long i=1;i<x;++i)
        {
            if(x%i==0)
            {
            long long t=i^x;
            if(t>=1&&t<=m)
            {
            st.insert(i);
            ++cnt;
            }
            }
        }
        
        for(int i=1;i<x;++i)
        {
            long long y=i^x;
            if(y<=m&&y>=0)
            if(y%i==0)
            {
                if(st.find(i)==st.end())
                ++cnt;
            }
        }
        cout<<cnt<<endl;
        
        

        
    }