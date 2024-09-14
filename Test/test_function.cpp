#include "../Include/test_function.h"
#include "../Entity/data_structures.h"
#include "../Include/core_functions.h"
#include <iostream>

using namespace std;

void printlnQueue(Queue Q){
    while (!Q.isEmpty()){
        cout<<Q.dequeue()<<" ";
    }
    cout<<endl;
}
