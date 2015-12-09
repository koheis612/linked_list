#include "slist.h"

// show list
void dump(struct slist* list) {
    struct slist *lp;
    int i;

    i = 0;
    for (lp = list->next; lp != NULL; lp = lp->next) {
        printf("[%d] %d\n", i++, lp->value);
    }
}

// create new head node
struct slist *create_head() {
    struct slist *head;
    head = (struct slist *)calloc(1, sizeof(struct slist));

    if (head == NULL) {
        perror("failed to allocate memory.\n");
        exit(0);
    }

    head->value = 0;
    head->next = NULL;

    return head;
}

// create new node
struct slist *create(int value) {
    struct slist *node;

    node = (struct slist *)calloc(1, sizeof(struct slist));

    if (node == NULL) {
        perror("failed to allocate memory.\n");
        exit(0);
    }

    node->value = value;
    node->next = NULL;

    return node;
}

// add a node to the end of list
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

// insert node
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

// delete node
void delete(struct slist *list, int index) {
    struct slist *prev;
    struct slist *next;
    int i;

    prev = list;
    for (i = 0; i < index; i++) {
        if(prev->next == NULL) {
            break;
        }
        prev = prev->next;
    }

    next = prev->next->next;
    if (next != NULL) {
        prev->next = next;
    } else {
        prev->next = NULL;
    }
}

// modify value of node
void modify(struct slist* list, int value, int index) {
    struct slist *tmp;
    int i;

    tmp = list;
    for (i = 0; i < index; i++) {
        if (tmp->next == NULL) {
            break;
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
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        if (tmp->value == target) {
            return index - 1;
        }
        index++;
    }
    return -1;
}

// main
int main(int argc, char const* argv[])
{
    struct slist *list;
    int target;

    list = create_head();

    append(list, 1);
    append(list, 2);
    append(list, 3);

    // insert(list, 999, 1);
    // delete(list, 0);

    dump(list);

    // search index;
    target = 999;
    printf("---\ntarget:%d index:%d\n", target, search(list, target));
    return 0;
}
