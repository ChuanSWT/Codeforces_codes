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
        vector<vector<int>> edges;
        vector<int> mark;
        vector<int> d;
        int n;
        int maxd=0;
        //num 总结点个数
        meth(int num,vector<vector<int>> other):edges(num),mark(num,0),d(num,0)
        {
            n=num;
            for(auto arr:other)
            {
                edges[arr[0]-1].push_back(arr[1]-1);
                edges[arr[1]-1].push_back(arr[0]-1);
            }
        }
        void cal()
        {
            vector<int> emp=mark;
            for(int i=0;i<n;++i)
            {
                dfs(i,0);
            }
        }
        int dfs(int node,int dep)
        {

        }
    };
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<int> mark(m,0);
        for(int &x:mark)
        cin>>x;
        vector<vector<int>> edges(n,vector<int>(2,0));
        for(auto& arr:edges)
        {
            cin>>arr[0];
            cin>>arr[1];
        }


        
        

        
    }