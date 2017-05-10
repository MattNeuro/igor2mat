// ibw2mat.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

// Externals.
extern int			loadIntoMatfile	(const char* filePath, MATFILE *mf);

int ibw2mat ()
{
	char * files[20000];
	int nfiles;
	int i;
	MATFILE * mf;

	printf("\t\t[Converting IBW files]\r\n\r\n");
	getFileList( files, & nfiles, "ibw");

	mf = getDefaultMatFile();

	for (i = 0; i < nfiles; i++) 
	{
		loadIntoMatfile(files[i], mf);
		free(files[i]);
	}

	if (matfile_close(mf))
		printf("Error closing matfile.");
	
	return 0;
}

