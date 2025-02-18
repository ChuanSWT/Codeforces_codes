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
    #define int long long
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
        //cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    class meth
    {
        public:
        vector<int> spent;
        vector<int> masks;
        vector<vector<int>> edges;
        vector<int> status;
        vector<int> lock;
        meth(int sz,vector<vector<int>> other,vector<vector<int>> o_status):masks(sz+1,1),edges(sz+1),spent(sz+1),
        status(sz+1),lock(sz+1,0)
        {
            for(auto arr:other)
            {
            edges[arr[0]].push_back(arr[1]);
            edges[arr[1]].push_back(arr[0]);
            }
            for(int i=0;i<o_status.size();++i)
            {
                spent[i+1]=o_status[i][0];
                status[i+1]=o_status[i][2]-o_status[i][1];
            }
            take_value();
            make_tree();
        }   
        void take_value()//子节点一定要比累计根节点最小值小，否则无效
        {
            set<int> st;
            queue<vector<int>> qu;
            qu.push({1,spent[1]});
            while(!qu.empty())
            {
                auto cur=qu.front();
                qu.pop();
                st.insert(cur[0]);
                int cur_spent=cur[1];
                for(int x:edges[cur[0]])
                {
                    if(st.find(x)!=st.end())
                        continue;
                    int x_spent=spent[x];
                    if(x_spent>=cur_spent)
                        spent[x]=-1;
                    qu.push({x,min(cur_spent,x_spent)});
                }
            }
        }
        void make_tree()
        {
            set<int> st;
            vector<vector<int>> newEdges;
            queue<int> qu;
            qu.push(1);
            while(!qu.empty())
            {
                int cur=qu.front();
                qu.pop();
                st.insert(cur);
                for(int x:edges[cur])
                {
                    if(st.find(x)!=st.end())
                        continue;
                    newEdges.push_back({x,cur});
                    qu.push(x);
                }
            }
            for(auto&arr:edges)
            arr.clear();
            for(auto arr:newEdges)
            {
                edges[arr[0]].push_back(arr[1]);
                ++lock[arr[1]];
            }

        }
        long long cal()
        {
            long long ans=0;
            queue<vector<int>> qu;//节点编号 待解决的0，待解决的1
            for(int i=1;i<lock.size();++i)
            if(lock[i]==0)
            {
            vector<int> temp={i,0,0};
            if(status[i]==1)
            temp[1]=1;
            if(status[i]==-1)
            temp[2]=1;
            qu.push(temp);
            }

            vector<vector<int>> jobs(lock.size(),vector<int>(2,0));//每个节点开启时，待解决的0和1
            for(int i=1;i<lock.size();++i)
            {
                if(status[i]==1)
                ++jobs[i][0];
                if(status[i]==-1)
                ++jobs[i][1];
            }
            while(!qu.empty())
            {
                vector<int> temp=qu.front();
                qu.pop();
                int cur=temp[0];
                int cur_zero=temp[1];
                int cur_one=temp[2];

                if(spent[cur]!=-1)
                {
                    int k=min(cur_zero,cur_one);
                    cur_zero-=k;
                    cur_one-=k;
                    ans+=2*k*spent[cur];
                }
                int parent=edges[cur][0];
                jobs[parent][0]+=cur_zero;
                jobs[parent][1]+=cur_one;
                --lock[parent];
                if(lock[parent]==0)
                {
                    qu.push({parent,jobs[parent][0],jobs[parent][1]});
                }

            }
            return ans;
        }
    };
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<vector<int>> nodes(n,vector<int>(3));
        vector<vector<int>> edges(n-1,vector<int>(2));
        for(auto&arr:nodes)
        cin>>arr[0]>>arr[1]>>arr[2];
        for(auto&arr:edges)
        cin>>arr[0]>>arr[1];
        int zero=0;
        int one=0;
        int ned_zero=0;
        int ned_one=0;
        for(auto arr:nodes)
        {
            if(arr[1]==0)
            ++zero;
            if(arr[1]==1)
            ++one;
            if(arr[2]==0)
            ++ned_zero;
            if(arr[2]==1)
            ++ned_one;

        }

        if(zero!=ned_zero||one!=ned_one)
        {
            //cout<<zero<<" "<<ned_zero;
            cout<<-1<<endl;
            return;
        }
        if(n==1)
        {
            cout<<0<<endl;
            return;
        }
        meth *test=new meth(n,edges,nodes);
        cout<<test->cal()<<endl;
        
        

        
    }