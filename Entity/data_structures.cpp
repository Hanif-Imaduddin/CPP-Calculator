#include "data_structures.h"
#include <iostream>

Stack::Stack() : tail(nullptr),head(nullptr),length(0) {}

void Stack::push(int data){
    if (this->tail == nullptr){
        this->head = new Node;
        this->head->data = data;
        this->head->next = nullptr;

        this->tail = this->head;
    }else{
        Node *temp = new Node;
        temp->data = data;
        temp->next = nullptr;

        this->tail->next = temp;
        this->tail = this->tail->next;
    }
    this->length++;
}

int Stack::pop(){
    if (this->head == nullptr){
        return -999;
    }else if (this->head->next == nullptr){
        int data = this->head->data;
        delete this->head;
        this->head = nullptr;
        this->tail = this->head;
        this->length--;
        return data;
    }else{
        int data = this->tail->data;
        Node *temp;
        temp = this->head;
        while (temp->next->next != nullptr){
            temp = temp->next;
        }
        temp->next = nullptr;
        delete this->tail;
        this->tail = temp;
        this->length--;
        return data;
    }
}

int Stack::getTopData(){
    if (this->tail != nullptr){
        return this->tail->data;
    }else{
        return -999;
    }
}

bool Stack::isEmpty(){
    return this->head == nullptr;
}

StackOfFloat::StackOfFloat() : tail(nullptr),head(nullptr),length(0) {}

void StackOfFloat::push(float data){
    if (this->tail == nullptr){
        this->head = new NodeOfFloat;
        this->head->data = data;
        this->head->next = nullptr;

        this->tail = this->head;
    }else{
        NodeOfFloat *temp = new NodeOfFloat;
        temp->data = data;
        temp->next = nullptr;

        this->tail->next = temp;
        this->tail = this->tail->next;
    }
    this->length++;
}

float StackOfFloat::pop(){
    if (this->head == nullptr){
        return -999;
    }else if (this->head->next == nullptr){
        float data = this->head->data;
        delete this->head;
        this->head = nullptr;
        this->tail = this->head;
        this->length--;
        return data;
    }else{
        float data = this->tail->data;
        NodeOfFloat *temp;
        temp = this->head;
        while (temp->next->next != nullptr){
            temp = temp->next;
        }
        temp->next = nullptr;
        delete this->tail;
        this->tail = temp;
        this->length--;
        return data;
    }
}

float StackOfFloat::getTopData(){
    if (this->tail != nullptr){
        return this->tail->data;
    }else{
        return -999;
    }
}

bool StackOfFloat::isEmpty(){
    return this->head == nullptr;
}

Queue::Queue() : head(nullptr),tail(nullptr),length(0){}

void Queue::enqueue(int data){
    Node *temp = new Node();
    temp->data = data;
    if (this->tail == nullptr){
        this->head = this->tail = temp;
    }else{
        this->tail->next = temp;
        this->tail = this->tail->next;
    }
    this->length++;
}

int Queue::dequeue(){
    int data = -999;
    if (this->head == nullptr){
        return data;
    }else if (this->head->next == nullptr){
        data = this->head->data;
        delete this->head;
        this->head = nullptr;
        return data;
    }else{
        data = this->head->data;
        Node *temp = this->head->next;
        delete this->head;
        this->head = temp;
        return data;
    }
}

bool Queue::isEmpty(){
    return this->head == nullptr;
}


