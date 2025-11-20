#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};
typedef Node* nodePtr;

int main(){
    nodePtr head = new Node;
    head->data = 20;
    head->link = NULL;
    
    return 0;
}
