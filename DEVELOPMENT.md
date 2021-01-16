# 📈 Stock Trading Game 
This is a fancy stock-trading game.

## Github Rules

##### Branch naming conventions

1. Skeleton

  **[ changed file ] / [ type ] / [ name ]**
 ```
    stock.cpp/feat/create-new-feature
    banking.cpp/test/create-multiuser-accounts
    player.cpp/feat/sell-stock
 ```
  
2. Type

 - feat : feature
 - new : something new
 - fix: error fix
 - update: any enhancement
 - build: build configuration update
 
3. Name

  Try to use **[ verb ] - [ noun ]** combination.
  verb: Always present tense.
  noun: Try not to use adjectives. 
    ex) make-~~fancy~~-feature
  ```
  // Good example
  create-class-Player (O)
  edit-class-Player (O)
  
  // Bad example of using ambiguous expressions
  delete-old-function (X) => delete-func-AddStock (O)
  ```
4. So it is important to think **`what to do`** before write codes and create a branch.
  
##### Pushing branches

1. Pushing directly to the master branch will not be allowed.
2. Any push without a review will not be permitted.
3. All pushes will go to smc-tech-talk/dev branch.
4. It is free to make as many branches as the contributor wants, but before you push it to smc-tech-talk/dev, **it is required to merge branches into [ username ]/dev branch.**
  ex) 
  ```
  /* Add changes and make commits */
  
  // ~ Coding 
  git add .
  git commit -m "Create AttckEveryone"
  
  // ~ Coding 
  git add .
  git commit -m "Finished final check of AttackEveryone"
  
  /* Checkout to your local dev branch */
  git checkout dev
  
  /* Then merge the branch into your local dev branch*/
  git merge banking.cpp/feat/add-new-feature
  
  /* Push your local dev branch to your forked Github repository */
  git push -u origin dev
  
  /* In Github */
   1. Make a pull request to smc-tech-talk/dev
  ```
  
## Commit naming rules

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
