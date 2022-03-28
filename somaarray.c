#include <stdio.h>

void soma(int numeros[10]) {
    int total = 0;
    for(int i = 0; i < 10; i++) {
        total += numeros[i];
    }
    printf("O total é %d", total);
}

int main() {
	int numeros[10];

	numeros[0] = 2;
	numeros[1] = 2;
	numeros[2] = 2;
	numeros[3] = 2;
	numeros[4] = 2;
	numeros[5] = 2;
	numeros[6] = 2;
	numeros[7] = 2;
	numeros[8] = 2;
	numeros[9] = 2;

	soma(numeros);

}