//
// Created by Tobe on 8/5/17.
//

#ifndef SYMBOL_TABLE_CPP_SYMBOL_TABLE_EXCEPTION_H
#define SYMBOL_TABLE_CPP_SYMBOL_TABLE_EXCEPTION_H

#include <exception>

class SymbolTableException : public std::exception {
public:
    const char *what() throw();
    SymbolTableException(const char*);
private:
    const char* message_;
};


#endif //SYMBOL_TABLE_CPP_SYMBOL_TABLE_EXCEPTION_H
