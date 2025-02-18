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
        //cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<string> grid(n);
        for(auto&s:grid)
        cin>>s;
        for(int x=0;x<n/2;++x)
        {
            for(int y=0;y<n/2;++y)
            {
                //cout<<x<<" "<<y<<endl;
                //return;
                int op=min(x,y)%4;
                char& left=grid[x][y];
                    char& right=grid[n-1-x][n-1-y];
                    char& up=grid[y][n-1-x];
                    char& down=grid[n-1-y][x];
                if(op==3)
                continue;
                if(op==0)
                {
                    swap(left,up);
                    swap(left,right);
                    swap(left,down);
                }
                if(op==1)
                {
                    swap(left,up);
                    swap(left,right);
                    swap(left,down);
                    swap(left,up);
                    swap(left,right);
                    swap(left,down);
                }
                if(op==2)
                {
                    swap(left,up);
                    swap(left,right);
                    swap(left,down);
                    swap(left,up);
                    swap(left,right);
                    swap(left,down);
                    swap(left,up);
                    swap(left,right);
                    swap(left,down);
                }
            }
        }
        for(auto s:grid)
        cout<<s<<endl;

        
    }