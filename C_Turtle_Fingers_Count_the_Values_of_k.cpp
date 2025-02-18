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
    void dfs(int baseA,int baseB,int left,int curA,int curB,set<int> &ans,set<int>& mem)
    {
        int sum=curA*curB;
        if(sum>left)
        return;
        if(mem.find(sum)!=mem.end())
        return;
        mem.insert(sum);
        
        if(left%sum==0)
        ans.insert(left/sum);
        dfs(baseA,baseB,left,curA*baseA,curB,ans,mem);
        dfs(baseA,baseB,left,curA,curB*baseB,ans,mem);
    }
    void compete_solution()
    {
        int a,b,l;
        cin>>a>>b>>l;
        set<int> ans;
        set<int> mem;
        dfs(a,b,l,1,1,ans,mem);
        cout<<ans.size()<<endl;
        

        
    }