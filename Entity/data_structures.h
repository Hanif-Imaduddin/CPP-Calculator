#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

struct Node{
	int data;
	Node *next;
};

struct NodeOfFloat{
    float data;
    NodeOfFloat *next;
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
    int getTopData();
    bool isEmpty();
};

class StackOfFloat{
private:
    NodeOfFloat *head;
    NodeOfFloat *tail;
public:
    int length;
    StackOfFloat();
    void push(float);
    float pop();
    float getTopData();
    bool isEmpty();
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
    bool isEmpty();
};

#endif // DATASTRUCTURES_H
