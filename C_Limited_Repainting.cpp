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


vector<int> make(string s,vector<int>nums){
    int n=s.size();
    int left=0;
    while(left<s.size()&&s[left]=='R')
        ++left;
    int right=n-1;
    while(right>=0&&s[right]=='R')
        --right;
    int cur=0;
    int cur_c='B';
    vector<int> ans;
    for(int i=left;i<=right;++i){
        if(s[i]==cur_c){
            cur+=nums[i];
        }
        else{
            ans.push_back(cur);
            cur=nums[i];
            if(cur_c=='B'){
                cur_c='R';
            }
            else{
                cur_c='B';
            }
        }
    }
    ans.push_back(cur);
    return ans;
}

void compete_solution()
{
    int n,k;
    cin >> n>>k;
    string s;
    cin>>s;
    vector<int> punish=cin_nums(n);
    //R为原始色
    //不管初始分数 涂到对的单元格
    //当某个单元格明显大于旁边的格子，是否
//10 2
//BRBRBBRRBR
//5 1 2 4 5 3 6 1 5 4
//512 53615
//两周的红块无论如何都不能填
    //vector<int> nums=make(s,punish);
    //print(nums);
//考虑反悔贪心
    //priority_queue<int> pq;
//又读假了是要最大的草'
    int left=1,right=0x3f3f3f3f;
    while(left<right){
        int mid=(left+right)/2;
        vector<int> mark(n,0);
        for(int i=0;i<n;++i){
            if(punish[i]>=mid){
                mark[i]=1;
            }
        }
        //至少要多少次填涂
        //由红色隔开蓝色
        int cnt=0;
        int cur=0;
        for(int i=0;i<s.size();++i){
            if(mark[i]){
                if(s[i]=='B'){
                    cur+=1;
                }
                else{
                    if(cur!=0){
                        cur=0;
                        cnt+=1;
                    }
                }
            }
        }
        if(cur){
            cnt+=1;
        }
        if(cnt<=k){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    cout<<left-1<<endl;

}