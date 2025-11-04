#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int A[101];


long long int factorial(long long int a) {
	if (a == 0) {
		return 1;
	}
	if (A[a] == 0) {
		A[a] = a * factorial(a - 1);
	}
	return A[a];
}


long long int nCr(int a, int b) {
	long long int n = a;
	if (b == 0) {
		return 1;
	}
	for (int i = a - 1; i >= a - b + 1; i--) {
		n *= i;
	}
	return n / factorial(b);
}


int main() {

	long long int A[17][17];
	long long int t = 1;
	int n, m, k;
	int a, b = 0;      //k의 좌표
	
	scanf("%d %d %d", &n, &m, &k);
	
	for (int i = 1; i <= n; i++) {			//m * n칸의 배열에 각각 숫자 부여
		for (int j = 1; j <= m; j++) {
			A[i][j] = t;
			t++;
		}
	}
	
	if (k == 0) {							//O로 표시된 칸이 없는 경우
		printf("%lld", nCr(m+n-1-1, n-1));		//(1, 1)에서 (m, n)으로 가는 경우의 수를 구한다.
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {		//O로 표시된 칸의 좌표를 (a,b)로 설정
				if (A[i][j] == k) {
					a = j;
					b = i;
				}
			}
		}
		
		printf("%lld\n", nCr(a + b - 2, b - 1) * nCr(m + n - a - b, n - b));
	}
	return 0;
}
