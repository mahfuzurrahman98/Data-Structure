//very simple, premitive & static implementation of stack(using array)

#include <stdio.h>

#define MX 10
int Stack[MX];
int top = -1;

void Push(int x) {
  if (top + 1 == MX) {           //Stack is full
    printf("Stack Overflow!\n"); //inserting new value not possible
    return;
  }
  top++;
  Stack[top] = x;
}

int getTop() {
  return Stack[top];
}

void Pop() {
  if (top == -1) {                //Stack is empty
    printf("Stack Underflow!\n"); //removing not possible
    return;
  }
  top--;
}

int main() {

  Push(12);
  Pop();
  Pop(); //Underflow
  Push(15);
  Push(2);
  Push(59);
  Pop();
  Push(12);
  Push(85);
  Push(2);
  Push(9);
  Pop();
  Push(12);
  Push(29);
  Push(72);
  Push(89);
  Push(172);
  Push(145); //Overerflow
  Push(285); //Overerflow
  Push(239); //Overerflow

  printf("Remaing Stack: ");
  while (top >= 0) {
    int tp = getTop();
    printf("%d ", tp);
    Pop();
  }
  printf("\n");
}