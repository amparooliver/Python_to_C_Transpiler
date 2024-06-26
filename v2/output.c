#include <stdio.h>

int main() {

int edad = 25;
int otro = 1;
bool puede_votar = false;
if(edad < 18) {
puede_votar = false;
otro = 0;
} else if(edad > 18) {

puede_votar = true;
}
else {
puede_votar = true;
otro = 0;
}
return 0;
}
