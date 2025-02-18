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
    int main()
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    class meth
    {
        public:
        vector<vector<int>> edges;//边
        vector<int> vals;//每个节点的值
        meth(vector<int> other_val,vector<int> p,int n):edges(n+1)
        {
            vals.push_back(0);
            for(int x:other_val)
            vals.push_back(x);
            for(int i=0;i<p.size();++i)
            {
                if(p[i]==-1)
                continue;
                edges[p[i]].push_back(i+1);
            }
            /*print(vals);
            for(auto arr:edges)
            {
                for(int num:arr)
                cout<<num<<" ";
                cout<<endl;
            }*/
        }
        int dfs(int cur)
        {
            if(edges[cur].empty())
            return vals[cur];
            int minv=INT_MAX;
            for(int &x:edges[cur])
            minv=min(minv,dfs(x));
            if(cur==1)
            return vals[cur]+minv;
            if(vals[cur]<minv)
            return (vals[cur]+minv)/2;
            else
            return minv;
        }
    };
    void compete_solution()
    {
        //尝试使用1下标开始，但是比较艰难
        int n;
        cin>>n;
        vector<int> vals(n,0);
        for(int &x:vals)
        cin>>x;
        vector<int> p(n,-1);
        for(int i=1;i<p.size();++i)
        cin>>p[i];
        meth test(vals,p,n);
        cout<<test.dfs(1)<<endl;
        

        
    }