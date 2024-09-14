#include "../Include/core_functions.h"
#include "../Entity/data_structures.h"
#include <iostream>

using namespace std;

string removeWhiteSpace(string str){
	string result;
	for (size_t i = 0;i < str.size();i++){
		if (str[i] != ' '){
			result += str[i];
		}
	}
	return result;
}

bool isNumber(char c){
	if (c >= '0' && c <= '9'){
		return true;
	}else{
		return false;
	}
}

Queue encodeInfix(string infix){
	Queue infix_encoded;
	char temp;
	string numStr;
	numStr = "";

	for (size_t i = 0;i < infix.size();i++){
		temp = infix[i];
		if (isNumber(temp)){
			numStr += string() + temp;
		}else{
			if (numStr != ""){
				infix_encoded.enqueue(stoi(numStr));
				numStr = "";
			}
			if (temp == '-'){
				if (infix[i-1] == '('){
					infix_encoded.enqueue(-3);
				}else{
					infix_encoded.enqueue(-8);
				}
			}else if (temp == '('){
				infix_encoded.enqueue(-1);
			}else if (temp == ')'){
				infix_encoded.enqueue(-2);
			}else if (temp == '^'){
				infix_encoded.enqueue(-4);
			}else if (temp == '*'){
				infix_encoded.enqueue(-5);
			}else if (temp == '/'){
				infix_encoded.enqueue(-6);
			}else if (temp == '+'){
				infix_encoded.enqueue(-7);
			}else if (temp == '='){
				break;
			}
		}
	}
	if (numStr != ""){
		infix_encoded.enqueue(stoi(numStr));
		numStr = "";
	}
	return infix_encoded;
}

/*
	'(' = -1
	')' = -2
	'-' = -3/-8
	'^' = -4
	'*' = -5
	'/' = -6
	'+' = -7
*/

int getPriority(int c){
    switch(c){
    case -4:
        return 1;
    case -5:
    case -6:
        return 2;
    case -7:
    case -8:
        return 3;
    default:
        return 999;
    }
}

Queue infixToPostfix(Queue infix){
    Stack signs;
    Queue postfix;
    int temp;
    while (!infix.isEmpty()){
        int data = infix.dequeue();
        if (data >= 0){
            postfix.enqueue(data);
        }else if (data <= -4){
            while (getPriority(data) >= getPriority(signs.getTopData())){
                postfix.enqueue(signs.pop());
            }
            signs.push(data);
        }else if (data == -3 || data == -1){
            signs.push(data);
        }else if (data == -2){
            temp = signs.pop();
            while(temp != -1){
                postfix.enqueue(temp);
                temp = signs.pop();
            }
        }
    }
    while (!signs.isEmpty()){
        postfix.enqueue(signs.pop());
    }
    return postfix;
}


