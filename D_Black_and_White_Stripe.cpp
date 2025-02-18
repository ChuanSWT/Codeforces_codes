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
        int n,k;
        cin>>n>>k;
        string str;
        cin>>str;

        int sum=0;
        for(int i=0;i<k-1;++i)
            if(str[i]=='B')
                ++sum;
        int maxv=0;
        for(int i=k-1;i<n;++i)
        {
            if(str[i]=='B')
                ++sum;
            maxv=max(maxv,sum);
            if(str[i-k+1]=='B')
                --sum;
        }
        cout<<k-maxv<<endl;
        

        
    }