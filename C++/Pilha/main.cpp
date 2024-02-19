#include <stdlib.h>
#include <stack>
#include <iostream>

using namespace std;

stack<int> pilha;

void push(int data) {
    pilha.push(data);
}

void pop() {
    pilha.pop();
}

void top() {
    system("clear");
    cout << "Top: " << pilha.top();
}

void showStack() {
    system("clear");
    int i = 0;
    stack<int> pilhaAux = pilha;
    while (!pilhaAux.empty()) {
        cout << "\n" << pilhaAux.top();
        pilhaAux.pop();
    }
    
}

void menu() {
    int choice, dataPush;
    char opctionRepeat;
    do{
        system("clear");
        cout << "\n1. Push (Insert data in stack)";
        cout << "\n2. Pop (Remove data from stack)";
        cout << "\n3. See the top data";
        cout << "\n4. Show stack";
        cout << "\nPlease type your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("clear");
                cout << "Please type the number to insert in the stack: ";
                cin >> dataPush;
                push(dataPush);
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 4: 
                showStack();
            default: "Invalid optcion";
        }
        system("clear");
        cout << "Do you wanna repeat? (s|S): ";
        cin >> opctionRepeat;
    } while (opctionRepeat == 's' || opctionRepeat == 'S');
    cout << "Thanks for using my system! :)";
}

int main(){
    menu();
    return(0);
}