#include <stdio.h>


int heap[100001] = { 0, };
int index; //the next empty spot
int n;

void insert(int key);
void heapify(int idx);

int main() {
	scanf("%d", &n);
	index = 1;
	int cmd;
	
	heap[0] = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &cmd);
		if (cmd != 0) {
			insert(cmd);
		}
		else { //cmd == 0 . return the smallest and remove
			if (index == 1) //empty
				printf("0\n");
			else {
				int temp = heap[1]; //value to return, aka smallest
				heap[1] = heap[index-1];
				heapify(1);
				index--;
				printf("%d\n", temp);
			}

		}
	}

	return 0;
}

//smallest in the root
void insert(int key) {
	int tempIdx = index;
	int temp;
	if (index == 1) { //if empty
		heap[1] = key;
		index++;
		return;
	}
	heap[index++] = key;
	while (tempIdx > 1) {
		if (heap[tempIdx / 2] < heap[tempIdx]) {
			temp = heap[tempIdx / 2];
			heap[tempIdx / 2] = heap[tempIdx];
			heap[tempIdx] = temp;
			tempIdx /= 2;
		}
		else {
			break;
		}
	}
	heapify(index);
}

void heapify(int idx) {
	int left = idx * 2;
	int right = left + 1;
	int largest = idx;

	if (left < index && heap[left] > heap[largest]) {
		largest = left;
	}
	if (right < index && heap[right] > heap[largest]) {
		largest = right;
	}
	if (largest != idx) {
		int temp = heap[idx];
		heap[idx] = heap[largest];
		heap[largest] = temp;
		heapify(largest);
	}
}