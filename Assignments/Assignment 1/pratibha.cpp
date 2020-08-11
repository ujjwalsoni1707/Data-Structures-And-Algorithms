#include <iostream>
using namespace std;


void print(){
    for (int e=0;e<n;e++){
        cout << a[e]<<" ";
    }
}
int main() {
	int n;
	cout << "Enter the value of n: ";
	cin >> n;
	int a[n];
	for (int i=0;i<n;i++){
		cin << a[i];
	}
	int head;
	cout << "Enter the value of head: ";
	cin >> head;
	
	cout << "Original Array :";
	print();
	cout << "\n";
	

	if (n==2){
	    int h=a[head+1];
	    int j=0;
	    for (int i=head+2;i<length-1;i++){
	        if (a[i]<h){h=a[i];j=i;}
	        
	    }
	    int temp=a[head];
	    a[head]=h;
	    a[j]=temp;
	}
	if (n==3){
	    for (int k=head;k<length-1;k++){
	        if (a[k]>a[k+1]){
	            int temp1=a[k];
	            a[k]=a[k+1];
	            a[k+1]=temp1;
	        }
	    }
	}
	if (n==1){
	    int g=1;;
	    for (int m=1;m<head-1;m++){
	        if (a[head]>a[m-1] && a[head]<a[m+1]){
	            int temp3=a[head];
	            a[head]=a[m];
	            a[m]=temp3;
	            g=0;
	            
	            break;
	            
	        }
	    }
	    if (g==1){
	        for (int c=1;c<head-1;c++){
	            if (a[head]>a[c-1]){
	            int temp3=a[head];
	            a[head]=a[c];
	            a[c]=temp3;
	            g=0;
	            
	            break;
	      }}}
	      if (g==1){
	        for (int v=1;v<head-1;v++){
	            if (a[head]<a[v+1]){
	            int temp3=a[head];
	            a[head]=a[v];
	            a[v]=temp3;
	            g=0;
	            
	            break;
	      }}}}
	      
	      
	cout << "New Array :";
	print();
	return 0;
}