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
        int n;
        cin>>n;
        vector<vector<double>> shoot(n,vector<double>(4));
        for(auto &arr:shoot)
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
        double v,x,y;
        cin>>v>>x>>y;
        //int cur=1;
        for(auto &arr:shoot)
        {

            double time=arr[0];
            double r=arr[1];
            double xx=arr[2];
            double yy=arr[3];
            double newX=v*time+x;
            double newY=y;
            xx=newX-xx;
            yy=newY-yy;
            xx*=xx;
            yy*=yy;
            r*=r;
            if(r>=xx+yy)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        

        
    }