#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
bitset<100000001> b;

int main()
{
	fastio;
	int n, m, x;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++)
	{
		cin >> x;
		b[x].flip();
	}

	cout << b.count();
}
	
