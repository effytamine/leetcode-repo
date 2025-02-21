#include <stdio.h> // Imports
#include <stdlib.h>

// Define Single-Linked List
typedef struct {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* newListNode(int value) {
    ListNode* Node = (ListNode* )malloc(sizeof(ListNode));
    Node->val = value;
    Node->next = NULL;
    return Node;
}
// Traverse Operation

// addTwonumbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy_head = newListNode(0);
    ListNode *l3 = dummy_head;

    int carry = 0;
    while(l1 != NULL || l2 != NULL){
        int l1_val = (l1 != NULL) ? l1->val : 0;
        int l2_val = (l2 != NULL) ? l2->val : 0;
        
        int cur_sum = l1_val + l2_val + carry;
        carry = cur_sum / 10;
        int last_digit = cur_sum % 10;

        l3->next = newListNode(last_digit);
        l3 = l3->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    
    return dummy_head->next;
}
// Main

int main() { 
    ListNode l1[3];
    ListNode l2[3];
    // ll1
    l1[0].val = 2;
    l1[0].next = &l1[1];

    l1[1].val = 4;
    l1[1].next = &l1[2];

    l1[2].val = 3;
    l1[2].next = NULL;

    // ll2
    l2[0].val = 5;
    l2[0].next = &l2[1];

    l2[1].val = 6;
    l2[1].next = &l2[2];

    l2[2].val = 4;
    l2[2].next = NULL;

    ListNode *Sum = addTwoNumbers(&l1[0], &l2[0]);
    ListNode *Sumptr = Sum;

    while (Sumptr != NULL)
    {
       printf("%i", Sumptr->val);
       Sumptr = Sumptr->next;
    }
    
}
