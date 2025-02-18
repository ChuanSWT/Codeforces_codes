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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cin>>grid[i][j];
            }
        }
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        vector<vector<int>> ans=grid;
        for(int x=0;x<grid.size();++x)
        {
            for(int y=0;y<grid[0].size();++y)
            {
                int maxv=-0x3f3f3f3f;
                //int count=0;
                for(int i=0;i<dx.size();++i)
                {
                    if(x+dx[i]>=0&&x+dx[i]<grid.size()&&y+dy[i]>=0&&y+dy[i]<grid[0].size())
                    {
                    maxv=max(maxv,grid[x+dx[i]][y+dy[i]]);
                    }
                }
                ans[x][y]=min(grid[x][y],maxv);
            }
        }
        for(auto a:ans)
        {
            for(auto b:a)
            cout<<b<<" ";
            cout<<endl;
        }
        
    }