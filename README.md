# Python_to_C_Transpiler
Proyecto final de Compiladores; implementa un esquema de traducción que permite convertir código escrito en Python a código en C. Las funcionalidades y limitaciones se encuentran en la documentacion TP_Oliver_Py2C.pdf.

## Uso
### Compilación y Ejecución de la V2
Para compilar y probar la versión 2 del transpilador, sigue estos pasos desde la carpeta  `v2`:

1. Generación del Analizador Léxico y Sintáctico:
```
bison -d -o parser.cpp parser.y
flex -o scanner.cpp scanner.l
```
2. Compilación del Código:
```
g++ main.cpp parser.cpp scanner.cpp -o parser

```
3. Testing:
OJO: Cada test.py, antes de probarlo,se debe guardar los archivos con una linea en blanco (UN ENTER) despues de la ultima linea de codigo para que funcionen correctamente.
```
./parser< test_files/test1.py
```
### Resultado
El resultado de la traducción se creará en un archivo llamado `output.c`.


