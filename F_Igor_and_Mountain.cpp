#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <iomanip>
#include <numeric>
#include <assert.h>
#define int long long

using namespace std;

void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        compete_solution();
    }
    return 0;
}
void debug(int n){
    cout<<n<<endl;
}
template <typename T>
void print(const std::vector<T> &vec)
{
    for (auto element : vec)
    {
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

vector<int> cin_nums(int n)
{
    vector<int> ans(n);
    for (auto &x : ans)
        cin >> x;
    return ans;
}
vector<vector<int>> cin_matrix(int n, int m)
{
    vector<vector<int>> ans(n, vector<int>(m));
    for (auto &arr : ans)
    {
        for (int i = 0; i < m; ++i)
            cin >> arr[i];
    }
    return ans;
}



int check_length(int x1,int y1,int x2,int y2,int d){
    return d*d>=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int cal_redius(int d){
    int left=0,right=1e9;
    while(left<right){
        int mid=(left+right)/2;
        if(mid*mid+1ll<=d*d){
            left=mid+1;
        }
        else
            right=mid;
    }
    return left-1;
}
void compete_solution()
{
    int mod=998244353ll;
    int n,m,d;
    cin >> n>>m>>d;
    vector<string> r_grid(n);
    for(auto &s:r_grid)
        cin>>s;

    vector<vector<int>> grid(n,vector<int>(m));
    for(int x=0;x<r_grid.size();++x){
        for(int y=0;y<r_grid[0].size();++y){
            grid[x][y]=r_grid[x][y]=='#'?0:1;
        }
    }
    vector<vector<int>> dp1(n,vector<int>(m,0));//首次进入
    vector<vector<int>> dp2(n,vector<int>(m,0));//同层攀爬

    for(int y=0;y<dp1[0].size();++y){
        if(grid[0][y]){
            dp1[0][y]=1;
        }
    }
    vector<int> temp=dp1[0];
    for(int i=1;i<temp.size();++i){
        temp[i]+=temp[i-1];
    }
    int radius=d-1;
    for(int y=0;y<dp2[0].size();++y){
        if(grid[0][y]==0)
            continue;
        int left=max(0ll,y-d);
        int right=min(m-1,y+d);
        dp2[0][y]+=temp[right];
        if(left!=0)
            dp2[0][y]-=temp[left-1];
        dp2[0][y]-=dp1[0][y];
    }
    //print(dp2[0]);
    for(int x=1;x<dp1.size();++x){
        vector<int> pre_sum(dp1[0].size(),0);//+
        for(int i=0;i<pre_sum.size();++i){
            pre_sum[i]+=dp1[x-1][i];
            pre_sum[i]%=mod;
            pre_sum[i]+=dp2[x-1][i];
            pre_sum[i]%=mod;
            if(i!=0)
                pre_sum[i]+=pre_sum[i-1];
            pre_sum[i]%=mod;//ok
        }
        for(int y=0;y<dp1[0].size();++y){
            if(grid[x][y]==0)
                continue;
            int left=max(0ll,y-radius);
            int right=min(m-1,y+radius);
            int sum=0;
            sum+=pre_sum[right];
            sum%=mod;
            if(left!=0)
                sum-=pre_sum[left-1];
            sum+=mod*mod;
            sum%=mod;
            dp1[x][y]=sum;
        }
        vector<int> pre_sum2=dp1[x];
        for(int i=1;i<pre_sum2.size();++i)
            pre_sum2[i]+=pre_sum2[i-1];
        for(int y=0;y<dp1[0].size();++y){
                if(grid[x][y]==0)
                continue;
                int left=max(0ll,y-d);
                int right=min(m-1,y+d);
                int sum=0;
                sum+=pre_sum2[right];
                sum%=mod;
                if(left!=0)
                    sum-=pre_sum2[left-1];
                sum+=mod*mod;
                sum%=mod;
                sum-=dp1[x][y];
                sum+=mod*mod;
                sum%=mod;
                dp2[x][y]=sum;
            }
        
    }
    int ans=0;
    for(int y=0;y<dp1[0].size();++y){
        ans+=dp1.back()[y];
        ans%=mod;
        ans+=dp2.back()[y];
        ans%=mod;
    }
    cout<<ans<<endl;
    
}