
void swap3(int inta[], int i, int j) {
	int tmp = inta[i];
	inta[i] = inta[j];
	inta[j] = tmp;
}

void swap(int inta[], int i, int j) {
	inta[i] = inta[i] ^ inta[j];
	inta[j] = inta[i] ^ inta[j];
	inta[i] = inta[i] ^ inta[j];
}
void heap_adjust(int inta[], int s, int n) {
	int i = 0, tmp = inta[s];

	for(i = 2*s+1; i < n; i = 2*i+1) {
		if(i+1 < n && inta[i] < inta[i+1])
			i ++;
		if(inta[i] > tmp) {
			inta[s] = inta[i];
			s = i;
		}
		else break;
	}
	inta[s] = tmp;
}

// O(nlogn)
void heap_sort(int inta[], int n) {
	int i = 0;
	// Build up a max heap
	for(i=n/2-1; i >= 0; i --) {
		heap_adjust(inta, i, n);
	}

	// exchange heap top data with last data, and adjust the heap
	for(i = n-1; i > 0; i --) {
		swap(inta, 0, i);
		heap_adjust(inta, 0, i);
	}
}
