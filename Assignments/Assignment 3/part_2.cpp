#include <bits/stdc++.h>
using namespace std;
vector< pair <int,int> > vect;
vector< pair <int,int> > vect1;
vector <int> costarr;
void BSEA(string one,string two,int pengap,int penmismat,int *arr){
    int m,n;
    m=one.length();
    n=two.length();
    int array[n+1][2] = {0}; 

    for (int i = 0; i <= n; i++) 
    { array[i][1] = ((n)*pengap)-(pengap*i); }
    
    
  
    for (int i=0;i<m;i++){
        array[n][0]=pengap+array[n][1];
        for (int j = n-1; j >=0; j--) 
        { 
            if (two[j] == one[m-1-i]){ array[j][0] = array[j + 1][1]; } 
            else
            { array[j][0] = min({array[j+1][1] + penmismat,array[j+1][0] + pengap,array[j][1] + pengap    }); 
            } 
        }
   /* for (int i = 0; i <= n; i++) 
    { cout << array[i][1]<<" ";  }
    cout << "\n";
    for (int i = 0; i <= n; i++) 
    { cout << array[i][0]<<" ";  }*/
        for (int k = 0; k <= n; k++) 
    { array[k][1] = array[k][0]; }
        
    }
    for (int i=0;i<=n;i++){
        arr[i]=array[i][0]+arr[i];
    }
    
}
void SEA(string one,string two,int pengap,int penmismat,int *arr){
    int m,n;
    m=one.length();
    n=two.length();
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
    for (int i=0;i<=n;i++){
        arr[i]=array[i][1]+arr[i];
    }
}
void A(string one,string two,int pengap,int penmismat,int g,int h){
    int m,n;
    m=one.length();
    n=two.length();
    int tl=m+n+1;
    //cout<<g<<h<<"\n";
    
    
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
    } } } 
    //cout << m<<","<<n<<"\n";
    int i,j,hh=1;  
    i = m; j = n; 
    m = tl-1; 
    n = tl-1; 
    
    char string1[tl], string2[tl]; 
      
    while ( i > 0 || j > 0) 
    { if (one[i - 1] == two[j - 1]) 
        { //cout << j-1+h<<","<<i-1+g<<"\n";
        vect.push_back( make_pair(j-1+h,i-1+g) );
            i--; j--; } 
        else if (array[i - 1][j - 1] + penmismat == array[i][j]) 
        { //cout << j-1+h<<","<<i-1+g<<"\n";
        vect.push_back( make_pair(j-1+h,i-1+g) );
            i--; j--; } 
        else if (array[i - 1][j] + pengap == array[i][j]) 
        { //cout << j+h<<","<<i-1+g<<"\n";
        vect.push_back( make_pair(j+h,i-1+g) );
            i--; } 
        else 
        { //cout << j-1+h<<","<<i+g<<"\n";
        vect.push_back( make_pair(j-1+h,i+g) );
            j--; 
        } 
    } 
    
}
int findmin(int array[],int n){
    int min=array[0];
    int index=0;
    for (int i=1;i<n;i++){
        if (min>array[i]){min=array[i];index=i;}
        
    }
    costarr.push_back(array[index]);
    return index;
}

void DAQ(string one,string two,int pengap,int penmismat,int g,int h){
    int m,n;
    m=one.length();
    n=two.length();
    if (m<=2 || n<=2){A(one,two,pengap,penmismat,g,h);return;}
    int arr[n]={0};
    
    int a,b,c;
    SEA(one.substr(0,m/2),two,pengap,penmismat,arr);
    
    BSEA(one.substr(m/2,m),two,pengap,penmismat,arr);
    /*for (int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }*/
    int index=0;
    //cout<<n;
    index=findmin(arr,n+1)+index;
    //cout << index+h<<","<<m/2+g<<"\n";
    vect.push_back( make_pair(index+h,m/2+g) );
    //cout << two[index-1]<<" and "<<one[m/2-1]<<"\n";
    DAQ(one.substr(0,m/2),two.substr(0,index),pengap,penmismat,0,0);
    DAQ(one.substr((m/2),m),two.substr(index,n),pengap,penmismat,m/2,index);
    
}
 

int main() {
    string one;
    cout<< "Enter the srting one: ";
    cin>> one;
    string two;
    cout<< "Enter the string two: ";
    cin>> two;
    int pengap;
    int penmismat;
    cout << "Enter the gap penality: ";
    cin>> pengap;
    cout << "Enter the mismatch penality: ";
    cin>> penmismat;
    int m,n;
    m=one.length();
    n=two.length();
    //cout << n<<"f";
    //cout<<"0,0\n";
    vect.push_back( make_pair(0,0) ); 
    DAQ(one,two,pengap,penmismat,0,0);
    //cout<<n<<","<<m<<"\n";
    vect.push_back( make_pair(n,m) );
    int len=vect.size();
    sort(vect.begin(), vect.end());
   /* for (int i=0; i<len; i++) 
    { 
        cout << vect[i].first << " "
             << vect[i].second << endl; 
    }*/
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
    cout<<"Cost= "<<costarr[0]<<"\n";
    //cout<<"__\n";
    int x1=0,x2=0;
    for (int i=0;i<len1-1;i++){
        if(vect1[i+1].first==vect1[i].first+1){
            x1++;
            cout<<two[x1-1];
        }
        else{cout<<"_";}
        if(vect1[i+1].second==vect1[i].second+1){
            x2++;
            cout<<one[x2-1];
        }
        else{cout<<"_";}
        cout<<"\n";
    }
    
return 0;}
      
    