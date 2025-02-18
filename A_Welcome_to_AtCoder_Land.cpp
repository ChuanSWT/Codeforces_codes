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
        int roundc=1;
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
        string s,t;
        cin>>s;
        cin>>t;
        if(s=="AtCoder"&&t=="Land")
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
        
        
    }