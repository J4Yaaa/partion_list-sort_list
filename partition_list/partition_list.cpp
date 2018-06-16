#include <iostream>
using namespace std;
//给定一个链表和一个值x，将其划分为所有小于x的节点都在大于或等于x的节点之前。

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    // 定义两个指针
    // high 指向第一个大于 x 的节点
    // low 指向第一个小于 x 的节点
    ListNode* high = head;
    ListNode* low = head->next;
    while(high != nullptr && low != nullptr)
    {
        while(high != nullptr && high->val < x)
        {
            high = high->next;
        }
        while(low != nullptr && low->val >= x)
        {
            low = low->next;
        }
        if(high != nullptr && low != nullptr)
        {
            int tmp = high->val;
            high->val = low->val;
            low->val = tmp;
        }
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

    ListNode* ret = partition(l1,3);
    cur = ret;
    while(cur != nullptr)
    {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
    return 0;
}
