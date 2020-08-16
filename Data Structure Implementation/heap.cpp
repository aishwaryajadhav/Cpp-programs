#include <bits/stdc++.h> 
using namespace std; 


class Heap{
    int* arr;
    int size;
    int capacity;
    bool swap(int a , int b){
        if(a==b)
            return false;
        int t=arr[a];
        arr[a]=arr[b];
        arr[b]=t;
        return true;
    }
    public:
    Heap(int* a, int s){
    	//cout<<a[5];
        arr=a;
        size=s;
        capacity=s;
        BuildMinHeap();
    }
    Heap(int c){
        arr=new int[c];
        capacity=c;
        size=0;
    }
    void print();
    void BuildMinHeap();
    void insert(int d);
    void heapify(int in);
    int getMin();
    void deleteNode(int in);
    int getLeftChild(int in);
    int getRightChild(int in);
    int getParent(int in);
    void sort();
};
int Heap::getLeftChild(int in){
    int m=2*in+1;
    if(m<size)
        return m;
    return -1;
}
int Heap::getRightChild(int in){
    int m=2*in+2;
    if(m<size)
        return m;
    return -1;
}
int Heap::getParent(int in){
    int m=(in-1)/2;
    if(m>=0 && m<size)
        return m;
    return -1;
}
void Heap::heapify(int in){
    int l,r,minIn=in;
    if(in<size){
        l=getLeftChild(in);
        r=getRightChild(in);
        if(l!=-1 && arr[l]<arr[minIn]){
            minIn=l;
        }
        if(r!=-1 && arr[r]<arr[minIn]){
            minIn=r;
        }
        if(swap(in,minIn))
            heapify(minIn);
    }
}
void Heap::BuildMinHeap(){
    if(size>1){
        int p=getParent(size-1);
        for(int i=p;i>=0;i--){
//        	cout<<arr[i]<<" ";
            heapify(i);
        }
    }
}
int Heap::getMin(){
    if(size==0)
        return -1;
    int min=arr[0];
    deleteNode(0);
    return min;
}
void Heap::insert(int d){
    if(size==capacity){
        cout<<"\nOverflow\n";
        return;
    }
    arr[size]=d;
    size++;
    int i=size-1;
    int p=getParent(i);
    while(p!=-1){
        if(arr[i]<arr[p]){
            swap(i,p);
        }
        else{
            break;
        }
        i=p;
        p=getParent(i);
    }
}
void Heap::deleteNode(int in){
    arr[in]=arr[size-1];
    size--;
    heapify(in);
}
void Heap::print(){
	cout<<endl;
	for(int i=0;i<size;i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
}
void Heap::sort(){
	int *sortedarr;
    if(size>1){
    	int s=size;
        sortedarr=new int[size];
        for(int i=0;i<s;i++){
            sortedarr[i]=getMin();
        }
        size=s;
    }
    arr=sortedarr;
    
}
int main(){
	int a[]={1, 5, 8,7, 0, 6, 2, 3};
	Heap h(a,8);
	h.print();
	cout<<h.getMin()<<endl;
	cout<<h.getMin()<<endl;
	h.print();
	h.insert(9);
	h.insert(0);
	h.print();
	h.sort();
	h.print();
	
}
