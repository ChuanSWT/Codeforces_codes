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
        string s;
        cin>>s;
        int n;
        cin>>n;
        vector<vector<int>> query(n,vector<int>(2));
        for(auto &arr:query)
        {
        cin>>arr[0]>>arr[1];
        --arr[0];
        }
        int sum=0;
        vector<int> status(s.size(),0);
        for(int i=0;i<s.size()-3;++i)
        {
            if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0')
            {
            ++sum;
            status[i]=1;
            }
        }
        for(auto arr:query)
        {


            int index=arr[0];
            char ori=s[index];
            char target=arr[1]+'0';
            s[index]=target;
            for(int i=index;i>=index-3&&i>=0;--i)
            {
                if(i+3>=s.size())
                continue;
                {
                if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='0')
                {
                    if(status[i]==1)
                    continue;
                    else
                    {
                        status[i]=1;
                        ++sum;
                    }
                }
                else
                {
                    if(status[i]==0)
                    continue;
                    else
                    {
                        status[i]=0;
                        --sum;
                    }
                }
                }
                
            }
            if(sum)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
        }
        
        

        
    }