//
// Created by Tobe on 8/5/17.
//

#include "symbol_table_exception.h"

SymbolTableException::SymbolTableException(const char *message) {
    message_ = message;
}

const char *SymbolTableException::what() throw() {
    return message_;
}
