#include <stdio.h>
#include<conio.h>
#define MAX_SIZE 100

// Function to check if parentheses are balanced
int isBalanced(char expression[]) {
    char stack[MAX_SIZE];
    int top = -1,i;

    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            stack[++top] = expression[i];
        } else if (expression[i] == ')') {
            if (top >= 0 && stack[top] == '(') {
                top--;
            } else {
                return 0; // Unmatched closing parenthesis
            }
        } else if (expression[i] == ']') {
            if (top >= 0 && stack[top] == '[') {
                top--;
            } else {
                return 0; // Unmatched closing square bracket
            }
        } else if (expression[i] == '}') {
            if (top >= 0 && stack[top] == '{') {
                top--;
            } else {
                return 0; // Unmatched closing curly brace
            }
        }
    }

    return top == -1 ? 1 : 0; // If the stack is empty, parentheses are balanced
}

// Example usage
int main() {
    char expression1[] = "{[()]}";
    char expression2[] = "{[(])}";
    char expression3[] = "(()";

    printf("Is '%s' balanced? %s\n", expression1, isBalanced(expression1) ? "Yes" : "No");
    printf("Is '%s' balanced? %s\n", expression2, isBalanced(expression2) ? "Yes" : "No");
    getch();
    return 0;
}