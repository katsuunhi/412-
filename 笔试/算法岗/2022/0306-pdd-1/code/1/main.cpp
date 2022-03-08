// aabb -> 2a2b

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    string str;
    cin >> str;
    char cur = str[0];
    int cnt = 1;
    string ans;
    for (int i = 1; i < str.size(); i ++) {
        if (str[i] == cur)  cnt ++;
        else {
            ans += to_string(cnt);
            ans += cur;
            cur = str[i];
            cnt = 1;
        }
    }
    if (cnt) {
        ans += to_string(cnt);
        ans += cur;
    }
    cout << ans << endl;
    return 0;
}