#include <iostream>
#include <stack>

struct ListNode {
 public:
  int m_nKey;
  ListNode *m_pNext;
  ListNode(int num) : m_nKey(num), m_pNext(nullptr) {}
};

void PrintListReversingly_Iteratively(ListNode *pHead) {
  std::stack<ListNode *> ListStack;
  ListNode *p = pHead;
  while (p != nullptr) {
    ListStack.push(p);
    p = p->m_pNext;
  }

  while (!ListStack.empty()) {
    p = ListStack.top();
    ListStack.pop();
    std::cout << p->m_nKey << " <- ";
  }
  std::cout << "HEAD" << std::endl;
}

void PrintListReversingly_Iteratively2(ListNode *pHead) {
  if (pHead == nullptr) {
    return;
  }
  std::stack<ListNode *> ListStack;
  ListNode *p = pHead;
  if (p->m_pNext != nullptr) {
    PrintListReversingly_Iteratively2(pHead->m_pNext);
    std::cout << p->m_nKey << " <- ";
  } else {
    std::cout << p->m_nKey << " <- ";
  }
}

int main() {
  // memory manage not done, prefer to use smart pointer
  ListNode *pHead = new ListNode(5);
  ListNode *pCurrent = pHead;
  for (size_t i = 0; i < 5; ++i) {
    pCurrent->m_pNext = new ListNode(i);
    pCurrent = pCurrent->m_pNext;
  }

  PrintListReversingly_Iteratively2(pHead);
  std::cout << "HEAD" << std::endl;

  pHead = nullptr;
  PrintListReversingly_Iteratively2(pHead);

  return 0;
}