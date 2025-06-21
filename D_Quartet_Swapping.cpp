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
class fenWick
{
    vector<int> tree;

public:
    fenWick(int n) : tree(n+1) {}
    fenWick(vector<int> nums)
    {
        int n = nums.size();
        tree.resize(n + 1);
        for (int i = 0; i < n; ++i)
        {
            add(i + 1, nums[i]);
        }
    }
    // 把下标为 i 的元素增加 val
    void add(int i, int val)
    {
        ++i;//对齐
        while (i < tree.size())
        {
            tree[i] += val;
            i += i & -i;
        }
    }

    // 返回下标在 [0,i] 的元素之和
    int pre(int i)
    {
        ++i;//对齐
        int res = 0;
        while (i > 0)
        {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
};



int cal_rev(int n,vector<int> nums){
    fenWick test(n+100);
    int cnt=0;
    for(int x:nums){
        cnt+=test.pre(n+10)-test.pre(x);
        test.add(x,1);
    }
    return cnt;
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    //1 4 3 2 5
    //3 2 1 4 5
    //3 4 5 2 1
    //5 2 3 4 1
    //5 4 1 2 3
    //1 2 5 4 3
    //2*3?????????????
    //rev static?
    //1 2 3 4 5
    //1 4 5 2 3
    //5 2 1 4 3
    //5 4 3 2 1 ?????????wat
    //3 2 5 4 1
    //3 4 1 2 5
    //too 2*3???
    //rev...static!!!!!
    //状态相连
    //-1的时候好像能给个全排序
    //0的时候也能全排序，但是刚好错开
    //!都能全排序
    //必须有一个错开吗？
    //不是太给面子的
    //我可以。。
    //把那个反序放在最后吗？
    //奇偶都试一下
    vector<int> even,odd;
    for(int i=0;i<nums.size();++i){
        if(i%2){
            odd.push_back(nums[i]);
        }
        else{
            even.push_back(nums[i]);
        }
    }
    int odd_rev=cal_rev(n,odd);
    int even_rev=cal_rev(n,even);
    //cout<<odd_rev<<" "<<even_rev<<endl;


    if((odd_rev+even_rev)%2){
        
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());  
        int osz=odd.size();
        int esz=even.size();
        vector<int> cp_odd=odd;
        vector<int> cp_even=even;
        swap(cp_even[esz-1],cp_even[esz-2]);
        swap(cp_odd[osz-1],cp_odd[osz-2]);

        //vector<vector<int>> anss;
        vector<int> ans;
        vector<int> temp;
        for(int i=0;i<n;++i){
            if(i%2==0){
                temp.push_back(cp_even[i/2]);
            }
            else{
                temp.push_back(odd[i/2]);
            }
        }
        ans=temp;
        temp.clear();
        for(int i=0;i<n;++i){
            if(i%2==0){
                temp.push_back(even[i/2]);
            }
            else{
                temp.push_back(cp_odd[i/2]);
            }
        }
        for(int i=0;i<n;++i){
            if(temp[i]>ans[i]){
                print(ans);
                return;
            }
            if(temp[i]<ans[i]){
                print(temp);
                return;
            }
        }
        print(ans);

    }
    else{
        //直接全排列
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        vector<vector<int>> arrs;
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(i%2==0){
                ans.push_back(even[i/2]);
            }
            else{
                ans.push_back(odd[i/2]);
            }
        }
        print(ans);
        return;
    }






    
}