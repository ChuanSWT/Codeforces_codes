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
    #define int long long
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
    signed main()
    {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL) ;
    //cout.tie(NULL);
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
    return 0;
    }
    //状态转移 从a到b，我能赚的最大分数
    //线性，对每个字符串预处理在进行转移
    //统计帮助值
    int cal_helper(string &s,string &pattern,int pre,int target_idx)
    {
        int index=pre;
        bool ok=false;
        for(char &c:s)
        {
            if(index%5==target_idx)
            ok=true;
            if(c==pattern[(index+1)%5])
            ++index;
            if(index%5==target_idx)
            ok=true;
        }
        if(!ok)
        return -0x3f3f3f3f;

        while(pattern[index%5]!=pattern[target_idx])
        --index;
        return index-pre;
    }
    //ok
    vector<vector<int>> cal(string s,string pattern)
    {
        vector<vector<int>> ans(5,vector<int>(5));
        set<char> st;
        st.insert('n');st.insert('a');st.insert('r');st.insert('e');st.insert('k');
        int sum=0;
        for(char c:s)
        if(st.find(c)!=st.end())
        ++sum;
        for(int x=0;x<ans.size();++x)
        {
            for(int y=0;y<ans[0].size();++y)
            {
                int rst=cal_helper(s,pattern,x,y);//新增匹配数量
                ans[x][y]=rst-(sum-rst);
            }
        }
        return ans;
    }
    //ok
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        string pattern="narek";
        //n:个数
        //m:各段长度，用于计算贡献
        //记得narek之外的字母屏蔽
        //未填完也算得分，最后取的时候剪掉
        vector<string> strs(n);
        for(auto&s:strs)
        cin>>s;
        //到第i个字符串--最后对照的字母--能取得最大分数

        vector<vector<int>> dp(n+1,vector<int>(5,-0x3f3f3f3f));
        dp[0][4]=0;
        for(int i=1;i<dp.size();++i)
        {
            string s=strs[i-1];
            vector<vector<int>> trans=cal(s,pattern);
            /*for(auto arr:trans)
            print(arr);
            cout<<endl;*/
            for(int j=i-1;j<i;++j)
            {
                for(int x=0;x<trans.size();++x)
                {
                    for(int y=0;y<trans[0].size();++y)
                    {
                        dp[i][y]=max(dp[i][y],dp[j][x]+trans[x][y]);//将以x下标为尾，转为以y下标为尾
                    }
                }
                for(int k=0;k<5;++k)
                dp[i][k]=max(dp[i][k],dp[j][k]);
            }
        }
        int maxv=0;
        for(auto arr:dp)
        {
            maxv=max(maxv,arr.back());
            for(int i=0;i<arr.size()-1;++i)
            maxv=max(maxv,arr[i]-2*(i+1));
        }
        cout<<maxv<<'\n';

        
        

        
    }