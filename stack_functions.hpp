#ifndef stack_functions_hpp
#define stack_functions_hpp

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

namespace linked_lists{
    
    template <class T>
    struct node{
        
        T data;
        node<T>* prev;
        
    };
    
    template <class T>
    class stack{
        
    public:
        
        stack();
        ~stack();
        
        void push(T user_data);
        void pop();
        void sort(bool descending);
        void display();
        void clear_stack();
        
        node<T>* stack_ptr;
        node<T>* temp_ptr;
        
    };
}

#endif
