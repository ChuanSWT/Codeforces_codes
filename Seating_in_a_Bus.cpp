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
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> seats(n,0);
        vector<int> nums(n);
        for(int &x:nums)
        {
        cin>>x;
        --x;
        }
        int index=0;
        for(int x:nums)
        {
            bool ok=false;
            seats[x]++;
            if(x!=0&&seats[x-1])
            ok=true;
            if(x+1!=seats.size()&&seats[x+1])
            ok=true;
            if(!ok&&index!=0)
            {
                cout<<"NO"<<endl;
                return;
            }
            ++index;
        }
cout<<"YES"<<endl;
        
        

        
    }