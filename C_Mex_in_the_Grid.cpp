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

int cal_mex(vector<int> nums){
    sort(nums.begin(),nums.end());
    int ans=0;
    for(int i=0;i<nums.size();++i){
        if(nums[i]==i){
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}

int cal(int n,vector<int> nums){
    vector<vector<int>> grid(n,vector<int>(n,0));
    for(int x=0;x<n;++x){
        for(int y=0;y<n;++y){
            grid[x][y]=nums[x*n+y];
        }
    }
    int ans=0;
    for(int x=0;x<n;++x){
        for(int y=0;y<n;++y){
            for(int a=x;a<=n;++a){
                for(int b=y;b<=n;++b){
                    vector<int> temp;
                    for(int i=x;i<a;++i){
                        for(int j=y;j<b;++j){
                            temp.push_back(grid[i][j]);
                        }
                    }
                    ans+=cal_mex(temp);
                }
            }
        }
    }
    return ans;
}

void compete_solution()
{
    int n;
    cin >> n;
    /*vector<int> nums;
    for(int i=0;i<n*n;++i){
        nums.push_back(i);
    }
    int cnt=0;
    vector<int> ans;
    int maxv=0;
    while(true){
        int rst=cal(n,nums);
        if(rst>maxv){
            ans=nums;
            maxv=rst;
        }
        if(!next_permutation(nums.begin(),nums.end()))
            break;
    }
    cout<<maxv<<endl;
    print(ans);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<ans[i*n+j]<<" ";
        }
        cout<<endl;
    }*/
    /*deque<deque<int>> ans(n,deque<int>(n));
    int cur=0;
    for(int i=0;i<n;++i){
        for(int y=0;y<i;++y){
            ans[i][y]=cur;
            cur+=1;
        }
        for(int x=0;x<i;++x){
            ans[x][i]=cur;
            ++cur;
        }
        ans[i][i]=cur;
        ++cur;
    }
    for(int i=0;i<n/2;++i){
        ans.push_back(ans[0]);
        ans.pop_front();
    }
    for(int i=0;i<n/2;++i){
        for(auto &arr:ans){
            arr.push_back(arr[0]);
            arr.pop_front();
        }
    }   
    for(auto arr:ans){
        for(int x:arr){
            cout<<x<<" ";
        }
        cout<<endl;
    }*/
   vector<vector<int>> ans(n,vector<int>(n,0));
    int cur=n*n-1;
    ans[0][0]=cur--;
    int x=0,y=0;
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};
    int att=0;
    while(cur){
        //cout<<x<<" "<<y<<endl;
        int newX=x+dx[att%4];
        int newY=y+dy[att%4];
        if(newX>=0&&newX<n&&newY>=0&&newY<n){
            if(ans[newX][newY]==0){
                ans[newX][newY]=cur--;
                x=newX;
                y=newY;
                continue;
            }
        }
        ++att;
        newX=x+dx[att%4];
        newY=y+dy[att%4];
        if(newX>=0&&newX<n&&newY>=0&&newY<n){
            if(ans[newX][newY]==0){
                ans[newX][newY]=cur--;
                x=newX;
                y=newY;
                continue;
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    for(auto arr:ans)
        print(arr);




    
}