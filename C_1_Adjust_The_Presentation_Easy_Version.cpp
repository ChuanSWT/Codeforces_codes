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
        vector<int> a(n),b(m);
        for(int&x:a)
        cin>>x;
        reverse(a.begin(),a.end());
        for(int&x:b)
        cin>>x;
        set<int> st;
        for(int i=0;i<b.size();++i)
        {
            int bk=-1;
            if(a.size())
            bk=a.back();
            if(st.find(b[i])!=st.end())
            continue;
            if(bk==b[i])
            {
                st.insert(bk);
                a.pop_back();
                continue;
            }
            cout<<"TIDAK"<<endl;
            return;
        }
        cout<<"YA"<<endl;
        return;

        
        

        
    }