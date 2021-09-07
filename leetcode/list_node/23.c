struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;

    struct ListNode *res = NULL, *main = NULL;
    int i = 0;
    do {
        res = lists[i];
        main = lists[i];
        i++;
    } while (!res && i < listsSize);

    for (; i < listsSize; ++i) {
        struct ListNode *tmp;
        struct ListNode *minor = lists[i];
        if (!minor)
            continue;

        if (main->val > minor->val) {
            main = minor;
            minor = res;
            res = main;
        }

        struct ListNode *pre;
        while (main && minor) {
            if (main->val > minor->val) {
                tmp = minor->next;
                pre->next = minor;
                minor->next = main;
                pre = minor;
                minor = tmp;
                continue;
            }

            pre = main;
            main = main->next;
        }

        if (minor)
            pre->next = minor;

        main = res;
    }

    return main;
}
