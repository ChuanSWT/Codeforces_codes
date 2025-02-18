#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,m,a[N],deg[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        ++deg[u],++deg[v];
    }
    if(n==1)
    {
        cout<<a[1]<<"\n";
    }
    else
    {
        int ans=0;
        multiset<int> s;
        for(int i=1;i<=n;i++)
            if(deg[i]>1)
                ans=max(ans,a[i]);
            else
                s.insert(a[i]);
        if(s.size()>=2)
        {
            ans=max(ans,*prev(prev(s.end())));
        }
        cout<<ans<<"\n";
    }
}