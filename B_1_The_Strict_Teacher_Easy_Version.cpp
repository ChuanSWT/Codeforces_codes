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
    void compete_solution()
    {
        int n,m,q;
        cin>>n>>m>>q;
        vector<int> techs(m);
        for(int&x:techs)
        cin>>x;
        int index;
        cin>>index;
        sort(techs.begin(),techs.end());
        if(index<=techs[0])
        {
            cout<<techs[0]-1<<endl;
            return;
        }
        if(index>=techs[1])
        {
            cout<<n-techs.back()<<endl;
            return;
        }
        cout<<(techs[1]-techs[0])/2<<endl;

        
        

        
    }