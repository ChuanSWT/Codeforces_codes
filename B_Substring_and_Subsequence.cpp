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
        string a,b;
        cin>>a;
        cin>>b;
        int m=b.size();
        int minv=0x3f3f3f3f;
        for(int i=0;i<b.size();++i)
        {
            int left=i;
            int index=i;
            for(int j=0;j<a.size();++j)
            {
                if(index<b.size()&&a[j]==b[index])
                {
                    ++index;
                }
            }
            int val=a.size();
            val+=(b.size()-(index-left));
            minv=min(minv,val);
        }
        cout<<minv<<endl;
       
        
        
    }