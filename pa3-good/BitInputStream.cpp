/**
*Authors: Tiffany Tse A10296316 username: titse,
*Author: Martin Vanek  A09383174 username: mvanek
* FileName: BitInputStream.cpp
* Date May 10,2013
* Final Rev-Date: Nov 15, 2013
* Description: Implementation of BitInputStream.hpp, see BitInputStream.hpp
* This file will read all the bits. 
*/

#include "BitInputStream.hpp"

/**Fill the buffer from the input*/
void BitInputStream::fill(){

	buf=in.get();
	nbits=0;
}

/** Read the next bit from the bit buffer.
* Fill the buffer from the input stream first if needed.
* Return 1 if the bit read is 1.
* Return 0 if the bit read is 0.
*/

int BitInputStream::readBit()
{
	if (nbits==8)
	{
		//If all bit in the buffer are read, fill the buffer first
		fill();

	}

		//get the bit at the appriopriate location in the bit 
		//buffer, and return the appropriate int 
		          int bit=1 & (buf>>(7-nbits)); //takes care
                  // of edge case where we didnt fill up buffer at beginning
//printf("Input---What is bit: %d \t What is buffer: %d \n",bit, bitbuff);

		//Increment the index
		nbits++;

		return bit; 

		
}

