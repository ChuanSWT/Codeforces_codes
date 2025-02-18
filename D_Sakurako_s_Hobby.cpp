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
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
class unionfind {
public:
    vector<int> f, rank;
    unionfind(int sz) : f(sz), rank(sz, 1) {
        for (int i = 0; i < f.size(); ++i)
            f[i] = i;
    }
    int find(int x) {
        if (f[x] != x)
            f[x] = find(f[x]); // 路径压缩
        return f[x];
    }
    void link(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if (fa == fb)
            return;
        if (rank[fa] < rank[fb]) {
            swap(fa, fb);
        }
        f[fb] = fa;
        if (rank[fa] == rank[fb]) {
            rank[fa]++; // 只有在两棵树高度相等时才增加高度
        }
    }
};
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int&x:nums)
        {
            cin>>x;
            --x;
        }
        string s;
        cin>>s;
        unionfind *test=new unionfind(n);
        for(int i=0;i<nums.size();++i)
        test->link(i,nums[i]);
        //0是黑色
        map<int,vector<int>> mp;
        map<int,int> ffmp;
        for(int i=0;i<nums.size();++i)
        {
            int f=test->find(i);
            mp[f].push_back(i);
            if(s[i]=='0')
            ++ffmp[f];
        }
        map<int,int> ans;
        for(auto p:mp)
        {
            for(int x:p.second)
            ans[x]=ffmp[p.first];
        }
        for(int i=0;i<nums.size();++i)
        cout<<ans[i]<<" ";
        cout<<endl;
        

        
    }