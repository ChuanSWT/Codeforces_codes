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
        int h,w,x1,y1,x2,y2;
        cin>>h>>w>>x1>>y1>>x2>>y2;
        if(x1>=x2)
        {
            cout<<"Draw"<<endl;
            return;
        }
        //alice 靠墙的距离
        long long aleft=y1-1;
        long long aright=w-y1;
        long long bleft=y2-1;
        long long bright=w-y2;
                    long long d=abs(x1-x2);
        if((x2-x1)%2==0)//bob主动进攻
        {

            if(y1==y2)
            {
                cout<<"Bob"<<endl;
                return;
            }
            if(y1<y2)//左侧有生还可能
            {
                int mv=(d)/2;
                y2-=mv;
                y1-=mv;
                if(y1<1)
                y1=1;
                if(y2<=y1)
                {
                cout<<"Bob"<<endl;
                }
                else
                {
                cout<<"Draw"<<endl;
                }
            }
            else
            {
                int mv=(d)/2;
                y2+=mv;
                y1+=mv;
                if(y1>w)
                y1=w;
                if(y2>=y1)
                {
                cout<<"Bob"<<endl;
                }
                else
                {
                cout<<"Draw"<<endl;
                }
            }

        }
        else//alice主动进攻
        {
            --d;
            if(y1==y2)
            {
                cout<<"Alice"<<endl;
                return;
            }
            if(y2<y1)//左侧有生还可能
            {
                ++x1;
                --y1;
                 int mv=(d)/2;
                y2-=mv;
                y1-=mv;
                if(y2<1)
                y2=1;
                if(y2>=y1)
                {
                cout<<"Alice"<<endl;
                }
                else
                {
                cout<<"Draw"<<endl;
                }

            }
            else
            {
                ++x1;
                ++y1;
                
                 int mv=(d)/2;
                y2+=mv;
                y1+=mv;
                if(y2>w)
                y2=w;
                if(y2<=y1)
                {
                cout<<"Alice"<<endl;
                }
                else
                {
                cout<<"Draw"<<endl;
                }
            }
        }

        
        
        

        
    }