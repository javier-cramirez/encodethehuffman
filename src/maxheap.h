#ifndef "MAXHEAP_H"
#define "MAXHEAP_H"

struct MaxHeapNode {
	int v;
	int key;
}

struct MaxHeapNode {
	int size;
	int capacity;
	int *pos;
	int MaxHeapNode **array;
}

struct MaxHeapNode* newMaxHeapNode(int v, int key);
struct MaxHeap* createMaxHeap(int capacity);
struct MaxHeapNode* getMax(struct MaxHeap* maxHeap);


void swapMaxHeapNode(struct MaxHeapNode** a, struct MaxHeapNode** b);
void maxHeapify(struct MaxHeap* maxHeap, int idx);
void increaseKey(struct MaxHeap* maxHeap, int v, int key);

int isEmpty(struct MaxHeap* maxHeap);
bool isMaxHeap(struct MaxHeap* maxHeap, int v);
