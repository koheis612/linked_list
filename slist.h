#ifndef INCLUDE_SLISH_H
#define INCLUDE_SLISH_H

#include <stdio.h>
#include <stdlib.h>

struct slist {
    int value;
    struct slist *next;
};


struct slist *create_head(void);
struct slist *create(int);

int search(struct slist *, int);

void dump(struct slist *);
void append(struct slist *, int);
void insert(struct slist *, int, int);
void delete(struct slist *, int);
void modify(struct slist *, int, int);

#endif
