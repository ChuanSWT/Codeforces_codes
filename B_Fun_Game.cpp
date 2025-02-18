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
        int n;
        cin>>n;
        string s,t;
        cin>>s;
        cin>>t;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='1')
            {
                cout<<"YES"<<endl;
                return;
            }
            if(t[i]=='1')
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;

        
    }