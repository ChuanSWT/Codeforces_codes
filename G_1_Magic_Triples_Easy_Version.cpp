#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
#define MOD 1000000007
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main()
{
    map<int,int> mark;
    int round;
    cin >> round;
    vector<int> ans;
    for (int i = 0; i < round; ++i)
    {
        int n=0;
        vector<int> nums;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        for(int &n:nums)
        mark[n]++;
        long long sum=0;
        long long t=1;
        int t1,t2,t3;
        set<int> st;
        for(int n:nums)
        st.insert(n);
        for(int num:st)
        {
            //cout<<num<<endl;
            t1=mark[num];
            mark[num]--;
            for(int j=1;j*j<=1e9/num;++j)
            {
                t2=mark[num*j];
                mark[num*j]--;
                t3=mark[num*j*j];
                mark[num*j*j]--;
                t=1;
                t*=t1;
                t*=t2;
                t*=t3;
                sum+=t;
                mark[num*j]++;
                mark[num*j*j]++;
            }
            mark[num]++;
        }
        cout<<sum<<endl;
        for(int &n:nums)
        mark[n]--;
    }
    for (auto n : ans)
    {
        cout << n << endl;
    }
    return 0;
}
