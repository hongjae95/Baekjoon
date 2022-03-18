#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
    int cnt, num, sum, avg;
    double add;
    int arr[1000] = { 0 };
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++) {
        scanf("%d", &num);
        sum = 0;
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        avg = sum / num;
        add = 0;
        for (int i = 0; i < num; i++) {
            if (arr[i] > avg) {
                add++;
            }
        }
        printf("%.3lf%%\n", (add * 100) / num);
    }

}
