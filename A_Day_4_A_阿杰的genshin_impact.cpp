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
        long long n,m;
        cin>>n>>m;
        int a,b;
        cin>>a>>b;
        vector<vector<int>> target(a,vector<int>(2));
        for(auto &arr:target)
        cin>>arr[0]>>arr[1];
        vector<vector<int>> shoot(b,vector<int>(3));
        for(auto &arr:shoot)
        cin>>arr[0]>>arr[1]>>arr[2];
        vector<int> mark(a,0);
        long long x,y,r;
        for(auto& q:shoot)
        {
            for(int i=0;i<a;++i)
            {
                if(mark[i])
                continue;
                x=q[0]-target[i][0];
                y=q[1]-target[i][1];
                x=x*x;
                y=y*y;
                r=q[2];
                r=r*r;
                if(r>=x+y)
                mark[i]=1;
            }
        }
        for(int &num:mark)
        if(num==0)
        {
            cout<<"It's bad"<<endl;
            return;
        }
        cout<<"That's good"<<endl;

        
        

        
    }