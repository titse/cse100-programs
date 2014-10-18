#include <iostream>
#include "BSTNode.hpp"
#include "BST.hpp"
#include "BSTIterator.hpp"

using namespace std;

int main()
{
	BST<int> *root1 = new BST<int>();
	
	root1->insert(500);
	root1->insert(400);
	root1->insert(300);
	root1->insert(231);
	root1->insert(100); 
	root1->insert(1);
		/*begin() method returns an iterator pointing to the smallest number*/	
	 BST<int>::iterator start = root1->begin();
	 BST<int>::iterator end = root1->end(); /**/

	cout << "intially iterator points at 500 \n "
	       << "it is pointing at" << *start << endl;
	if(*start == 1)	
		cout << " good job " << endl;
	else
		cout <<  "error" << endl;


	while(start != end){		

	  
	cout << *start << endl;


	start++;

}

		
	//BSTNode<int>::iterator it;

	 //root->insert(2);
	//root->insert(3);

	 //TIterator(root);

    root1->inorder();
	
    cout << "Yeah, inorder works :) " << endl;
      
      cout << "now checking find" << endl;


	/*Find returns anm iterator pointing the item you are looking for*/

	BST<int>::iterator itemfind = root1->find(500);
	
	if( *itemfind == 500 )
		cout << "pointing to right element" << endl;
	else
		cout << "error" << endl;

	while(itemfind != end){		

	  
	cout << *itemfind << endl;


	itemfind++;

}

	cout << "\n" << "now checking when you pass an element" << "that is not in the tree" << endl;

	
	BST<int>::iterator itemfind2 = root1->find(12233);
	if( itemfind2 == 0)
		cout << " find a no element.... yeah pointing to 0 as it is supposed to " << endl;
	else
		cout << "error iterator pointing to bad element" << endl;

	
		BST<int>::iterator itemfind3 = root1->find(90.116246246246262462462626);

		cout << *itemfind3 << endl;

	BST<int>::iterator itemfind9 = root1->find(0);

  root1->insert(0);
	BST<int>::iterator itemfind4 = root1->find(0);

		cout << *itemfind4 << endl;


	if(root1->size())
		cout << "Passed : not empty" << endl;
	else
		cout << " ERROR: With size method" << endl;

	
	BST<int> * root123 = new BST<int>();

	if(root123->size() == 0)
		cout << "Passed: empty!" << endl;
	else
		cout << "Error: with size returning false" << endl;

	if(root123->empty())
		cout << "Passed: empty method" << endl;

	   
	cout << "inserting an element that already is in tree" << endl;
	
	if(root1->insert(90) == false)
		cout << " Passed: returned false when trying to insert same element" << endl;

	
	BST<int>::iterator itemfind55 = root1->end();


	if (itemfind55==0)
		cout<< "We have got the end of the tree" << endl;

	else
		cout<< "Error! we didnt get it :(" << endl; 













	return 0; 
}

