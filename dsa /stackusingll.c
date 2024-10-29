#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the stack
struct Stack {
    struct Node* top;
};

// Function prototypes
struct Node* createNode(int data);
struct Stack* createStack();
void push(struct Stack* stack, int data);
int pop(struct Stack* stack);
int isEmpty(struct Stack* stack);
void displayStack(struct Stack* stack);

int main() {
    struct Stack* stack = createStack();
    int data, choice;

    do {
        printf("\n\tStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;

            case 2:
                if (!isEmpty(stack)) {
                    int element = pop(stack);
                    printf("Popped data: %d\n", element);
                } else {
                    printf("Stack is empty\n");
                }
                break;

            case 3:
                printf("Stack data: ");
                displayStack(stack);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    // Free the memory
    free(stack);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to display the items in the stack
void displayStack(struct Stack* stack) {
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




