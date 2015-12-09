#include "slist.h"

int main(int argc, char const* argv[])
{
    struct slist *list;
    int target;

    list = create_head();

    append(list, 1);
    append(list, 2);
    append(list, 3);

    insert(list, 999, 1);
    // delete(list, 0);

    dump(list);

    // search index;
    target = 999;
    printf("---\ntarget:%d index:%d\n", target, search(list, target));
    return 0;
}
