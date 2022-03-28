#include <stdio.h>
#include <math.h>

void potencia(int a, int b) {
	int pot = pow(a,b);
	printf("%d elevado a %d = %d", a, b, pot);
}

int main(){
	int a = 2;
	int b = 3;

	potencia(a,b);
}