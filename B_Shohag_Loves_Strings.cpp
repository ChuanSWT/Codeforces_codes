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
    #include<numeric>
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
        string s;
        cin>>s;
        for(int i=0;i+2<s.size();++i)
        {
            set<char>st;
            for(int j=i;j<i+3;++j)
            st.insert(s[j]);
            if(st.size()==3)
            {
                for(int j=i;j<i+3;++j)
                cout<<s[j];
                cout<<endl;
                return;
            }
        }
        for(int i=0;i+1<s.size();++i)
        {
            if(s[i]==s[i+1])
            {
                cout<<s[i]<<s[i+1]<<endl;
                return;
            }
        }        
        cout<<-1<<endl;

        
    }