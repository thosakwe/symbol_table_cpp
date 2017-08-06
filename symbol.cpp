//
// Created by Tobe on 8/5/17.
//

#include "symbol.h"

template<typename T>
Symbol<T>::Symbol(std::string name) {
    name_ = name;
}

template<typename T>
Symbol<T>::Symbol(std::string name, T value) {
    name_ = name;
    value_ = value;
}

template<typename T>
std::string Symbol<T>::get_name() {
    return name_;
}

template<typename T>
T Symbol<T>::get_value() {
    return value_;
}

template<typename T>
void Symbol<T>::set_value(T value) {
    if (!constant_)
        value_ = value;
    else {
        std::string message = "Cannot overwrite the value of constant symbol \"" + name_ + "\".";
        throw new SymbolTableException(message.c_str());
    }
}

template<typename T>
bool Symbol<T>::is_constant() {
    return constant_;
}

template<typename T>
void Symbol<T>::MarkAsConstant() {
    constant_ = true;
}
