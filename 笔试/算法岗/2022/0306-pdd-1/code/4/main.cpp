//给两个骰子，问经过几次翻转他们可以变成一样，给的顺序为上下左右前后。
//如果不能翻转成一样，返回-1
//翻转包括向前翻转、向后翻转、向左翻转和向右翻转
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nums;
void pern(vector<int> num, int cur) {
    if (cur == nums.size() - 1) {
        nums.push_back(num);
        return;
    } else {
        for (int i = cur; i < num.size(); i ++) {
            swap(num[i], num[cur]);
            pern(num, cur + 1);
            swap(num[i], num[cur]);
        }
    }
}
int n = 6*5*4*3*2;
int f[6*5*4*3*2 + 1];
void init() {
    for (int i = 0; i < n; i ++)    f[i] = i;
}
int findf(int x) {
    if (f[x] == x)  return x;
    f[x] = findf(f[x]);
    return f[x];
}
void join(int x, int y) {
    int fa = findf(x);
    int fb = findf(y);
    if (fa != fb)   f[y] = f[x];
}



// 上下左右前后
vector<int> front(vector<int> a) {
    vector<int> ret(a);
    ret[1] = a[4];
    ret[5] = a[1];
    ret[0] = a[5];
    ret[4] = a[0];
    return ret;
}
vector<int> back(vector<int> a) {
    vector<int> ret(a);
    ret[1] = a[5];
    ret[4] = a[1];
    ret[5] = a[0];
    ret[0] = a[4];
    return ret;
}
vector<int> left(vector<int> a) {
    vector<int> ret(a);
    ret[1] = a[2];
    ret[3] = a[1];
    ret[0] = a[3];
    ret[2] = a[0];
    return ret;
}
vector<int> right(vector<int>& a) {
    vector<int> ret(a);
    ret[2] = a[1];
    ret[1] = a[3];
    ret[3] = a[0];
    ret[0] = a[2];
    return ret;
}


int helper(vector<int> a, vector<int> b) {
    if (a == b) return 0;
    queue<vector<int>> q;
    map<vector<int>, bool> mp;
    q.push(a);
    mp[a] = true;
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i ++) {
            vector<int> tmp = q.front();
            q.pop();
            for (auto &it : tmp)    cout << it << " ";
            cout << endl;
            if (tmp == b)   return level;
            vector<int> f = front(a);
            vector<int> b = back(a);
            vector<int> l = left(a);
            vector<int> r = right(a);
            if (!mp[f]) q.push(f);
            if (!mp[b]) q.push(b);
            if (!mp[l]) q.push(l);
            if (!mp[r]) q.push(r);
            // q.push(f);
            // q.push(b);
            // q.push(l);
            // q.push(r);
            mp[f] = mp[b] = mp[l] = mp[r] = true;
        }
        level ++;
    }
    return -1;
}

int main() {
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++) {
        vector<int> v1(6), v2(6);
        for (int j = 0; j < 6; j ++)    cin >> v1[j];
        for (int j = 0; j < 6; j ++)    cin >> v2[j];
        cout << helper(v1, v2) << endl;
    }
    return 0;
}