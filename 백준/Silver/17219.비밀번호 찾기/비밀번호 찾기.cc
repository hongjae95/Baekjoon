#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int main()
{
	fastio;
	int N, M;
	unordered_map<string, string> m;
	cin >> N >> M;
	while (N--)
	{
		string id, pw;
		cin >> id >> pw;
		m[id] = pw;
	}

	while (M--)
	{
		string id;
		cin >> id;
		cout << m[id] << '\n';
	}
}
