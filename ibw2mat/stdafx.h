// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>


// TODO: reference additional headers your program requires here
#include "getFiles.h"
#include "Variables.h"
#include "IgorBin.h"
#include "CrossPlatformFileIO.h"
#include "IgorSupport.h"
#include "ReadWave.h"

#include "matfiles.h"
#include "PackedFile.h"
#include "igor2mat.h"

MATFILE *	current_mat_file;