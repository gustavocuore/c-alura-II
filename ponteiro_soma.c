#include <stdio.h>

void soma(int* num, int a, int b) {
	*num = a + b;
	
}

int main() {
	int a = 2;
	int b = 5;
	int num;
	soma(&num, a, b);
	printf("a + b = %d", num);

}