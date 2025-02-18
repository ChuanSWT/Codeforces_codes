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
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    int fd(int index,vector<int> &techs)
    {
        int left=0,right=techs.size();
        while(left<right)
        {
            int mid=(left+right)/2;
            if(techs[mid]<index)
            left=mid+1;
            else
            right=mid;
        }
        return left;
    }
    void compete_solution()
    {
        int n,m,q;
        cin>>n>>m>>q;
        vector<int> techs(m);
        for(int&x:techs)
        cin>>x;
        vector<int> qs(q);
        for(int &x:qs)
        cin>>x;
        sort(techs.begin(),techs.end());
        for(int index:qs)
        {
        if(index<=techs[0])
        {
            cout<<techs[0]-1<<endl;
            continue;
        }
        if(index>=techs.back())
        {
            cout<<n-techs.back()<<endl;
            continue;
        }
        int rst=fd(index,techs);
        int nxt=techs[rst];
        int pre=techs[rst-1];
        cout<<(nxt-pre)/2<<endl;


        }

        
        

        
    }