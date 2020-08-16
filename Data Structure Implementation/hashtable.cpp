#include <iostream>
#include <forward_list> 
#include <bits/stdc++.h> 

using namespace std;

class HashTable{
    private:
        forward_list<pair<int, int>> hashtable[50];
        int hash_function(int val);
        forward_list<pair<int, int>>::iterator find_key(int key);
    public:
        void insert(int key, int val);
        int get(int key);
        void delete_h(int key);
        void update(int key, int val);
        bool check_key(int key);
};

int HashTable::hash_function(int val){
    return val%50;
}

void HashTable::insert(int key, int val){
    int key_index=hash_function(key);
    forward_list<pair<int, int>>& fl = hashtable[key_index];
    if(!check_key(key)){
        fl.push_front(make_pair(key,val));
    }
    else{
        cout<<"Key already present. Aborting.\n";
    }  
}

void HashTable::update(int key, int val){
    int key_index=hash_function(key);
    forward_list<pair<int, int>>& fl = hashtable[key_index];
    auto it = find_key(key);
    if(it==fl.end()){
        cout<<"Key not Found\n";
    }
    else{
        it->second=val;
    }  
}

int HashTable::get(int key){
    int key_index=hash_function(key);
    forward_list<pair<int, int>>& fl = hashtable[key_index];
    auto it = find_key(key);
    if(it== fl.end()){
        cout<<"Key not Found\n";
        throw "Key not found";
    }
    return it->second;
}

bool HashTable::check_key(int key){
	forward_list<pair<int, int>>& fl = hashtable[hash_function(key)];
    return !(find_key(key)==fl.end());
}

forward_list<pair<int, int>>::iterator HashTable::find_key(int key){
    int index=hash_function(key);
    forward_list<pair<int, int>>& fl = hashtable[index];
    for(auto it = fl.begin(); it!=fl.end();it++){
        if(it->first==key)
            return it;
    }
    return fl.end(); 
}

void HashTable::delete_h(int key){
    int index=hash_function(key);
    forward_list<pair<int, int>>& fl = hashtable[index];
    auto it=fl.begin();
    if(it->first == key)
        fl.pop_front();
    else{
    	auto it1=next(it,1);
        while(it1!=fl.end()){
            if(it1->first==key){
                fl.erase_after(it);
                return;
            }
            it++;
        }
        cout<<"Key does not exist\n";
    }
}

int main(){
	HashTable h;
	h.insert(1,2);
	cout<<h.check_key(2)<<endl;
	h.insert(2,3);
	cout<<h.check_key(2)<<endl;
	h.insert(52,8);
	cout<<h.get(52)<<endl;
	h.update(52, 9);
	cout<<h.get(52)<<endl;
	h.delete_h(2);
	cout<<h.check_key(2)<<endl;
	return 0;
}
