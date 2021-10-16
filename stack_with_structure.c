//very simple, premitive & static implementation of stack(using array)

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int MX, top;
  int *arr;
} Stack;

void initialize(Stack *x) {
  x->MX = 10, x->top = -1;
  x->arr = (int *)malloc(x->MX);
}

void Push(Stack *x, int value) {
  if (x->top + 1 == x->MX) {     //Stack is full
    printf("Stack Overflow!\n"); //inserting new value not possible
    return;
  }
  x->top++;
  x->arr[x->top] = value;
}

int getTop(Stack *x) {
  return x->arr[x->top];
}

void Pop(Stack *x) {
  if (x->top == -1) {             //Stack is empty
    printf("Stack Underflow!\n"); //removing not possible
    return;
  }
  x->top--;
}

int main() {
  Stack st, st2;
  initialize(&st);
  initialize(&st2);

  Push(&st, 12);
  Pop(&st);
  Pop(&st);
  Push(&st, 15);
  Push(&st, 2);
  Push(&st, 59);
  Pop(&st);
  Push(&st, 12);
  Push(&st, 85);
  Push(&st, 2);
  Push(&st, 9);
  printf("Remaing Stack1: ");
  while (st.top >= 0) {
    int tp = getTop(&st);
    printf("%d ", tp);
    Pop(&st);
  }

  printf("\n-----------------\n");
  Pop(&st2);
  Push(&st2, 12);
  Push(&st2, 29);
  Pop(&st2);
  Pop(&st2);
  Push(&st2, 72);
  Push(&st2, 89);
  Push(&st2, 172);
  Push(&st2, 145);
  Push(&st2, 285);
  Pop(&st2);
  Push(&st2, 239);

  printf("Remaing Stack2: ");
  while (st2.top >= 0) {
    int tp = getTop(&st2);
    printf("%d ", tp);
    Pop(&st2);
  }
  printf("\n");
}