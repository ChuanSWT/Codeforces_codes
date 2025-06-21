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


vector<int> dx={1,0,1,0};
vector<int> dy={1,1,0,0};
void dfs2(vector<int> &path,vector<int> nums,vector<int>&ans){
    if(path.size()==nums.size()){
        vector<int> days(8,0);
        bool found=false;
        for(int i=0;i<(1<<(int)days.size());++i){
            for(int j=0;j<days.size();++j){
                if((1<<j)&i){
                    days[j]=1;
                }
                else{
                    days[j]=0;
                }
            }
            //print(path);
            bool guessed=false;
            for(int j=0;j<nums.size();++j){
                int day1=days[nums[j]+1],day2=days[nums[j]+2];
                int guess1=dx[path[j]],guess2=dy[path[j]];
                //cout<<day1<<" "<<guess1<<" "<<day2<<" "<<guess2<<endl;
                if(day1==guess1&&day2==guess2){
                    guessed=true;
                }
            }
            if(!guessed){
                //print(days);
                found=true;
            }
        }

        if(!found){
            ans=path;
        }
        return;
    }
    for(int i=0;i<4;++i){
        path.push_back(i);
        dfs2(path,nums,ans);
        path.pop_back();
    }
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<int> nums=cin_nums(n);
    sort(nums.begin(),nums.end());
    /*vector<int> my_nums={1,1,2,2};
    auto dfs=[&](auto&&dfs){
        if(my_nums.size()>=4){
            vector<int> path,ans;
            dfs2(path,my_nums,ans);
            if(ans.size()){
                print(ans);
            }
            return;
        }
        for(int i=0;i<=4;++i){
            my_nums.push_back(i);
            dfs(dfs);
            my_nums.pop_back();
        }
    };
    dfs(dfs);*/
    map<int,int> mp;
    for(int x:nums){
        mp[x]+=1;
    }
    int pre=-10;
    int cur=0;//可确保的位数
    bool ok=false;
    for(auto [num,cnt]:mp){
        if(num!=pre+1){
            cur=0;
        }

        pre=num;
        if(cnt==1){
            continue;
        }
        if(cnt==2||cnt==3){
            cur+=1;
            if(cur>=2){
                ok=true;
            }
            continue;
        }
        if(cnt>=4){
            ok=true;
        }
    }
    //cout<<cur<<endl;
    if(ok){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }




    
}