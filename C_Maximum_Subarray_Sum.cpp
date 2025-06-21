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



vector<int> make(vector<int> nums){
    int n=nums.size();
    vector<int> ans(n,0);
    int cur=0;
    for(int i=0;i<nums.size();++i){
        cur=max(0ll,cur+nums[i]);
        ans[i]=cur;
    }
    return ans;
}
bool check(string s){
    for(char c:s){
        if(c=='0')
            return true;
    }
    return false;
}
void myck(vector<int> nums,int k){
    vector<int> rst=make(nums);
    if(*max_element(rst.begin(),rst.end())!=k){
        cout<<"NONONONONONONO"<<endl;
        return;
    }
}
void compete_solution()
{
    int n,k;
    cin >> n>>k;
    string s;
    cin>>s;
    vector<int> nums=cin_nums(n);
    for(int i=0;i<n;++i){
        if(s[i]=='0'){
            nums[i]=-2e12;
        }
    }
    if(n==1){
        if(s[0]=='0'){
            cout<<"Yes"<<endl;
            cout<<k<<endl;
            return;
        }
        if(nums[0]==k){
            cout<<"Yes"<<endl;
            cout<<k<<endl;
            return;
        }
        else{
            cout<<"No"<<endl;
            return;
        }
    }
    vector<int> rev_nums=nums;
    reverse(rev_nums.begin(),rev_nums.end());

    vector<int> pre=make(nums);
    vector<int> nxt=make(rev_nums);
    reverse(nxt.begin(),nxt.end());

    int mx=*max_element(pre.begin(),pre.end());
    if(mx>k){
        cout<<"No"<<endl;
        return;
    }
    if(mx==k){
        cout<<"Yes"<<endl;
        print(nums);
        return;
    }
    if(!check(s)){
        cout<<"No"<<endl;
        return;
    }
    for(int i=0;i<n;++i){
        if(s[i]=='0'){
            if(i==0){
                nums[i]=k-nxt[i+1];
                cout<<"Yes"<<endl;
                print(nums);
                //myck(nums,k);
                return;
            }
            if(i==n-1){
                nums[i]=k-pre[i-1];
                cout<<"Yes"<<endl;
                print(nums);
                //myck(nums,k);
                return;
            }
            nums[i]=k-pre[i-1]-nxt[i+1];
            cout<<"Yes"<<endl;
            print(nums);
            //myck(nums,k);
            return;
        }
    }




    
}