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
        int roundc=1;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    class meth
    {
        public:
        vector<vector<int>> scs;
        vector<int> val;
        int ans;
        vector<bool> mark;
        meth(vector<vector<int>>& other)
        {
            scs=other;
            val=vector<int>(other[0].size(),0);
            mark=vector<bool>(other.size(),false);
            ans=0x3f3f3f3f;
        }
        bool check(vector<int> nums)
        {
            for(int n:nums)
            if(n==0)
            return false;
            return true;
        }
        void dfs(int cur)
        {
            if(cur>=ans)
            return ;
            if(check(val))
            {
                ans=min(ans,cur);
                return;
            }
            for(int i=0;i<scs.size();++i)
            {
                if(mark[i]==false)
                {
                    /*for(bool b:mark)
                    cout<<b<<" ";
                    cout<<endl;*/
                    mark[i]=true;
                    for(int j=0;j<scs[i].size();++j)
                    if(scs[i][j])
                    ++val[j];
                    dfs(cur+1);
                    for(int j=0;j<scs[i].size();++j)
                    if(scs[i][j])
                    --val[j];
                    mark[i]=false;
                }
            }
        }
    };
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> scs;
        for(int i=0;i<n;++i)
        {
            vector<int> temp;
            string s;
            cin>>s;
            for(int i=0;i<s.size();++i)
            temp.push_back(s[i]=='o'?1:0);
            scs.push_back(temp);
        }
        /*for(auto a:scs)
        {
            for(auto b:a)
            cout<<b<<" ";
            cout<<endl;
        }*/
        //cout<<scs.size()<<endl;
        meth test(scs);
        test.dfs(0);
        cout<<test.ans<<endl;
        
        
    }