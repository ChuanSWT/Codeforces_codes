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
    bool check(int right,string&s)
    {
        int index=s.size()-1;
        int i=right;
        while(index>=right)
        {
            if(s[i]!=s[index])
            return false;
            --i;
            --index;
        }
        return true;
    }
    void compete_solution()
    {
        string s;
        cin>>s;
        int right=s.size()/2;//右侧包含
        while(right+1<s.size())
        {
            //cout<<right<<endl;
            int sz=s.size()-right-1;
            int left=right-sz+1;//左侧包含
            if(left==0)
            {
                ++right;
            continue;
            }
            if(s[right]!=s.back())
            {
                ++right;
                continue;
            }
            if(check(right,s))
            {
                cout<<"YES"<<endl;
                for(int i=0;i<=right;++i)
                cout<<s[i];
                cout<<endl;
                return;
            }
            ++right;
        }
        cout<<"NO"<<endl;
        

        
    }