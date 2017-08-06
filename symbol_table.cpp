//
// Created by Tobe on 8/5/17.
//

#include "symbol_table.h"

template <typename T>
SymbolTable<T>::SymbolTable() {
    parent_ = nullptr;
}

template <typename T>
SymbolTable<T>::SymbolTable(SymbolTable<T> *parent) {
    parent_ = parent;
}

template <typename T>
bool SymbolTable<T>::is_root() {
    return parent_ == nullptr;
}

template <typename T>
Symbol<T> *SymbolTable<T>::Add(std::string name, T value) {
    for (unsigned int i = 0; i < symbols.size(); i++) {
        Symbol<T>* symbol = symbols.at(i);

        if (!symbol->get_name().compare(name)) {
            std::string message = "";
            throw new SymbolTableException(message.c_str());
        }
    }

    Symbol<T>* new_symbol = new Symbol<T>(name, value);
    symbols.push_back(new_symbol);
    return new_symbol;
}

template <typename T>
Symbol<T> *SymbolTable<T>::Put(std::string name, T value) {
    Symbol<T>* symbol = ResolveOrCreate(name);
    symbol->set_value(value);
    return symbol;
}

template <typename T>
Symbol<T> *SymbolTable<T>::Resolve(std::string name) {
    SymbolTable<T>* symbolTable = this;

    while (symbolTable != nullptr) {
        for (unsigned int i = 0; i < symbolTable->symbols.size(); i++) {
            Symbol<T>* symbol = symbolTable->symbols.at(i);

            if (!symbol->get_name().compare(name))
                return symbol;
        }

        symbolTable = symbolTable->parent_;
    }

    return nullptr;
}

template <typename T>
Symbol<T> *SymbolTable<T>::ResolveOrCreate(std::string name) {
    Symbol<T>* resolved = Resolve(name);
    if (resolved != nullptr) return resolved;
    Symbol<T>* new_symbol = new Symbol<T>(name);
    symbols.push_back(new_symbol);
    return new_symbol;
}

template <typename T>
void SymbolTable<T>::Remove(std::string name) {
    SymbolTable<T>* symbolTable = this;
    int index = -1;

    while (index == -1 && symbolTable != nullptr) {

        for (unsigned int i = 0; i < symbolTable->symbols.size(); i++) {
            Symbol<T>* symbol = symbolTable->symbols.at(i);

            if (!symbol->get_name().compare(name)) {
                index = i;
                break;
            }
        }

        symbolTable = symbolTable->parent_;
    }

    if (index != -1 && symbolTable != nullptr) {
        symbolTable->symbols.erase(symbolTable->symbols.begin() + index);
    }

}

template <typename T>
SymbolTable<T> *SymbolTable::CreateChild() {
    return new SymbolTable<T>(this);
}
