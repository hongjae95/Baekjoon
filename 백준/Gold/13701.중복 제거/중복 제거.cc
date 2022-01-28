#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
bitset< 1 << 25> b;

int main()
{
	fastio;
	int n;
	while (cin >> n)
	{
		if (b[n] == 1) continue;
		cout << n << ' ';
		b[n] = 1;
	}
}
	
