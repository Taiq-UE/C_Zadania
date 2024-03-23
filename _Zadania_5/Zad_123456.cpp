#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void free_list(node_t *head) {
    node_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void add_first(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void pop(node_t ** head) {
    if (*head == NULL) {
        return;
    }

    node_t * next_node = (*head)->next;
    free(*head);
    *head = next_node;
}

void remove_last(node_t ** head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        node_t * second_last = *head;
        while (second_last->next->next != NULL) {
            second_last = second_last->next;
        }
        free(second_last->next);
        second_last->next = NULL;
    }
}

void remove_by_index(node_t ** head, int n) {
    if (*head == NULL) {
        return;
    }

    node_t * temp = *head;

    if (n == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < n - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    node_t * next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void remove_by_value(node_t ** head, int val) {
    if (*head == NULL) {
        return;
    }

    node_t * temp = *head;

    if (temp->val == val) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp->next != NULL && temp->next->val != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return;
    }

    node_t * next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main() {
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    if (head == NULL) {
        return 1;
    }

    head->val = 1;
    head->next = NULL;

    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);

    print_list(head);

    add_first(&head, 0);

    printf("\n");
    print_list(head);

    pop(&head);
    printf("\n");
    print_list(head);

    remove_last(&head);
    printf("\n");
    print_list(head);

    remove_by_index(&head, 2);
    printf("\n");
    print_list(head);

    remove_by_value(&head, 2);
    printf("\n");
    print_list(head);

    free_list(head);

    return 0;
}