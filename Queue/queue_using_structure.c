#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int MX, Front, Rear, SIZE;
  int *arr;
} Queue;

void initialize(Queue *x) {
  x->MX = 10;
  x->arr = (int *)malloc(x->MX);
  x->Front = -1;
  x->Rear = -1;
  x->SIZE = 0;
}

void enqueue(Queue *x, int value) {
  if (x->SIZE == x->MX) {        //Queue is full
    printf("Queue Overflow!\n"); //inserting not possible
    return;                      //return from here
  }
  if (x->Rear == -1) {     //First enqueue when Queue is empty
    x->Rear++, x->Front++; //Front & Rear both are set to 0
    x->arr[x->Rear] = value;
  } else { //Other enqueues
    x->Rear++;
    x->arr[x->Rear] = value;
  }
  x->SIZE++; //increase size
  printf("%d is pushed!\n", value);
}

void dequeue(Queue *x) {
  if (x->SIZE == 0) {             //Queue is empty
    printf("Queue Underflow!\n"); //removing not possible
    return;
  }
  if (x->SIZE == 1 && x->Front == x->Rear) { 
    // in case front and rear get the same position
    // and queue has only one element left
    printf("value: %d is popped!\n", x->arr[x->Front]);
    x->Front = x->Rear = -1, x->SIZE = 0; // get back to the initial state
  }
  printf("value: %d is popped!\n", x->arr[x->Front]);
  x->Front++, x->SIZE--; //increase Front pointer & decrease size
}

int getFrontValue(Queue *x) {
  return x->arr[x->Front];
}

int main() {
  Queue q, q2;
  initialize(&q);
  initialize(&q2);

  enqueue(&q, 12);
  enqueue(&q, 92);
  enqueue(&q, 52);
  enqueue(&q2, 172);
  enqueue(&q2, 32);
  printf("\n-------\n");
  printf("%d\n", getFrontValue(&q));
  printf("%d\n", getFrontValue(&q2));
}
