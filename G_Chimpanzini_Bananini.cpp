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
    int time;
    cin >> time;
    bool rev=false;
    deque<int> dq;
    int sum=0;
    int posi_sum=0;
    int nega_sum=0;
    while(time--){
        int op;
        cin>>op;
        //cycle
        if(op==1){
            if(rev==false){
                int val=dq.back();
                dq.pop_back();
                dq.push_front(val);

                int left_sum=sum-val;
                posi_sum+=left_sum;
                posi_sum-=(dq.size()-1)*val;
        
                nega_sum-=left_sum;
                nega_sum+=(dq.size()-1)*val;
            }
            else{
                int val=dq.front();
                dq.pop_front();
                dq.push_back(val);

                int left_sum=sum-val;
                nega_sum+=left_sum;
                nega_sum-=(dq.size()-1)*val;
        
                posi_sum-=left_sum;
                posi_sum+=(dq.size()-1)*val;
            }
        }
        //rev
        if(op==2){
            rev=!rev;
        }
        //append
        if(op==3){
            int val;
            cin>>val;
            if(rev==false){
                posi_sum+=(1+(int)dq.size())*val;
                nega_sum+=sum+val;

                dq.push_back(val);
                sum+=val;
            }
            else{
                nega_sum+=(1+(int)dq.size())*val;
                posi_sum+=sum+val;

                dq.push_front(val);
                sum+=val;
            }
        }
        if(!rev){
            cout<<posi_sum<<endl;
        }
        else{
            cout<<nega_sum<<endl;
        }
    }

    
}