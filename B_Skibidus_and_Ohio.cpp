#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
	FastIO;
	int t;cin>>t;
	while(t--){
	    string w;
	    cin>>w;
	    int cnt=0;
	    bool ch=0;
	    int x =w.size();
	    for(int i=0;i<w.size();i++){
	        
	        if(w[i] == w[i+1]){
	            cnt++;
	           ch=1;
	}
	    }
	if(ch){
	    cout<<1<<endl;
	}
	else{
	    cout<<x<<endl;
	}
	    }
}