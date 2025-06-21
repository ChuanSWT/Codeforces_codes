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




void compete_solution()
{
    int n;
    cin >> n;
    //分成两部分，一部分的min和另一部分的gcd相等
    //为了实现这一点 min那部分一定就有原数组最小值
    //尝试 找到所有倍数 然后集合gcd

    vector<int> nums=cin_nums(n);

    int mnv=*min_element(nums.begin(),nums.end());
    
    vector<int> newNums;
    bool f=true;
    for(int x:nums){
        if(x%mnv)
            continue;
        if(x==mnv){
            if(!f){
                newNums.push_back(x/mnv);
            }
            f=false;
            continue;
        }
        newNums.push_back(x/mnv);
    }
    if(newNums.empty()){
        cout<<"No"<<endl;
        return;
    }
    int cur=newNums[0];
    for(int i=1;i<newNums.size();++i){
        cur=gcd(cur,newNums[i]);
    }
    if(cur!=1){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
}