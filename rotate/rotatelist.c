/**

https://leetcode.com/problems/rotate-list/
 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

 */

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    int len = 0, i;
    struct ListNode *t1 = NULL;
    struct ListNode *h2 = NULL;
    struct ListNode *t2 = NULL;
    struct ListNode *p2 = NULL;
    if(!head || k<0) return NULL;
    t1= head;
    while(t1){
        len++;
        t2 = malloc(sizeof(struct ListNode));
        t2->next = NULL;
        //memset(t2, 0, sizeof(struct ListNode));
        t2->val = t1->val;
        if(p2)
            p2->next = t2;
        else
            h2 = t2;

        p2=t2;
        t1 = t1->next;
    }
    //get the real movements
    if(!(i = k%len))
        return h2; //Do not need to move

    // create circle-round list
    t2->next = h2;
    i = len - i;
    while(i-->0){
        t2 = t2->next;
    }
    h2 = t2->next;
    t2->next = NULL;
    return h2;
}
