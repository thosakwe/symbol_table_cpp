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
}
```