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
    clear(list, 0);

    dump(list);

    /*
     * sort_list is implemented by swapping values.
    sort_list(list);
    dump(list);
    */

    // search index;
    target = 999;
    puts("---");
    printf("target:%d index:%d\n", target, search(list, target));
    return 0;
}
