#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> tree[100001];
bool vis[100001];
int val[100001];

int dfs(int root)
{
	if (val[root] > 0) return val[root];
	vis[root] = true;
	int ret = 1;
	for (int i = 0; i < tree[root].size(); i++)
	{
		int nxt = tree[root][i];
		if (vis[nxt]) continue;
		ret += dfs(tree[root][i]);
	}
	val[root] = ret;
	return ret;
}

int main()
{
	fastio;
	int N, R, Q;
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	val[R] = dfs(R);
	
	for (int i = 0; i < Q; i++)
	{
		int q;
		cin >> q;
		cout << val[q] << '\n';
	}
}



