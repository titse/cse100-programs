/**
* Authors: Tiffany Tse A10296316 username: titse,
* Author: Martin Vanek  A09383174 username: mvanek 
* FileName: HCNode.cpp
* Date Nov 2,2013
* Final Rev-Date: Nov 10 2013
* Description: Implementation of HCNode.hpp see HCNode for full description 
* the function is to override the < operator 
*/
#include "HCNode.hpp"

bool HCNode:: operator<(const HCNode& other){
  // if counts are different, just compare counts
  // counts are equal. use symbol value to break tie.
  if(count != other.count) 
  {
	return count > other.count;
  }
  // (for this to work, internal HCNodes 
  // must have symb set.) important to gernterate the same  tree 
  return symbol < other.symbol;
}
/**method to compare one node and another*/
bool comp(HCNode* one, HCNode* other)
{
  return (one->count) < (other->count);
}
