#ifndef SORTING_HPP
#define SORTING_HPP
#include <iostream>
#include "seqLinearList.hpp"

template<class Item>
class Sort{
	private:
		
	public:
		
        
    template<class Item>
	void insertionsort(LinearList<Item>& ll,int n){
    		for (int i=2;i<=n;i++){
    	    Item value=ll.returnListElement(i);
        	
       		 int hole=i;
        
       		 while (hole>0 && ll.returnListElement(hole-1)>value){
            	Item h=ll.returnListElement(hole-1);
            
            	ll.find(hole,h);
            
            	hole=hole-1;}
        
        	ll.find(hole,value);
        
    	}
    	for (int i=1;i<n+1;i++){
		Item f=ll.returnListElement(i);
		cout << f<<" ";}}


	void mergeSort(LinearList<Item>& A, int low, int high);
    void quickSort(LinearList<Item>& A, int low, int high);
};

#endif