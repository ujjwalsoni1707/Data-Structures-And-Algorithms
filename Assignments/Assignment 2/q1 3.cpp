// C++ program for building Heap from Array 

#include <iostream> 

using namespace std; 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. N is size of heap 
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 


void buildHeap(int arr[], int n) 
{ 
	
	int startIdx = (n / 2) - 1; 

	for (int i = startIdx; i >= 0; i--) { 
		heapify(arr, n, i); 
	} 
} 

// A utility function to print the array 
// representation of Heap 
void printHeap(int arr[], int n) 
{ 
	 

	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

// Driver Code 
int main() 
{ 
	 
	int k,n;cin >>k;cin>>n;
	int arr[n];
	for (int i=0;i<n;i++){
	    cin >> arr[i];
	}
    buildHeap(arr, n); 
    printHeap(arr, n); 
	int cnt=0;
	for (int i=0;i<k;i++){
	    cnt=cnt+arr[0];
	    arr[0]=arr[0]/2;
	    buildHeap(arr,n);
	}
	cout<<cnt<<" is answer";
	return 0; 
} 
