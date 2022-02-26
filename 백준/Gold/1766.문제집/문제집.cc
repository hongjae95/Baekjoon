#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> v[32005];
int indegree[32005];
priority_queue<int, vector<int>, greater<>> pq;

int main()
{
	fastio;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= N; i++)
		if (!indegree[i])
			pq.push(i);

	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		cout << cur << ' ';
		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			indegree[nxt]--;
			if (!indegree[nxt]) pq.push(nxt);
		}
	}
}



