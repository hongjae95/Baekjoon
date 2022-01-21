#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
	fastio;
	int n, m, d;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	while (m--)
	{
		cin >> d;
		auto lo = lower_bound(v.begin(), v.end(), d);
		if (lo == v.end() || *lo != d)
			cout << "-1\n";
		else
			cout << lo - v.begin() << '\n';
	}
}
