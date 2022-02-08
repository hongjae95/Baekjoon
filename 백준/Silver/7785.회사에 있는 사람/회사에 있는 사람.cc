#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int main()
{
	fastio;
	unordered_set<string> s;
	int n;
	cin >> n;
	while (n--)
	{
		string name, cmd;
		cin >> name >> cmd;
		if (cmd == "enter")
			s.insert(name);
		else if (cmd == "leave")
			s.erase(name);
	}

	vector<string> v(s.begin(), s.end());
	sort(v.begin(), v.end(), greater<string>());
	for (auto& e : v)
		cout << e << '\n';
}
