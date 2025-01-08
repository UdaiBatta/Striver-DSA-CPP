#include<iostream>
using namespace std;

struct Person{
    public:

    int data;
    Person* next;

    Person(int data){
        this->data = data;
        this->next = nullptr;
    }
};