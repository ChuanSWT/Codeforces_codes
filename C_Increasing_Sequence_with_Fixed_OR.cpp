#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

void compete_solution();


int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}   
int main() {
    int a=pow(2,3.4);
    int roundc;
    cin >> roundc;
    for (int ic = 0; ic < roundc; ++ic) {
        compete_solution();
    }
    return 0;
} 

vector<int> i_v(long long num) {
    vector<int> ans(63,0);
    for(long long i = 62; i >= 0; --i) {
        if(num >= 1ll<<i) {
            num -= 1ll<<i;
            ans[i] = 1;
        }
    }
    return ans;
}

long long cal(vector<int> &arr) {
    long long sum = 0;
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i])
            sum += 1ll<<i;
    }
    return sum;
}

vector<int> make(vector<int> val, vector<int> ori,long long record) {
    //cout<<val.size()<<endl;
    vector<int> ans = val;
    for(int &num : ans)
        num = 0;
    
    for(int i = 62; i >= 0; --i) {
        if(ori[i] == 1 && val[i] == 0) {
            ans[i] = 1;
        }
    }
    
     for(int i=62;i>=0;--i)
        {
            if(ans[i]==0&&val[i])
            {
                ans[i]=1;
                if(cal(ans)>=cal(val))
                ans[i]=0;
            }
        }

    if(cal(ans) <record)
        return {};
    //cout<<"push"<<endl;
    return ans;
}

void compete_solution() {
    long long n;
    cin >> n;
    long long record = 0;
    
    for(long long i = 0; i < 62; ++i) {
        if((1ll<<i) > n) {
            record = (1ll<<i-1);
            break;
        }
    }
    
    vector<int> ori = i_v(n);
    vector<vector<int>> nums;
    nums.push_back(ori);
    //cout << cal(ori) << endl;
    
    vector<int> emp;
    while(nums.back() != emp) {
        nums.push_back(make(nums.back(), nums[0],record));
        //cout<<"push"<<cal(nums.back())<<endl;
    }
    while(cal(nums.back())==0)
    nums.pop_back();
    vector<int> bb(63,0);
    for(int i=0;i<bb.size();++i)
    {
        if(ori[i])
        bb[i]=1;
        if(cal(bb)==cal(ori))
        {
            bb[i]=0;
            break;
        }
    }
    if(cal(bb)!=0)
    nums.push_back(bb);
    cout<<nums.size()<<endl;
reverse(nums.begin(),nums.end());
    for(auto arr : nums)
        cout << cal(arr) <<" ";
    cout << endl;
    //cout << endl;
}
