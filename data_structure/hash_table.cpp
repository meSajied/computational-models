#include "headers/hash_table.h"
using namespace std;

Hash::Hash(int index){
    this->BUCKET = entry;
    table = new list<int>[BUCKET];
}

Hash::insert_item(int key){
    int index = Hash::doing_hash(key);
    table[index].push_back(key);
}

Hash::delete_item(int key){
    int index = Hash::doing_hash(key); 

    list <int>::iterator i; 
    for (i = table[index].begin(); 
            i != table[index].end(); i++) { 
        if (*i == key){
        break;
        }

        if (i != table[index].end()){
        table[index].erase(i);
    }
    }
}

Hash::doing_hash(int key){
    int hashed_key = key % BUCKET;
    return hashed_key;
}