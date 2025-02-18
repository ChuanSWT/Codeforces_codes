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
        int n,q;
        cin>>n>>q;
        vector<int> parent(n-1);
        for(int &x:parent)
        cin>>x;
        vector<int> arr(n);
        for(int &x:arr)
        cin>>x;
        vector<vector<int>> query(q);
        for(auto&arr:query)
        cin>>arr[0]>>arr[1];
        //也许不需要在树上进行交换
        //只需要在序列上交换即可?
        for(auto arr:query)
        {
            swap[]
        }
        

        
    }