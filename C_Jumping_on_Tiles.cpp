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

void compete_solution()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int> nums;
    for(char c:s){
        nums.push_back(c-'a');
    }
    map<int,vector<int>> mp;
    for(int i=0;i<nums.size();++i){
        mp[nums[i]].push_back(i);

    }
    int cur=nums[0],end=nums.back();
    int min_cost=abs(cur-end);
    vector<int> ans;
    while(cur!=end){
        for(int x:mp[cur]){
            ans.push_back(x);
        }
        if(cur<end)
            ++cur;
        else
            --cur;
    }
    for(int x:mp[cur]){
        ans.push_back(x);
    }
    cout<<min_cost<<" "<<ans.size()<<endl;
    for(auto &x:ans){
        ++x;
    }
    print(ans);


}