#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int INF = 0x3f3f3f3f;

int item[105];
int dist[105][105];
vector<int> field[105];

int main()
{
	fastio;
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> item[i];
	
	for (int i = 1; i <= n; i++)
		fill(dist[i], dist[i] + 1 + n, INF);
	
	for (int i = 0; i < r; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		field[u].push_back(v);
		field[v].push_back(u);
		dist[u][v] = min(dist[u][v], d);
		dist[v][u] = min(dist[v][u], d);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	
	int maxitem = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] > m) continue;
			cnt += item[j];
		}
		maxitem = max(maxitem, cnt);
	}

	cout << maxitem;

}



