#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char token[20];
    
    printf("Enter postfix expression (e.g., 5 3 + 2 *): ");
    
    while (scanf("%s", token) == 1) {
        // Check if token is a number
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            
            int b = pop();
            int a = pop();
            char op = token[0];
            
            if (op == '+') push(a + b);
            else if (op == '-') push(a - b);
            else if (op == '*') push(a * b);
            else if (op == '/') push(a / b);
        } else {
            // It's a number
            push(atoi(token));
        }
    }
    
    printf("Result: %d\n", stack[top]);
    return 0;
}