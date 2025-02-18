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
        int roundc=1;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        vector<string> grid(n);
        for(auto&s:grid)
        cin>>s;

        vector<vector<int>> mark(n,vector<int>(m,0));
        vector<string> strs;
        string path;
        int x=0,y=0;
        int att=0;
        int cnt=0;
        while(true)
        {
            path+=grid[x][y];
            mark[x][y]=1;
            ++cnt;
            if(cnt==n*m)
            {
                strs.push_back(path);
            break;
            }
            bool ok=true;
            if((att%4==0&&ok)&&(y+1==grid[0].size()||mark[x][y+1]))
            {
                x+=1;
                ++att;
                ok=false;
            }
            if((att%4==1&&ok)&&(x+1==grid.size()||mark[x+1][y]))
            {
                y-=1;
                ++att;
                ok=false;
            }
            if((att%4==2&&ok)&&(y-1<0||mark[x][y-1]))
            {
                x-=1;
                ++att;
                ok=false;
            }
            if((att%4==3&&ok)&&(x-1<0||mark[x-1][y]))
            {
                strs.push_back(path);
                path.clear();
                y+=1;
                ++att;
                ok=false;
            }

            if(ok)
            {
                x+=dx[att%4];
                y+=dy[att%4];
            }

        }
        long long sum=0;
        for(auto &s:strs)
        {
            s+=s;
            for(int i=0;i<s.size()/2;++i)
            if(s[i]=='1'&&s[i+1]=='5'&&s[i+2]=='4'&&s[i+3]=='3')
            ++sum;
        }
        cout<<sum<<endl;
        
        

        
    }