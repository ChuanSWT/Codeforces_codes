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
        int roundc=1;
        //cin >> roundc;
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
        vector<int> a(n,-1);
        for(int i=1;i<a.size();++i)
        {
        cin>>a[i];
        --a[i];
        }
        vector<vector<int>> o_edges(m,vector<int>(2));
        for(auto&arr:o_edges)
        {
        cin>>arr[0]>>arr[1];
        --arr[0];
        --arr[1];
        }
        vector<vector<int>> edges(n);
        for(auto arr:o_edges)
        {
            edges[arr[0]].push_back(arr[1]);
            edges[arr[1]].push_back(arr[0]);
        }
        vector<int> d(n,-1);
        d[0]=0;

        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto x:edges[node])
            {
                while(d[x]==-1)
                {
                    d[x]=d[node]+1;
                    q.push(x);
                    x=a[x];

                }
            }
        }
        for(int i=1;i<d.size();++i)
        cout<<d[i]<<" ";
        cout<<endl;


        
        

        
    }