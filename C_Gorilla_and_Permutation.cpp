    #include<iostream>
    #include<vector>
    #include<string>
    #include<map>
    #include<unordered_map>
    #include<cmath>
    #include<algorithm>
    #include<set>
    #include<tuple>
    #include<cmath>
    #include<queue>
    using namespace std;
    void compete_solution();
    int gcd(int x, int y)
    {
    if (y == 0)
        return x;
    return gcd(y, x % y);
    }   
    int main()
    {
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL) ;
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        int n,k,m;
        cin>>n>>k>>m;

        vector<int> ans(n,0);
        for(int i=0;i<ans.size();++i)
        ans[i]=i+1;
        reverse(ans.begin(),ans.end());

        reverse(ans.rbegin(),ans.rbegin()+k);
        for(int num:ans)
        cout<<num<<" ";
        cout<<endl;

        
    }