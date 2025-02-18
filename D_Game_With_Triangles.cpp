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
int cal_r(int a,int b){
    int ans=0;
    while(a!=0&&b!=0&&!(a==1&&b==1)){
        if(a>b){
            a-=2;
            --b;
        }
        else{
            b-=2;
            --a;
        }
        ++ans;
    }
    return ans;
}
void compete_solution()
{
    int n,m;
    cin>>n>>m;

    vector<int> nums1=cin_nums(n);
    vector<int> nums2=cin_nums(m);
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    /*高度固定为2
    //规则为选其中一个数组的两点，分数+=两点距离,还要丢弃另一个数组中的任意一个顶点
    //贪心地讲，选最远两个点，接着选另一个数组的中点
    //前几次不受约束的贪心？
    //之后被约束后反悔？
    //反悔条件 有数组顶点数归0 or 两边数组顶点数都为1
    //反悔:1.撤销栈顶的分数,2 归还?顶点 3.必须贪心计算另一个栈中的最长两条边 并删除,放到栈外记录分数
    //2 为避免取中点，可记为取走数量
    //剩余顶点=当前定点数-取走数量
    //无法进行:栈空

    //定义两个栈 对应两个数组
    //归还：需求方需要本身持有至少三个顶点,被需求方需至少有一个cache
    */
    deque<int> dq1;
    deque<int> dq2;
    for(int &x:nums1)
        dq1.push_back(x);
    for(int &x:nums2)
        dq2.push_back(x);


    vector<long long> ans;
    long long sum=0;
    vector<int> cache1;
    vector<int> cache2;
    int nsz=n,msz=m;
    int temp;
    int length=cal_r(n,m);
    for(int i=0;i<length;++i){
        if(nsz>=2&&msz>=2){
            int t1=dq1.back()-dq1[0];
            int t2=dq2.back()-dq2[0];
            if(t1>t2){
                nsz-=2;
                msz-=1;
                sum+=t1;
                cache1.push_back(t1);
                dq1.pop_front();
                dq1.pop_back();
            }
            else{
                nsz-=1;
                msz-=2;
                sum+=t2;
                cache2.push_back(t2);
                dq2.pop_back();
                dq2.pop_front();
            }
        }
        else
        if(nsz==0){
            msz-=3;
            sum-=cache1.back();
            cache1.pop_back();
            temp=dq2.back()-dq2[0];
            sum+=temp;
            cache2.push_back(temp);
            dq2.pop_back();
            dq2.pop_front();
            temp=dq2.back()-dq2[0];
            sum+=temp;
            cache2.push_back(temp);
            dq2.pop_back();
            dq2.pop_front();
        }
        else
        if(msz==0)
        {
            nsz-=3;
            sum-=cache2.back();
            cache2.pop_back();
            temp=dq1.back()-dq1[0];
            sum+=temp;
            cache1.push_back(temp);
            dq1.pop_front();
            dq1.pop_back();
            temp=dq1.back()-dq1[0];
            sum+=temp;
            cache1.push_back(temp);
            dq1.pop_front();
            dq1.pop_back();
        }
        else
        if(nsz==1){
            nsz-=1;
            msz-=2;
            temp=dq2.back()-dq2[0];
            sum+=temp;
            cache2.push_back(temp);
            dq2.pop_back();
            dq2.pop_front();
        }
        else
        if(msz==1){
            nsz-=2;
            msz-=1;
            temp=dq1.back()-dq1[0];
            sum+=temp;
            cache1.push_back(temp);
            dq1.pop_front();
            dq1.pop_back();
        }
        ans.push_back(sum);
    }
    cout<<ans.size()<<endl;
    print(ans);
}