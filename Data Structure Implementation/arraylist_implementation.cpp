// Implementation of Vector/ArrayList

#include <bits/stdc++.h> 

using namespace std; 

template <typename T> 
class ArrayList{
    private:
        int capacity=1;
        int count=0;
        T* arrayptr=NULL;
    public:
        ArrayList();
        void insert(T val);
        T get(int index);
};

template <typename T> 
ArrayList<T>::ArrayList(){
    arrayptr=new T[capacity];
    this->capacity=capacity;
}

template <typename T> 
T ArrayList<T>::get(int index){
    if(count>0 && index < count)
        return arrayptr[index];
    throw "Index out of bound exception";
}

template <typename T> 
void ArrayList<T>::insert(T val){
    if(count==capacity){
    	capacity=capacity*2;
        T* arrayptr2 = new T[capacity];
        cout<<"Expanding capacity: ";
        for (int i=0;i<count;i++){
            arrayptr2[i]=arrayptr[i];
        }
        delete[] arrayptr;
        arrayptr = arrayptr2;
    }
    cout<<"Inserted value: "<<val<<"\n";
    arrayptr[count]=val;
    count++;
}

int main(){
	ArrayList<int> a;
	a.insert(1);
	cout<<a.get(0)<<"\n";
	a.insert(2);
	a.insert(3);
	a.insert(4);
	cout<<a.get(2)<<"\n";
	a.insert(5);
	a.insert(6);
	a.insert(7);
	cout<<a.get(5)<<"\n";
	a.insert(8);
	cout<<a.get(7)<<"\n";
	a.insert(9);
	
	
}
