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
int mod=998244353LL;
int cal(vector<int> a,vector<int> b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    //print(a);
    //print(b);
    int ans=1;
    for(int i=0;i<a.size();++i)
    {
    ans*=min(a[i],b[i]);
    ans%=mod;
    }
    return ans;
}
long long mod_inverse(long long b, long long m) {
    long long t = 0, new_t = 1;
    long long r = m, new_r = b;
    while (new_r != 0) {
        long long quotient = r / new_r;
        t = t - quotient * new_t;
        r = r - quotient * new_r;
        swap(t, new_t);
        swap(r, new_r);
    }
    if (r > 1) {
        throw invalid_argument("b has no inverse modulo m");
    }
    if (t < 0) {
        t = t + m;
    }
    return t;
}

// 计算 (a / b) * c % m
long long mod_operation(long long a, long long b, long long c, long long m) {
    long long b_inv = mod_inverse(b, m); // 计算 b 的模反元素
    long long result = (a % m) * b_inv % m; // (a * b^-1) % m
    result = (result * c) % m; // 然后乘以 c
    return result;
}
void trans(int pre,int cur,int &ans)
{
    ans=mod_operation(ans,pre,cur,mod);
}
void compete_solution()
{
    int n,k;
    cin >> n>>k;
    vector<int> a=cin_nums(n);
    vector<int> b=cin_nums(n);
    vector<vector<int>> query=cin_edges(k,2);
    for(auto &arr:query)
        --arr[1];
    vector<int> ans;
    ans.push_back(cal(a,b));
    int sum=ans[0];
    
    //元素值 最右边的下标
    vector<int> a_arr=a;
    vector<int> b_arr=b;
    map<int,priority_queue<int>> mpA;
    map<int,priority_queue<int>> mpB;
    sort(a_arr.begin(),a_arr.end());
    sort(b_arr.begin(),b_arr.end());
    for(int i=0;i<n;++i)
    {
        mpA[a_arr[i]].push(i);
        mpB[b_arr[i]].push(i);
    }
    for(auto qry:query)
    {
        int index=qry[1];
        if(qry[0]==1)
        {
            int val=a[index];
            ++a[index];
            int target_idx=mpA[val].top();
            mpA[val].pop();
            mpA[val+1].push(target_idx);

            //检测更新
            
            if(a_arr[target_idx]<b_arr[target_idx])
            {
                int pre=a_arr[target_idx];
                int cur=pre+1;
                trans(pre,cur,sum);
            }



            //反应到排序数组中
            ++a_arr[target_idx];
            ans.push_back(sum);
        }
        else
        {
            int val=b[index];
            ++b[index];
            int target_idx=mpB[val].top();
            mpB[val].pop();
            mpB[val+1].push(target_idx);

            //检测更新
            if(b_arr[target_idx]<a_arr[target_idx])
            {
                int pre=b_arr[target_idx];
                int cur=pre+1;
                trans(pre,cur,sum);
            }



            //反应到排序数组中
            ++b_arr[target_idx];
            ans.push_back(sum);
        }

    }
    print(ans);
    


    
}