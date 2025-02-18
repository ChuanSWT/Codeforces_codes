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
        int x,n;
        cin>>x>>n;
        int count=0;
            for(int k=max(2,n);k<=x;++k)
            {
                int x1=x;
                x1%=2*k-2;
                if(x1==0)
                x1=2*k-2;
                if(x1<k)
                {
                    if(x1==n)
                    ++count;
                    //cout<<k<<" "<<x1<<endl;
                }
                else
                {
                    if(2*k-x1==n)
                    ++count;
                    //cout<<k<<" "<<2*k-x1<<endl;
                }
            }
        cout<<count<<endl;

        
    }