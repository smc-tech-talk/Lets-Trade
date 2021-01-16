# 📈 Stock Trading Game 
This is a fancy stock-trading game.

## Github Rules

##### Branch naming conventions

1. <working file>/<type>/<name>
  ex) stock.cpp/feat/new-feature
  ex) banking.cpp/test/multiuser-accounts
  ex) player.cpp/feat/sell-stock
  
2. types
 - feat : feature
 - new : something new
 - fix: error fix
 - update: any enhancement
 - build: build configuration update
 
##### Pushing branched

1. Pushing directly to the master branch will not be allowed.
2. Any push without a review will not be permitted.


## C++ grammar rules

1. When accessing a private variable, use `this->`
```cpp
class Person{
  private:
    string name;
  ...  
}

Person::Person(string n){
  name = n; // WRONG
  this->name = n; // YES!
}
```
