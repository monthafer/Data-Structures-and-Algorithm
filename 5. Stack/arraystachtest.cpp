#include "arraystack.cpp"
#include <iostream>
#include <string>

using namespace std;

bool is_balanced(const string& expression)
// Postcondition: A true return value indicates that the parentheses in the given expression
// are balanced. Otherwise the return value is false.
// Library facilities used: stack, string (and using namespace std)
{
   // Meaningful names for constants
   const char LEFT_PARENTHESIS = '(';
   const char RIGHT_PARENTHESIS = ')';
   ArrayStack<char> store;
   // Stack to store the left parentheses as they occur
   size_type i; // An index into the string
   char next;
   // The next character from the string
   bool failed = false;
   // Becomes true if a needed parenthesis is not found
   for (i = 0; !failed && (i < expression.length( )); ++i){
       next = expression[i];
       if (next == LEFT_PARENTHESIS)
       store.push(next);
       else if ((next == RIGHT_PARENTHESIS) && (!store.empty( )))
       store.pop( ); // Pops the corresponding left parenthesis
       else if ((next == RIGHT_PARENTHESIS) && (store.empty( )))
       failed = true;
   }
   return (store.empty( ) && !failed);
}

int main() {
    ArrayStack<int> intStack;

    intStack.push(10);
    intStack.push(20);

    std::cout << "Top: " << intStack.top() << "\n";
    intStack.pop();
    std::cout << "Top after pop: " << intStack.top() << "\n";

    string unb = "(2+7(82-(7/8))+8)";
    string bal = "(21-9+(7*4/(98))-65";

    cout << "Is balanced " << unb << ": " << (is_balanced(unb)? "Yes" : "No") << "\n";
    cout << "Is balanced " << bal << ": " << (is_balanced(bal)? "Yes" : "No") << "\n";

    return 0;
}
