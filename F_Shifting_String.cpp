//ChuanSWT is looking at you
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
//以其作为循环子小结长度，是否可行？
bool check(string &s,int k)
{
    for(int i=0;i<k;++i)
    {
        for(int j=i;j<s.size();j+=k)
        {
            if(s[i]!=s[j])
            return false;
        }
    }
    return true;
}
vector<int> cal(int n)
{
    vector<int> ans;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            if(i*i==n)
            {
                ans.push_back(i);
            }
            else
            {
                ans.push_back(n/i);
                ans.push_back(i);
            }
        }
    }
    return ans;
}
long long sp_cal(long long a,long long b)
{
    long long base=gcd(a,b);
    return a*b/base;
}
    void compete_solution()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> nums(n);
        for(int &x:nums)
            cin>>x;
        
        for(auto&x:nums)
            --x;
        //okcool 循环节
        vector<int> mark(n,0);
        set<long long> st;
        for(int i=0;i<n;++i)
        {
            if(mark[i])
            continue;
            mark[i]=1;
            vector<int> path;
            path.push_back(i);
            while(nums[path.back()]!=path[0])
            {
                path.push_back(nums[path.back()]);
                mark[path.back()]=1;
            }
            //灭水的135小节--子循环节
            string sub_s;
            for(int idx:path)
            sub_s+=s[idx];
            vector<int> rst=cal(path.size());
            int minv=path.size();
            for(int x:rst)
            {
                if(check(sub_s,x))
                minv=min(minv,x);
            }
            st.insert(minv);
        }
        long long ans=1;
        for(long long x:st)
        {
            ans=sp_cal(ans,x);
        }
        cout<<ans<<endl;
        
    }