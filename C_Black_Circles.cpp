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
        //一旦被圆包围，则不可能脱出
        //若能在最后到达，就一定不被包围
        int n;
        cin>>n;
        vector<vector<long long>> points(n,vector<long long>(2));
        for(auto &arr:points)
        cin>>arr[0]>>arr[1];
        long long x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        long long myD=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        for(auto p:points)
        {
            long long newD=(p[0]-x2)*(p[0]-x2)+(p[1]-y2)*(p[1]-y2);
            if(newD<=myD)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        

        
    }