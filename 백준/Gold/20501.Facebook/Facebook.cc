#include <iostream>
#include <string>
#include <bitset>
#define MAX 2001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bitset<2001> bs[MAX];
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		for(int j = 0; j < n; ++j){
			if(s[j] == '1'){
				bs[i].set(j);
			}
		}
	}
	int q;
	cin >> q;
	for(int k = 0; k < q; ++k){
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		cout << (bs[x] & bs[y]).count() << '\n';
	}
	return 0;
}