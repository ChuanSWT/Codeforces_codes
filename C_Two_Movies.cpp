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
    int main()
    {
        int roundc;
        cin >> roundc;
        for (int ic = 0; ic < roundc; ++ic)
        {
            compete_solution();
        }
        return 0;
    }
    int gcd(int x, int y)
    {
        if (y == 0)
            return x;
        return gcd(y, x % y);
    }
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> mv1(n,0),mv2(n,0);
        for(int i=0;i<n;++i)
        cin>>mv1[i];
        for(int i=0;i<n;++i)
        cin>>mv2[i];
        int v1=0;int v2=0;
        int nerd=0,fan=0;
        for(int i=0;i<mv1.size();++i)
        {
            if((mv1[i]==-1&&mv2[i]==-1)||(mv1[i]==1&&mv2[i]==1))
            {
                if(mv1[i]==-1&&mv2[i]==-1)
                ++nerd;
                else
                ++fan;
            }
            else
            {
                if(mv1[i]==-1)
                {
                    v2+=mv2[i];
                }
                else
                {
                    if(mv2[i]==-1)
                    v1+=mv1[i];
                    else
                    {
                        if(mv1[i]>mv2[i])
                        v1+=mv1[i];
                        else
                        v2+=mv2[i];
                    }
                }
            }
        }
        int water=nerd+fan;
        if(abs(v1-v2)<water)
        {
            int av=(v1+v2+fan-nerd);
            if(av<0)
            {
                cout<<(v1+v2+fan-nerd-1)/2<<endl;
            }
            else
            cout<<(v1+v2+fan-nerd)/2<<endl;
        }
        else
        {
            if(v1>v2)
            cout<<(v2+fan)<<endl;
            else
            cout<<(v1+fan)<<endl;
        }

        
        
    }