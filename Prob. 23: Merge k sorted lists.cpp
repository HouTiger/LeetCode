/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = lists.size();
        if (N == 0)
            return NULL;
        bool all_null = true;
        vector<ListNode*>::iterator ii = lists.begin();
        for (; ii != lists.end();) {
            if (*ii) {
                all_null = false;
                ++ii;
            } 
            else {
                ii = lists.erase(ii);
                
            }
        }
        if (all_null)
            return NULL;
        ListNode* head = new ListNode(-1);
        ListNode* ptr = head;
        ListNode* t;
        int min = 2147483647;
        int index = -1;
        int cnt = 0;
        while(!lists.empty()) {
            // printf("cnt = %d\n", cnt);
            cnt += 1;
            min = 2147483647;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i]->val < min) {
                    min = lists[i]->val;
                    index = i;    
                }
            }
            
            t = new ListNode(min);
            // cout << min << endl;
            ptr->next = t;
            ptr = ptr->next;
            if (lists[index]->next) {
                lists[index] = lists[index]->next;
            }
            else {
                lists.erase(lists.begin() + index);
            }
            
        }
        
        return head->next;
    }
};