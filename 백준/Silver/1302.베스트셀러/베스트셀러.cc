#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
	fastio;
	map<string, int> m;
	string str;
	int n, cnt = 0;
	cin >> n;
	while (n--)
	{
		cin >> str;
		m[str]++;
	}

	for (auto& e : m)
		cnt = max(cnt, e.second);
	
	for (auto& e : m)
		if (e.second == cnt)
		{
			cout << e.first;
			return 0;
		}
}
