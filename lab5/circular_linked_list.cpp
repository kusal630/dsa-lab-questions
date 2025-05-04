#include <cstdio>
#include <cstdlib>

struct Node {
    int data;
    struct Node* next;
};

struct CircularList {
    struct Node* head;
};

/* Time Complexity: O(1) - Simple pointer initialization */
void initList(struct CircularList* list) {
    list->head = NULL;
}

/* Time Complexity: O(n) - Traversing to last node to update link */
void insertBeginning(struct CircularList* list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) temp = temp->next;
        newNode->next = list->head;
        temp->next = newNode;
        list->head = newNode;
    }
}

/* Time Complexity: O(n) - Traversing to last node */
void insertEnd(struct CircularList* list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != list->head) temp = temp->next;
        temp->next = newNode;
        newNode->next = list->head;
    }
}

/* Time Complexity: O(n) - Traversing to position */
void insertPosition(struct CircularList* list, int value, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insertBeginning(list, value);
        return;
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* temp = list->head;
    if (temp == NULL) {
        newNode->next = newNode;
        list->head = newNode;
        return;
    }
    
    for (int i = 1; i < pos - 1 && temp->next != list->head; i++) temp = temp->next;
    if (temp->next == list->head && pos > 1) {
        insertEnd(list, value);
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

/* Time Complexity: O(n) - Traversing to last node to update link */
void deleteBeginning(struct CircularList* list) {
    if (list->head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = list->head;
    if (temp->next == temp) {
        list->head = NULL;
        free(temp);
        return;
    }
    
    struct Node* last = list->head;
    while (last->next != list->head) last = last->next;
    list->head = temp->next;
    last->next = list->head;
    free(temp);
}

/* Time Complexity: O(n) - Traversing to second-to-last node */
void deleteEnd(struct CircularList* list) {
    if (list->head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = list->head;
    if (temp->next == temp) {
        list->head = NULL;
        free(temp);
        return;
    }
    
    struct Node* prev = NULL;
    while (temp->next != list->head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = list->head;
    free(temp);
}

/* Time Complexity: O(n) - Traversing to position */
void deletePosition(struct CircularList* list, int pos) {
    if (list->head == NULL) {
        printf("List empty\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        deleteBeginning(list);
        return;
    }
    
    struct Node* temp = list->head;
    struct Node* prev = NULL;
    for (int i = 1; i < pos && temp->next != list->head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == list->head && pos > 1) {
        deleteEnd(list);
        return;
    }
    if (prev == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

/* Time Complexity: O(n) - Linear search through circular list */
int search(struct CircularList* list, int value) {
    if (list->head == NULL) return -1;
    struct Node* temp = list->head;
    int pos = 1;
    do {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    } while (temp != list->head);
    return -1;
}

/* Time Complexity: O(n) - Traversing the entire list */
void display(struct CircularList* list) {
    if (list->head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = list->head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n");
}

/* Time Complexity: O(1) per operation call, overall depends on user interaction */
int main() {
    struct CircularList list;
    initList(&list);
    int choice, value, pos;
    
    while (1) {
        printf("\n1.Insert Beginning 2.Insert End 3.Insert Position 4.Delete Beginning\n");
        printf("5.Delete End 6.Delete Position 7.Search 8.Display 9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &value); insertBeginning(&list, value); break;
            case 2: printf("Enter value: "); scanf("%d", &value); insertEnd(&list, value); break;
            case 3: printf("Enter value and position: "); scanf("%d %d", &value, &pos); insertPosition(&list, value, pos); break;
            case 4: deleteBeginning(&list); break;
            case 5: deleteEnd(&list); break;
            case 6: printf("Enter position: "); scanf("%d", &pos); deletePosition(&list, pos); break;
            case 7: printf("Enter value to search: "); scanf("%d", &value); 
                    pos = search(&list, value); 
                    if (pos != -1) printf("Found at position %d\n", pos); 
                    else printf("Not found\n"); break;
            case 8: display(&list); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
