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
    void compete_solution()
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int&x:nums)
        cin>>x;
        int a=0,b=0;
        for(int x:nums)
        {
            if(x==5)
            ++a;
            else
            {
                if(x==10)
                {
                    if(a==0)
                    {
                        cout<<"No"<<endl;
                        return;
                    }
                    else
                    {
                        --a;
                        ++b;
                    }
                }
                else
                {
                    if(b!=0&&a!=0)
                    {
                        --b;
                        --a;
                    }
                    else
                    {
                        if(a>=3)
                        {
                            a-=3;
                        }
                        else
                        {
cout<<"No"<<endl;
return;
                        }
                    }
                }
            }
        }
cout<<"Yes"<<endl;
        

        
    }