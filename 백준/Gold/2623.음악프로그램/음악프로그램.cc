#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> v[1005];
vector<int> res;
int indegree[1005];
queue<int> q;

int main()
{
	fastio;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int k, st, en;
		cin >> k;
		if (k == 0) continue;
		cin >> st;
		if (k == 1) continue;
		for (int j = 0; j < k - 1; j++)
		{
			cin >> en;
			v[st].push_back(en);
			indegree[en]++;
			st = en;
		}
	}

	for (int i = 1; i <= N; i++)
		if (!indegree[i]) q.push(i);

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		res.push_back(cur);

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			indegree[nxt]--;
			if (!indegree[nxt]) q.push(nxt);
		}
	}

	if (res.size() != N)
		cout << 0;
	else
		for (int i = 0; i < N; i++)
			cout << res[i] << '\n';
}



