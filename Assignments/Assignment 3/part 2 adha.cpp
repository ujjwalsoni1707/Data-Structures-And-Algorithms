#include <bits/stdc++.h>
using namespace std;

int main() {
	string one;
	cout<< "Enter the srting one: ";
	cin>> one;
	string two;
	cout<< "Enter the string two: ";
	cin>> two;
	int m,n;
	m=one.length();
	n=two.length();
	int pengap;
	int penmismat;
	cout << "Enter the gap penality: ";
	cin>> pengap;
	cout << "Enter the mismatch penality: ";
	cin>> penmismat;
	//cout << n<<"f";
    
    
    int array[n+1][2] = {0}; 

    for (int i = 0; i <= n; i++) 
    { array[i][0] = pengap*i; }
    
  
    for (int i=0;i<m;i++){
        array[0][1]=pengap+array[0][0];
        for (int j = 1; j <= n; j++) 
        { 
            if (two[j-1] == one[i]){ array[j][1] = array[j - 1][0]; } 
            else
            { array[j][1] = min({array[j-1][0] + penmismat,array[j-1][1] + pengap,array[j][0] + pengap    }); 
            } 
        }
        /*for (int i = 0; i <= n; i++) 
    { cout << array[i][0]<<" ";  }
    cout << "\n";
    for (int i = 0; i <= n; i++) 
    { cout << array[i][1]<<" ";  }*/
        for (int k = 0; k <= n; k++) 
    { array[k][0] = array[k][1]; }
        
    }
        
     
    cout << "COST = "; 
    cout << array[n][1] << "\n";
   
   return 0;}
      
    