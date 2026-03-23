#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack s;

    s.isEmpty();

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();

    s.pop();
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.isEmpty();
    
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.peek();
    s.display();

    return 0;
}

