#include <iostream>
#include <fstream>
#include <map>
#include "parser.hpp"

extern int yylex();
extern std::map<std::string, std::string> symbol_table;
extern std::string* goalStr;


int main(int argc, char const *argv[]) {
    std::ofstream output_file("output.c");
    if (!output_file.is_open()) {
        std::cerr << "Error al abrir el archivo output.c" << std::endl;
        return 1;
    }

    int result = yylex();

    // Generar el archivo output.c
    output_file << "#include <stdio.h>\n\n";
    output_file << "int main() {\n\n";

    if (goalStr) {
        output_file << *goalStr << "\n";
    }

    output_file << "return 0;\n";
    output_file << "}\n";

    output_file.close();

    return result;
}