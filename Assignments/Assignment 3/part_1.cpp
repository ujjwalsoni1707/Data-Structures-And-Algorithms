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
    
    int tl=m+n+1;
    
    int array[tl][tl] = {0}; 

    for (int i = 0; i <= tl-1; i++) 
    { array[i][0] = pengap*i; 
        array[0][i] = pengap*i; }     
  
    int a,b,c;
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            if (one[i - 1] == two[j - 1]){ array[i][j] = array[i - 1][j - 1]; } 
            else
            { a=array[i - 1][j - 1] + penmismat;
                b=array[i - 1][j] + pengap;
                c=array[i][j - 1] + pengap ;   
                if (a <= b && a <= c) 
                    array[i][j]=a; 
                else if (b <= a && b <= c) 
                    array[i][j]=b; 
                else
                    array[i][j]=c;  
            } 
        } 
    } 
    cout << "COST = "; 
    cout << array[m][n] << "\n";
   
   int i,j,h=1;  
    i = m; j = n; 
    m = tl-1; 
    n = tl-1; 
    char string1[tl], string2[tl]; 
      
    while ( !(i == 0 || j == 0) )
    { if (one[i - 1] == two[j - 1]) 
        {string1[m] = one[i - 1]; 
            string2[n] = two[j - 1]; 
            i--; j--;m--;n--; } 
        else if (array[i - 1][j - 1] + penmismat == array[i][j]) 
        { string1[m] = one[i - 1]; 
            string2[n] = two[j - 1]; 
            i--; j--;m--;n--; } 
        else if (array[i - 1][j] + pengap == array[i][j]) 
        { string1[m] = one[i - 1]; 
            string2[n] = '_'; 
            i--;m--;n--; } 
        else 
        { string1[m] = '_'; 
        string2[n] = two[j - 1]; 
            j--;m--;n--; 
        } 
    } 
    while (m >= 1) 
    { 
    if (i >= 1) 
        {string1[m] = one[--i];m--;} 
    else 
        {string1[m] = '_';m--;} 
    } 
    while (n >= 1) 
    { if (j >= 1) 
        {string2[n] = two[--j];n--;} 
    else 
        {string2[n] ='_';n--;} 
    } 
 
    for (i = tl-1; i >= 1; i--) 
    {   if (string2[i] == '_' && string1[i] == '_') 
        { h = i + 1; break; } 
    } 
    for (i = h; i <= tl-1; i++) 
    { cout<<(char)string1[i];} 
    cout << "\n"; 
    for (i = h; i <= tl-1; i++) 
    { cout << (char)string2[i];}
    return 0;
}