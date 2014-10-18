/**
*Authors: Tiffany Tse A10296316 username: titse,
*Author: Martin Vanek  A09383174 username: mvanek
* FileName: BitInputStream.cpp
* Description: In Huffman, tree transveral is done by transvering to 0 and 1
* which are on the leaves the point to parent's child. This is done by 
* encoding symbols which will be the nodes and contain the frequency managed
* by HCTree. BitInputStream takes encode infile to an outfile by writing
* the code (a sequence of 0s and 1s) for each character sequence. This file reques ifstream to be ios::binary for argument argv[]
*/
#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP

#include <iostream>
#include <bitset>

class BitInputStream {
	
private: 
		std::istream& in; //the istream to delegate to
		char buf; //buffer of bits 
		int nbits; //the bit buffer of ints


public: 

/**
* Initalize a BitInputStream object, when given a istream--
* constructor: int should be 8 because a byte is 8bits 
*/

	 BitInputStream(std::istream& s) : in(s) {
	  buf=0; 
	  nbits=8;
	 
	 }  

	/**Fill the buffer from the input*/
		void fill();


	/** Read the next bit from the bit buffer.
	* Fill the buffer from the input stream first if needed.
	* Return 1 if the bit read is 1.
	* Return 0 if the bit read is 0.
	*/
		int readBit();
		



};


#endif //BITINPUTSTREAM_HPP


