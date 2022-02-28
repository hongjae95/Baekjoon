#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> v[505];
int res[505];
int t[505];
int indegree[505];
queue<int> q;

int main()
{
	fastio;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> t[i];
		while (1)
		{
			int prev;
			cin >> prev;
			if (prev == -1) break;
			indegree[i]++;
			v[prev].push_back(i);
		}
	}

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

	for (int i = 1; i <= N; i++)
		cout << res[i] << '\n';
}



