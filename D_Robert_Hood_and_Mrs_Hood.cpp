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
        int n,d,k;
        cin>>n>>d>>k;
        vector<vector<int>> jobs(k,vector<int>(2));
        for(auto&arr:jobs)
        cin>>arr[0]>>arr[1];

        vector<int> join(n+2,0);
        vector<int> leave(n+2,0);
        for(auto arr:jobs)
        {
            ++join[arr[0]];
            ++leave[arr[1]];
        }
        int maxv=-1;
        int index0=-1;
        int s=0;
        for(int i=1;i<d;++i)
            s+=join[i];
        for(int i=d;i<=n;++i)
        {
            s+=join[i];
            if(s>maxv)
            {
                maxv=s;
                index0=i-d+1;
                
            }
            s-=leave[i-d+1];
        }
        //print(join);
        //print(leave);
        s=0;
        int index1=-1;
        int minv=0x3f3f3f3f;
        for(int i=1;i<d;++i)
            s+=join[i];
        for(int i=d;i<=n;++i)
        {
            s+=join[i];
            //cout<<i<<" "<<s<<endl;
            if(s<minv)
            {
                minv=s;
                index1=i-d+1;
                //cout<<i<<" "<<index1<<endl;
            }
            s-=leave[i-d+1];
            //cout<<i<<" "<<s<<endl;
        }
        cout<<index0<<" "<<index1<<endl;

        

        
    }