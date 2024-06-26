#include <stdio.h>

void recipeMenu();
void conParametros(int a, int b);

int main() {

// Se deberia trasladar esta declaracion fuera del main 
void recipeMenu() {
	int a = 2;
}
// Se deberia trasladar esta declaracion fuera del main 
void conParametros(int a, int b) {
	int c = a + b;
}
conParametros(2, 3);
recipeMenu();

return 0;
}
