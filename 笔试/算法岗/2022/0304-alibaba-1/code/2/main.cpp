#include <bits/stdc++.h>
using namespace std;

int kk = 0;
void helper(vector<int>& nums, int cur) {
    if (kk == 0)    return;
    if (cur == nums.size() - 1) {
        for (int i = 0; i < nums.size(); i ++) {
            if (i == 0) cout << nums[i];
            else    cout << " " << nums[i];
        }
        kk --;
        cout << endl;
    } else {
        for (int i = cur; i < nums.size(); i ++) {
            if (cur + 1 == nums[i])   continue;
            swap(nums[i], nums[cur]);
            helper(nums, cur + 1);
            swap(nums[i], nums[cur]);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> tmp;
    kk = k;
    for (int i = 0; i < n; i ++)    tmp.push_back(i + 1);
    helper(tmp, 0);
    return 0;
}