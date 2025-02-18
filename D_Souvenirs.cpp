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
        int n,m;
        cin>>n>>m;
        vector<int> box(n,0),man(m,0);
        for(int i=0;i<n;++i)
        cin>>box[i];
        for(int i=0;i<m;++i)
        cin>>man[i];
        sort(box.begin(),box.end());
        sort(man.begin(),man.end());
        int i=0;
        int j=0;
        long long ans=0;
        while(j<man.size())
        {
            while(i<box.size()&&box[i]<man[j])
            ++i;
            if(i==box.size())
            {
                cout<<-1<<endl;
                return;
            }
            ans+=box[i];
            ++i;
            ++j;
        }
        cout<<ans<<endl;

        
    }