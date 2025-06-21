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
int compete_solution_lc(int n, int m);

void debug(int n)
{
    cout << n << endl;
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

int lcm(int a, int b)
{
    int base = gcd(a, b);
    return a / base * b;
}
vector<int> make(int n)
{
    vector<int> nums;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                nums.push_back(i);
            else
            {
                nums.push_back(i);
                nums.push_back(n / i);
            }
        }
    }
    sort(nums.begin(), nums.end());
    return nums;
}
vector<int> ans_path;
vector<int> path;
void dfs(int cur, int target, int cost, int &ans)
{
    if (cost >= ans)
        return;
    if (cur == target)
    {
        if (cost < ans)
        {
            ans_path = path;
        }
        ans = min(ans, cost);
        return;
    }
    for (int i = 2; i <= 100; ++i)
    {
        path.push_back(i);
        dfs(i, target, cost + lcm(cur, i), ans);
        path.pop_back();
    }
}
void compete_solution()
{

    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout<<0<<'\n';
        return ;
    }
    vector<int> rst1 = make(n);
    vector<int> rst2 = make(m);
    // 需要2作为中转 可能一开始就到2
    // 或2作为因数间中转
    int minv = 0x3f3f3f3f3f3f3f3f;

    for (int i = 0; i < rst1.size(); ++i)
    {
        for (int j = 0; j < rst2.size(); ++j)
        {
            if (rst1[i] == 1 || rst2[j] == 1)
                continue;
            for (int flag1 = 0; flag1 <= 1; ++flag1)
            {
                for (int flag2 = 0; flag2 <= 1; ++flag2)
                {
                    for (int flag3 = 0; flag3 <= 1; ++flag3)
                    {
                        for (int flag4 = 0; flag4 <= 1; ++flag4)
                        {
                            if(flag1&&flag3)
                                continue;
                            int pre=n;
                            int sum = 0;
                            // 一般为 n 2 rst1 2 rst2 m
                            if (flag1)
                            {
                                sum+=lcm(pre,2);
                                pre=2;
                            }
                            if(sum>=minv)continue;
                            if (flag2)
                            {
                                sum+=lcm(pre,rst1[i]);
                                pre=rst1[i];
                            }if(sum>=minv)continue;
                            if (flag3)
                            {
                                sum+=lcm(pre,2);
                                pre=2;
                            }if(sum>=minv)continue;
                            if (flag4)
                            {
                                sum+=lcm(pre,rst2[j]);
                                pre=rst2[j];
                            }if(sum>=minv)continue;
                            sum+=lcm(pre,m);
                            minv = min(minv, sum);
                        }
                    }
                }
            }
        }
    }
    cout << minv << '\n';
}
int compete_solution_lc(int n, int m)
{
    if (n == m)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<int> rst1 = make(n);
    vector<int> rst2 = make(m);
    // 需要2作为中转 可能一开始就到2
    // 或2作为因数间中转
    int minv = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < rst1.size(); ++i)
    {
        for (int j = 0; j < rst2.size(); ++j)
        {
            if (rst1[i] == 1 || rst2[j] == 1)
                continue;
            for (int flag1 = 0; flag1 <= 1; ++flag1)
            {
                for (int flag2 = 0; flag2 <= 1; ++flag2)
                {
                    for (int flag3 = 0; flag3 <= 1; ++flag3)
                    {
                        for (int flag4 = 0; flag4 <= 1; ++flag4)
                        {

                            // 一般为 n 2 rst1 2 rst2 m
                            vector<int> temp;
                            temp.push_back(n);
                            if (flag1)
                            {
                                temp.push_back(2);
                            }
                            if (flag2)
                            {
                                temp.push_back(rst1[i]);
                            }
                            if (flag3)
                            {
                                temp.push_back(2);
                            }
                            if (flag4)
                            {
                                temp.push_back(rst2[j]);
                            }
                            temp.push_back(m);
                            int sum = 0;
                            for (int i = 1; i < temp.size(); ++i)
                            {
                                sum += lcm(temp[i - 1], temp[i]);
                            }
                            minv = min(minv, sum);
                        }
                    }
                }
            }
        }
    }
    return minv;
}
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
    /*for(int n=2;n<=10;++n){
        for(int m=n+1;m<=10;++m){
            int ans1=lcm(n,m);
            dfs(n,m,0,ans1);
            int ans2=compete_solution_lc(n,m);
            if(ans1!=ans2){
                cout<<n<<" "<<m<<endl;
                cout<<ans1<<" "<<ans2<<endl;
                print(ans_path);
            }
        }
    }*/
    return 0;
}
/*
7 9
29 30
2 3 9
7 15
35 36
2 3 15
9 11
37 40
3 2 11
9 13
41 44
3 2 13
9 17
49 52
3 2 17
9 19
53 56
3 2 19
11 15
43 48
43 48
2 3 15
2 3 15
13 15
47 54
2 3 15
15 17
55 64
3 2 17
15 19
59 68
3 2 19*/