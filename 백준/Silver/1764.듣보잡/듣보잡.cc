#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int v[100], w[100], dp[10001];

int main()
{
	fastio;
	set<string> s1, s2;
	int n, m;
	string str;
	cin >> n >> m;
	while (n--)
	{
		cin >> str;
		s1.insert(str);
	}

	while (m--)
	{
		cin >> str;
		if (s1.count(str))
			s2.insert(str);
	}

	cout << s2.size() << '\n';

	for (auto& e : s2)
		cout << e << '\n';

}
