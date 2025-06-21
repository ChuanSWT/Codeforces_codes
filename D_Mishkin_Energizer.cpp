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



bool check_only(vector<int> nums){
    map<int,int> mp;
    for(int x:nums)
        ++mp[x];
    return mp.size()==1;
}
bool check_balance(vector<int> nums){
    map<int,int> mp;
    mp[0]=0;
    mp[1]=0;
    mp[2]=0;
    
    for(int x:nums){
        ++mp[x];
    }
    
    for(auto p:mp){
        for(auto p2:mp){
            if(p2.second!=p.second)
                return true;
        }
    }
    return false;
}
int take_fre(vector<int> nums,int idx){
    map<int,int> mp;
    for(int x:nums){
        ++mp[x];
    }
    vector<vector<int>> temp;
    for(int i=0;i<3;++i){
        temp.push_back({mp[i],i});
    }
    sort(temp.begin(),temp.end());
    return temp[idx][1];
}
int take(int pre,int nxt){
    vector<int> cnt(3,0);
    cnt[pre]+=1;
    cnt[nxt]+=1;
    for(int i=0;i<cnt.size();++i){
        if(cnt[i]==0)
            return i;
    }
    return -1;
}
void compete_solution()
{
    int n;
    cin >> n;
    string s;
    cin>>s;
    vector<int> nums;
    for(char c:s){
        if(c=='T')
            nums.push_back(0);
        if(c=='I')
            nums.push_back(1);
        if(c=='L')
            nums.push_back(2);
    }
    if(check_only(nums)){
        cout<<-1<<endl;
        return;
    }
    //只有两种情况
    //一种是321
    //一种是322
    //两个不同元素相交处 能产生无限多个abc

    //ABBB
    //ACBBB
    //ACABBB
    //ACACBBB...

    //CCCABBB
    //CCCBABBB
    //CCCABABBB
    //CCCACBABBB
    vector<int> anss;
    while(check_balance(nums)){
        //print(nums);
        int loser=take_fre(nums,0);
        int oker=take_fre(nums,1);
        //cout<<loser<<" "<<oker<<endl;
        int idx1=-1;
        int idx2=-1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]==nums[i-1])
                continue;
            int rst=take(nums[i-1],nums[i]);
            if(rst==loser)
                idx1=i-1;
            if(rst==oker)
                idx2=i-1;

            
        }
        //cout<<loser<<endl;
        if(idx1!=-1){
            nums.insert(nums.begin()+idx1+1,loser);
            anss.push_back(idx1);
            continue;
        }
        if(idx2!=-1){
            nums.insert(nums.begin()+idx2+1,oker);
            anss.push_back(idx2);
            continue;
        }
    }
    //wa是超过步数了 不然是T
    //
    //print(nums);
    if(anss.size()>2*n){
        cout<<-1<<endl;
        return;
    }
    cout<<anss.size()<<endl;
    for(int x:anss){
        cout<<x+1<<endl;
    }

    
    
}
//print(nums);



    /*vector<int> anss;
    int d=maxv-minv;
    //print(nums);
    for(int i=1;i<nums.size();++i){
        if(nums[i]!=nums[i-1]){
            for(int j=0;j<d;++j){
                anss.push_back(i-1);
                nums.insert(nums.begin()+(i),take(nums[i-1],nums[i]));//print(nums);
                anss.push_back(i-1);
                nums.insert(nums.begin()+(i),take(nums[i-1],nums[i]));//print(nums);
                anss.push_back(i);
                nums.insert(nums.begin()+(i+1),take(nums[i],nums[i+1]));//print(nums);
            }
            break;
        }
    }
    //print(nums);
    int offset=0;
    for(int i=1;i<nums.size();++i){
        if(nums[i-1]==nums[i])
            continue;
        int val=take(nums[i-1],nums[i]);
        if(cnt[val]<maxv){
            ++cnt[val];
            anss.push_back(i-1+offset);
            ++offset;
        }
    }*/
    //print(nums);