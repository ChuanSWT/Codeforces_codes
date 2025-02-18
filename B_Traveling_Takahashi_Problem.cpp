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
        vector<vector<double>> points(n,vector<double>(2));
        for(auto &arr:points)
        cin>>arr[0]>>arr[1];//cout<<"hi"<<endl;
        //print(points[0]);
        points.push_back({0,0});
        //__int128 sum=0;
        double preX=0;
        double preY=0;
        double rst=0;
        for(auto p:points)
        {
            double newX=p[0];
            double newY=p[1];
            double cur=0;

            double temp=newX-preX;
            preX=newX;
            cur+=temp*temp;

            temp=newY-preY;
            preY=newY;
            cur+=temp*temp;

            cur=sqrt(cur);
            rst+=cur;
        }

        cout<<fixed<<setprecision(10)<<rst<<endl;


        

        
    }