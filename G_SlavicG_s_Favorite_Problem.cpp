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
        //ios_base::sync_with_stdio(false); 
        //cin.tie(NULL) ;
            int roundc;
            cin >> roundc;
            for (int ic = 0; ic < roundc; ++ic)
            {
                //cout<<ic<<endl;
                compete_solution();
            }
            return 0;
        }
        class meth
        {
            public:
            int n;
            vector<vector<vector<int>>> edges;
            vector<int> mark;
            vector<int> rst;
            int a;
            int b;
            meth(int on,int oa,int ob,vector<vector<int>> other):edges(on),mark(on,0),rst(on,-1)
            {
                n=on;
                a=oa;
                b=ob;
                for(auto arr:other)
                {
                    edges[arr[0]].push_back({arr[1],arr[2]});
                    edges[arr[1]].push_back({arr[0],arr[2]});
                }
            }
            void check()
            {
                vector<int> ori=rst;
                dfs(a,0,0);
                //print(rst);
                if(rst[b]==0)
                {
                    cout<<"YES"<<endl;
                    return;
                }
                vector<int> rst1=rst;
                rst=ori;
                //cout<<rst1.size()<<endl;
                for(int &x:mark)
                x=0;
                dfs(b,0,1);
                //print(rst);
                vector<int> rst2=rst;
                rst=ori;
                set<int> st;
                for(int i=0;i<n;++i)
                {
                    if(i==b)
                    continue;
                    if(rst2[i]==-1)
                    continue;
                    st.insert(rst2[i]);
                }
                
                for(int i=0;i<n;++i)
                {
                    if(i==b)
                    continue;
                    if(i==-1)
                    continue;
                    if(st.find(rst1[i])!=st.end())
                    {
                        cout<<"YES"<<endl;
                        return;
                    }
                }
                cout<<"NO"<<endl;
            }
            void dfs(int node,int val,int cas)
            {
                rst[node]=val;
                //cout<<node<<endl;
                if(cas==0&&node==b)
                return;
                for(auto &arr:edges[node])
                {
                    //cout<<"hi"<<endl;
                    if(mark[arr[0]]==0)
                    {
                        mark[arr[0]]=1;
                        dfs(arr[0],val^arr[1],cas);
                    }
                }
            }
        };
        void compete_solution()
        {
            int n,a,b;
            cin>>n>>a>>b;
            vector<vector<int>> edges;
            for(int i=0;i<n-1;++i)
            {
                int a1,b1,c1;
                cin>>a1>>b1>>c1;
                edges.push_back({a1-1,b1-1,c1});
            }
            meth test(n,a-1,b-1,edges);
            test.check();

            
        }