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
    using namespace std;
    void compete_solution();
    int main()
    {
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    void compete_solution()
    {
        int x,y,z;
        cin>>x>>y>>z;
        int minv=0x3f3f3f3f;
        for(int i=0;i<=10;++i)
        {
            minv=min(minv,abs(x-i)+abs(y-i)+abs(z-i));
        }
        cout<<minv<<endl;
    }