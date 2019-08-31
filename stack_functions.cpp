#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>
#include "stack_functions.hpp"

using namespace std;

namespace linked_lists{
    
    template <class T>
    stack<T>::stack(){
        
        cout << "+linkedlist\n";
        
        stack_ptr = NULL;
        temp_ptr = NULL;
        
    }
    
    template <class T>
    stack<T>::~stack(){
        
        cout << "-linkedlist\n";
        
    }
    
    template <class T>
    void stack<T>::push(T user_data){
        
        node<T>* n = new node<T>;
        
        n->data = user_data;
        
        if(stack_ptr != NULL){
            
            n->prev = stack_ptr;
            stack_ptr = n;
            
        }else{
            
            stack_ptr = n;
            n->prev = NULL;
            
        }
    }
    
    template <class T>
    void stack<T>::pop(){
        
        node<T>* pop_node = new node<T>;
        
        if(stack_ptr != NULL){
            
            pop_node = stack_ptr;
            stack_ptr = stack_ptr->prev;
                        
            delete pop_node;
            
        }else{
            
            cout << "stack list is empty.\n";
            
        }
    }
    
    template <class T>
    void stack<T>::sort(bool descending){
        
        bool sort_done(false);
        node<T>* n = new node<T>;
        node<T>* pop_node = new node<T>;
        
        if(stack_ptr->prev != NULL){
            
            while(sort_done != true){//sorts temp_ptr in ascending order (top, down)
                
                bool push_done(false);
                
                n = stack_ptr;
                stack_ptr = stack_ptr->prev;
                
                if(temp_ptr != NULL){
                    
                    while(push_done != true){
                        
                        if(temp_ptr == NULL){
                            
                            temp_ptr = n;
                            n->prev = NULL;
                            
                            push_done = true;
                            
                        }else{
                            
                            if(n->data >= temp_ptr->data){
                                
                                n->prev = temp_ptr;
                                temp_ptr = n;
                                
                                push_done = true;
                                
                                if(stack_ptr == NULL && n->data >= temp_ptr->data){
                                    
                                    sort_done = true;
                                    
                                }
                                
                            }else{
                                
                                pop_node = temp_ptr;
                                temp_ptr = temp_ptr->prev;
                                
                                pop_node->prev = stack_ptr;
                                stack_ptr = pop_node;
                                
                            }
                        }
                    }
                    
                }else{
                    
                    temp_ptr = n;
                    n->prev = NULL;
                    
                }
                
            }
            
            if(descending != true){
                
                while(temp_ptr != NULL){//sorts stack_ptr in ascending order (top, down)
                    
                    n = temp_ptr;
                    temp_ptr = temp_ptr->prev;
                    
                    n->prev = stack_ptr;
                    stack_ptr = n;
                    
                }
                
            }else{//sorts stack in descending order (top, down)
                
                stack_ptr = temp_ptr;
                temp_ptr = NULL;
                
            }
            
            cout << "sorting done.\n";
            
        }
    }
    
    template <class T>
    void stack<T>::display(){
        
        node<T>* display_node = new node<T>;
        
        if(stack_ptr != NULL){
            
            display_node = stack_ptr;
            
            while(display_node != NULL){
                
                cout << "node data: " << display_node->data << endl;
                display_node = display_node->prev;
                
            }
            
            if(display_node == NULL){
                
                cout << "stack end reached.\n";
                
            }
            
        }else{
            
            cout << "stack list is empty.\n";
            
        }
    }
    
    template <class T>
    void stack<T>::clear_stack(){
        
        if(stack_ptr != NULL){
            
            while(stack_ptr != NULL){
                
                node<T>* del_node = new node<T>;
                
                del_node = stack_ptr;
                stack_ptr = stack_ptr->prev;
                
                delete del_node;
                
            }
            
            cout << "stack cleared.\n";
            
        }else{
            
            cout << "stack list empty.\n";
            
        }
    }
}
