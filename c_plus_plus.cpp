#include <iostream>
#include "data_structure/headers/hash_table.h"
using namespace std;

int main(){
    Hash hash(10);

    hash.insert_item(7);
    hash.insert_item(14);
    hash.delete_item(14);
}