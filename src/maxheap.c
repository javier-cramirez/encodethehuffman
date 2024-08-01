#include <stdio.h>
#include <stdlib.h>
#include <maxheap.h>
#include <stdbool.h>

struct MaxHeapNode* newMaxHeapNode(int v, int key) 
{
	struct MaxHeapNode* maxHeapNode = (struct MaxHeapNode*)malloc(sizeof(struct MaxHeapNode));
	maxHeapNode->v = v;
	maxHeapNode->key = key;
	return maxHeapNode;
}

struct MaxHeap* createMaxHeap(int capacity) 
{
	struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
	maxHeap->pos* = (int*)malloc(sizeof(int));
	maxHeap->size = 0;
	maxHeap->capacity = capacity;
	maxHeap->array = (struct MaxHeapNode**)malloc(capacity * sizeof(MaxHeapNode));
}

void swapMaxHeapNode(struct MaxHeapNode* a, struct MaxHeapNode* b) 
{
	struct MaxHeapNode temp = *a;
	a* = b*;
	b* = temp;
}

void maxHeapify(struct MaxHeap* maxHeap, int idx) 
{
	int largest, left, right;
	largest = idx;
	left = 2*idx + 1;
	right = 2*idx + 2;

	if (left <= maxHeap->size && maxHeap->array[left]->key < maxHeap->array[largest]->key) 
		largest = left;
	if (right <= maxheap->size && maxHeap->array[right]->key < maxHeap->array[largest]->key) 
		largest = right;
	if (smallest != idx) {
		MaxHeapNode* largestNode = maxHeap->array[largest];
		MaxHeapNode* idxNode = maxHeap->array[idx];

		maxHeap->pos[largest->v] = idx;
		maxHeap->pos[idx->v] = largest;
		swapMaxHeapNode(&maxHeap->array[largest], &maxHeap->array[idx]);
		maxHeapify(maxHeap, largest);
	}
}

void increaseKey(struct MaxHeap* maxHeap, int v, int key) 
{
	// Get index of v in heap array
	int i = maxHeap->pos[v];

	// Get vertex and update value
	maxHeap->array[i]->key = key;
	
	// Exchange A[i] with A[PARENT(i)], and update info mapping pq(obj)->array(idx)
	while (i > 1 && maxHeap->array[(i-1)/2]->key < maxHeap->array[i]->key) {
		maxHeap->pos[maxHeap->array[i]->v] = (i-1)/2;
		maxHeap->pos[maxHeap->array[(i-1)/2]->v] = i;
		swapMaxHeapNode(&maxHeap->array[(i-1)/2], &maxHeap->array[i]);
		i = (i-1)/2;
	}
}
