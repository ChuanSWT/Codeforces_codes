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




bool checkPoint(vector<vector<int>> sounds){
    map<int,int> mp1,mp2;
    for(auto arr:sounds){
        int x=arr[0],y=arr[1];
        mp1[x]+=1;
        mp2[y]+=1;
    }
    for(auto arr:sounds){
        int x=arr[0],y=arr[1];
        if(mp1[x]==1&&mp2[y]==1)
            return false;
    }
    return true;

}

void compete_solution()
{
    int n;
    cin>>n;
    vector<vector<int>> sounds=cin_matrix(n,2);
    sort(sounds.begin(),sounds.end());

    //一次只能变一个
    //一下不能两个都变
    //其中一项不能连续存在三次

    //相同值似乎形成联通关系
    //考虑图
    //图上概念：
    //相同的元素可以形成一条边
    //与其他元素以元素不相同为前提 连接

    //可以看成红蓝边 以及中立点
    //进行图上遍历
    //必须在红蓝边间跳转
    //可以经过任意中立点

    //贪心地说 希望拥有相同值的点 全部组边
    //如何选择不同的值？


    //先看判空?
    //若有游离点 则判空
    //若某一边明显过多

    //进行游离点判空
    if(!checkPoint(sounds)){
        cout<<"NO"<<endl;
        return;
    }
    //以及接入点过多？
    

    



    
}