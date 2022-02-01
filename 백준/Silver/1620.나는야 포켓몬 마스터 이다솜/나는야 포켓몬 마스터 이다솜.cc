#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

bool isNumber(string str)
{
	for (auto& c : str)
		if (!isdigit(c)) return false;
	return true;
}

int main()
{
	fastio;
	map<string, int> dict1;
	map<int, string> dict2;
	string name, target;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> name;
		dict1[name] = i;
		dict2[i] = name;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> target;
		if (isNumber(target))
			cout << dict2[stoi(target)] << '\n';
		else
			cout << dict1[target] << '\n';
	}
}
