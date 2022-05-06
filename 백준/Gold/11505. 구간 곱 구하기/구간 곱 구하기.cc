#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<long long> arr;
vector<long long> tree;
const long long mod = 1'000'000'007;

void init(int node, int L, int R)
{
	if (L == R)
		tree[node] = arr[L];
	else
	{
		init(node * 2, L, (L + R) / 2);
		init(node * 2 + 1, (L + R) / 2 + 1, R);
		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod;
	}
}

long long mul(int node, int L, int R, int nodeL, int nodeR)
{
	if (nodeL > R || nodeR < L) return 1;
	if (nodeL <= L && R <= nodeR) return tree[node];
	return (mul(node * 2, L, (L + R) / 2, nodeL, nodeR) * mul(node * 2 + 1, (L + R) / 2 + 1, R, nodeL, nodeR)) % mod;
}

void update(int node, int L, int R, int idx, long long val)
{
	if (idx < L || idx > R)
		return;
	if (L == R)
	{
		arr[idx] = val;
		tree[node] = val;
		return;
	}
	update(node * 2, L, (L + R) / 2, idx, val);
	update(node * 2 + 1, (L + R) / 2 + 1, R, idx, val);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod;
}

int main()
{
	fastio;
	int N, M, K; // 수의 개수, 수 변경 횟수, 구간곱 구하기 횟수
	cin >> N >> M >> K;
	arr.resize(N, 1);
	int h = (int)ceil(log2(N));
	int sz = (1 << (h + 1));
	tree.resize(sz, 1);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) // 수 변경
			update(1, 0, N - 1, b - 1, c);
		else if (a == 2) // 구간곱 구하기
			cout << mul(1, 0, N - 1, b - 1, c - 1) << '\n';
	}
}





