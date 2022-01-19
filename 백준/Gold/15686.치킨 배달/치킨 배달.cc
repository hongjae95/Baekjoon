#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

#define X first
#define Y second
#define MAX 200

typedef struct Info {
	int x;
	int y;
	int min_dist;
}info;

int res = 1e9;
int n, m;
int city[51][51];
bool check[51][51];
vector<pair<int, int>> ck_all;
vector<pair<int, int>> ck_set;
vector<Info> home;

void set_ck(int cnt, int st)
{
	if (cnt == m) // 치킨집 확정되면 거리 구하기
	{
		int dist_sum = 0;
		memset(city, -1, sizeof(city));

		// 각 집에서 가장 가까운 치킨집까지의 거리 갱신
		for (int i = 0; i < home.size(); i++)
			for (int j = 0; j < ck_set.size(); j++)
				if (home[i].min_dist > abs(home[i].x - ck_set[j].X) + abs(home[i].y - ck_set[j].Y))
					home[i].min_dist = abs(home[i].x - ck_set[j].X) + abs(home[i].y - ck_set[j].Y);

		// 최소 거리 총합
		for (auto e : home)
			dist_sum += e.min_dist;

		// 결과값 갱신
		if (dist_sum < res)
			res = dist_sum;

		for (int i = 0; i < home.size(); i++)
			home[i].min_dist = MAX;

		return;
	}

	// 치킨집 고르기
	for (int i = st; i < ck_all.size(); i++)
	{
		if (check[ck_all[i].X][ck_all[i].Y]) continue;
		check[ck_all[i].X][ck_all[i].Y] = true;
		ck_set.push_back({ ck_all[i].X, ck_all[i].Y });
		set_ck(cnt + 1, i + 1);
		ck_set.pop_back();
		check[ck_all[i].X][ck_all[i].Y] = false;
	}
}

int main()
{
	fastio;
	cin >> n >> m;
	memset(city, -1, sizeof(city));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1)
			{
				info temp = { i,j,MAX };
				home.push_back(temp);
			}
			if (city[i][j] == 2)
				ck_all.push_back({ i,j });
		}

	for (int i = 0; i < ck_all.size(); i++)
	{
		if (check[ck_all[i].X][ck_all[i].Y]) continue;
		check[ck_all[i].X][ck_all[i].Y] = true;
		ck_set.push_back({ ck_all[i].X, ck_all[i].Y });
		set_ck(1, i + 1);
		ck_set.pop_back();
		check[ck_all[i].X][ck_all[i].Y] = false;
	}

	cout << res;
}
