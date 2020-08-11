#include<iostream> 
#include<climits> 
using namespace std; 

 
void swap(int *x, int *y); 

 
class MinHeap 
{ 
	int *harr;  
	int capacity; 
	int heap_size;  
public: 

	MinHeap(int capacity); 
void MinHeapify(int ); 
	int parent(int i) { return (i-1)/2; } 
	int left(int i) { return (2*i + 1); } 
	int right(int i) { return (2*i + 2); } 
	int dequeue(); 
	void decreaseKey(int i, int new_val); 
	int getMin() { return harr[0]; } 
	void deleteKey(int i); 
	void enqueue(int k); 
		void Merge_(int a[],int b[],int n,int m);
}; 

MinHeap::MinHeap(int cap) 
{ 
	heap_size = 0; 
	capacity = cap; 
	harr = new int[cap]; 
} 

void MinHeap::enqueue(int k) 
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; } 

	heap_size++; 
	int i = heap_size - 1; 
	harr[i] = k; 

	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
	swap(&harr[i], &harr[parent(i)]); 
	i = parent(i); } } 

void MinHeap::decreaseKey(int i, int new_val) 
{ 
	harr[i] = new_val; 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
	swap(&harr[i], &harr[parent(i)]); 
	i = parent(i); 
	} 
} 

int MinHeap::dequeue() 
{ 
	if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 
 	int root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root; 
} 

void MinHeap::deleteKey(int i) 
{ 
	decreaseKey(i, INT_MIN); 
	dequeue(); 
} 


void MinHeap::MinHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && harr[l] < harr[i]) 
		smallest = l; 
	if (r < heap_size && harr[r] < harr[smallest]) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&harr[i], &harr[smallest]); 
		MinHeapify(smallest); 
	} 
} 

void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; } 
int main() 
{ 
    int k,n;cin >>k;cin>>n;
	int arr[n];
	for (int i=0;i<n;i++){
	    cin >> arr[i];
	}
	MinHeap h(11); 
	for (int i=0;i<n;i++){
	   h.enqueue(arr[i]*(-1));
	}
    //cout << h.getMin() << " ";   
	//h.dequeue(); 
	//cout << h.getMin() << " "; 
	int cnt=0;
	for (int i=0;i<k;i++){
	    cnt=cnt+(h.getMin()*(-1));
	    h.enqueue(h.getMin()/2);
	    h.dequeue();
	}
	cout<<cnt<<" is answer"; 
	return 0; 
} 
