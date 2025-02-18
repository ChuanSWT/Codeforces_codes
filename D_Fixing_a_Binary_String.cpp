#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<set>
#include<tuple>
using namespace std;
#define MOD 1000000007
void compete_solution();
int main()
{
    int roundc;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic)
    {
        compete_solution();
    }
    return 0;
}
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
vector<int> make_vector(int length)
{
    vector<int> a(length,0);
    for(int i=0;i<length;++i)
    cin>>a[i];
    return a;
}
vector<int> div(string &s)
{
    s+='A';
    int left=0;
    vector<int>cache;
    for(int i=1;i<s.size();++i)
    {
        if(s[i]!=s[i-1])
        {
            cache.push_back(i-left);
            left=i;
        }
    }
    s.pop_back();
    return cache;
}
void compete_solution()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> cache;
    s+='A';
    int left=0;
    for(int i=1;i<s.size();++i)
    {
        if(s[i]!=s[i-1])
        {
            cache.push_back(i-left);
            left=i;
        }
    }
    s.pop_back();
    int danger=0;
    for(int n:cache)
    if(n!=k)
    ++danger;
    if(danger==0)
    {
        if(cache.size()%2==0||cache.size()==1)
        cout<<k<<endl;
        else
        cout<<k*2<<endl;
        return;
    }
    int sum=cache.back();
    int temp=-1;
    for(int i=cache.size()-2;i>=0;--i)
    {
        if(cache[i]!=k)
        {
            if(cache[i]>k)
            temp=sum+k;
            break;
        }
        sum+=cache[i];
    }
    bool err=false;
    string s1,s2;
    s1=s.substr(s.size()-sum,sum);
    string t1=s.substr(0,s.size()-sum);
    reverse(t1.begin(),t1.end());
    s1+=t1;
    //cout<<s1<<endl;
    vector<int> check1=div(s1);
    for(int n:check1)
    if(n!=k)
    {
    err=true;
    break;
    }
    if(!err)
    {
        cout<<s.size()-sum<<endl;
        return;
    }
    err=false;

    if(temp!=-1)
    s2=s.substr(s.size()-temp,temp);
    string t2=s.substr(0,s.size()-temp);
    reverse(t2.begin(),t2.end());
    s2+=t2;
    //cout<<s1<<endl;
    vector<int>check2=div(s2);
    for(int n:check2)
    if(n!=k)
    {
    err=true;
    break;
    }
    if(!err)
    {
        cout<<s.size()-temp<<endl;
        return;
    }
    if(err)
    cout<<-1<<endl;
}
//cout<<s1<<endl;
    //cout<<s2<<endl;
    
    //cout<<sum<<endl;