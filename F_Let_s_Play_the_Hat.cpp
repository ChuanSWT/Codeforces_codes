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
//计算一局中大桌容纳个数
int cal(int n,int m)
{
    int cnt=n%m;
    int base=n/m;
    return cnt*(base+1);
}
void inst(vector<vector<int>> &ans,vector<int> nums,int k)
{
    vector<int> temp={k};
    for(int i=0;i<nums.size();++i)
    {
        temp.push_back(nums[i]);
        if(temp.size()==k+1)
        {
            ans.push_back(temp);
            temp={k};
        }
    }
}
void compete_solution()
{
    int n,m,k;
    cin >>n>>m>>k;
    //特判平等
    if(n%m==0)
    {
        int base=n/m;
        while(k--)
        {
            for(int i=0;i<n;i+=base)
            {
                cout<<base<<" ";
                for(int j=i;j<i+base;++j)
                {
                    cout<<j+1<<" ";
                }
                cout<<endl;
            }
        }
        return;
    }
    //区分大桌小桌
    //巡回遍历
    int small=n/m;
    int big=n/m+1;
    int length=cal(n,m);
    //cout<<length<<endl;
    int cur=0;
    vector<vector<int>> ans;
    while(k--)
    {
        vector<int> party;
        for(int i=cur;i%n!=(cur+length)%n;++i)
            party.push_back(i%n+1);
        vector<int> poor;
        for(int i=cur+length;i%n!=cur%n;++i)
            poor.push_back(i%n+1);
        inst(ans,party,big);
        inst(ans,poor,small);
        cur+=length;
    }
    for(auto arr:ans)
    print(arr);
    cout<<endl;

    
}