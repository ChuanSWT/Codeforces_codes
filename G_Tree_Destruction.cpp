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
        vector<int> lock;
        vector<int> mark;
        vector<vector<int>> choice;
        int n;
        meth(int sz,vector<vector<int>> other):edges(sz),lock(sz,0),choice(sz),mark(sz,0)
        {
            n=sz;
            for(auto arr:other)
            {
                //cout<<arr[0]<<" "<<arr[1]<<endl;
                edges[arr[0]].push_back(arr[1]);
                edges[arr[1]].push_back(arr[0]);
                ++lock[arr[0]];
                ++lock[arr[1]];
            }
        }

        int bfs()
        {
            vector<int> db(n,0);
            int ans=0;
            queue<int> qu;
            for(int i=0;i<n;++i)
                if(lock[i]==1)
                    qu.push(i);
            while(!qu.empty())
            {
                int node=qu.front();
                qu.pop();
                if(mark[node])
                continue;
                mark[node]=1;
                
                //cout<<node<<endl;
                //for(auto arr:choice)
                //print(arr);
                //cout<<endl;
                int zero_ans=choice[node].size();
                sort(choice[node].rbegin(),choice[node].rend());
                int one_ans=0;
                if(choice[node].size()>=1)
                {
                    one_ans=choice[node][0]+(int)choice[node].size()-1;
                }
                int two_ans=0;
                if(choice[node].size()>=2)
                {
                    two_ans=choice[node][0]+choice[node][1]+(int)choice[node].size()-2;
                }
                
                for(int x:edges[node])
                {
                    ans=max(ans,db[x]+1);
                    if(mark[x])
                    continue;
                    //cout<<x+1<<endl;
                    //cout<<zero_ans<<" "<<one_ans<<endl;
                    choice[x].push_back(max(zero_ans,one_ans));
                    --lock[x];
                    if(lock[x]==1)
                    {
                    qu.push(x);
                    //cout<<node+1<<" push "<<max(zero_ans,one_ans)<<endl;
                    }
                }
                //print(choice[node]);
                ans=max(ans,zero_ans);
                ans=max(ans,one_ans);
                ans=max(ans,two_ans);
                db[node]=max(db[node],two_ans);
            }
            return ans;
        }
    };
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<vector<int>> edges(n-1,vector<int>(2));
        for(auto&arr:edges)
        {
        cin>>arr[0]>>arr[1];
        --arr[0];
        --arr[1];
        }
        meth* test=new meth(n,edges);
        //return;
        
        int rst=test->bfs();
        //print(test->choice[2]);
        cout<<rst<<endl;
        

        
    }