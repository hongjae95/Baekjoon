#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int main()
{
	fastio;
	int n;
	cin >> n;
	vector<bitset<2000>> bv(n);
	for (int i = 0; i < n; i++)
		cin >> bv[i];

	int q;
	cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << (bv[a - 1] & bv[b - 1]).count() << '\n';;
	}
}
	
