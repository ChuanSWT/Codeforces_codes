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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> nums1(n,0);
        vector<int> nums2(m,0);
        for(int&x:nums1)
        cin>>x;
        for(int&x:nums2)
        cin>>x;
        set<int> s1;
        set<int> s2;
        for(int num:nums1)
        {
            if(num>=1&&num<=k)
            s1.insert(num);
        }
        for(int num:nums2)
        {
            if(num>=1&&num<=k)
            s2.insert(num);
        }
        if(s1.size()<k/2||s2.size()<k/2)
        {
            cout<<"NO"<<endl;
            return;
        }
        for(int num:s1)
        s2.insert(num);
        if(s2.size()==k)
        {
            cout<<"YES"<<endl;
        }
        else

        {
            cout<<"NO"<<endl;
        }
        
        

        
    }