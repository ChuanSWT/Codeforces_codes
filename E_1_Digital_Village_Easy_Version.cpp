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
    set<int> users;
    class meth
    {
        public:
        vector<vector<vector<long long>>> edges;
        vector<vector<long long>> d;
        int n;
        meth(int sz,vector<vector<int>> o_edges):edges(sz),d(sz,vector<long long>(sz,0x3f3f3f3f3f3f3f3f))
        {
            n=sz;
            for(auto arr:o_edges)
            {
                edges[arr[0]].push_back({arr[1],arr[2]});
                edges[arr[1]].push_back({arr[0],arr[2]});
            }
        }
        void cal_d()
        {
            for(int i=0;i<n;++i)
                dijkstra(i);

            //所有不上网的都计为0
            for(int x=0;x<d.size();++x)
            {
                for(int y=0;y<d[0].size();++y)
                    if(users.find(y)==users.end())
                        d[x][y]=0;
            }
        }
        void dijkstra(int root)
        {
            priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
            pq.push({0,root});//当前距离 当前节点
            while(!pq.empty())
            {
                auto arr=pq.top();
                pq.pop();
                int cur_d=arr[0];
                int cur=arr[1];
                if(cur_d>=d[cur][root])
                continue;
                d[cur][root]=cur_d;
                for(auto edge:edges[cur])
                {
                    int dist=edge[0];
                    int edge_d=edge[1];
                    if(max(edge_d,cur_d)<d[dist][root])
                    pq.push({max(edge_d,cur_d),dist});
                }
            }
        }

    };
    int cal(vector<int> &old,vector<int> &a)
    {
        int ans=0;
        for(int i=0;i<old.size();++i)
        {
            if(a[i]<old[i])
            ans+=old[i]-a[i];
        }
        return ans;
    }
    void compete_solution()
    {
        users.clear();
        int n,m,p;
        cin>>n>>m>>p;
        for(int i=0;i<p;++i)
        {
            int t;
            cin>>t;
            --t;
            users.insert(t);
        }
        vector<vector<int>> edges(m,vector<int>(3));
        for(auto&arr:edges)
        {
        cin>>arr[0]>>arr[1]>>arr[2];
        --arr[0];--arr[1];
        }
        meth *test=new meth(n,edges);
        test->cal_d();
        //for(auto arr:test->d)
        //print(arr);
        //当他有服务器的时候，他就是0延迟
        //但当他没有时，则取最大延迟
        vector<vector<long long>> d=test->d;
        set<int> selected;

        vector<int> cur_d(n,0);
        for(int i=0;i<cur_d.size();++i)
        {
            if(users.find(i)!=users.end())
            cur_d[i]=1e13;
        }
        for(int i=0;i<p;++i)//枚举安装多少个基站
        {
            int index=-1;
            map<int,vector<int>> mp;
            int maxv=0;
            for(int x:users)
            {
                if(selected.find(x)!=selected.end())
                continue;
                int temp=cal(cur_d,d[x]);
                if(temp>maxv)
                {
                    index=x;
                    maxv=temp;
                }
            }
            for(int i=0;i<cur_d.size();++i)
            cur_d[i]=min(cur_d[i],d[index][i]);
            int sum=0;
            for(int x:cur_d)
            sum+=x;
            cout<<sum<<" ";
            selected.insert(index);
        }
        for(int i=p;i<n;++i)
        cout<<0<<" ";
        cout<<endl;
        return;

        



        
        

        
    }