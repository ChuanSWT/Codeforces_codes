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
    long long fd(long long limit,long long base)
    {   
        long long maxv=0;
        for(long long i=limit;i>=limit-base*3&&i>=0;--i)
        if((base^i)%base==0)
            maxv=max(maxv,base^i);
        return maxv;
    }
    void compete_solution()
    {
        long long x,m;
        cin>>x>>m;
        set<int> st;
        int cnt=0;
        for(long long y=1;y<x&&y<=m;++y)
        {
            long long mod=x^y;
            if(mod%y==0)
            {
                ++cnt;
            //cout<<"y "<<y<<" "<<mod<<endl;
            }
        }
        //cout<<fd(m,x)<<endl;
        //cout<<cnt<<endl;
        cout<<cnt+fd(m,x)/x-1<<endl;
        

        
    }