class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            ListNode* kth = prevGroupEnd;

            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }

            if (!kth) break;

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroup = kth->next;

            ListNode* prev = nextGroup;
            ListNode* curr = groupStart;

            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};