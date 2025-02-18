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
void dfs(vector<int>& a,int index,vector<int> &s,int pro,vector<int> &path,vector<int>& ans)
{
    if(index==-1||pro==-1)
    {
        if(index==-1)
        {
            ans=path;
            return;
        }
        return;
    }
    int one_target=s[pro];
    int two_target=0x3f3f3f3f;
    if(pro!=0&&s[pro-1]!=0)
    {   
        two_target=s[pro-1]*10+one_target;
    }
    int cur=a[index];
    for(int i=0;i<10;++i)
    {
        int temp=cur+i;
        if(one_target==temp)
        {
            
            path.push_back(i);
            dfs(a,index-1,s,pro-1,path,ans);
            path.pop_back();
        }
        if(two_target==temp)
        {
            path.push_back(i);
            dfs(a,index-1,s,pro-2,path,ans);
            path.pop_back();
        }
    }
}
vector<int> cal(vector<int> a,vector<int> b,vector<int> s)
{   
    for(int i=a.size()-1;i>=0;--i)
    {
        int val=a[i]+b[i];
        if(val>=10)
        {
            s.pop_back();
            s.pop_back();
        }
        else
        s.pop_back();
    }
    return s;
}
void compete_solution()
{
    string a,s;
    cin>>a;
    cin>>s;
    vector<int> a_arr;
    vector<int> s_arr;
    for(char c:a)
    a_arr.push_back(c-'0');
    for(char c:s)
    s_arr.push_back(c-'0');
    vector<int> path;
    vector<int> ans;
    dfs(a_arr,a.size()-1,s_arr,s.size()-1,path,ans);
    if(ans.empty())
    {
        cout<<-1<<endl;
        return;
    }
    reverse(ans.begin(),ans.end());
    vector<int> rst=cal(a_arr,ans,s_arr);
    for(int c:ans)
    rst.push_back(c);
    reverse(rst.begin(),rst.end());
    while(rst.size()&&rst.back()==0)
    rst.pop_back();
    reverse(rst.begin(),rst.end());
    for(int x:rst)
    cout<<x;
    cout<<endl;
    

    
}