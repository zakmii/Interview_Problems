#include <bits/stdc++.h>

class Node{
    private:

    int data;
    int freq;
    Node* left;
    Node* right;

    public:

    Node(int data,int freq,Node* Left=NULL,Node* Right=NULL){
        this->data=data;
        this->freq=freq;

        this->left=Left;
        this->right=Right;
    }

    int getData(){
        return this->data;
    }

    int getFreq(){
        return this->freq;
    }

    Node* getLeft(){
        return this->left;
    }

    Node* getRight(){
        return this->right;
    }
};

class Comparator{ //comparator class for Min-Heap(priority queue) on the basis of frequency of Node
public:
    bool operator()(Node* A,Node* B)
    {
        int freqA=A->getFreq();
        int freqB=B->getFreq();

        return freqA>freqB;
    }
};

class createTree{
    private:

    int n; //number of elements
    vector<string> huffCode; //final huffman code
    priority_queue<Node*,vector<Node*>,Comparator> pq; //using STL Min-Heap with a custom 
    //compartor class to compare the node on the basis of their frequency

    public:

    createTree(vector<int> freq){
        this->n=freq.size();

        this->huffCode.assign(n,"");
        
        for(int i=0;i<n;i++){
            Node* node=new Node(i,freq[i]);
            
            pq.push(node);
        }

        while(pq.size()>1){
            //take the top 2 Nodes as they have minimum frequency
            Node* nodeA=pq.top();
            pq.pop();

            Node* nodeB=pq.top();
            pq.pop();

            //combining the 2 nodes into 1 and adding their frequencies
            int freqA=nodeA->getFreq();
            int freqB=nodeB->getFreq();

            int combinedFreq= freqA + freqB;

            Node* combinedNode=new Node(-1,combinedFreq,nodeA,nodeB); //putting data as -1 
            //cuz we won't really use its data so it doesnt matter
            //just dont put data same as the data of Core Nodes

            //adding the node in our Min-Heap
            pq.push(combinedNode);
        }

        //Now there is only 1 Node left in our Priority_queue
        //That Node it the Root of our Tree
        //So we start traversing from there
        //check the member function getHuffmanCode below
    }

    vector<string> getHuffmanCode(){
        Node* root=pq.top();
        
        //now traversing our tree
        traversal(root,"");

        return this->huffCode;
    }

    void traversal(Node* root,string str){
        if(root==NULL){
            return;
        }

        int index=root->getData(); //data is the index of the respective element we are encoding

        if(index!=-1){ //means that we reached the bottom Core Nodes from where the tree was built
            this->huffCode[index]=str;
        }

        Node* Left=root->getLeft();
        Node* Right=root->getRight();

        traversal(Left,str+"0"); //when go left then add "0" to our code
        traversal(Right, str+"1");//when go right then add "1" to our code
    }

};

vector<string> huffmanCode(vector<int> &freq)
{
    if(freq.size()==1){
        return {"0"};
    }

    createTree *Tree=new createTree(freq);

    vector<string> ans=Tree->getHuffmanCode();

    return ans;
}