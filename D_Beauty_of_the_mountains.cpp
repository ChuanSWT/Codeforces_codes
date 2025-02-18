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
    long long gcd(long long x, long long y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    void compete_solution()
    {
        long long n,m,k;
        cin>>n>>m>>k;        

        long long sum=0;
        vector<vector<long long>> grid(n,vector<long long>(m,0));
        for(int x=0;x<n;++x)
        {
            for(int y=0;y<m;++y)
            {
                cin>>grid[x][y];
            }
        }        
        vector<vector<long long>> mark(n,vector<long long>(m,0));
        for(int x=0;x<n;++x)
        {
            string s;
            cin>>s;
            for(int y=0;y<s.size();++y)
            {
                if(s[y]=='0')
                mark[x][y]=-1;
                else
                mark[x][y]=1;
            }
        }
                for(int x=0;x<n;++x)
        {
            for(int y=0;y<m;++y)
            {
                if(mark[x][y]==1)
                grid[x][y]=-grid[x][y];
                sum+=grid[x][y];
            }
        }     
        /*for(auto a:mark)
        {
            for(auto b:a)
            cout<<b<<" ";
            cout<<endl;
        }*/

        vector<vector<long long>> left_sum=mark;
        for(int x=0;x<n;++x)
        {
            for(int y=1;y<m;++y)
            {
                left_sum[x][y]+=left_sum[x][y-1];
            }
        }
        for(int y=0;y<m;++y)
        {
            for(int x=1;x<n;++x)
            {
                left_sum[x][y]+=left_sum[x-1][y];
            }
        }
            /*for(auto a:mark)
        {
            for(auto b:a)
            cout<<b<<" ";
            cout<<endl;
        }*/

        set<long long> st;
        for(int x=0;x<n;++x)
        {
            for(int y=0;y<m;++y)
            {
                long long sum1=0;
                int x2=x+k-1;
                int y2=y+k-1;
                int x1=x-1;
                int y1=y-1;
                if(!(x2<n&&y2<m))
                continue;
                sum1+=left_sum[x2][y2];
                if(x1>=0)
                sum1-=left_sum[x1][y2];
                if(y1>=0)
                sum1-=left_sum[x2][y1];
                if(x1>=0&&y1>=0)
                sum1+=left_sum[x1][y1];
                if(sum1!=0)
                st.insert(abs(sum1));
            }
        }
        if(sum==0)
        {
            cout<<"YES"<<endl;
            return;
        }
        if(st.empty())
        {
 cout<<"NO"<<endl;
            return;
        }
        vector<long long> nums;
        for(auto p:st)
        nums.push_back(p);
        long long bullet=nums[0];
        for(int i=1;i<nums.size();++i)
        bullet=gcd(bullet,nums[i]);
        if(sum%bullet)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;

        
        
    }