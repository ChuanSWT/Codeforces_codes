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
    int check(int n,int x,int y)
    {
        if(x>n/2)
        {
            x=n-x+1;
        }
        if(y>n/2)
        {
            y=n-y+1;
        }
        return min(x,y);
    }
    void compete_solution()
    {
        int n,x1,y1,x2,y2;
        cin>>n>>x1>>y1>>x2>>y2;
        //算出相对层级
        int d1=check(n,x1,y1);
        int d2=check(n,x2,y2);
        //cout<<d1<<' '<<d2<<endl;
        int ans=0;
        if(x1>n/2)
        {
            x1=n-x1;
        }
        if(y1>n/2)
        {
            y1=n-y1;
        }
        if(d1<d2&&x1==y1)
        ++ans;
        ans=abs(d1-d2);
        cout<<ans<<endl;
        
        

        
    }