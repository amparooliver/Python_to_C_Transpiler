# Python_to_C_Transpiler
Este proyecto implementa un esquema de traducción que permite convertir código escrito en Python a código en C.

## Uso
### Compilación y Ejecución de la Versión Simplificada
Para compilar y probar la versión simplificada del transpilador, sigue estos pasos desde la carpeta  `simple_version_first`:

1. Generación del Analizador Léxico y Sintáctico:
```
flex simple_python_lexer.l
bison -d simple_python_parser.y
```
2. Compilación del Código:
```
gcc -o parser simple_python_parser.tab.c lex.yy.c -lfl
```
3. Ejecución:
```
./parser < input.txt
```
### Resultado
El resultado de la traducción se creará en un archivo llamado `output.c`.
