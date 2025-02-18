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
    vector<vector<int>> make(int n)
    {
        vector<int> ans(n,0);
        for(int &x:ans)
        cin>>x;
        //print(ans);
        vector<vector<int>> rst;
        for(int i=0;i<ans.size();++i)
        rst.push_back({ans[i],i});
        sort(rst.begin(),rst.end());
        reverse(rst.begin(),rst.end());
        while(rst.size()>3)
        rst.pop_back();
        return rst;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<vector<int>> a=make(n);
        vector<vector<int>> b=make(n);
        vector<vector<int>> c=make(n);
        int maxv=0;
        /*for(auto x:a)
        {
            for(auto y:x)
            cout<<y<<" ";
            cout<<endl;
        }
        for(auto x:b)
        {
            for(auto y:x)
            cout<<y<<" ";
            cout<<endl;
        }
        for(auto x:c)
        {
            for(auto y:x)
            cout<<y<<" ";
            cout<<endl;
        }*/
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                for(int k=0;k<3;++k)
                {
                    int ai=a[i][1];
                    int bi=b[j][1];
                    int ci=c[k][1];
                    if(ai==bi||ci==bi||ai==ci)
                    continue;
                    maxv=max(maxv,a[i][0]+b[j][0]+c[k][0]);
                }
            }
        }
        cout<<maxv<<endl;
        

        
    }