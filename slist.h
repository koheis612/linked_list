#include <stdio.h>
#include <stdlib.h>

struct slist {
    int value;
    struct slist *next;
};

struct slist *create(int);
struct slist *top(struct slist *, int);

int search(struct slist *, int);

void dump(struct slist *);
void append(struct slist *, int);
void insert(struct slist *, int, int);
void delete(struct slist *, int);
void modify(struct slist *, int, int);
