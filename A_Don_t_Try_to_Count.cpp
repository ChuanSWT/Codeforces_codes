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
    int count(string &a,string &b)
    {
        //cout<<a<<endl;
        if(a.size()<b.size())
        return 0;
        int ans=0;
        for(int i=0;i<=a.size()-b.size();++i)
        {
            bool ok=true;
            for(int j=0;j<b.size();++j)
            {
                if(a[i+j]!=b[j])
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            return 1;
        }
        return 0;
    }
    void compete_solution()
    {
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        int cur=0;
        while(s1.size()<=400)
        {
            int rst=count(s1,s2);
            if(rst!=0)
            {
                cout<<cur<<endl;
                return;
            }
            ++cur;
            s1+=s1;
        }
        cout<<-1<<endl;
        

        
    }