#include <bits/stdc++.h>
using namespace std;
vector< pair <int,int> > vect;
vector< pair <int,int> > vect1;

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
   int i,j,hh=1;  
    i = m; j = n; 
    m = tl-1; 
    n = tl-1; 
    
    char string1[tl], string2[tl]; 
      
    while ( !(i == 0 || j == 0) ) 
    { if (one[i - 1] == two[j - 1]) 
        { //cout << j-1+h<<","<<i-1+g<<"\n";
        vect.push_back( make_pair(j-1,i-1) );
            i--; j--; } 
        else if (array[i - 1][j - 1] + penmismat == array[i][j]) 
        { //cout << j-1+h<<","<<i-1+g<<"\n";
        vect.push_back( make_pair(j-1,i-1) );
            i--; j--; } 
        else if (array[i - 1][j] + pengap == array[i][j]) 
        { //cout << j+h<<","<<i-1+g<<"\n";
        vect.push_back( make_pair(j,i-1) );
            i--; } 
        else 
        { //cout << j-1+h<<","<<i+g<<"\n";
        vect.push_back( make_pair(j-1,i) );
            j--; 
        } 
    }
    while (j!=0){
        {vect.push_back( make_pair(j-1,i) );j--;}
    }
    while (i!=0){
        {vect.push_back( make_pair(j,i-1) );i--;}
    }
    m=one.length();
    n=two.length();
    
     vect.push_back( make_pair(0,0) ); 
   // DAQ(one,two,pengap,penmismat,0,0);
    //cout<<n<<","<<m<<"\n";
    vect.push_back( make_pair(n,m) );
    int len=vect.size();
   /* for (int i=0; i<len; i++) 
    { 
        cout << vect[i].first << " "
             << vect[i].second << endl; 
    }*/
    
    sort(vect.begin(), vect.end());
    
    vect1.push_back( make_pair(vect[0].first,vect[0].second ) ); 
    for (int i=1;i<len;i++)
    {
       if (vect[i-1].first!=vect[i].first || vect[i-1].second!=vect[i].second)
       {vect1.push_back(make_pair(vect[i].first,vect[i].second ));} 
    }
   // cout<<".......................\n";
    int len1=vect1.size();
    /*for (int i=0; i<len1; i++) 
    { 
        cout << vect1[i].first << " "
             << vect1[i].second << endl; 
    }*/
    cout<<"\n";
    //cout<<"Cost= "<<costarr[0]<<"\n";
    //cout<<"__\n";
    int x1,x2;
    x1=0;x2=0;
    string three=" ";string four=" ";
    for (int i=0;i<len1-1;i++){
        if(vect1[i+1].first==vect1[i].first+1){
            x1++;
            cout<<two[x1-1];
            three=three+two[x1-1];
        }
        else{cout<<"_";
        three=three+"_";}
        if(vect1[i+1].second==vect1[i].second+1){
            x2++;
            cout<<one[x2-1];
            four=four+one[x2-1];
        }
        else{cout<<"_";
        four=four+"_";}
        cout<<"\n";
    }
    cout<<"\n";
    cout<<four<<"\n";
    cout<<three;
    /*int cost=0;
    string six="_";
    int len2=four.size();
    for (int i=1;i<len2;i++){
        if (four[i]==three[i]){cost=cost+0;}
        else if ((four[i]!=three[i]) && (four[i]!=six[0]) && (three[i]!=six[0])){cost=cost+penmismat;}
        else{cost=cost+pengap;}
    }cout<<"\nCost= "<<cost;
    */

   
    return 0;
}