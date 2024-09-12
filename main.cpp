#include <iostream>
#include "Entity/data_structures.h"
using namespace std;

int main()
{
    Stack S;
    Queue Q;

    S.push(10);
    cout<<S.pop()<<endl;

    Q.enqueue(99);
    Q.enqueue(100);
    cout<<Q.dequeue();
    return 0;
}
