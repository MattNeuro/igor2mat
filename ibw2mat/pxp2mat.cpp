// pxp2mat.cpp : Convert pxp files to matlab files.
//
#include "stdafx.h"




int pxp2mat ()
{
	char *		files[1024];
	char *		target;
	int			i, nfiles;
	MATFILE *	mf;
	size_t		length; 

	printf("\t\t[Converting PXP files]\r\n\r\n");
	getFileList( files, & nfiles, "pxp");

	for (i = 0; i < nfiles; i++) 
	{
		// Determine string length and allocate enough memory to accommodate it.
		length				= strlen(files[i]);
		target				= (char *) malloc(length * sizeof(char) + 1);
		memset(target, '\0', length);

		// Change the extension of the target file-name.
		target				= strcpy(target, files[i]);
		target[length - 1]	= 't';
		target[length - 2]	= 'a';
		target[length - 3]	= 'm';

		// Create the matlab file (with new extension):
		current_mat_file	= getMatFile(target);

		// Copy waves in PXP file to the matlab file.
		//loadIntoMatfile(files[i], mf);
		ReadPackedFile(files[i]);

		// Free up memory again.
		//free(target);
		free(files[i]);
	}

	//if (matfile_close(mf))
	//	printf("Error closing matfile.");
	//
	return 0;
}