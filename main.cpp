#include <iostream>
#include "Entity/data_structures.h"
#include "Include/core_functions.h"
#include "Include/test_function.h"
using namespace std;

int main()
{
    string infix = "7 - 34 *((-22)-1/5)+10";
    Queue infix_encoded = encodeInfix(infix);
    Queue postfix = infixToPostfix(infix_encoded);
    cout<<infix<<endl;
    printlnQueue(postfix);

    return 0;
}
