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
        string pat="GDUTISTHEBEST";//length=13
        string s;
        cin>>s;
        int sz=s.size();
        vector<int> left(sz,0);
        vector<int> right(sz,0);
        string rs=s;
        reverse(rs.begin(),rs.end());
        string rpat=pat;
        reverse(rpat.begin(),rpat.end());
        for(int i=0;i<sz&&i<pat.size();++i)
        {
            if(s[i]!=pat[i])
            break;
            left[i]=i+1;
        }
        for(int i=0;i<sz&&i<pat.size();++i)
        {
            if(rs[i]!=rpat[i])
            break;
            right[i]=i+1;
        }

        for(int i=1;i<left.size();++i)
        if(left[i]==0)
        left[i]=left[i-1];
        for(int i=1;i<right.size();++i)
        if(right[i]==0)
        right[i]=right[i-1];

        reverse(right.begin(),right.end());
        for(int i=0;i<left.size();++i)
        if(left[i]+right[i]>=pat.size())
        {
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl;
        



        
        

        
    }