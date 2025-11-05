#include <bits/stdc++.h>
using namespace std;

struct hash{
    int BUCKET;

    vector<vector<int>> table;

    void insertItem(int key){
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key);

    int hashFunction(int x){
        return (x % BUCKET);
    }

    void displayHash();

    Hash(int b){
        this->BUCKET = b;
        table.resize(BUCKET);
    }
};

void Hash::deleteItem(int key){
    int index = hashFunction(key);

    auto it = find(table[index].begin(), table[index].end(), key);
    if(it != table[index].end()){
        table[index].erase(it);
    }
}

void Hash::displayHash(){
    for(int i = 0; i < BUCKET; i++){
        cout << i;
        for(int x : table[i]){
            cout << "--> " << x;
        }
        cout << endl;
    }
}

int main(){
    vector<int> a = {15, 26, 21, 1, 90};

    Hash h(7);
    for(int key : a){
        h.insertItem(key);
    }

    h.deleteItem(15);
    h.displayHash();
}