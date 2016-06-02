#if !defined(BPNG_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Tunder $
   $Notice: (C) Copyright 2014 by SpaceCat, Inc. All Rights Reserved. $
   ======================================================================== */

#include <stdint.h>
#include <fstream>

struct bImage
{
    union { void* data; uint8_t* pixels; };
    uint32_t size, width, height;
};

struct bPNGIOPTR
{
    uint8_t* data;
    int size, offset;
};

void bMemImage( bImage* image, void* memory );
bool bMemPNG( bImage* image, void* memory, int size );
bool bReadPNG( const char* filename, bImage* image );
bool bWritePNG( const char* filename, bImage* image );

#define BPNG_H
#endif
