#ifndef CORE_FUNCTIONS_H_INCLUDED
#define CORE_FUNCTIONS_H_INCLUDED
#include "../Entity/data_structures.h"
#include <iostream>

using namespace std;
bool isNumber(char);
string removeWhiteSpace(string);
Queue encodeInfix(string);
int getPriority(int);
Queue infixToPostfix(Queue);
#endif // CORE_FUNCTIONS_H_INCLUDED
