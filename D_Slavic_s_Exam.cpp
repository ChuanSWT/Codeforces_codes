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
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL) ;
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
        string s;
        string pat;
        cin>>s;
        cin>>pat;
        //cout<<s<<endl;
        int index=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='?'||s[i]==pat[index])
            {
                //cout<<"hello"<<endl;
            s[i]=pat[index];
            ++index;
            }
            if(index==pat.size())
            {
                cout<<"YES"<<endl;
                for(char &c:s)
                if(c=='?')
                c='a';
                cout<<s<<endl;
                return;
            }
        }
        cout<<"NO"<<endl;
        
        

        
    }