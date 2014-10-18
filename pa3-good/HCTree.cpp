/**
*Authors: Tiffany Tse A10296316 username: titse,
*Author: Martin Vanek  A09383174 username: mvanek
* FileName: HCTree.cpp
* Date May 10,2014
* Final Rev-Date: May 15,2014
* Description: Implementation of HCTree.hpp see HCTree for full description 
*/

//start of HCTREE.cpp
#include "HCTree.hpp"
#include "HCNode.hpp"
#include <bitset>
#include <algorithm>
#include <stack>


   /***
   *destructor copied from BST
   *
   */
static void deleteAll (HCNode *n)
  {
	  if(0==n)
		  return;
	  deleteAll(n->c0);
	  deleteAll(n->c1);
	 
	  delete n;
	
  }


HCTree::~HCTree()
{
	deleteAll(root);
	
}

 /** Use the Huffman algorithm to build a Huffman coding trie.
     *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
     *  the frequency of occurrence of byte i in the message.
     *  POSTCONDITION:  root points to the root of the trie,
     *  and leaves[i] points to the leaf node containing byte i.
     */

	void HCTree:: build(const vector<int>& freqs) {
		
		//loop through priority and frequency to add leaves	
		for(int i=0; i<freqs.size(); i++)
		{
			if (freqs.at(i) !=0) 
			{
				leaves[i]= new HCNode(freqs.at(i),i);
				pq.push(leaves[i]); //pq defined in HCTree

			}


		}
		
		//what if you got one leaf? make a dummy node. 

		if (pq.size()==1)
		{
			HCNode *lparent= new HCNode(0,0);
			pq.push(lparent); 
		}
		
		// if the priority_queue has more than one node let say internal nodes
		// then there must be internal leaves that we must make
		while(pq.size() > 1)
		{
			HCNode *newnode= new HCNode(0,0);
	
			//set childO from HCNodes to top of priority queue
			newnode->c0=pq.top(); 
			
			//set that newnode on top of priority queue to new node's parent
			newnode->c0->p=newnode;

			//call pq.pop to go to the next element
				pq.pop();

			//set child1 from HCnode to next element
				newnode->c1=pq.top();

			//set newnode to child1's parent
				newnode->c1->p=newnode;
			
			//call pop again to move next element
				pq.pop();

			//calculate the total number of nodes
			newnode->count = newnode->c0->count + newnode->c1->count;
			
			//push newnode to the bottom of priority queue
			pq.push(newnode);
		}
		//set root to root of priority queue
		root = pq.top();
	}


     /** Write to the given ofstream
     *  the sequence of bits (as ASCII) coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT 
     *  BE USED IN THE FINAL SUBMISSION.
     */

 /* void HCTree:: encode( byte symbol, ofstream& out) const{
     HCNode *lenodes=leaves[symbol]; //stores 0 or 1
	 HCNode *parent=lenodes->p;
	 stack<int> num_code;
	//start at the bottom and then go up while lenodes is not
	// equal to root
		while (lenodes !=root)
		{
			//if symbol is left child 
			if (parent->c0 == lenodes)
			{
				num_code.push(0);

			}
			//if the symbol is right child assign 1 
            else 
			{
				
				//add 1 to the stack 
				num_code.push(1); 

			}
			lenodes = parent;
			parent = lenodes->p;

		}
			//if the symbols are added then  push to top of stack and pop them.
			while(!num_code.empty())
			{
				out << num_code.top(); 
				num_code.pop();//pop them off the stack when you are done

			}
	
		}

    

*/

    /** Write to the given BitOutputStream
     *  the sequence of bits coding the given symbol.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
void HCTree::encode(byte symbol, BitOutputStream& out) const{

     HCNode *lenodes=leaves[symbol]; //stores 0 or 1
	 HCNode *parent=lenodes->p;//parent pointer 
	 stack<int> num_code;
	//start at the bottom and then go up while lenodes is not
	// equal to root
		while (lenodes !=root)
		{
			//if symbol is left child 
			if (parent->c0 == lenodes)
			{
				num_code.push(0);

			}
			//if the symbol is right child assign 1 
            else 
			{
				
				//add 1 to the stack 
				num_code.push(1); 

			}
		    //update lenode's parents 
            lenodes = parent;
			parent = lenodes->p;//fwd pointer to lenodes parent

		}
			//if the symbols are added then  push to top of stack and pop them.
			while(!num_code.empty())
			{
                 //write the bits at the top stack
				out.writeBit(num_code.top()); 
				num_code.pop();//pop them off the stack when you are done

			}


}



   /** Return the symbol coded in the next sequence of bits (represented as 
     *  ASCII text) from the ifstream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT BE USED
     *  IN THE FINAL SUBMISSION.
     */
/*
  int HCTree::decode(ifstream& in) const {
	HCNode *leaf =root; //leaf pointer going down
	int bit; //variable to decode down tree

	// must statifies these conditions when going down the tree 
	while (leaf->c0 !=0 && leaf->c1 != 0)
	{
		bit = in.get();
		if (bit== 48)
		{	
			leaf=leaf->c0; 
		}

		else
		{
			leaf=leaf->c1; 
			//bit==0;
		}
	}

	return leaf->symbol; 



 } */



    /** Return symbol coded in the next sequence of bits from the stream.
     *  PRECONDITION: build() has been called, to create the coding
     *  tree, and initialize root pointer and leaves vector.
     */
int HCTree:: decode(BitInputStream& in) const{
 
	HCNode *leaf =root; //leaf pointer going down
	int bit; //variable to decode down tree

	// must statifies these conditions when going down the tree 
	while (leaf->c0 !=0 && leaf->c1 != 0)
	{
		//read the bits which are 1 and 0s before transveral
        bit=in.readBit();
		if (bit== 0)
		{	
			leaf=leaf->c0; 
		}

		else
		{
			leaf=leaf->c1; 
			//bit==1;
		}
	}
    //return the leaf storing the symbol
	return leaf->symbol; 



}

//end of HCTree.cpp
