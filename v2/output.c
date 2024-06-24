#include <iostream>

int main() {

int puntaje = 91;
char nota_final[] = "No sacaste cinco";
char le_quiero_al_alumno[] = "No";
if(puntaje >= 90) {
if(le_quiero_al_alumno == "Si") {
nota_final = "FELICIDADES!! Sacaste un 5!!";
} else {
nota_final = "Sacaste un 5 Juan, chau, no te quiero ver mas";
}
}

}
