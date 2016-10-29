#include <stdio.h>
#include <string.h>
#define n1 100005
int data[n1];
int main() {
	int T, n,a,b;

	memset(data, 0, sizeof(data));

	for(int m = 1; m < n1; m++) {
		a = m;
		b = m;
		while(a > 0) { 
			b += a % 10;
			a /= 10; 
		}
		if(data[b] == 0 || m < data[b]) 
			data[b] = m;
	}

  
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		printf("%d\n", data[n]);
	}
return 0;
}