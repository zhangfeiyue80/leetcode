#include<iostream>
#include<string>
#include<vector>

#include<stdlib.h>

using namespace std;
/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp=0, carry=0, num1=0, num2=0;
        ListNode* node2 = nullptr;
        ListNode* lsum = new ListNode();
        ListNode* node1 = lsum;

        temp = l1->val + l2->val + carry;
        carry = temp/10;
        node1->val = temp%10;

        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            node2 = new ListNode();

            // 此处代码处于 while 循环内，需要注重优化 减少 if 分支判断
            // 用条件数据传送取代条件控制转移来避免循环内部的多次分支预测错误所引起的性能下降(链表元素数目越多，此优化越明显)
            //cout << "addTwoNumbers l1->val is " << l1->val << endl;
            num1 = l1 ? l1->val : 0;
            num2 = l2 ? l2->val : 0;

            node1->next = node2;
            temp = num1 + num2 + carry;
            carry = temp/10;
            node2->val = temp%10;
            node1 = node2;

            // 此处代码处于 while 循环内，需要注重优化 减少 if 分支判断
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return lsum;
    }
};

void strToVec(string str, vector<int> &vec) {
    string::size_type num = str.size();
    for(int i=1; i<num; i+=2) {
        int element = atoi( &str.at(i) );
        vec.push_back(element);
    }
}

ListNode* vecToList(vector<int> vec) {
    vector<int>::size_type num = vec.size();
    ListNode *node1=nullptr, *node2=nullptr, *list=nullptr;
    //cout << "vecToList: vec.size() is" << vec.size() << endl;
    node1 = new ListNode( vec.at(0) );
    list = node1;
    for(int i=1; i<num; i++) {
        node2 = new ListNode( vec.at(i) );
        node1->next = node2;
        node1 = node2;
    }

    return list;
}

int main() {
    char charIn[256] = {0};
    cin.getline(charIn, 256, '\n');
    string strIn(charIn);
    string::size_type l1StartPos = strIn.find_first_of('[');
    string::size_type l1EndPos = strIn.find_first_of(']');
    string::size_type l2StartPos = strIn.find_last_of('[');
    string::size_type l2EndPos = strIn.find_last_of(']');
    string l1Str = strIn.substr(l1StartPos, l1EndPos-l1StartPos+1);
    string l2Str = strIn.substr(l2StartPos, l2EndPos-l2StartPos+1);

    vector<int> l1Vec;
    vector<int> l2Vec;
    ListNode *l1, *l2, *it, *lsum=nullptr;
    strToVec(l1Str, l1Vec);
    strToVec(l2Str, l2Vec);
    //cout << "main l1Vec.at(0) is " << l1Vec.at(0) << endl;
    l1 = vecToList(l1Vec);
    l2 = vecToList(l2Vec);

    //cout << "main l1->val is " << l1->val << endl;
    lsum = Solution::addTwoNumbers(l1, l2);

    cout << "[" << lsum->val;
    for(it = lsum->next; it != nullptr; it=it->next ) {
        cout << "," << it->val;
    }
    cout << "]" << endl;
    return 0;
}
