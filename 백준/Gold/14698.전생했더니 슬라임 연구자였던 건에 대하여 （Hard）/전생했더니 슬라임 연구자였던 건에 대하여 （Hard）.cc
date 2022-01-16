#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long>> pq;

unsigned long long t, n, x, sum, bunch;

int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        sum = 1;
        cin >> n;
        
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            pq.push(x);
        }

        if (n == 1)
        {
            cout << "1\n";
            pq.pop();
        }
        else
        {
            while (pq.size() != 1)
            {
                bunch = 1;

                bunch *= pq.top();
                pq.pop();
                bunch *= pq.top();
                pq.pop();

                sum = bunch % 1000000007 * sum % 1000000007;
  
                pq.push(bunch);
            }

            cout << sum << '\n';

            while (pq.size() != 0)
                pq.pop();
        }
    }
}

