/**
*Authors: Tiffany Tse A10296316 username: titse,
*Author: Martin Vanek  A09383174 username: mvanek
* FileName: BitOutputStream.cpp
* Date May 15,2013
* Final Rev-Date: Nov 15, 2013
* Description: Implementation of BitOutputStream.hpp, see BitOutputStream.hpp 
*/
#include "BitOutputStream.hpp"

/**Send the buffer to the output and clear it*/
void BitOutputStream::flush()
{
	out.put(buf); 
    out.flush();
    buf = nbits = 0;
}


/** Write the least significant bit of the argument to
the bit buffer, and increment the bit buffer index.
But flush the buffer first, if it is full.
*/
void BitOutputStream::writeBit(int i)
{
	//is the buffer full? then flush it
	if (nbits==8)
	{
		flush();

	}
	//Write the least significant bit of i into the buffer
	//at the current index

   	buf = buf | (i<<7-nbits);
   //  printf("Output--- What is bit: %d \t What is buffer: %d\n",i, buf);

	//increment the index
	nbits++;
}
