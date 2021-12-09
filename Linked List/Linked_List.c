#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *link;
} Node;

Node *createNode(int item, Node *next) {
  Node *newNode = (Node *)malloc(sizeof(Node)); //allocate memory for the new node
  newNode->data = item;
  newNode->link = next;
  return newNode;
}

Node *Prepend(Node *head, int item) { //Prepend means inserting value at the begining
  Node *newNode = createNode(item, NULL);
  if (head == NULL) { //Linked List is Empty
    return newNode;
  } else { //Linked List has one or more values
    newNode->link = head;
    head = newNode;
    return head;
  }
}

Node *Append(Node *head, int item) { //append means inserting value at the end
  Node *newNode = createNode(item, NULL);
  if (head == NULL) { //Linked List is Empty
    return newNode;
  } else { //Linked List has one or more values
    Node *curNode = head;
    while (curNode->link != NULL) {
      curNode = curNode->link;
    }
    curNode->link = newNode;

    return head;
  }
}

Node *Pop_Back(Node *head) {
  if (head == NULL) { //Linked List is Empty
    printf("Linked List is Empty!\n");
  }

  else if (head->link == NULL) { //Linked List has only one value
    head = NULL;
  }

  else { //Linked List has more than one value
    Node *curNode = head;
    while (curNode->link->link != NULL) {
      curNode = curNode->link;
    }
    curNode->link = NULL;
  }
  return head;
}

Node *Pop_Front(Node *head) {
  if (head == NULL) { //Linked List is Empty
    printf("Linked List is Empty!\n");
  }

  else if (head->link == NULL) { //Linked List has only one value
    head = NULL;
  } else { //Linked List has more than one value
    head = head->link;
  }
  return head;
}

Node *insertNode(Node *head, int pos, int x) {
  int len = listSize(head);
  if (pos < 0 && pos >= len) {
    printf("Invalid position!\n");
    return head;
  }

  int i = 0;
  Node *curNode = head;
  while (i < pos) {
    curNode = curNode->link;
    i++;
  }

  Node *newNode = createNode(x, NULL);
  newNode->link = curNode->link;
  curNode->link = newNode;

  return head;
}

Node *deleteNode(Node *head, int pos) {
  int len = listSize(head);
  if (pos < 0 && pos >= len) {
    printf("Invalid position!\n");
    return head;
  }
  if (pos == 0) {
    return Pop_Front(head);
  }

  int i = 0;
  Node *curNode = head;
  while (i < pos - 1) {
    curNode = curNode->link;
    i++;
  }
  Node *temp = curNode->link;
  curNode->link = curNode->link->link;
  free(temp);

  return head;
}

void traverse(Node *head) {
  Node *i = head;
  while (i != NULL) {
    printf("%d ", i->data);
    i = i->link;
  }
  printf("\n");
}

int listSize(Node *head) {
  Node *i = head;
  int sz = 0;
  while (i != NULL) {
    sz++;
    i = i->link;
  }
  return sz;
}

int main() {
  //freopen("in.txt", "r", stdin);
  int x, n;
  Node *ll = NULL;

  Pop_Back(ll);
  ll = Prepend(ll, -99);

  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    ll = Append(ll, x);
  }
  ll = Prepend(ll, 90);
  ll = Prepend(ll, 80);
  ll = Append(ll, 70);
  ll = Pop_Back(ll);
  ll = Pop_Front(ll);

  printf("traverse: ");
  traverse(ll);
  printf("Size: %d\n", Length(ll));
}
