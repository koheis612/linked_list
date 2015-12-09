#include "slist.h"

void dump(struct slist* list) {
    struct slist *lp;
    int i;

    i = 0;
    for (lp = list->next; lp != NULL; lp = lp->next) {
        printf("[%d] %d\n", i++, lp->value);
    }
}

struct slist *create_head() {
    struct slist *head;
    head = (struct slist *)calloc(1, sizeof(struct slist));

    if (head == NULL) {
        perror("failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    head->value = 0;
    head->next = NULL;

    return head;
}

struct slist *create(int value) {
    struct slist *node;

    node = (struct slist *)calloc(1, sizeof(struct slist));

    if (node == NULL) {
        perror("failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    node->value = value;
    node->next = NULL;

    return node;
}

void append(struct slist* list, int value) {
    struct slist *node;
    struct slist *tail;

    tail = list;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    node = create(value);
    tail->next = node;
}

void insert(struct slist* list, int value, int index) {
    struct slist *prev;
    struct slist *next;
    struct slist *now;

    int i;

    now = create(value);
    prev = list;
    for (i = 0; i < index; i++) {
        if (prev->next == NULL) {
            append(list, value);
            return;
        }
        prev = prev->next;
    }

    next = prev->next;
    now->next = next;
    prev->next = now;
}

void clear(struct slist *list, int index) {
    struct slist *prev;
    struct slist *next;
    struct slist *tmp;
    int i;

    prev = list;

    for (i = 0; i < index; i++) {
        if(prev->next == NULL) {
            perror("failed to clear node.\n");
            exit(EXIT_FAILURE);
        }
        prev = prev->next;
    }

    next = prev->next->next;
    if (next != NULL) {
        tmp = prev->next;
        prev->next = next;
    } else {
        tmp = prev->next;
        prev->next = NULL;
    }

    free(tmp);
}

void modify(struct slist* list, int value, int index) {
    struct slist *tmp;
    int i;

    tmp = list;
    for (i = 0; i < index; i++) {
        if (tmp->next == NULL) {
            perror("failed to modify node.\n");
            exit(EXIT_FAILURE);
        }
        tmp = tmp->next;
    }
    tmp->value = value;
}

// search index
int search(struct slist *list, int target) {
    struct slist *tmp;
    int index;

    index = 0;
    for (tmp = list->next; tmp != NULL; tmp = tmp->next) {
        if (tmp->value == target) {
            return index;
        }
        index++;
    }
    perror("failed to search target from list.\n");
    exit(EXIT_FAILURE);
}

void swap_values(struct slist *p1, struct slist *p2) {
    int tmp;
    tmp = p1->value;
    p1->value = p2->value;
    p2->value = tmp;
}

void sort_list(struct slist *list) {
    struct slist *start;
    struct slist *tmp;
    struct slist *min;

    start = list->next;

    while(start->next) {
        min = start;
        tmp = start->next;
        while (tmp) {
            if (min->value > tmp->value) {
                min = tmp;
            }
            tmp = tmp->next;
        }
        swap_values(start, min);
        start = start->next;
    }
}
