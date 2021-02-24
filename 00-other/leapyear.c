#include<stdio.h>

int isleapyear(int year) {
	int isleapyear = 0;
	if(year % 4 == 0) {
		if(year % 100 == 0) {
			if(year % 400 == 0) {
				isleapyear = 1;
			}
		}
		isleapyear = 1;
	}
	return isleapyear;
}

int main() {
	int i;
	printf("input year:");
	scanf("%d",&i);
	if(isleapyear(i) == 1)
		printf("%d:isleapyear.",i);
	else 
		printf("%d:not leapyear.",i);
	return 0;
}
