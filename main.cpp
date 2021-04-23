//
//  main.cpp
//  TowersOfHanoi
//
//  Created by Alec Garza on 4/23/21.
//  Copyright © 2021 Alec Garza. All rights reserved.
//

#include <iostream>
#include <math.h>
struct Node{
    int diam;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack();
    bool push(int);
    int pop();
    int peek();
    int count();
    void print();
    bool isEmpty();
};

Stack::Stack(){
    top = NULL;
}

bool Stack::push(int diam){
    bool status = false;
    Node* temp = new Node();
    temp->diam = diam;
    temp->next = top;
    top = temp;
    if(top->diam == diam){
        status = true;
    }
    return status;
}

bool Stack::isEmpty(){
    bool status = false;
    if(top == NULL){
        status = true;
    }
    return status;
}

int Stack::pop(){
    int value = INT_MIN;
    if(top){
        Node* temp = top;
        value = temp->diam;
        top = temp->next;
        delete(temp);
    }
    return value;
}

int Stack::count(){
    int count = 0;
    Node* temp = top;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

int Stack::peek(){
    int value = INT_MIN;
    if(top){
        value = top->diam;
    }
    return value;
}

void Stack::print(){
    Node* temp = top;
    while(temp){
        std::cout << temp->diam << ' ';
        temp = temp->next;
    }
}

void moveDisk(Stack *source, Stack *destination){
    int tower1Top = source->pop();
    int tower2Top = destination->pop();
    
    if(tower1Top == INT_MIN){
        source->push(tower2Top);
    }
    else if(tower2Top ==INT_MIN){
        destination->push(tower1Top);
    }
    else if(tower1Top > tower2Top){
        source->push(tower1Top);
        source->push(tower2Top);
    }
    else{
        destination->push(tower2Top);
        destination->push(tower1Top);
    }
}


int main() {
    Stack towerOne;
    Stack towerTwo;
    Stack towerThree;
    int towerSize = 10;
    
    if(towerOne.isEmpty() && towerTwo.isEmpty() && towerThree.isEmpty()){
        std::cout << "Three empty stacks created" << std::endl;
    }
    std::cout << '\n';
    
    std::cout << "Putting " << towerSize << " plates of subsequently smaller diameter on towerOne" << std::endl;
    for(int i=towerSize; i>0; i--){
        towerOne.push(i);
    }
    std::cout << '\n';
    
    std::cout << "Printing Tower One: " << std::endl;
    towerOne.print();
    std::cout << '\n';
    std::cout << '\n';
    
    std::cout << "Testing pop() on Tower One (removing top value):" << std::endl;
    std::cout << towerOne.pop() << std::endl;
    std::cout << "Tower Size is now " << towerSize-1 << std::endl;
    std::cout << '\n';
    
    std::cout << "Printing updated list:" << std::endl;
    towerOne.print();
    std::cout << '\n';
    std::cout << '\n';
    
    std::cout << "Testing peek()" << std::endl;
    std::cout << towerOne.peek() << std::endl;
    std::cout << '\n';
    
    std::cout << "Testing count()" << std::endl;
    std::cout << towerOne.count() << std::endl;
    std::cout << '\n';
    
    int total_moves = pow(2, towerOne.count()) - 1;
    
    std::cout << "Running Towers of Hanoi algorithm" << std::endl;
    if(towerOne.count()%2 != 0){
        for(int i=1; i<=total_moves; i++){
            if(i%3==1){
                moveDisk(&towerOne, &towerThree);
            }
            else if(i%3==2){
                moveDisk(&towerOne, &towerTwo);
            }
            else if(i%3==0){
                moveDisk(&towerTwo, &towerThree);
            }
        }
    }
    else if(towerOne.count()%2==0){
        for(int i=1; i<=total_moves; i++){
            if(i%3==1){
                moveDisk(&towerOne, &towerTwo);
            }
            else if(i%3==2){
                moveDisk(&towerOne, &towerThree);
            }
            else if(i%3==0){
                moveDisk(&towerTwo, &towerThree);
            }
        }
    }
    
    std::cout << "Checking Tower Three count is equal to " << towerSize-1 << std::endl;
    std::cout << "Tower Three Count: " << towerThree.count() << std::endl;
    std::cout << "\n";
    std::cout << "Checking Tower Three elements are in ascending order " << std::endl;
    towerThree.print();
    std::cout << "\n";

}

