#include <stdio.h>

int main() {

char variable[] = "Hello World!!!";
// variable = 2024; // Asignacion no valida en C, revisar si afecta el flujo 
int numero = 10;
numero = 10.567;
// printf("%?", variable); // Print no valido en C, revisar si afecta el flujo 
printf("%d", numero);

return 0;
}
