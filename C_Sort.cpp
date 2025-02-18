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
    void compete_solution()
    {
        int n,q;
        cin>>n>>q;
        string a;
        string b;
        cin>>a;
        cin>>b;
        vector<vector<int>> que(q,vector<int>(2));
        for(auto &p:que)
        cin>>p[0]>>p[1];
        vector<vector<int>> left(a.size(),vector<int>(26,0));
        for(int i=0;i<a.size();++i)
        {
            left[i][a[i]-'a']++;
            if(i!=0)
            for(int j=0;j<26;++j)
            left[i][j]+=left[i-1][j];

            left[i][b[i]-'a']--;

        }
        for(auto arr:que)
        {
            int ln=arr[0]-1;
            int rn=arr[1]-1;
            vector<int> r(26,0);
            vector<int> l(26,0);
            if(ln!=0)
            l=left[ln-1];
            r=left[rn];
            for(int i=0;i<l.size();++i)
            r[i]-=l[i];
            int sum=0;
            for(int i=0;i<r.size();++i)
            if(r[i]>0)
            sum+=r[i];
            cout<<sum<<endl;
        }

        
        

        
    }