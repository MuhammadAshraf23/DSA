#include <iostream>
using namespace std;

int stack [5],top=-1;

void push(int x){
    if(top==4){
       cout << "Stack is Full" << "\n";

    }
    else{
        top++;
        stack[top]=x;
       
    }
}
void display(){
    if(top>=0){
        cout <<"Stack elements are: \n";
        for(int i=top; i>=0; i--){
            cout << stack[i] <<endl;
        
        }
    }
    else{
        cout <<"Stack is empty";
    }
}
void pop(){
    if(top==-1){
        cout<<"Stack is empty:"<<endl;

    }
    else{
       cout<<"The popped Elements are:" <<stack[top]<<endl;
        top--;
    }
}
int peek(){
    return stack[top];
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
   int y=peek();
   cout<<"peek element:"<<y<<endl;
}