/**
*Authors: Tiffany Tse A10296316 username: titse,
*Author: Martin Vanek  A09383174 username: mvanek
* FileName: uncompress.cpp
* Date May 2,2014
* Final Rev-Date: May 15 2014
* Description: Compressing a file makes it smaller but we must 
* account for the uncompression that allows one to read the file 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "HCTree.hpp"

using namespace std;



int main ( int argc, char* argv[])
{
	


	/*********checks cmd line arguments *******/

	if (argc !=3)
	{
	  printf("Wrong arguments called!\n");
		printf("Usage: uncompress [infile] [outfile]\n");
		return 1; 
	}

	/******declare variables *****/
	int symbol=0;
	int filesize=0;
	int compress_size=0;
	double ratio=0.0;

	/********* Read header in input files**************/
	printf ("Reading header from file \%s\"....\n", argv[1]);

	vector<int> freqs(256);
	ifstream openfile(argv[1],ios::binary);
	bool empty=true;
	int num = 0;
	byte filein;

	if(openfile.is_open() && openfile.good())
	{
		for (int i=0; i<freqs.size(); i++)
		{
			openfile >> num;
			freqs[i]= num;
			filesize = filesize + num; 
		}
        /*Get rid of space after that symbol in freq*/	
        openfile.get();
        
	}
	printf ("Reading complete..... next stage \n");

	/***********Report file information*********/
	for (int i=0; i<freqs.size(); i++)
	{
		if(freqs.at(i)!=0)
		{
			symbol++; 
			empty = false;
		}   
	}

	printf("Uncompress file will have %d unique symbols and %d bytes\n", symbol, filesize);
/*********Build huffman tree ******/	
    printf("Building Huffman Tree\n");

  HCTree hufftree;

    if(!empty)
    {
       hufftree.build(freqs);
    }
   
	printf("Done building huffman tree  on to the final next stage.......\n");


	/********Write decoded data into a file *********/
	printf("Writing to file \%s\"....\n", argv[2]);

	ofstream out; 
	out.open(argv[2],ios::binary);
        BitInputStream decfile =BitInputStream(openfile); 
	if(!empty)
	{
		for(int j=0; j<filesize; j++)
		{
			//out << (byte)hufftree.decode(openfile); 
			
			out<<(byte)hufftree.decode(decfile);
			out.flush();
		}

	}
	printf("Complete! Finished with all the tasks!\n");
	
	out.close();
	openfile.close();

	/******Reporting old file information******/
	openfile.clear();
	openfile.open(argv[1], ios::binary);
	while(openfile.is_open())
	{
		filein = openfile.get();

		if (!openfile.good())
		{
			break;
		}
        compress_size++;
	}
	if (!openfile.eof())
	{
		cerr<<"Sorry there was a problem opening the file\n"<<endl;
		return-1;
	}

	openfile.close();
	if(compress_size !=0)
	{
		ratio= double(filesize)/double(compress_size);

	}
    printf ("Compress size: \%d \n", compress_size);
	printf ("Uncompression ratio: %g\n" , ratio );
	return 0;
}
