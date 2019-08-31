#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>
#include "stack_functions.hpp"
#include "stack_functions.cpp"

using namespace std;
using namespace linked_lists;

int main(){
    
    stack<int> istack1;
    stack<int> istack2;
    stack<int> istackm;
    
    int option(0), user_num(0);
    bool program_end(false), descending(true), first_stack(true);
    
    while(program_end != true){
        
        if(first_stack != true){
            
            cout << "<<<< STACK 2 <<<<" << endl;
            
        }else{
            
            cout << "<<<< STACK 1 <<<<" << endl;
            
        }
        
        cout << "0 - switch stack" << endl;
        cout << "1 - push" << endl;
        cout << "2 - pop" << endl;
        cout << "3 - sort" << endl;
        cout << "4 - merge" << endl;
        cout << "5 - display" << endl;
        cout << "6 - exit" << endl;
        cin >> option;
        
        switch(option){
                
            case 0:
                
                cout << "switching stack.\n";
                
                if(first_stack == true){
                    
                    first_stack = false;
                    
                }else{
                    
                    first_stack = true;
                    
                }
                
                break;
                
            case 1:
                
                cout << "enter data: ";
                cin >> user_num;
                
                if(first_stack != true){
                    
                    istack2.push(user_num);
                    
                }else{
                
                    istack1.push(user_num);
                    
                }
                
                break;
                
            case 2:
                
                if(first_stack != true){
                    
                    cout << "node " << istack2.stack_ptr->data << " popped" << endl;
                    istack2.pop();
                    
                }else{
                    
                    cout << "node " << istack1.stack_ptr->data << " popped" << endl;
                    istack1.pop();
                    
                }
                
                break;
                
            case 3:
                
                cout << "sort in (top, down)\n (1)descending\n (2)ascending\n";
                cin >> option;
                
                switch(option){
                    case 1:
                        
                        descending = true;
                        
                        break;
                        
                    case 2:
                        
                        descending = false;
                        
                        break;
                        
                    default:
                        
                        cout << "invalid input.\n";
                        
                        break;
                }
                
                if(first_stack != true){
                    
                    istack2.sort(descending);
                    
                }else{
                    
                    istack1.sort(descending);
                    
                }
                
                break;
                
            case 4:
                
                cout << "merging lists.\n";
                
                if(istack1.stack_ptr != NULL || istack2.stack_ptr != NULL){
                    
                    if(istack1.stack_ptr != NULL){
                        
                        while(istack1.stack_ptr != NULL){
                            
                            istackm.push(istack1.stack_ptr->data);
                            istack1.pop();
                            
                        }
                        
                        cout << "stack 1 loaded to merge.\n";
                        
                    }else{
                        
                        cout << "stack 1 list is empty.\n";
                        
                    }
                    
                    if(istack2.stack_ptr != NULL){
                        
                        while(istack2.stack_ptr != NULL){
                            
                            istackm.push(istack2.stack_ptr->data);
                            istack2.pop();
                            
                        }
                        
                        cout << "stack 2 loaded to merge.\n";
                        
                        
                    }else{
                        
                        cout << "stack 2 list is empty.\n";
                        
                    }
                    
                    descending = true;
                    istackm.sort(descending);
                    istackm.display();
                    istackm.clear_stack();
                    
                }else{
                    
                    cout << "both stacks empty.\n";
                    
                }
                
                break;
                
            case 5:
                
                if(first_stack != true){
                    
                    istack2.display();
                    
                }else{
                    
                    istack1.display();
                    
                }
                
                break;
                
            case 6:
                
                cout << "exiting program.\n";
                program_end = true;
                
                break;
                
            default:
                
                cout << "invalid input.\n";
                
                break;
        }
    }
    
    return 0;
}


