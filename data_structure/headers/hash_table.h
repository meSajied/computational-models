#include <list> 
using namespace std;

#ifndef HASH_TABLE_H
#define HASH_TABLE_H
  
class Hash{
private:
    int BUCKET;
    list <int>* table;
    int doing_hash(int key);

public: 
    Hash(int index);
    void insert_item(int key);
    void delete_item(int key);
};

#endif