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
        int n,m;
        cin>>n>>m;
        vector<string> grid(n);
        for(auto& s:grid)
        cin>>s;
        int index=0;
        string s="vika";
        for(int y=0;y<grid[0].size();++y)
        {
            if(index==s.size())
            break;
            for(int x=0;x<grid.size();++x)
            {
                if(grid[x][y]==s[index])
                {
                    ++index;
                    break;
                }
            }
        }
        if(index==s.size())
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        

        
    }