#define NULL 0

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head){
    struct ListNode *res= NULL;
    struct ListNode *cur = head;
    while (cur){
        head = head->next;
        cur->next = res;
        res = cur;
        cur = head;
    }
    return res;
}

int main(int argc, char const *argv[]){
    return 0;
}
