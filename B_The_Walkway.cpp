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



int cal(vector<int> nums,int length,int d){
    //相当于起点一定有
    sort(nums.begin(),nums.end());
    if(nums[0]!=1){
        nums.insert(nums.begin(),1);
    }
    nums.push_back(length+1);
    int sum=0;
    for(int i=1;i<nums.size();++i){
        sum+=(nums[i]-nums[i-1]-1)/d;
    }
    sum-=1;
    sum+=nums.size();
    return sum;

}
void compete_solution()
{
    int n,m,d;
    cin >> n>>m>>d;

    vector<int> sellers=cin_nums(m);
    sort(sellers.begin(),sellers.end());
    //从中间移走似乎能快速计算
    
    //看例子
    //0 1 0 0 1 0
    //1 1 0 1 1 0
    //d==2
    //距离 3 4 5
    //吃了 1 1 2
    
    int ori=cal(sellers,n,d);
    int minv=0x3f3f3f3f;
    int cnt=0;

    vector<int> nums1=sellers;
    nums1.erase(nums1.begin());
    int rst1=cal(nums1,n,d);
    map<int,int> ans;
    ++ans[rst1];
    //cout<<minv<<endl;
    //cout<<cnt<<endl;
    for(int i=1;i+1<sellers.size();++i){
        int rst1=0;
        rst1+=(sellers[i]-sellers[i-1]-1)/d;
        rst1+=(sellers[i+1]-sellers[i]-1)/d;
        rst1+=1;
        int rst2=0;
        rst2+=(sellers[i+1]-sellers[i-1]-1)/d;
        //cout<<ori-rst1+rst2<<endl;
        //cout<<cnt<<endl;
        if(ori-rst1+rst2<=minv){
            ++ans[ori-rst1+rst2];
            
        }

    }

    vector<int> nums2=sellers;
    nums2.pop_back();
    int rst2=cal(nums2,n,d);
    ++ans[rst2];
    //cout<<rst1<<" "<<rst2<<endl;
    cout<<ans.begin()->first<<" "<<ans.begin()->second<<endl;



    
}