#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<pair<int, int>> v[105];
int indegree[105];
queue<int> q;
int need[105][105]; // i를 조립하는데 필요한 기본부품 j의 개수

int main()
{
	fastio;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;
		v[y].push_back({ x,k });
		indegree[x]++;
	}

	for (int i = 1; i <= N; i++)
		if (!indegree[i])
		{
			q.push(i);
			need[i][i] = 1;
		}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			auto nxt = v[cur][i];

			for (int j = 1; j <= N; j++)
			{
				need[nxt.first][j] += need[cur][j] * nxt.second;
			}

			indegree[nxt.first]--;

			if (!indegree[nxt.first]) q.push(nxt.first);
		}
	}

	for (int i = 1; i <= N; i++)
		if (need[N][i])
			cout << i << ' ' << need[N][i] << '\n';
	
}





