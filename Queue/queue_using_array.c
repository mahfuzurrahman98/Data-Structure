//very simple, premitive & static implementation of queue(using array)

#include <stdio.h>

#define MX 10
int Q[MX];
int Front = -1;
int Rear = -1;
int Q_size = 0;

void enqueue(int x) {
  if (Q_size == MX) {            //Queue is full
    printf("Queue Overflow!\n"); //inserting not possible
    return;                      //return from here
  }
  if (Rear == -1) {  //First enqueue when Queue is empty
    Rear++, Front++; //Front & Rear both are set to 0
    Q[Rear] = x;
  } else { //Other enqueues
    Rear++;
    Q[Rear] = x;
  }
  Q_size++; //increase size
  printf("%d is pushed\n", x);
}

void dequeue() {
  if (Q_size == 0) {              //Queue is empty
    printf("Queue Underflow!\n"); //removing not possible
    return;
  }
  if (Q_size == 1 && Front == Rear) {
    // in case front and rear get the same position
    // and queue has only one element left
    printf("value: %d is popped!\n", Q[Front]);
    Front = Rear = -1, Q_size = 0; // get back to the initial state
  }
  printf("value: %d is popped!\n", Q[Front]);
  Front++, Q_size--; //increase Front pointer & decrease size
}

int getFrontValue() {
  return Q[Front];
}

int main() {
  enqueue(12);
  dequeue();
  dequeue();
  enqueue(15);
  enqueue(2);
  enqueue(59);
  dequeue();
  printf("%d\n", getFrontValue());
  //    enqueue(12);
  // 	enqueue(85);
  // 	enqueue(2);
  // 	enqueue(9);
  // 	dequeue();
  // 	enqueue(12);
  // 	enqueue(29);
  // 	enqueue(72);
  // 	enqueue(89);
  // 	enqueue(172);
  // 	enqueue(145);
  // 	enqueue(285);
  // 	enqueue(239);
}
