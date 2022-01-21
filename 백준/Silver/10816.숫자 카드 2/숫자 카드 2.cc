#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
	fastio;
	int n, m;
	cin >> n;
	vector<int> v1(n);
	for (int i = 0; i < n; i++)
		cin >> v1[i];
	cin >> m;
	vector<int> v2(m);
	for (int i = 0; i < m; i++)
		cin >> v2[i];
	sort(v1.begin(), v1.end());

	for (int i = 0; i < m; i++)
	{
		auto lo = lower_bound(v1.begin(), v1.end(), v2[i]);
		auto hi = upper_bound(v1.begin(), v1.end(), v2[i]);

		cout << hi - lo << ' ';
	}
}
