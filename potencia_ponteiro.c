#include <stdio.h>
#include <math.h>

void potencia(int* resultado, int a, int b) {
	*resultado = pow(a,b);
	printf("%d elevado a %d = %d", a, b, *resultado);
}

int main() {
	int resultado;
	potencia(&resultado, 10, 5);
}