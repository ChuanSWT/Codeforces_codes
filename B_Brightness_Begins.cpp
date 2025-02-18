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
    __int128 fid(__int128 n)
{
	__int128 left = 0;
	__int128 right = 0x3f3f3f3f3f3f3f3f;
	while (left < right)
	{
		__int128 mid = (left + right) / 2;
		if (mid * mid <= n)
			left = mid + 1;
		else
			right = mid;
	}
	return left-1;
}
    void compete_solution()
    {
        long long n;
        cin>>n;
        __int128 left=0,right=1e36+100;
        while(left<right)
        {
            __int128 mid=(left+right)>>1;
            __int128 rst=mid-fid(mid);
            if(rst<n)
            left=mid+1;
            else
            right=mid;
        }
        cout<<(long long)left<<endl;
        
        

        
    }