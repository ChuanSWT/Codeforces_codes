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
    vector<int> get(int n)
    {
    vector<int> ans;
    for (int i = 1; i*i <= n; ++i)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if(i*i!=n)
            ans.push_back(n/i);
        }
    }
    return ans;
    }
    bool check1(string &s,string &p)
    {
        int err=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!=p[i%p.size()])
            ++err;
        }
        if(err>1)
        return false;
        else
        return true;
    }
    bool check(string &s,int length)
    {
        string t1;
        string t2;
        for(int i=0;i<length;++i)
        t1+=s[i];
        for(int i=s.size()-1;i>s.size()-1-length;--i)
        t2+=s[i];
        reverse(t2.begin(),t2.end());
        if(check1(s,t1)||check1(s,t2))
        return true;
        else
        return false;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> nums=get(n);
        int minv=n;
        int sz=nums.size();
        for(int i=sz-1;i>=0;--i)
        {
            if(check(s,nums[i]))
            minv=min(minv,nums[i]);
        }
        cout<<minv<<endl;
        

        
    }