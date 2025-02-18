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
        int n;
        cin>>n;
        string a,b;
        cin>>a;
        cin>>b;
        int count=0;
        int suma=0;
        for(char c:a)
        if(c=='1')
        ++suma;
        int sumb=0;
        for(char c:b)
        if(c=='1')
        ++sumb;
        int x=0,y=0;
        for(int i=0;i<a.size();++i)
        {
            if(a[i]=='1'&&b[i]=='0')
            ++x;
            if(a[i]=='0'&&b[i]=='1')
            ++y;
        }
        cout<<max(x,y)<<endl;
        


        

        
    }