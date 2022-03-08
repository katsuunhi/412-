#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    //12 33 235 444 123
    for (int i = 0; i < t; i ++) {
        int n;
        // string n;
        cin >> n;
        // cout << n.find(to_string(i)) << endl;
        // long long ret = 0;
        for (int j = 1; j <= n; j ++) {
            string num;
            cin >> num;
            if (num.find(to_string(j)) != num.npos)
            cout << j << endl;
            // long long num;
            // int x = (int)(log(j)/log(10));
            // long long p = pow(10, x + 1);
            // cin >> num;
            // while (num) {
            //     // cout << num << " ";
            //     if (num%p == j) {
            //         ret ++;
            //         // cout << "is";
            //         break;
            //     }
                
            //     num /= 10;
            // }

        }
        // cout << ret << endl;
        // cout << log(50)/log(10) << endl;
    }
    return 0;
}