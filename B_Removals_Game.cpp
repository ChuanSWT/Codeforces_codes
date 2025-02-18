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
        deque<int> a(n),b(n);
        for(int &x:a)
        cin>>x;
        for(int &x:b)
        cin>>x;
        int a1=a.front(),a2=a.back();
        while(a.size()!=1)
        {
            int a1=a.front();
            int a2=a.back();
            int b1=b.front();
            int b2=b.back();
            if(a1!=b1&&a1!=b2)
            {
                cout<<"Alice"<<endl;
                return;
            }
            if(a2!=b1&&a2!=b2)
            {
                cout<<"Alice"<<endl;
                return;
            }
            if(a1==b1)
            {
                a.pop_front();
                b.pop_front();
                continue;
            }
            if(a1==b2)
            {
                a.pop_front();
                b.pop_back();
                continue;
            }
            if(a2==b1)
            {
                a.pop_back();
                b.pop_front();
                continue;
            }
            if(a2==b2)
            {
                a.pop_back();
                b.pop_back();
                continue;
            }
        }
        cout<<"Bob"<<endl;
        
        

        
    }