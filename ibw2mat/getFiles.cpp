#include "getFiles.h"


int			getFileList			(char ** files, int * nfiles, char * extension);
MATFILE *	getMatFile			(char * name);
MATFILE *	getDefaultMatFile	();

/**
 *	Obtain a list of all files in the current directory.
 *
 *	Then, filter this list on IBW files.
**/
int getFileList (char ** files, int * nfiles, char * extension) 
{
	DIR				* dir;
	struct dirent	* ent;
	char			  match[4];
	int				  index = 0; 
	match[3]				= '\0';		// C-string; zero-terminate for strcmp.

	printf("\t[Obtaining file list]\r\n");

	if ((dir = opendir (".")) == NULL) 
		return EXIT_FAILURE;

	/* print all the files and directories within directory */
	while ((ent = readdir (dir)) != NULL) 
	{
		match[0] = ent -> d_name[ent -> d_namlen - 3];
		match[1] = ent -> d_name[ent -> d_namlen - 2];
		match[2] = ent -> d_name[ent -> d_namlen - 1];

		if (strcmp(match, extension) != 0)
			continue;

		files[index] = (char *) malloc(ent -> d_namlen * sizeof(char) + 1);
		printf ("%s \t %s\n", ent->d_name, match);
		strcpy(files[index++], ent -> d_name);
	}
	closedir (dir);
	* nfiles = index;

	printf("\r\nRead %d files.\r\n\r\n", * nfiles);

    return 0;
}


/**
 *	Open a matlab file for writing
**/
MATFILE * 
	getDefaultMatFile () 
{
	char * name = "wavedata.mat";
	return getMatFile(name);
}

MATFILE * 
	getMatFile (char * name) 
{
	MATFILE *mf;
	int error;

	printf("Opening MAT file '%s' for writing.\r\n", name);
	mf = openmatfile(name, & error);
	if (!mf) {
		printf("Error %d occurred while opening the file.\n", error);
		return NULL;
	}
	return mf;
}
