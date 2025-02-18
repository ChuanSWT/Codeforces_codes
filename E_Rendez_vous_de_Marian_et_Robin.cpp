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
    class meth
    {
        public:
        vector<vector<vector<int>>> edges;
        vector<int> value;
        int sz;
        meth(int sz,vector<vector<int>> o_edges,vector<int> horse):edges(sz+1),value(sz+1,0)
        {
            this->sz=sz+1;
            for(auto arr:o_edges)
            {
                edges[arr[0]].push_back({arr[1],arr[2]});
                edges[arr[1]].push_back({arr[0],arr[2]});
            }
            for(auto x:horse)
            value[x]=1;
        }
        vector<vector<int>> dijkstra(int n)
        {
            vector<vector<int>> d(sz,vector<int>(2,0x3f3f3f3f3f3f3f3f));
            priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
            if(value[n])
            pq.push({0,n,1});//当前距离 //当前节点 //是否骑马
            else
            pq.push({0,n,0});
            //cout<<endl;
            while(!pq.empty())
            {
                auto arr=pq.top();
                pq.pop();
                int cur_d=arr[0];
                int cur=arr[1];
                int ride=arr[2];
                //cout<<cur<<" "<<cur_d<<" "<<ride<<endl;
                if(cur_d>=d[cur][ride])
                continue;
                d[cur][ride]=min(d[cur][ride],cur_d);
                //cout<<cur<<" change "<<d[cur][ride]<<endl;
                if(ride==1)
                {
                    for(auto &xx:edges[cur])
                    {
                        int other=xx[0];
                        int ds=xx[1];
                        if(d[cur][1]+ds/2<d[other][1])
                        {
                            pq.push({d[cur][1]+ds/2,other,1});
                        }
                    }
                }
                else
                {
                    for(auto &xx:edges[cur])
                    {
                        int other=xx[0];
                        int ds=xx[1];
                        if(d[cur][0]+ds<d[other][0])
                        {
                            if(value[other]==1)
                            pq.push({d[cur][0]+ds,other,1});
                            else
                            pq.push({d[cur][0]+ds,other,0});
                        }
                    }
                }
            }
            return d;
        }
    };
    void compete_solution()
    {
        int n,m,h;
        cin>>n>>m>>h;
        vector<int> horse(h);
        for(int &x:horse)
            cin>>x;
        vector<vector<int>> edges(m,vector<int>(3));
        for(auto&arr:edges)
        cin>>arr[0]>>arr[1]>>arr[2];

        meth *test=new meth(n,edges,horse);
        vector<vector<int>> rst1=test->dijkstra(1);

        vector<vector<int>> rst2=test->dijkstra(n);

        long long minv=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=n;++i)
        {
            long long min1=min(rst1[i][0],rst1[i][1]);
            long long min2=min(rst2[i][0],rst2[i][1]);
            minv=min(minv,max(min1,min2));
        }
        /*for(auto arr:rst1)
        {
            print(arr);
        }
        for(auto arr:rst2)
        {
            print(arr);
        }*/
       if(minv>=0x3f3f3f3f3f3f3f3f)
       minv=-1;
        cout<<minv<<endl;


        

        
    }