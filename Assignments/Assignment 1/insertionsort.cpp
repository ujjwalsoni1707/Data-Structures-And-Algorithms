#include <iostream>
using namespace std;
#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <string.h>

template<class Item>
class LinearList{
	private:
		int MaxSize;
		Item *element;    
              	int len;
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		
		LinearList()
		{
			len = 0;
			element = new Item[MaxSize]();
		};

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize)
		{
			MaxSize = MaxListSize;
			len = 0;
			element = new Item[MaxSize]();

		};

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList()
		{
			delete[] element;
		};

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i)
		{
			return element[i];
		}; //return i'th element of list
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty()
		{
			if (len == 0)
			{
				return true;
			}
			return false;
		};

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length()
		{
			return len;
		}

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize()
		{
			return MaxSize;
		}

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k)
		{
			return element[k-1];
		}

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x)
		{
			if (k<=len)
			{
				element[k-1] = x;
				return true;
			}
			else
			{
				return false;
			}
		}

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x)
		{
			for (int i=0; i<len; i++)
			{
				if (element[i] == x)
				{
					return i;
					break;
				}
			}
			return 0;
		}

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x)
		{

		}

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x)
		{
			len += 1;
			for (int i=len-1; i>=k; i--)
			{
				element[i] = element[i-1];
			}
			element[k-1] = x;
		}
};


#endif

void insertionsort(LinearList<int> ll,int n){
    for (int i=2;i<=n;i++){
        int value=ll.returnListElement(i);
        
        int hole=i;
        
        while (hole>0 && ll.returnListElement(hole-1)>value){
            int h=ll.returnListElement(hole-1);
            
            ll.find(hole,h);
            
            hole=hole-1;
            
        }
        
        ll.find(hole,value);
        
    }
    for (int i=1;i<n+1;i++){
	int f=ll.returnListElement(i);
	cout << f<<" ";}
    
}
int main() {
	LinearList<int> ll(10);
	int n;
	cout << "Enter size of array: ";
	cin >> n;
	cout << "\n";
	
	
	
	for (int i=1;i<n+1;i++){
	    int s;
	    cin >> s;
	    ll.insert(i,s);
	}
	for (int i=1;i<n+1;i++){
	int b=ll.returnListElement(i);
	cout << b<<" ";}
	
	cout<<"\n";
	insertionsort(ll,n);
	
	
	
	return 0;
}