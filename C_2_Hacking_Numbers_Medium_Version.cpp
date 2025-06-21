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



bool check1(vector<int> nums){
    for(int x:nums){
        if(x==0)
            return false;
    }
    return true;
}
void compete_solution()
{
    int n;
    cin >> n;
    string rst;
    //这一步为了将1e9类大数降到可能可以处理的地步
    cout<<"digit"<<endl;
    cout.flush();
    cin>>rst;
    //max:72
    //尝试用两条指令找到准确数字
    //吗？
    //这一步最坏是质数
    //1到15都能填充//drop..
    //在第一步使用除法是否能有效？
    //或者乘一个超级大数？
    //！！！乘9可以归到9或18
    //！99 ->18
    cout<<"mul 99"<<endl;
    cout.flush();
    cin>>rst;
    cout<<"digit"<<endl;
    cout.flush();
    cin>>rst;

    cout<<"add "<<n-18<<endl;
    cout.flush();
    cin>>rst;
cout<<"!"<<endl;
    cout.flush();
    cin>>rst;


    
}