#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

long long N, ans;
int arr[1000001];
int temp[1000001];

void merge(int st, int mid, int en) // 정복
{
	int left = st, right = mid + 1, idx = st;
	while (left <= mid || right <= en)
	{
		if (right > en || (left <= mid && arr[left] <= arr[right]))
			temp[idx++] = arr[left++];
		else
		{
			temp[idx++] = arr[right++];
			ans += (mid - left + 1);
		}
	}

	for (int i = st; i <= en; i++) arr[i] = temp[i];
}

void mergeSort(int st, int en) // 분할
{
	if (st < en)
	{
		int mid = (st + en) / 2;
		mergeSort(st, mid);
		mergeSort(mid + 1, en);
		merge(st, mid, en);
	}
}

int main()
{
	fastio;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	mergeSort(0, N - 1);
	cout << ans;
}



