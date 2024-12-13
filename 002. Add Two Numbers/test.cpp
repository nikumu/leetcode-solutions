#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode();
        ListNode *current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        return dummyHead->next;
    }
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}
