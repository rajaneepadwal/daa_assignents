#include<iostream>
using namespace std;
struct Node
{
    char data;
    int freq;

    Node* left;
    Node* right;

    Node(char d, int f)
    {
        data = d;
        freq = f;
        left = NULL;
        right = NULL;
    }
};
void sorted(Node* nodes[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(nodes[i]->freq > nodes[j]->freq)
            {
                Node* temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
}
int main()
{
    char data[]={'a','b','c','d'};
    int freq[]={5,9,12,13};
    int size=4;
    
    // struct Node* root=buildTree(data,freq,size);
        struct Node* nodes[4], *left, *right;
        for(int i=0;i<4;i++)
        {
            nodes[i]=new struct Node(data[i],freq[i]);
        }
        while(size>1)
        {
            sorted(nodes,size);
            left=nodes[0];
            right=nodes[1];

            struct Node *newNode=new struct Node('@',left->freq+right->freq);
            newNode->left=left;
            newNode->right=right;
            nodes[0]=newNode;
            nodes[1]=nodes[size-1];
            size--;
        }
}