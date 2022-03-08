//s -> s+r(s) , r(s) + s,操作k次，生成多少个不同的字符串
// r(s)  翻转s
#include <bits/stdc++.h>
using namespace std;

int helper(string str, int k) {
    if (k == 0) return 1;
    int ans = 0;
    string rs = str;
    reverse(rs.begin(), rs.end());
    if (str == rs)  return 1;
    return 2;
}

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t --) {
        int k, l;
        cin >> k >> l;
        string str;
        cin >> str;
        cout << helper(str, k) << endl;
    }
    return 0;
}