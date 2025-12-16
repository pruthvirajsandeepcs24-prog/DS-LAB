#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char name[20];
    int empID;
    int age;
} Employee;

typedef struct Node {
    Employee data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(char name[], int empID, int age) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->data.name, name);
    newNode->data.empID = empID;
    newNode->data.age = age;

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void displayList(Node *head) {
    Node *temp = head;

    printf("\nDoubly Linked List Structure:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| Node Addr | Prev Addr | Name | EmpID | Age | Next Addr |\n");
    printf("-----------------------------------------------------------------------------\n");

    while (temp != NULL) {
        printf("| %-9p | %-9p | %-10s | %-5d | %-3d | %-9p |\n",
               (void*)temp,
               (void*)temp->prev,
               temp->data.name,
               temp->data.empID,
               temp->data.age,
               (void*)temp->next);
        temp = temp->next;
    }

    printf("-----------------------------------------------------------------------------\n");
}

Node* searchNode(Node *head, int empID) {
    Node *temp = head;

    while (temp != NULL) {
        if (temp->data.empID == empID) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    Node *N1 = createNode("Rahul", 10028, 45);
    Node *N2 = createNode("Karan", 10029, 32);
    Node *N3 = createNode("Pooja", 10030, 28);
    Node *N4 = createNode("Kiran", 10031, 29);
    Node *N5 = createNode("Pavan", 10032, 36);

    N1->next = N2;

    N2->prev = N1;
    N2->next = N3;

    N3->prev = N2;
    N3->next = N4;

    N4->prev = N3;
    N4->next = N5;

    N5->prev = N4;

    displayList(N1);

    int idToSearch;
    printf("\nEnter Employee ID to Search: ");
    if (scanf("%d", &idToSearch) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 0;
    }

    Node *result = searchNode(N1, idToSearch);

    if (result != NULL) {
        printf("\nSearch Result:\n");
        printf("Employee Found\n");
        printf("Name : %s\n", result->data.name);
        printf("EmpID : %d\n", result->data.empID);
        printf("Age : %d\n", result->data.age);
    } else {
        printf("\nEmployee with EmpID %d not found.\n", idToSearch);
    }

    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);

    return 0;
}
