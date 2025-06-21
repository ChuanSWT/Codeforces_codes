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
    /*int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    map<int,set<int>> mp;
    for(int i=0;i<n;++i){
        mp[nums[i]].insert(i);
    }
    priority_queue<vector<int>,vector<vector<int>>,less<>> pq;
    vector<int> mark(n,0);
    int ans=0;
    int cnt=n;
    while(cnt){
        ++ans;
        auto mx=mp.rbegin()->first;
        set<int> &st=mp[mx];
        int idx=*st.begin();
        //cout<<idx<<endl;
        mp[mx].erase(idx);
        if(mp[mx].empty()){
            mp.erase(mx);
        }
        mark[idx]=1;
        --cnt;
        int left=idx-1,right=idx+1;
        if(mp.size()&&left!=-1&&nums[left]<=mp.rbegin()->first)
            pq.push({nums[left],left});
        if(mp.size()&&right!=n&&nums[right]<=mp.rbegin()->first)
            pq.push({nums[right],right});
        //print(pq.top());
        while(mp.size()&&pq.size()&&pq.top()[0]==mp.rbegin()->first){
            //cout<<pq.top()[0]<<endl;
            auto p=pq.top();
            pq.pop();
            int val=p[0],index=p[1];
            if(mark[index]){
                continue;
            }
            --cnt;
            mp[val].erase(index);
            
            if(mp[val].empty()){
                mp.erase(val);
            }
            if(index!=0&&mark[index-1]==0){
                pq.push({nums[index-1],index-1});
                //cout<<nums[index-1]<<endl;
            }
            if(index!=n-1&&mark[index+1]==0){
                pq.push({nums[index+1],index+1});
                //cout<<index+1<<endl;
            }
        }
        print(mark);
    }
    cout<<ans<<endl;*/
    int n;
    cin >> n;
    vector<int> r_nums=cin_nums(n);
    vector<int> nums;
    for(int x:r_nums){
        if(nums.empty()){
            nums.push_back(x);
            continue;
        }
        if(nums.back()!=x){
            nums.push_back(x);
        }
    }
    int m=nums.size();
    int cnt=0;
    for(int i=1;i+1<nums.size();++i){
        if(nums[i]>nums[i+1]&&nums[i-1]<nums[i]){
            cnt+=1;
        }
    }
    if(nums.size()>=2){
    if(nums[0]>nums[1])
        cnt+=1;
    if(nums[m-1]>nums[m-2])
        cnt+=1;
    }
    if(cnt==0)  
        cnt=1;
    cout<<cnt<<endl;
    /*int n;
    cin>>n;
    vector<int> nums=cin_nums(n);
    priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
    vector<int> mark(n,0);
    for(int i=0;i<nums.size();++i){
        pq.push()
    }*/




    
}