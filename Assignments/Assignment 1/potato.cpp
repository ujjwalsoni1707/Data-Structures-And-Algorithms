#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node* head;
void insert(int x){
node* temp=(node*)malloc(sizeof(struct node));
temp->data=x;
temp->next=head;
head=temp;
}
void cir(){
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    
}

void delete_(int i,int n){
    struct node* temp1;
    struct node* temp2;
    if (i==1){
    cout << n;
    return;}
    else{
    temp1=head;
    for(int j=0;j<i-2;j++){
        temp1=temp1->next;}
        
        temp2=temp1->next;    
        temp1->next=temp2->next;
        free(temp2);
    }
    for (int l=0;l<n-2;l++){
        for (int g=0;g<i-1;g++){
            temp1=temp1->next;}
            struct node* temp2=temp1->next;
            temp1->next=temp2->next;
            free(temp2);
        
    }
    cout<<temp1->data;
}

int main() {
int n;
cin>> n;
for (int j=n;j>0;j--){
    insert(j);
}
int i;
cin >> i;

cir();
delete_(i,n);
	return 0;
}