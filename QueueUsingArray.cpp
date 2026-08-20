
#include <bits/stdc++.h>
using namespace std;
class Queue{
    public:
    int start=-1;//front
    int end=-1;//rear
    int currSize=0;
    int queue[10];


    public:
    void push(int x){
        if(currSize==10){
            cout<<"Queue is full"<<endl;
            return;
           
        }
        if(currSize==0){
            start=0,end=0;
        }
        else end=(end+1)%10;
        queue[end]=x;
        currSize++;
    }
    void pop(){
        if(currSize==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        int el=queue[start];
        if(currSize==1){
            start=end=-1;
        }
        else{
            start=(start+1)%10;
            
        }
        currSize--;
        cout<<"poped element :"<<el<<endl;
    }
    int front(){
        if(currSize==0){
            cout<<"empty queue"<<endl;
            return -1;   
        }
        return queue[start];
    }
    int rear() {
    if (currSize == 0) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue[end];
    }

    int size(){
        return currSize;
    }
    void traverse() {
    if(currSize == 0){
        cout << "Queue is empty" << endl;
        return;
    }

    int i = start;

    while (true) {
        cout << queue[i] << " ";

        if(i == end)
            break;

        i = (i + 1) % 10;
    }

    cout << endl;
}
   
};
 



int main(){
    
    Queue q;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++){
        q.push(arr[i]);
    }

    q.pop();
    q.traverse();
    cout<<"front :"<<q.front()<<endl;
    cout<<"rear:"<<q.rear()<<endl;
    q.pop();
    cout<<q.size()<<endl;
}