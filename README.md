# symbol_table
A simple symbol table implementation in C++.
A port of my [Dart version](https://github.com/thosakwe/symbol_table).

# Usage

```c++
#include "symbol_table.h"
 
int main() {
  SymbolTable<float> floats;
  
  // Create a new variable within this scope.
  floats.add("one", 1.0);
  floats.add("two_point_five", 2.5);
  
  // Set a variable within an ancestor, OR create a new variable if none exists.
  floats.put("two", 2.0);
  
  // Completely remove a variable.
  floats.remove("two");
  
  // Find a symbol, either in this symbol table or an ancestor.
  Symbol<float>* symbol = floats.Resolve("one");
  
  // Find OR create a symbol.
  Symbol<float>* symbol = floats.ResolveOrCreate("one");
  
  symbol->get_name(); // "one"
  symbol->get_value(); // 1.0
  symbol->is_constant(); // false
  
  // Mark a symbol as constant to prevent overwrites.
  symbol->MarkAsConstant();
  
  symbol->set_value(3.0); // Throws a SymbolTableException
  
  // Create a child scope.
  SymbolTable<T>* child = floats->CreateChild();
  
  // Children can have local values of symbols that *shadow* those of parents.
  child->add("one", 3.0);
}
```