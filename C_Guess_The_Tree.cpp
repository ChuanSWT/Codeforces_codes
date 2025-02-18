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
    class unionfind {
public:
    vector<int> f, rank;
    unionfind(int sz) : f(sz), rank(sz, 1) {
        for (int i = 0; i < f.size(); ++i)
            f[i] = i;
    }
    int find(int x) {
        if (f[x] != x)
            f[x] = find(f[x]); // 路径压缩
        return f[x];
    }
    void link(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if (fa == fb)
            return;
        if (rank[fa] < rank[fb]) {
            swap(fa, fb);
        }
        f[fb] = fa;
        if (rank[fa] == rank[fb]) {
            rank[fa]++; // 只有在两棵树高度相等时才增加高度
        }
    }
};

    class meth
    {
        public:
        int n;
        set<vector<int>> edges;
        unionfind *block;
        meth(int num)
        {
            block=new unionfind(num+1);
            n=num;
            //nodes.insert(1);
        }
        void cal()
        {
            for(int i=2;i<=n;++i)
            {
                int fa=block->find(1);
                int fb=block->find(i);
                if(fa==fb)
                continue;
                dfs(1,i);
            }
        }
        void dfs(int left,int right)
        {
            int fl=block->find(left);
            int fr=block->find(right);
            if(fl==fr)
            return;
            if(left>right)
            swap(left,right);
            cout<<"? "<<left<<" "<<right<<endl;
            cout.flush();
            int rec;
            cin>>rec;
            if(rec==left)
            {
            edges.insert({left,right});
            block->link(left,right);
            }
            else
            {
                dfs(left,rec);
                dfs(rec,right);
            }
        }

    };
    void compete_solution()
    {
        int n;
        cin>>n;
        meth *test=new meth(n);
        test->cal();
        set<vector<int>> ans=test->edges;
        cout<<"! ";
        for(auto p:ans)
        {
            cout<<p[0]<<" "<<p[1]<<" ";
        }
        cout<<endl;
        cout.flush();
        

        
    }