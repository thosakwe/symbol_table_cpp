//
// Created by Tobe on 8/5/17.
//

#ifndef SYMBOL_TABLE_CPP_SYMBOL_TABLE_H
#define SYMBOL_TABLE_CPP_SYMBOL_TABLE_H

#include <vector>
#include "symbol.h"

template<typename T>
class SymbolTable {
public:
    SymbolTable<T>();

    /**
     * Determines if this symbol table is the root of its hierarchy.
     * @return `true` if this symbol table has no parent.
     */
    bool is_root();

    /**
     * Creates a symbol within this scope, with the given value.
     * @param name
     * @param value
     * @return
     */
    Symbol<T>* Add(std::string name, T value);

    /**
     * Creates a new symbol table that is a child of this one, with its own scope.
     * @return
     */
    SymbolTable<T>* CreateChild();

    /**
     * Assigns a value to an existing symbol, or creates a new one.
     * @param name
     * @param value
     * @return
     */
    Symbol<T>* Put(std::string name, T value);

    /**
     * Finds an existing symbol.
     * @param name
     * @return
     */
    Symbol<T>* Resolve(std::string name);

    /**
     * Finds an existing symbol, or creates a new one.
     * @param name
     * @return
     */
    Symbol<T>* ResolveOrCreate(std::string name);

    /**
     * Entirely removes a symbol from the tree, if it exists.
     * @param name
     */
    void Remove(std::string name);
private:
    SymbolTable<T>(SymbolTable<T>*);

    std::vector<Symbol<T>*> symbols;
    SymbolTable* parent_;
};


#endif //SYMBOL_TABLE_CPP_SYMBOL_TABLE_H
