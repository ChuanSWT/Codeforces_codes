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
    #include<iomanip>
    #include<numeric>
    #define int long long
    using namespace std;
    void compete_solution();
    template <typename T>
    void print(const std::vector<T>& vec) {
    for (auto element : vec) {
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
    signed main()
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
        int roundc=1;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> dmg(n);
        vector<int> def(n);
        for(auto&x:dmg)
        cin>>x;
        for(auto&x:def)
        cin>>x;
        dmg.push_back(0);
        def.push_back(0x3f3f3f3f3f3f3f3f);
        //邻居关系表
        vector<int> left(n+1,n);
        vector<int> right(n+1,n);
        
        left[0]=n;
        for(int i=1;i<n;++i)
            left[i]=i-1;
        right[n-1]=n;
        for(int i=0;i+1<n;++i)
            right[i]=i+1;
        vector<int> cur;
        vector<int> nxt;
        for(int i=0;i<n;++i)
        if(def[i]<dmg[left[i]]+dmg[right[i]])
        nxt.push_back(i);
        vector<int> mark(n+1,0);
        vector<int> ans;
        for(int time=1;time<=n;++time)
        {
            cur=nxt;
            nxt.clear();
            ans.push_back(cur.size());
            vector<int> checks;
            for(int cur_node:cur)
            {
                //cout<<cur_node<<" ";
                mark[cur_node]=1;
                int left_node=left[cur_node];
                int right_node=right[cur_node];
                right[left_node]=right_node;
                left[right_node]=left_node;
                checks.push_back(left_node);
                checks.push_back(right_node);
            }
            //cout<<endl;
            for(int x:checks)
            {
                if(mark[x])
                continue;
                if(dmg[left[x]]+dmg[right[x]]>def[x])
                {
                //cout<<x<<" "<<dmg[left[x]]<<" "<<dmg[right[x]]<<endl;
                mark[x]=1;
                nxt.push_back(x);
                }
            }


        }
        print(ans);
        
        

        
    }