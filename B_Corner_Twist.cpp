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
        vector<string> grid(n),target(n);
        for(auto&s:grid)
        cin>>s;
        for(auto&s:target)
        cin>>s;
        vector<vector<int>> mp(n,vector<int> (m,0));
        for(int x=0;x<grid.size();++x)
        {
            for(int y=0;y<grid[0].size();++y)
            {
                mp[x][y]=(grid[x][y]-target[x][y]+3)%3;
            }
        }
        for(int x=0;x+1<mp.size();++x)
        {
            for(int y=0;y+1<mp[0].size();++y)
            {
                if(mp[x][y]==0)
                continue;
                if(mp[x][y]==2)
                {
                    mp[x][y]+=1;
                    mp[x+1][y+1]+=1;
                    mp[x+1][y]+=2;
                    mp[x][y+1]+=2;
                    mp[x][y]%=3;
                    mp[x+1][y+1]%=3;
                    mp[x+1][y]%=3;
                    mp[x][y+1]%=3;
                }
                else
                {
                    mp[x][y]+=2;
                    mp[x+1][y+1]+=2;
                    mp[x+1][y]+=1;
                    mp[x][y+1]+=1;
                    mp[x][y]%=3;
                    mp[x+1][y+1]%=3;
                    mp[x+1][y]%=3;
                    mp[x][y+1]%=3;
                }
            }
        }
        for(auto &arr:mp)
        {
            //print(arr);
            for(auto &x:arr)
            if(x)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
cout<<"YES"<<endl;
        
        
        

        
    }