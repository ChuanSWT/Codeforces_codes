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
    int check(long long b,long long c,long long d)
    {
        if(b==0&&c==0&&d==0)
        return 0;
        if(b==0&&c==0&&d!=0)
        return 1;
        if(b==0&&c!=0&&d==0)
        return 1;
        if(b==0&&c!=0&&d!=0)
        return -1;
        if(b!=0&&c==0&&d==0)
        return -1;
        if(b!=0&&c==0&&d!=0)
        return 1;
        if(b!=0&&c!=0&&d==0)
        return 1;
        //if(b!=0&&c!=0&&d!=0)
        return 0;

    }
    void compete_solution()
    {
        long long b,c,d;
        cin>>b>>c>>d;
        long long ans=0;
        for(int i=0;i<63;++i)
        {
            long long mask=1ll<<i;
            long long rst=check((b&mask),(c&mask),(d&mask));
            if(rst==-1)
            {
                cout<<-1<<endl;
                return;
            }
            if(rst==1)
            ans|=mask;
        }
        cout<<ans<<endl;
        
        

        
    }