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
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    class UnionFind
    {
        public:
        vector<int> f,rank;

        UnionFind(int sz):f(sz),rank(sz,1)
        {
            for(int i=0;i<f.size();++i)
            f[i]=i;
        }
        int find(int x)
        {
            if(f[x]!=x)
            f[x]=find(f[x]);
            return f[x];
        }
        void link(int a,int b)
        {
            int fa=find(a);
            int fb=find(b);
            if(fa==fb)
            return;
            if(rank[fa]<rank[fb])
            swap(fa,fb);
            f[fb]=fa;
            if(rank[fa]==rank[fb])
            ++rank[fa];
        }
        int cal(int left,int right)
        {
            map<int,int> mp;
            for(int i=left;i<right;++i)
            ++mp[find(i)];
            return mp.size();
        }
    };
    vector<int> make(int start,int length,int n)
    {
        vector<int> ans;
        while(start<=n)
        {
            ans.push_back(0);
            start+=length;
        }
        return ans;
    }
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> query(m,vector<int>(3));
        for(auto&arr:query)
        cin>>arr[0]>>arr[1]>>arr[2];
        
        map<vector<int>,vector<vector<int>>> mp;
        for(auto arr:query)
        {
            int t1=arr[0]%arr[1];//起步 不能为0
            if(t1==0)
            t1=arr[1];
            int t2=arr[1];//步长
            mp[{t1,t2}].push_back(arr);
        }
        UnionFind *test=new UnionFind(n+1);
        /*UnionFind *real=new UnionFind(n+1);
        for(auto arr:query)
        {
            for(int i=arr[0];i<=arr[0]+arr[1]*arr[2];i+=arr[1])
            real->link(arr[0],i);
        }
        cout<<real->cal(1,n+1)<<endl;*/
        for(auto &p:mp)
        {
            auto left=p.first;
            auto right=p.second;
            int start=left[0];
            int length=left[1];
            vector<int> d=make(start,length,n);
            for(auto &arr:right)
            {
                if(arr[2]==0)
                continue;
                int newS=(arr[0]-start)/length;//差分第几个 0->
                ++d[newS];
                if(newS+arr[2]<d.size())
                --d[newS+arr[2]];
            }
            vector<int> ud=d;
            for(int i=0;i<ud.size();++i)
            ud[i]=start+i*length;
            vector<int> rst;
            int s=0;
            for(int i=0;i<d.size();++i)
            {
                s+=d[i];
            if(s!=0)
            rst.push_back(ud[i]);
            else 
            rst.push_back(-1);
            }
            //print(rst);
            for(int i=1;i<rst.size();++i)
            {
                if(rst[i-1]!=-1)
                test->link(rst[i-1],ud[i]);
            }
        }
        int ans=test->cal(1,n+1);
        cout<<ans<<endl;

        
        

        
    }