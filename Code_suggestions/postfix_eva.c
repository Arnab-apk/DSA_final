#include <stdio.h>
#include <ctype.h> // Needed for the isdigit() function

#define MAX 100

// --- Simple Array-Based Stack ---
int stack[MAX];
int top = -1;

// Push a number onto the stack
void push(int val) {
    if (top > MAX) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

// Pop a number off the stack
int pop() {
    if (top ==-1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// --- Postfix Evaluation Function ---
int evaluatePostfix(char* exp) {
    int i = 0;
    
    // Read the string character by character until we hit the null terminator '\0'
    while (exp[i] != '\0') {
        
        // If the character is a blank space, just skip it
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // STEP 1: If the character is a number, push it to the stack
        if (isdigit(exp[i])) {
            // Note: exp[i] is a character (like '5'). 
            // To convert it to the actual integer number 5, we subtract the character '0'.
            push(exp[i] - '0'); 
        } 
        // STEP 2: If the character is an operator, pop two elements and do the math
        else {
            int val1 = pop(); // The top element (right side of the equation)
            int val2 = pop(); // The second element (left side of the equation)
            
            // Apply the operator and push the result back onto the stack
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
        i++; // Move to the next character in the expression
    }
    
    // STEP 3: The final result is the only number left in the stack!
    return pop(); 
}

// --- Main function to test it ---
int main() {
    // Example: "2 3 1 * + 9 -" 
    // This evaluates to: 2 + (3 * 1) - 9 = -4
    char exp[] = "231*+9-"; 
    
    printf("Postfix Expression: %s\n", exp);
    
    int result = evaluatePostfix(exp);
    
    printf("Evaluation Result: %d\n", result);
    
    return 0;
}