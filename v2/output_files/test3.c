#include <stdio.h>

void procedimiento();

int main() {

// Se deberia trasladar esta declaracion fuera del main 
void procedimiento() {
	int a = 2;
int b = 3;
int resultado = a + b;
printf("%d", resultado);
}
procedimiento();

return 0;
}
