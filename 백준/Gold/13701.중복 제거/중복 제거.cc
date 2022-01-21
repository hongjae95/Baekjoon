#pragma GCC optimize("Ofast")
#include<unistd.h>
#include<cstdio>
int iptr, left;
char ibuf[1<<16];
char read_ch() {
	if (iptr >= left) left = read(0, ibuf, sizeof ibuf), iptr = 0;
	if (!left) return -1;
	return ibuf[iptr++];
}
int read() {
	int x = 0;
	for (;;) {
		char c = read_ch();
		switch (c) {
			case -1: return -1;
			case 48 ... 57: x = x*10 + (c - 48); break;
			default: return x;
		}
	}
}
int d[1<<20];
int main()
{
	for (int i; ~(i = read());) {
		if (d[i>>5]>>(i&31)&1) continue;
		printf("%d ", i);
		d[i>>5] |= 1 << (i&31);
	}
	return 0;
}