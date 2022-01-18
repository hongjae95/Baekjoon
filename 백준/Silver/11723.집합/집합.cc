#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int M, S, x; // S = 0000 0000 0000 0000 0000 0000 
string cmd;

int main()
{
	fastio;
	cin >> M;
	while (M--)
	{
		cin >> cmd;
		if (cmd == "add") // x 추가
		{
			cin >> x;
			S |= (1 << x);
		}
		else if (cmd == "remove") // x 제거
		{
			cin >> x;
			S &= ~(1 << x);
		}
		else if (cmd == "check")
		{
			cin >> x;
			if (S & (1 << x))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "toggle")
		{
			cin >> x;

			if (S & (1 << x)) // x가 있으면
				S &= ~(1 << x);
			else
				S |= (1 << x);

		}
		else if (cmd == "all")
		{
			S |= (1 << 21) - 2;
		}
		else if (cmd == "empty")
		{
			S &= 0;
		}
	}

}
