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


int k;
int check_meet_right(int start,int start_time,vector<vector<int>> &arrs,int pre){
    for(int i=0;i<arrs.size();++i){
        if(i==pre)
            continue;
        int &pos=arrs[i][0];
        int &delay=arrs[i][1];
        if(start>pos)
            continue;
        
        if(abs(start_time+(pos-start)-delay)%k==0){
            //cout<<start+delay<<endl;
            return i;
        }
    }
    return -1;
}
int check_meet_left(int start,int start_time,vector<vector<int>> &arrs,int pre){
    for(int i=arrs.size()-1;i>=0;--i){
        if(i==pre)
            continue;
        int &pos=arrs[i][0];
        int &delay=arrs[i][1];
        if(start<pos)
            continue;
        if(abs(start_time+(start-pos)-delay)%k==0)
            return i;
    }
    return -1;
}
void compete_solution()
{
    int n;
    cin>>n>>k;
    vector<int> positions=cin_nums(n);
    vector<int> delay=cin_nums(n);
    int q;
    cin>>q;
    vector<int> queries=cin_nums(q);
    //交通灯500个，路段长度不变
    //直接快速模拟走路？
    vector<vector<int>> arrs;
    for(int i=0;i<n;++i){
        arrs.push_back({positions[i],delay[i]});
    }
    sort(arrs.begin(),arrs.end());


    for(int start:queries){
        //cout<<start<<endl;
        vector<vector<int>> mem(n,vector<int>(2,0));
        //检查第一次相遇的红灯
        int cur_time=0;
        int red_idx=check_meet_right(start,0,arrs,-1);
        if(red_idx==-1){
            cout<<"YES"<<endl;
            continue;
        }
        int pre=red_idx;
        mem[red_idx][0]=1;
        cur_time+=arrs[red_idx][0]-start;
        int cur=arrs[red_idx][0];
        int flag=1;
        while(true){
            //cout<<red_idx<<endl;
            if(flag){
                //cout<<cur<<" "<<cur_time<<endl;
                int r_idx=check_meet_left(cur,cur_time,arrs,pre);
                if(r_idx==-1){
                    cout<<"YES"<<endl;
                    break;
                }
                if(mem[r_idx][flag]){
                    cout<<"NO"<<endl;
                    break;
                }
                mem[r_idx][flag]=1;
                flag=!flag;
                cur_time+=cur-arrs[r_idx][0];
                cur=arrs[r_idx][0];

                pre=r_idx;
            }
            else{
                int r_idx=check_meet_right(cur,cur_time,arrs,pre);
                if(r_idx==-1){
                    cout<<"YES"<<endl;
                    break;
                }
                if(mem[r_idx][flag]){
                    cout<<"NO"<<endl;
                    break;
                }
                mem[r_idx][flag]=1;
                flag=!flag;
                cur_time+=arrs[r_idx][0]-cur;
                cur=arrs[r_idx][0];
                pre=r_idx;
            }
        }
    }

    
}