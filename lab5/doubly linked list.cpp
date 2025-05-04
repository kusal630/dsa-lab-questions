#include <cstdio>
#include <cstdlib>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoublyList {
    struct Node* head;
    struct Node* tail;
};

/* Time Complexity: O(1) - Simple pointer initialization */
void initList(struct DoublyList* list) {
    list->head = NULL;
    list->tail = NULL;
}

/* Time Complexity: O(1) - Constant time due to direct head access */
void insertBeginning(struct DoublyList* list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = list->head;
    
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        list->head->prev = newNode;
        list->head = newNode;
    }
}

/* Time Complexity: O(1) - Constant time due to tail pointer */
void insertEnd(struct DoublyList* list, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = list->tail;
    
    if (list->tail == NULL) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

/* Time Complexity: O(n) - Traversing to the position */
void insertPosition(struct DoublyList* list, int value, int pos) {
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
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;
    
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    else list->tail = newNode;
    temp->next = newNode;
}

/* Time Complexity: O(1) - Constant time due to direct head access */
void deleteBeginning(struct DoublyList* list) {
    if (list->head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = list->head;
    list->head = list->head->next;
    if (list->head == NULL) list->tail = NULL;
    else list->head->prev = NULL;
    free(temp);
}

/* Time Complexity: O(1) - Constant time due to tail pointer */
void deleteEnd(struct DoublyList* list) {
    if (list->tail == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = list->tail;
    list->tail = list->tail->prev;
    if (list->tail == NULL) list->head = NULL;
    else list->tail->next = NULL;
    free(temp);
}

/* Time Complexity: O(n) - Traversing to the position */
void deletePosition(struct DoublyList* list, int pos) {
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
    for (int i = 1; i < pos && temp != NULL; i++) temp = temp->next;
    
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    
    temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    else list->tail = temp->prev;
    free(temp);
}

/* Time Complexity: O(n) - Linear search through the list */
int search(struct DoublyList* list, int value) {
    struct Node* temp = list->head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

/* Time Complexity: O(n) - Traversing the entire list */
void display(struct DoublyList* list) {
    if (list->head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Time Complexity: O(1) per operation call, overall depends on user interaction */
int main() {
    struct DoublyList list;
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