#include<bits/stdc++.h>
using namespace std;
const int Maxstk=100;
int Q[Maxstk];
int front1=-1;
int rear=-1;

void Enqueue(int val){
    if(rear==Maxstk-1){
        cout<<"Overflow"<<endl;
    }
    else{
        if(front1 ==-1){
            front1 =0;
        }
            rear++;
            Q[rear]=val;


    }
}

void Dequeue(){
if(front1==-1||front1>rear){
    cout<<"Underflow"<<endl;
}
    else{
        int val=Q[front1];
        front1++;
    }
    cout<<endl;
}


void display(){
    if(front1==-1 || front1>rear){
        cout<<"Queue is empty"<<endl;
        return;
    }
    for(int i=front1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int main(){

 Enqueue(30);
 Enqueue(20);
 Enqueue(10);
 display();
 Dequeue();
 display();


}

