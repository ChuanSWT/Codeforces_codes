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
bool check(vector<int> nums){
    for(int i=0;i+1<nums.size();++i)
        if(nums[i]==0)
        return false;
    for(int i=0;i+1<nums.size();++i)
        if(nums[i]%(i+1))
            return false;
    return true;
}
vector<int> make1(vector<int> nums){
    set<int> st;
    for(int x:nums){
        st.insert(x);
    }
    for(int i=1;i+1<nums.size();++i){
        int base=i+1;
        int target=nums[i];
        for(int j=nums[i];j>0;j-=base){
            if(st.find(j)==st.end())
                target=j;
        }
        st.erase(nums[i]);
        st.insert(target);
        nums[i]=target;
    }
    return nums;
}
//补上最后一个无关紧要的
vector<int> make2(vector<int> nums){
    set<int> st;
    for(int i=0;i<nums.size()-1;++i){
        st.insert(nums[i]);
    }
    int cur=1;
    while(st.find(cur)!=st.end())
        ++cur;

    nums.back()=cur;
    return nums;
}
void compete_solution()
{
    int n,x;
    cin>>n>>x;
    //构造一个长为n,开头必须为x的n排列
    //使得每个数字都是下标的倍数，除了最后一个数字
    //还需要字典序最小

    //3 2 1
    //2 4 3 1
    //考虑贪心？
    //相当于去除了乘数1和n
    //再去除了其中的一个排列数
    //5 5
    //5 2 3 4 1
    //4 2 3 x
    //3 2 x
    //2 4 3 x
    //1 2 3 4 5
    //6 2 3 4 5 1
    //5 2 3 4 x
    //4 2 3 x
    //3 2 6 4 5 1 ???
    //2 4 3 x
    //1 2 3 4 5 6
    //3 2 9 4 5 6 7 8 1
    //若放在第一位的数是n的除数，则一定有解
    //12
    //4 2 3 8 5 6 7 x
    //4 2 3 12 .... 1
    //16
    //4 2 3 8 5 6 7 16 9 10 ...1
    //对于当前被占据的位置 找出一个它的倍数 使得倍数仍然是n的除数 这个数尽量小
    vector<int> ans(n,0);
    set<int> st;
    st.insert(x);
    for(int i=1;i+1<ans.size();++i){
        int base=i+1;
        if(st.find(base)==st.end()){
            ans[i]=base;
            continue;
        }
        int cur=base;
        for(int j=base+base;j<=n;j+=base){
            if(n%j==0){
                cur=j;
                break;
            }
        }
        if(cur==base){
            cout<<-1<<endl;
            return;
        }
        ans[i]=cur;
        st.insert(cur);
    }
    ans[0]=x;
    ans=make2(ans);
    print(ans);

    
}