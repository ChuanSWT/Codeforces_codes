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
        int roundc=1;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    string check0(int n)
    {
        //cout<<"check0"<<endl;
        string ans;
        for(int i=0;i<n;++i)
        {
            bool ok=false;
            int rst;
            cout<<"? "<<ans<<'0'<<endl;
            cout.flush();
            cin>>rst;
            if(rst==1)
            {
                ans+='0';
            }
            else
            {
            cout<<"? "<<ans<<'1'<<endl;
            cout.flush();
            cin>>rst;
            if(rst==1)
            {
                ans+='1';
                continue;
            }
            else
            {
                string pre;
        pre+=ans[0];
        if(pre=="1")
        pre="0";
        else
        pre='1';
        ans=pre+ans;
        //cout<<ans<<endl;
            return ans;
            }
            }
            
        }
        string pre;
        if(ans.size()!=n)
        {
        pre+=ans[0];
        if(pre=="1")
        pre="0";
        else
        pre='1';
        ans=pre+ans;
        }
        //cout<<ans<<endl;
        return ans;

    }
    string check1(string s,int n)
    {
        //cout<<"check1"<<endl;
        string ans;
        for(int i=0;i<n-s.size();++i)
        {
            bool ok=false;
            int rst;
            cout<<"? "<<'0';
            cout.flush();
            for(int j=ans.size()-1;j>=0;--j)
            {
            cout<<ans[j];
            cout.flush();
            }
            cout<<s<<'\n';
            cout.flush();
            cin>>rst;
            if(rst==1)
            {
                ans+='0';
            }
            else
            {
            cout<<"? "<<'1';
            cout.flush();
            for(int j=ans.size()-1;j>=0;--j)
            {
            cout<<ans[j];
            cout.flush();
            }
            cout<<s<<'\n';
            cout.flush();
            cin>>rst;
            if(rst==1)
            {
                ans+='1';
                continue;
            }
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans+s;

    }

    void compete_solution()
    {
        int n;
        cin>>n;
        string s=check0(n);
        if(s.size()!=n)
        {
            s=check1(s,n);
        }
        cout<<"! "<<s<<endl;
        cout.flush();
        

        
    }