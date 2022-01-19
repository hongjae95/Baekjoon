#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int lcs[1001][1001];
int T;
string s1, s2;

int main()
{
	fastio;
	memset(lcs, 0, sizeof(lcs));
	cin >> s1 >> s2;
	if (s1.size() > s2.size())
		swap(s1, s2);

	for (int i = 1; i <= s1.size(); i++)
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}

	cout << lcs[s1.size()][s2.size()];
}
