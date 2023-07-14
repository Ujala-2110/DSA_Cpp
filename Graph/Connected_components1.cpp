#include <bits/stdc++.h>
using namespace std;

vector <int> v[15];
bool vis[15];

void dfs(int s) {
	vis[s] = true;
	for (auto it :v[s]) {
		if (vis[it] == false) {
			dfs(it);
		}
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	// for (int i = 0; i <= n; i++) {
	// 	v[i].clear();
	// }

	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		//cout << x << " " << y << endl;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	// memset(vis, false, sizeof(vis));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}