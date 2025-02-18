#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<set>
#include<tuple>
using namespace std;
#define MOD 1000000007
class meth
{
    public:
    //需要long long
    vector<vector<long long>> block;//识别两个块是否属于同一块
    //vector<int> bs;//附随block，表示每个block对应的大小
    vector<vector<long long>>grid;//点所隶属块的大小
    vector<vector<long long>>mark;//dfs所需标记
    vector<vector<int>> path;//dfs所需路径
    long long sz=0;//dfs所需当前区块大小
    vector<long long> dx={0,0,1,-1};
    vector<long long> dy={1,-1,0,0};
    meth(vector<vector<long long>> other)
    {
        grid=other;
        mark=other;
        block=other;
        for(auto &arr:block)
        for(long long &n:arr)
        n=0;
    }
    void dfs()
    {
        long long cur=1;
        for(int x=0;x<grid.size();++x)
        {
            for(int y=0;y<grid[0].size();++y)
            {
                //遍历每个区块
                if(mark[x][y])
                {
                    dfs_helper(x,y);
                    for(vector<int> arr:path)
                    {
                        block[arr[0]][arr[1]]=cur;
                        grid[arr[0]][arr[1]]=sz;
                    }
                    sz=0;
                    path.clear();
                    ++cur;
                }
            }
        }
    }
    void dfs_helper(int x,int y)
    {
        ++sz;
        path.push_back({x,y});
        mark[x][y]=0;
        for(int i=0;i<4;++i)
        {
            if(x+dx[i]>=0&&x+dx[i]<grid.size()&&y+dy[i]>=0&&y+dy[i]<grid[0].size())
            {
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(mark[newX][newY])
                {
                    dfs_helper(newX,newY);
                }
            }
        }
    }
    void cal()
    {
        dfs();
        long long ans=0;
        for(int x=0;x<grid.size();++x)
        {
            long long sum=0;
            set<long long> st;
            for(int y=0;y<grid[0].size();++y)
            {
                if(block[x][y]==0)
                ++sum;
                for(int i=0;i<4;++i)
                if(x+dx[i]>=0&&x+dx[i]<grid.size()&&y+dy[i]>=0&&y+dy[i]<grid[0].size())
                {
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(block[newX][newY]==0)
                continue;
                if(st.find(block[newX][newY])==st.end())
                    {
                    sum+=grid[newX][newY];
                    st.insert(block[newX][newY]);
                    }
                }
                ans=max(ans,sum);
            }
        }
            for(int y=0;y<grid[0].size();++y)
            {
            long long sum=0;
            set<long long> st;
            for(int x=0;x<grid.size();++x)
            {
                if(block[x][y]==0)
                ++sum;
                for(int i=0;i<4;++i)
                if(x+dx[i]>=0&&x+dx[i]<grid.size()&&y+dy[i]>=0&&y+dy[i]<grid[0].size())
                {
                long long newX=x+dx[i];
                long long newY=y+dy[i];
                if(block[newX][newY]==0)
                continue;
                if(st.find(block[newX][newY])==st.end())
                {
                    sum+=grid[newX][newY];
                    st.insert(block[newX][newY]);
                }
                }
            }
            ans=max(ans,sum);
            }
        cout<<ans<<endl;
    }

};
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

void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<vector<long long>> grid;
    for(int x=0;x<n;++x)
    {
        vector<long long> temp(m,0);
        string s;
        cin>>s;
        for(int i=0;i<s.size();++i)
        if(s[i]=='#')
        temp[i]=1;
        grid.push_back(temp);
    }
    meth test(grid);
    test.cal();

    
}