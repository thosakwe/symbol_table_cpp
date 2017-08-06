//
// Created by Tobe on 8/5/17.
//

#include <iostream>
#include "symbol_table.h"

int main() {
    SymbolTable<int> symbolTable;
    symbolTable.Add("one", 1);

    std::cout << symbolTable.Resolve("one")->get_value() << std::endl;
}