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
        vector<int> nums;
        set<int> st;
        vector<int> mark;
        int maxv=0;
        meth(vector<int> other):mark(other.size(),0)
        {
            nums=other;
            for(int i=0;i<other.size();++i)
            st.insert(i);
        }
        void dfs(int cur)
        {
            maxv=max(maxv,cur);
            int index=-1;
            auto p=st.find(0);
            int t=0;
            for(int i=0;i<nums.size()-1;++i)
            {
                if(mark[i])
                continue;
                p=st.find(i);
                ++index;
                ++p;                
                if(p==st.end())
                continue;

                if(nums[i]==index+1)
                {
                    t=*p;
                    mark[i]=1;
                    mark[t]=1;
                    //cout<<i<<endl;
                    st.erase(i);
                    st.erase(t);
                    dfs(cur+1);
                    mark[i]=0;
                    mark[t]=0;
                    st.insert(i);
                    st.insert(t);
                }
            }
        }
    };
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n,0);
        for(int i=0;i<n;++i)
        cin>>nums[i];
        meth test(nums);
        test.dfs(0);
        cout<<test.maxv<<endl;

        
        
    }