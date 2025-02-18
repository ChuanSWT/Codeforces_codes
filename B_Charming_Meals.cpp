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
    long long cal(vector<long long> &a,vector<long long> &b,int r)
    {
        long long minv=0x3f3f3f3f;
        for(int i=0;i<a.size();++i)
        minv=min(minv,abs(a[i]-b[(i+r)%a.size()]));
        return minv;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(auto&x:a)
        cin>>x;
        for(auto&x:b)
        cin>>x;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long maxv=0;
        for(int i=0;i<n;++i)
        {
            maxv=max(maxv,cal(a,b,i));
        }
        cout<<maxv<<endl;

        

        
    }