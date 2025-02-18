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
    vector<int> cal(vector<int> arr)
    {
        vector<int> ans(2,-1);
    int ori_sz=arr.size();
            set<int> st;
            for(int x:arr)
            st.insert(x);
            arr={};
            for(int x:st)
            arr.push_back(x);
            int no=-1;
            for(int i=0;i<arr.size();++i)
            {
                if(arr[i]!=i)
                {
                no=i;
                arr.push_back(no);
                break;
                }
            }
            if(no==-1)
            {
                no=arr.size();
            arr.push_back(no);
            }
            ans[0]=no;
           for(int x:arr)
            st.insert(x);
            arr={};
            for(int x:st)
            arr.push_back(x);
            //print(arr);
            int reward=0;
            for(int i=0;i<arr.size();++i)
            {
                if(arr[i]!=i)
                {
                reward=i;
                break;
                }
            }
            if(reward==0)
            reward=arr.size();
            ans[1]=reward;
            return ans;

    }
    class unionFind
    {
        public:
        vector<int> f;
        vector<int> rank;
        unionFind(int n):f(n),rank(n,1)
        {
            for(int i=0;i<f.size();++i)
            f[i]=i;
        }
        int find(int a)
        {
            if(f[a]!=a)
            f[a]=find(f[a]);
            return f[a];
        }
        void link(int a,int b)
        {
            int fa=find(a);
            int fb=find(b);
            if(fa==fb)
            return;
            if(rank[fa]<rank[fb])
            swap(fa,fb);
            if(rank[fa]==rank[fb])
            {
                f[fb]=fa;
                ++rank[fa];
            }
        }
    };
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arrs(n);
        for(int i=0;i<arrs.size();++i)
        {
            int sz;
            cin>>sz;
            vector<int> nums(sz);
            for(int&x:nums)
            cin>>x;
            arrs[i]=nums;
        }


        vector<vector<int>> rst;
        for(auto arr:arrs)
        {
            rst.push_back(cal(arr));

        }
        //for(auto arr:rst)
        //print(arr);
        int max_sz=0;
        
        for(auto arr:arrs)
        {
            max_sz=max(max_sz,(int)arr.size());
        }
        unionFind *test=new unionFind(max_sz+10);//safe 存储跳转数据
        for(auto arr:rst)
        test->link(arr[0],arr[1]);
        map<int,vector<int>> mp;
        for(int i=0;i<test->f.size();++i)//归到并查集分块
        {
            int fi=test->find(i);
            mp[fi].push_back(i);
        }

        map<int,int> leader;//每个数对应的最大值
        for(auto p:mp)
        {
            int maxv=0;
            for(auto x:p.second)
            {
                maxv=max(maxv,x);
            }
            for(auto x:p.second)
            leader[x]=maxv;
        }
        long long feed=0;
        for(auto arr:rst)
        feed=max(feed,(long long)arr[1]);
        long long ans=0;
        if(feed>=m)
        cout<<(m+1)*feed<<endl;
        else
        {
            long long sum=0;
            sum=(m)*(m+1ll)/2ll+(feed)*(feed+1ll)/2ll;
            cout<<sum<<endl;
        }
        
        

        
    }