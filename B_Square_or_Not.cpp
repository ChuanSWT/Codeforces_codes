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
    bool check(vector<string> grid)
    {
        int target=(grid.size()+grid[0].size()-2)*2;
        for(auto s:grid)
        for(auto c:s)
        if(c=='1')
        --target;
        if(target!=0)
        return false;
        for(int x=0;x<grid.size();++x)
        {
        if(grid[x][0]=='0')
        return false;
        if(grid[x][grid[0].size()-1]=='0')
        return false;
        }
        for(int y=0;y<grid[0].size();++y)
        {
        if(grid[0][y]=='0')
        return false;
        if(grid[grid.size()-1][y]=='0')
        return false;
        }
        return true;
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=1;i*i<=s.size();++i)
        {
            if(i*i!=s.size())
            continue;
            if(s.size()%i==0)
            {
                vector<string> temp;
                for(int j=0;j<s.size();j+=i)
                {
                    string t;
                    for(int k=j;k<j+i;++k)
                    t+=s[k];
                    temp.push_back(t);
                }
                if(check(temp))
                {
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
        cout<<"No"<<endl;
        

        
    }