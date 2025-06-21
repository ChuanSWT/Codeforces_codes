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
using namespace std;
#define int long long
#define double long double
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

bool check(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int &x1 = a[0];
    int &y1 = a[1];
    int &x2 = b[0];
    int &y2 = b[1];
    int &x3 = c[0];
    int &y3 = c[1];
    if ((y2 - y1)*(x3 - x1) == (y3 - y1) *(x2 - x1) )
        return false;
    return true;
}
double cal_matrix(vector<vector<double>> &a,vector<vector<double>> &b){
    double sum=0;
    for(int i=0;i<3;++i){
        sum+=a[1][i]*b[i][0];
    }
    return sum;
    /*vector<vector<double>> ans(a.size(),vector<double>(b[0].size(),0));
    for(int x=0;x<ans.size();++x){
        for(int y=0;y<ans[0].size();++y){
            for(int i=0;i<a[0].size();++i){
                ans[x][y]+=a[x][i]*b[i][y];
            }
        }
    }
    return ans;*/
}
//
double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    // 计算三条边长
    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    // 计算半周长
    double s = (a + b + c) / 2.0;

    // 计算面积
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}
void compete_solution()
{
    int n;
    cin >> n;
    vector<vector<int>> points = cin_matrix(n, 2);
    double minv = 1e18;
    //cout<<"hi"<<endl;return;
    for (int i = 0; i < points.size(); ++i)
    {
        vector<int> &a = points[i];
        double x1 = a[0];
        double y1 = a[1];
        for (int j = i + 1; j < points.size(); ++j)
        {
            vector<int> &b = points[j];
            double x2 = b[0];
            double y2 = b[1];
            for (int k = j + 1; k < points.size(); ++k)
            {      
                vector<int> &c = points[k];
                if (!check(a, b, c))
                    continue;
                // 计算面积,考虑旋转变换和平移变换？
                double x3 = c[0];
                double y3 = c[1];
                minv=min(minv,triangleArea(x1,y1,x2,y2,x3,y3));

            }
        }
        
    }
    if(minv>=1e15){
        cout<<-1<<'\n';
        return;
    }
    cout<<fixed<<setprecision(10)<<minv<<'\n';
}