#include<stdio.h>

int fibonacci(int n) {
	if(n <= 1)return n;
	int first = 0;
	int second = 1;
	while(n-- > 1) {
		second += first;
		first = second - first;
	}
	return second;
}

int main() {
	printf("%d",fibonacci(10));
    return 0;
}