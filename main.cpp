/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Tunder $
   $Notice: (C) Copyright 2014 by SpaceCat, Inc. All Rights Reserved. $
   ======================================================================== */

#include "bpng.h"

int main( int argc, char *argv[] )
{
    // Write red .png image
    bImage image;
    image.width = image.height = 32;
    image.size = image.width * image.height * 4;
    image.data = malloc( image.size );

    /*uint8_t colors[] = { 255, 0, 0, 255 };
    
    for( int i=0; i<image.size; i++ )
        *(image.pixels+i) = colors[i%4];*/
	
	uint32_t color = 255 << 24 | 255;
	uint32_t* pixel = (uint32_t*)image.data;
	
	for( int i=0; i<image.width*image.height; i++ )
		*pixel++ = color;

    bWritePNG( "./test.png", &image );
    
    free( image.data );

    // Read and copy image
    bImage copy;
    copy.width = image.width;
    copy.height = image.height;
    copy.size = copy.width * copy.height * 4;
    copy.data = malloc( copy.size );

    bReadPNG( "./test.png", &copy );
    bWritePNG( "./copy.png", &copy ); // prove that it works

    free( copy.data );
    
    return 0;
}
