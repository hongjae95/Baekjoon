#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> v[1005];
queue<int> q;
int indegree[1005];
int sz[1005];

int main()
{
	fastio;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		indegree[y]++;
	}

	for (int i = 1; i <= N; i++)
		if (!indegree[i])
		{
			q.push(i);
			sz[i] = 1;
		}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			sz[nxt] = max(sz[nxt], sz[cur] + 1);
			indegree[nxt]--;
			if (!indegree[nxt])
				q.push(nxt);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << sz[i] << ' ';
}





