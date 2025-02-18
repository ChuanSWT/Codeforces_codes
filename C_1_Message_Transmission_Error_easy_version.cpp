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
        //cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    bool check(string &s,int i,int j)
    {
        i=0;
        while(i<s.size()&&j<s.size())
        {
            if(s[i]!=s[j])
            return false;
            ++i;
            ++j;
        }
        return true;
    }
    void compete_solution()
    {
        string s;
        cin>>s;
        int n=s.size();
        for(int i=1;i<s.size();++i)//a end
        {
            for(int j=1;j<s.size();++j)//b begin
            {
                if(j>=i)
                continue;

                int t1=i;
                int t2=s.size()-j;
                if(t1!=t2)
                continue;
                if(check(s,i,j))
                {
                    cout<<"YES"<<endl;
                    for(int k=0;k<i;++k)
                    cout<<s[k];
                    cout<<endl;
                    return;
                }

            }
        }
        cout<<"NO"<<endl;
        

        
    }