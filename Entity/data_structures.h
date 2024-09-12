#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

struct Node{
	int data;
	Node *next;
};

class Stack{
private:
    Node *head;
    Node *tail;
public:
    int length;
    Stack();
    void push(int);
    int pop();
};

class Queue{
private:
    Node *head;
    Node *tail;
public:
    int length;
    Queue();

    void enqueue(int);

    int dequeue();
};

#endif // DATASTRUCTURES_H
