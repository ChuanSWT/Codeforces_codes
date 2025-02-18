#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
    if(sum[n]!=0){
        cout<<"YES\n";
        return;
    }else{
        set<int> se;
        for(int i=1;i<n;i++){
            if(sum[i]){
                if(!se.empty()&&se.size()!=se.count(sum[i])){
                    cout<<"YES\n";
                    return;
                }
                se.insert(sum[i]);
            }
        }
        se.clear();
        if(sum[n]) se.insert(sum[n]);
        for(int i=n-1;i>=1;i--){
            if(sum[i]){
                if(!se.empty()&&se.size()!=se.count(sum[i])){
                    cout<<"YES\n";
                    return;
                }
                se.insert(sum[i]);
            }
        }
        cout<<"NO\n";
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
}