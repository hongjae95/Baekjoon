#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

string pckmon[100001];

int main()
{
	fastio;
	map<string, int> dict;
	string name, target;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> name;
		dict[name] = i;
		pckmon[i] = name;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> target;
		auto it = dict.find(target);
		if (it == dict.end())
			cout << pckmon[stoi(target)] << '\n';
		else
			cout << it->second << '\n';
	}
}
