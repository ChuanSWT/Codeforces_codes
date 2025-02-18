    #include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
#define MOD 1000000007
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main()
{
    int roundc;
    cin >> roundc;
    vector<int> ans;
    for (int ic = 0; ic < roundc; ++ic)
    {
        int n,f,k;
        cin>>n>>f>>k;
        --f;
        vector<int> nums;
        for(int i=0;i<n;++i)
        {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        int fav=nums[f];
        //cout<<fav<<endl;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int left=-1,right=-1;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==fav)
            {
                if(left==-1)
                left=i;
                right=i;
            }
        }
        //cout<<left<<" "<<right<<endl;
        if(k<=left)
        cout<<"NO"<<endl;
        else
        if(k>right)
        cout<<"YES"<<endl;
        else
        cout<<"MAYBE"<<endl;

    }
    for (auto n : ans)
    {
        cout << n << endl;
    }
    return 0;
}