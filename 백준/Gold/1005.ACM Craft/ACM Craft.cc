#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> v[1005];
int res[1005];
int t[1005];
int indegree[1005];
queue<int> q;

void init()
{
	memset(res, 0, sizeof(res));
	memset(t, 0, sizeof(t));
	memset(indegree, 0, sizeof(indegree));
	
	for (int i = 0; i < 1005; i++)
		v[i].clear();
}

int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		init();
		int N, K, W;
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> t[i];
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			indegree[y]++;
			v[x].push_back(y);
		}
		cin >> W;

		for (int i = 1; i <= N; i++)
			if (!indegree[i])
			{
				res[i] = t[i];
				q.push(i);
			}

		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			
			for (int i = 0; i < v[cur].size(); i++)
			{
				int nxt = v[cur][i];
				
				res[nxt] = max(res[nxt], res[cur] + t[nxt]);
				indegree[nxt]--;
				if (!indegree[nxt]) q.push(nxt);
			}
		}
		cout << res[W] << '\n';
	}

}



