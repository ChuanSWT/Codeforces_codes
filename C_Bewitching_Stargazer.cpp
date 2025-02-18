#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
#include <queue>
#include <iomanip>
#include <numeric>
#define int long long
#define gird grid
using namespace std;


void compete_solution();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int roundc = 1;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
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
vector<vector<int>> cin_edges(int n, int m)
{
    vector<vector<int>> ans(n, vector<int>(m));
    for (auto &arr : ans)
    {
        for (int i = 0; i < m; ++i)
            cin >> arr[i];
    }
    return ans;
}
int dfs(int left,int right,int k,int &ans)
{
    if(left>right)
    return 0;
    //cout<<left<<" "<<right<<endl;
    //cout<<ans<<endl;
    int mid=(left+right)/2;
    int length=right-left+1;
    if(length<k)
        return 0;
    int sum=0;
    if(length%2==1)
    {
        ++sum;
        ans+=mid;
        int ori_ans=ans;
        int diff=mid+1-left;//左右对称
        int rst=dfs(left,mid-1,k,ans);
        int new_ans=ans;
        int profit=new_ans-ori_ans;
        ans+=profit+rst*diff;//right
        //cout<<"rst "<<rst<<endl;
        //dfs(mid+1,right,k,ans);
        sum+=rst*2ll;
    }
    if(length%2==0)
    {
        int ori_ans=ans;
        int diff=mid+1-left;
        int rst= dfs(left,mid,k,ans);
        //cout<<left<<" "<<mid<<endl;
        int new_ans=ans;
        int profit=new_ans-ori_ans;
        ///cout<<rst<<endl;
        ans+=profit;//right
        int add=rst*diff;
        ans+=add;

        sum+=rst*2ll;
        //dfs(mid+1,right,k,ans);
    }
    return sum;
}
void compete_solution()
{
    int n,k;
    cin >> n>>k;
    int ans=0;
    dfs(1,n,k,ans);
    cout<<ans<<endl;
    return;


    
}