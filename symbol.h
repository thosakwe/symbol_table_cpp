//
// Created by Tobe on 8/5/17.
//

#ifndef SYMBOL_TABLE_CPP_SYMBOL_H
#define SYMBOL_TABLE_CPP_SYMBOL_H

#include <string>
#include "symbol_table_exception.h"

/**
 * Stores a named value of a specific type.
 * @tparam T
 */
template<typename T>
class Symbol {
public:
    Symbol(std::string);
    Symbol(std::string, T);

    std::string get_name();
    T get_value();

    /**
     * Assigns a value to this symbol. Will throw an exception on a constant symbol.
     * @throws SymbolTableException
     */
    void set_value(T);

    bool is_constant();

    /**
     * Marks this symbol as constant.
     */
    void MarkAsConstant();
private:
    std::string name_;
    T value_;
    bool constant_;
};


#endif //SYMBOL_TABLE_CPP_SYMBOL_H
