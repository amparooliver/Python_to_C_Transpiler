#include <iostream>
#include <fstream>
#include <map>
#include "parser.hpp" // Incluir el header generado por Bison
extern int yylex();
extern std::map<std::string, std::string> symbol_table; // Accede a la tabla de símbolos desde parser.hpp
extern std::string* goalStr;
//extern std::string funcProcStr[2];

int main(int argc, char const *argv[]) {
    std::ofstream output_file("output.c");

    if (!output_file.is_open()) {
        std::cerr << "Error al abrir el archivo output.c" << std::endl;
        return 1;
    }

    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output_file.rdbuf());

    if (!yylex()) {
        // Encabezado y función principal
        std::cout << "#include <iostream>\n\n";

        // Imprimir funciones y procedimientos
        /*if (!funcProcStr->empty()) {
            std::cout << *funcProcStr << "\n";
        }*/
      
        std::cout << "int main() {\n\n";

        // Imprimir el código generado por Bison (goalStr)
        std::cout << *goalStr << "\n";

        std::cout << "}\n";

        std::cout.rdbuf(coutbuf);
        output_file.close();

        return 0;
    } else {
        std::cerr << "Error al ejecutar yylex" << std::endl;
        output_file.close();
        return 1;
    }
}
