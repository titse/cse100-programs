/**
* *Authors: Tiffany Tse A10296316 username: titse,
* Author: Martin Vanek  A09383174 username: mvanek
* FileName: compress.cpp
* Date May 10,2013
* Final Rev-Date: May 15, 2013
* Description: Compress the file so that it will be smaller
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <ios>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "HCTree.hpp"


using namespace std;

int main (int argc, char* argv[])
{

//wrong input    
    if ( argc!=3)
    {
      printf("./compress called with incorrect arguments.\n");
      printf("Usage: ./compress infile outfile\n");
      return 1;
    }



        //reading inputs
        printf("Reading from file \%s\"...",argv[1]);

        /**
        * varaibles needed for compress 
        *
        */
        vector<int> freqs(256, 0); 
        ifstream in;
        in.open(argv[1], ios::binary); //ios binary for putting binary bits 
        bool empty = true;
        byte filein;
        int filesize=0;
	double ratio = 0.0;
	int compress_size =0;
        int symbol=0;




/***open file information***/
 
    while(in.is_open())
    {
      filein = in.get();//extracts a single character from the stream
        
       if(!in.good()){
             break;
                
       } 

       for(int i=0; i<freqs.size(); i++)
        {
         if(filein == i)
          {
             if(freqs[i] == 0)//new unique symbol
                 symbol++;

             freqs[i]++;//populate the frequencies
             empty = false;//make empty false so we can rebuild tree
          }
         }
       filesize++;
    }


		in.close();
		printf("done.\n");
    


/******************tree building---------------- */
//reconstruct the tree using hctree
  printf("Building Huffman Tree..."); 
  HCTree hufftree;

    if(!empty){

       hufftree.build(freqs);
	}
   

     printf("done.\n");

/************Report file information ---------*/

      
        //print out how many symbols and size
        printf("Found %d unique symbols and size %d bytes \n", symbol, filesize);

	//after checkpoint, use binary since we are writing bits for
    //ifstream and ofstream

       ofstream out(argv[2], ios::binary);
	  
	/**write the header file into compressed file to reconstruct 
	in uncompress *****/
		
		
		printf("Writing header file to ... \%s.....", argv[2] );
		for (int i=0; i<freqs.size(); i++)
		{
			//send file to output file and send freq along with spaces
                 out<<freqs.at(i)<<" ";
                  out.flush(); //checkpoint!
                    
                        
		}
		//flush after sending the file
		    //bitstre.flush();
		 
      
	printf ("done. \n");
      
 

/********encoding the file into new file*****/
  in.clear();
  in.open(argv[1],ios::binary);
  BitOutputStream bitstre = BitOutputStream(out); 	

 if(!empty){
    	    for( int j = 0; j < filesize; j++ )
    		{
      			filein = in.get();
            	//out.flush(); //CHECKPOINT 
     			hufftree.encode(filein, bitstre);
     			 
  		  }
 }
                  
		bitstre.flush(); //note dont put flush inside for loop anymore
		  //because it will give you a werid @@@ :( 
		  printf("done encoding huffman tree....\n");

		  in.close();
		  out.close();

  /********* report new file info **********/

         // in.clear();
	  in.open(argv[2],ios::binary);

	  while(in.is_open())
	  {
		filein = in.get();
    
		if(! in.good() )
		{
		  break;
		}

		compress_size++;
	  }
    //check for problems 
	  if(! in.eof() )
	  {
		cerr << "There was a problem" << endl;
		return -1;
	  }
  
	 printf("Output file has the size of %d bytes.\n",compress_size);
	  in.close();

 

  /*****reporting compression ratio******/
  if( filesize != 0 )
  {
    ratio = (double)compress_size / (double)filesize;
  }

  printf("Compression ratio: %g\n",ratio);
  
  return 0;
}
