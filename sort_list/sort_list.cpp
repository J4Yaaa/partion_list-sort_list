#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortList(ListNode *head) {
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    vector<int> v;
    ListNode* cur = head;
    while(cur != nullptr)
    {
        v.push_back(cur->val);
        cur = cur->next;
    }
    sort(v.begin(),v.end(),less<int>());
    cur = head;
    int i = 0;
    while(cur != nullptr)
    {
        cur->val = v[i++];
        cur = cur->next;
    }
    return head;
}

int main()
{
    //1.构建链表
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(2);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(2);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    ListNode* cur = l1;
    while(cur != nullptr)
    {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;

    ListNode* ret = sortList(l1);
    cur = ret;
    while(cur != nullptr)
    {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;


    return 0;
}
