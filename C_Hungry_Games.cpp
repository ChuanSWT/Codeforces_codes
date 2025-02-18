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

void compete_solution();

template <typename T>
void print(const std::vector<T>& vec) {
    for (auto element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int roundc;
    cin >> roundc;

    for (int ic = 0; ic < roundc; ++ic) {
        compete_solution();
    }

    return 0;
}

void compete_solution() {
    long long n, x;
    cin >> n >> x;

    vector<int> nums(n, 0);
    for (int &val : nums)
        cin >> val;

    long long sum = 0;  
    int left = 0; 
    int right = 0;
    vector<int> ans(n, -1);

    while (left < nums.size()) {
        while (right < nums.size() && sum + nums[right] <= x) {
            sum += nums[right];
            ++right;
        }
        ans[left] = right;
        sum -= nums[left];
        ++left;
    }

    vector<int> arr = ans;

    for (int i = ans.size() - 1; i >= 0; --i) {
        ans[i] = ans[i] - i;
        if(i+ans[i]+1<ans.size())
        ans[i]+=ans[i+ans[i]+1];
    }
    long long rst=0;
    for(int num:ans)
    rst+=num;
    cout<<rst<<endl;

    
}
