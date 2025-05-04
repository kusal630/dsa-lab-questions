#include <cstdio>
#include <cstdlib>

struct Process {
    int time;
    struct Process* next;
};

struct Scheduler {
    struct Process* head;
    int timeSlot;
};

/* Time Complexity: O(1) - Simple pointer and value initialization */
void initScheduler(struct Scheduler* sched, int slot) {
    sched->head = NULL;
    sched->timeSlot = slot;
}

/* Time Complexity: O(n) - Traversing to last node */
void insertProcess(struct Scheduler* sched, int time) {
    struct Process* newNode = (struct Process*)malloc(sizeof(struct Process));
    newNode->time = time;
    
    if (sched->head == NULL) {
        newNode->next = newNode;
        sched->head = newNode;
    } else {
        struct Process* temp = sched->head;
        while (temp->next != sched->head) temp = temp->next;
        temp->next = newNode;
        newNode->next = sched->head;
    }
}

/* Time Complexity: O(n) - Traversing to last node to update links */
void execute(struct Scheduler* sched) {
    if (sched->head == NULL) {
        printf("No processes in queue\n");
        return;
    }
    
    struct Process* curr = sched->head;
    struct Process* prev = curr;
    while (prev->next != sched->head) prev = prev->next;
    
    int remaining = curr->time - sched->timeSlot;
    printf("Executing process with time %d, remaining: %d\n", curr->time, remaining);
    
    if (remaining <= 0) {
        printf("Process completed\n");
        if (curr->next == curr) {
            sched->head = NULL;
        } else {
            prev->next = curr->next;
            sched->head = curr->next;
        }
        free(curr);
    } else {
        curr->time = remaining;
        sched->head = curr->next;
        prev->next = curr;
        curr->next = sched->head;
    }
}

/* Time Complexity: O(n) - Traversing the entire list */
void display(struct Scheduler* sched) {
    if (sched->head == NULL) {
        printf("No processes in queue\n");
        return;
    }
    struct Process* temp = sched->head;
    do {
        printf("%d ", temp->time);
        temp = temp->next;
    } while (temp != sched->head);
    printf("\n");
}

/* Time Complexity: O(1) per operation call, overall depends on user interaction */
int main() {
    int slot;
    printf("Enter time slot: ");
    scanf("%d", &slot);
    
    struct Scheduler sched;
    initScheduler(&sched, slot);
    int choice, time;
    
    while (1) {
        printf("\n1.Insert Process 2.Execute 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: printf("Enter process time: "); scanf("%d", &time); insertProcess(&sched, time); break;
            case 2: execute(&sched); break;
            case 3: display(&sched); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}