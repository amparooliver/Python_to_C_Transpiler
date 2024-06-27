#include <stdio.h>

int main() {

int contador_externo = 0;
int limite_externo = 4;
int limite_interno = 6;
float acumulador = 0.0;
bool estado = true;
while (contador_externo < limite_externo) {
	if(estado) {
	if(acumulador == 0.0) {
	for (int indice_interno = 0; indice_interno <  limite_interno; indice_interno++) {
	acumulador = 1.5 + acumulador;
}
estado = false;
char mensaje[] = "El acumulador ha sido actualizado";
}
}
contador_externo = 1 + acumulador;
}
int resultado_final = acumulador;

return 0;
}
