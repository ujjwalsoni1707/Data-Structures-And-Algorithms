
#include<iostream> 
#include<climits> 
using namespace std; 

 
void swap(int *x, int *y); 

 
class MinHeap 
{ 
	int *ptr;  
	int capacity; 
	int heap_size;  
public: 

	MinHeap(int capacity); 

	void MinHeapify(int ); 
	int parent(int i) { return (i-1)/2; } 
	int left(int i) { return (2*i + 1); } 
	int right(int i) { return (2*i + 2); } 
	int extractMin(); 
	void decreaseKey(int i, int new_val); 
	int getMin() { return ptr[0]; } 
    void deleteKey(int i); 
    void insertKey(int k); 
	void Merge_(int a[],int b[],int n,int m);
}; 


MinHeap::MinHeap(int c) 
{ heap_size = 0; 
	capacity = c; 
	ptr = new int[c]; } 

void MinHeap::insertKey(int k) 
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 
    heap_size++; 
	int i = heap_size - 1; 
	ptr[i] = k; 

	while (i != 0 && ptr[parent(i)] > ptr[i]) 
	{ 
	swap(&ptr[i], &ptr[parent(i)]); 
	i = parent(i); 
	} } 

void MinHeap::decreaseKey(int i, int new_val) 
{ 
	ptr[i] = new_val; 
	while (i != 0 && ptr[parent(i)] > ptr[i]) 
	{ 
	swap(&ptr[i], &ptr[parent(i)]); 
	i = parent(i); 
	} } 

int MinHeap::extractMin() 
{ 
	if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return ptr[0]; 
	} 
 
	int root = ptr[0]; 
	ptr[0] = ptr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root; } 

void MinHeap::deleteKey(int i) 
{ 
	decreaseKey(i, INT_MIN); 
	extractMin(); 
} 

void MinHeap::MinHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && ptr[l] < ptr[i]) 
		smallest = l; 
	if (r < heap_size && ptr[r] < ptr[smallest]) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&ptr[i], &ptr[smallest]); 
		MinHeapify(smallest); 
	} 
} 


void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 
void MinHeap::Merge_(int a[],int b[],int n,int m)
{
    int arr[m+n];
  for (int i = 0; i < n; i++) 
        arr[i] = a[i]; 
    for (int i = 0; i < m; i++) 
        arr[n + i] = b[i]; 
  MinHeap h2(25);
  for (int i=0;i<m+n;i++){
      h2.insertKey(arr[i]);
  }
  cout <<"Min element in merged heap "<< h2.getMin()<<"\n";
}
 
int main() 
{ 
    int a[]={3,9,15,5,4,45};
    int b[]={5,7,4,3};
    int n = sizeof(a) / sizeof(a[0]); 
    int m = sizeof(b) / sizeof(b[0]); 
  
	MinHeap h(11); 
	MinHeap h1(11);

	
	
	for (int i=0;i<6;i++){
	    h.insertKey(a[i]);// b) Function to insert a key
	}
	for (int i=0;i<4;i++){
	    h1.insertKey(b[i]);
	}
	h.Merge_(a,b,n,m);// d) Function to merge the two heaps  
	//cout << h.extractMin() << " "; 
	cout << h.getMin() << "\n"; // a) Function to get minimum element 
	h.deleteKey(0); // e) Function to remove key
	cout << h.getMin() << "\n";
	h.decreaseKey(1, 2); // c) Function for decrease key
	cout << h.getMin()<<"\n"; 
	return 0; 
} 
