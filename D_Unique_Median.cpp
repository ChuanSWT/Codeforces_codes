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
class NumArray {
    private:
    vector<int> nums;
    vector<int> tree;
public:
    int prefixSum(int i)
    {
        int s=0;
        for(;i>0;i-=i&-i)
        s+=tree[i];
        return s;
    }
    NumArray(vector<int>& nums):nums(nums.size()),tree(nums.size()+1) {
        for(int i=0;i<nums.size();++i)
        update(i,nums[i]);
    }
    
    void update(int index, int val) {
        int delta=val-nums[index];
        nums[index]=val;
        for(int i=index+1;i<tree.size();i+=i&-i)
        tree[i]+=delta;
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right+1)-prefixSum(left);
    }
};

int cal(vector<int> nums){
int n=nums.size();
//0代表目标数字 1代表大数 -1代表小数
//-1 0 0 1 ok
//-1 -1 0 0 bad
//-1 0 0 0 1 1 ok
//偶数情况下，0+(-1)和0+1的数量都必须至少为n/2+1
//换言之，任何一方加0都必须大于令一方
//左端点可以在任意地方起,起时任意值都有可能
//区间dp？
//状态很多2e9
//也许可以将奇数情况算在内？

//枚举结尾 哈希表？
//当前结尾 我知道了-1 0 1各自的数量
//哈希表原表也可以表示每个数的数量
//直觉上 我会选择0较多的前缀,而1和-1都较少
//通过审视当前-1 0 1配比 我可以知道我需要个数
//特判全是-1和1，那么直接跳过！
//当前0较多 多到当前前缀直接满足题意//那么就只要找到前缀，使得仍然能满足题意
//可以做前缀和 统计0+1，和0-1的个数
//容忍度
int pre_sun=0;//统计 1+0-(-1)的个数
int pre_moon=0;//统计-1+0-(1)的个数
//只要存在前缀在其容忍范围内即可
//例如 当前情况为 1 3 2
//那么容忍情况为加入4个-1 或 加入 2个1
vector<int> emp(n+10,0);
NumArray sun(emp);
NumArray moon(emp);
vector<int> cur(3,0);
int ans=0;
for(int i=0;i<nums.size();++i){
    ++cur[nums[i]+1];
    //cout<<i<<endl;  
    if(cur[1]!=0)
    {
        //当前可能无法满足条件
        int t1=cur[1]+cur[2]-cur[0]-1;//对-1的容忍度
        int t2=cur[1]+cur[0]-cur[2]-1;//对1的容忍度
        if(t1>=0)
        ans+=sun.sumRange(0,t1);
        if(t2>=0)
        ans+=moon.sumRange(0,t2);

    }

    int temp1=cur[0]-cur[2]-cur[1];//删去当前前缀，冲击1的容忍度
    int temp2=cur[2]-cur[0]-cur[1];
    if(temp1>=0)
    moon.update(temp1,1);
    if(temp2>=0)
    sun.update(temp2,1);

}
return ans;

}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    //值域很小
    //求子数组，在排序后，中间两个数相等
    //统计数量

    //奇数大小的数组一定可以
    //题目给出特殊条件[值域很小(10)]
    //先统计出奇数子数组的数量？
    int odd_ans=0;
    for(int i=1;i<n;i+=2){
        odd_ans+=n-i+1;
    }
    //cout<<odd_ans<<endl;
    //做前缀和，快速查询区域的某个数的数量？
    //时间较高
    //黑白世界？针对每个值做？
    int ans=0;
    for(int val=1;val<10;++val){
        vector<int> newNums=nums;
        for(int &x:newNums){
            if(x==val){
                x=0;
            }
            else{
                if(x>val)
                    x=1;
                else
                    x=-1;
            }
        }
        ans+=cal(newNums);
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;


}