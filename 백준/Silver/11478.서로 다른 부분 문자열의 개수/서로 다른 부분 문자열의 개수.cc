#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
	fastio;
	set<string> s;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		for (int j = 0; j < str.size(); j++)
			s.insert(str.substr(i, j));

	cout << s.size();
}
