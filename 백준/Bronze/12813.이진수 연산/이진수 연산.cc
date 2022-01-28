#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int main()
{
	fastio;
	bitset<100000> b1;
	bitset<100000> b2;
	cin >> b1 >> b2;

	cout << (b1 & b2) << '\n';
	cout << (b1 | b2) << '\n';
	cout << (b1 ^ b2) << '\n';
	cout << (~b1) << '\n';
	cout << (~b2) << '\n';
}
	
