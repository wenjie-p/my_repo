#include<iostream>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
}*LinkedList;

void output(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode **t1 = &head, *t2 = head;
    for(int i = 1; i < n; i++){
        t2 = t2->next;
    }
    while(t2){
        t1 = &((*t1)->next);
        t2 = t2->next;
    }
    *t1 = (*t1)->next;
}

void init(ListNode* head){
    int n;
    cin >> n;
    int val;
    ListNode* cur;
    for(int i = 0; i < n; i++){
        cin >> val;
        //ListNode node(val);
        ListNode* node = new ListNode;
        node->val = val;
        node->next = NULL;
        if(head == NULL){
            head = node;
            cur = head;
        }else{
            cur->next = node;
            cur = cur->next;
        }
    }
}

int main(int argc, char* argv[]){
    ListNode* head;
    init(head);
    output(head);
    int n;
    cin >> n;
    ListNode* res = removeNthFromEnd(head, n);
    output(res);
    return 0;
}
