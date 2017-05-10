// ibw2mat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// Externals.
extern int			ibw2mat			();
extern int			pxp2mat			();


int _tmain(int argc, _TCHAR* argv[]) 
{
	printf("\t\t[Starting Igor to MAT conversion]\r\n\r\n");
	
	ibw2mat();
	pxp2mat();

	printf("Ending.");
	return 0;
}
