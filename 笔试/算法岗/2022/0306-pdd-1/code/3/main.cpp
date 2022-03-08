// 两组打仗，【攻击力，防御力】，问a组怎么分配可以攻击成功所有b组，并且尽量多的防御成功，求最大的防御成功数
// 攻击失败返回-1
//攻击成功： a的攻击力大于等于b的防御力
//防御成功：a的防御力大于b的攻击力

#include <bits/stdc++.h>
using namespace std;

bool cmp1(vector<int> a, vector<int> b) {
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

int helper(vector<vector<int>> v1, vector<vector<int>> v2) {
    int ans = 0;
    sort(v1.begin(), v1.end(), cmp1);
    sort(v2.begin(), v2.end(), cmp1);
    
    int p1 = 0, p2 = 0;
    vector<int> used(v1.size());
    for (int j = 0; j < v2.size(); j ++) {
        // cout << v2[j][0] << endl;
        p1 = INT_MAX;
        int isFind = 0;
        for (int i = 0; i < v1.size(); i ++) {
            // cout << i << endl;
            if (used[i] == 0) {
                if (v1[i][0] >= v2[j][1]) {
                    p1 = min(p1, i);
                    // cout << i << endl;
                }
                if (v1[i][0] >= v2[j][1] && v1[i][1] > v2[j][0]) {
                    ans ++;
                    used[i] = 1;
                    isFind = 1;
                    break;
                } 
            }
        }
        if (!isFind) {
            if (p1 == INT_MAX)  return -1;
            else    used[p1] = 1;
        }
    }
    return ans;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v1, v2;
    for (int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        v1.push_back({a, b});
    }
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        v2.push_back({a, b});
    }
    cout << helper(v1, v2) << endl;
    return 0;
}