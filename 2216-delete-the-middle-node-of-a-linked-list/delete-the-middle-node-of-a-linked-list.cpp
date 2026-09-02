/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
          return nullptr;
        
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;

        }
        int midIndx = count/2;
        int findIndex = 0;

        ListNode* start = head;
        while(start && findIndex!=midIndx-1){
            findIndex++;
            start = start->next;

        }

        ListNode* del = start->next;
        start->next = del->next;
        del->next = nullptr;
        delete del;

        return head;
    }
};