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
vector<int> cin_vector(int length)
{
    vector<int> a(length,0);
    for(int i=0;i<length;++i)
    cin>>a[i];
    return a;
}
void compete_solution()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid;
    for(int x=0;x<n;++x)
    {
        vector<int> temp(m,0);
        string s;
        cin>>s;
        for(int i=0;i<s.size();++i)
        if(s[i]=='#')
        temp[i]=1;
        grid.push_back(temp);
    }
    /*for(auto a:grid)
    {
        for(auto b:a)
        cout<<b<<" ";
        cout<<endl;
    }*/
    int ansX,ansY;
    for(int x=0;x<grid.size();++x)
    {
        bool safe=true;
        for(int y=0;y<grid[0].size();++y)
        {
            if(grid[x][y])
            {
                safe=false;
            ansY=y;
            break;
            }
        }
        if(!safe)
        break;
    }
    for(int y=0;y<grid[0].size();++y)
    {
        bool safe=true;
        for(int x=0;x<grid.size();++x)
        {
            
            if(grid[x][y])
            {
            safe=false;
            ansX=x;
            break;
            }
        }
        if(!safe)
        break;
    }
    cout<<ansX+1<<" "<<ansY+1<<endl;
    
}