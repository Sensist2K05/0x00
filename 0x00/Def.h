#pragma once
#include "0x00.h"

typedef union _COLORPAL32 
{
	COLORREF cp32Colors;
	struct 
	{
		BYTE cp32Blue;
		BYTE cp32Green;
		BYTE cp32Red;
		BYTE Unused;
	};
} COLORPAL32, *LPCOLORPAL32;


BITMAPINFO bmicrt(INT x, INT y) {
	BITMAPINFO bmi = {sizeof(bmi), x, y, 1, 32, BI_RGB};
	return bmi;
} 

typedef LPVOID *DIBSECTIONBITS; 

