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
        int n,m;
        cin>>n>>m;
        vector<int> ans;
        int cur=1;
                int index=m+1;
        --m;
        while(cur<=m)
        {
            m-=cur;
            ans.push_back(cur);
            cur*=2;
        }
        while(m)
        {
            while(cur>m)
            cur/=2;
            m-=cur;
            ans.push_back(cur);
        }
        ans.push_back(index);
        if(index==2)
        ans.push_back(3);
        while(ans.back()+m-1<=n)
        ans.push_back(ans.back()+m-1);
        cout<<ans.size()<<endl;
        for(int num:ans)
        cout<<num<<" ";
        cout<<endl;
    }