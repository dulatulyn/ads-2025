
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    
    Node(int x){
        val = x;
        next = nullptr;
    }
};


int main(){ 
    int n;
    cin >> n;

    Node* thread = new Node(0);
    Node* dum = thread;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        dum->next = new Node(k);
        dum = dum->next;
    }

    Node* temp = thread->next;
    while(temp && temp->next){
        cout << temp->val << " ";
        temp = temp->next->next;
    }
    if(temp)cout << temp->val;
    
    

    return 0;
}
