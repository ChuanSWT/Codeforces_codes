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
        string s;
        cin>>s;
        vector<int> ans;
        int x=0;
        int y=0;
        for(int i=0;i<n-1;++i)
        {
            if(s[i]=='1')
            ++x;
            else
            ++y;
            if(!(x&&y))
            ans.push_back(1);
            else
            {
                if(i!=0&&s[i]==s[i-1])
                ans.push_back(ans.back());
                else
                ans.push_back(i+1);
            }
        }
for(int num:ans)
cout<<num<<" ";
cout<<endl;
        

        
    }