/**
* Authors: Tiffany Tse A10296316 username: titse,
* Author: Martin Vanek  A09383174 username: mvanek
* FileName: BitOutputStream.cpp
* Date May 10,2014
* Final Rev-Date: May 15, 2014
* Description: Bit Output Stream holds the buffer destined for ouput until
* there are enough of the them to send to the destination; then they are sent
* in one large chunk. This class is doing bitwise output that delegates an 
* object to an existing class. 
* GOAL: PERFORM BITWISE FUNCTIONS
*/

#ifndef BITOUTPUTSTREAM_HPP
#define BITOUTPUTSTREAM_HPP

#include <iostream>
#include <bitset>

class BitOutputStream {
	
private:
	char buf; //one byte buffer of bits 
	int nbits; //how many bits have been written to buf
	std::ostream & out; //reference to putput stream to use

public:
	/**
	* Initialize a BitOutStream that will use the given ostream for output
	*
	*/
	BitOutputStream(std::ostream & os) : out(os) {
		//clear buffer and bit counter
		buf=0;
		nbits=0;
	}
	/**Send the buffer to the output and clear it*/

	void flush();

	/** Write the least significant bit of the argument to
	the bit buffer, and increment the bit buffer index.
	But flush the buffer first, if it is full.
	*/
	void writeBit(int i);

	//is the bit buffer full, then flush it


	//write the least significant bit of i into the buffer
	//at the current index


	//increment the index



};


#endif //BITOUTPUTSTREAM_HPP

