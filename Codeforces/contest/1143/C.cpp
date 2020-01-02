#include <bits/stdc++.h>
using namespace std;
#define N int(1e5 + 10)
vector<int> tree[N];
struct node {
    int c; // =1 bu
    int p;
    int child_cnt;
    int not_respect;
} queens[N];
int main() {
    ios::sync_with_stdio(false);
    // FILE *file = freopen("../input", "r", stdin);
    int n;
    cin >> n;
    int p, c;
    for (int i = 1; i <= n; i++) {
        cin >> p >> c;
        if (p == -1)
            p += 1;
        queens[i].p = p;
        queens[i].c = c;
        tree[p].push_back(i);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        queens[i].child_cnt = tree[i].size();
        queens[i].not_respect = 0;
        for (int j = 0; j < tree[i].size(); j++) {
            queens[i].not_respect += queens[tree[i][j]].c;
        }
        if (queens[i].child_cnt == queens[i].not_respect && queens[i].c == 1) {
            pq.push(i);
        }
    }
    vector<int> ans;
    while (pq.empty() == false) {
        int tmp = pq.top();
        pq.pop();
        ans.push_back(tmp);
        set<int> s;
        s.insert(tmp);
        int parent = queens[tmp].p;
        queens[parent].child_cnt += queens[tmp].child_cnt;
        queens[parent].not_respect += queens[tmp].not_respect;
        if (queens[parent].child_cnt == queens[parent].not_respect &&
            queens[parent].c == 1) {
            if (s.count(tmp) == 0)
                pq.push(parent);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    if (ans.size() == 0)
        cout << -1;
    cout << endl;
    return 0;
}
