// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "MathcadRemmbr.h"

// table of error messages
char* ErrorMessageTable[NUMBER_OF_ERRORS] = 
{
	"Function is interrupted",
	"Insufficient memory for this allocation",
	"The handle passed is not a handle or memory is already freed"
};

#pragma region FunctionInfo structures

FUNCTIONINFO createRecall =
{
	"CreateRecall",
	"size",
	"Creates a new recall in memory and returns its handle",
	(LPCFUNCTION)CreateRecall,
	COMPLEX_SCALAR,
	1,
	{
		COMPLEX_SCALAR
	}
};

FUNCTIONINFO forgetRecall = 
{
	"ForgetRecall",
	"recall",
	"Forgets a recall given by a handle",
	(LPCFUNCTION)ForgetRecall,
	COMPLEX_SCALAR,
	1,
	{
		COMPLEX_SCALAR
	}
};

FUNCTIONINFO cloneRecall = 
{
	"CloneRecall",
	"recall",
	"Clone a recall for some need",
	(LPCFUNCTION)CloneRecall,
	COMPLEX_SCALAR,
	1,
	{
		COMPLEX_SCALAR
	}
};

FUNCTIONINFO remember =
{
	"Remember",
	"recall,data",
	"Remembers data as some recall",
	(LPCFUNCTION)Remember,
	COMPLEX_SCALAR,
	2,
	{
		COMPLEX_SCALAR, COMPLEX_ARRAY
	}
};

FUNCTIONINFO getRecall =
{
	"GetRecall",
	"recall",
	"Remembers data as some recall",
	(LPCFUNCTION)GetRecall,
	COMPLEX_ARRAY,
	1,
	{
		COMPLEX_SCALAR
	}
};

FUNCTIONINFO forgetAll =
{
	"ForgetAll",
	"dummy",
	"Forgets everything, clears memory",
	(LPCFUNCTION)ForgetAll,
	COMPLEX_SCALAR,
	1,
	{
		COMPLEX_SCALAR
	}
};

#pragma endregion

BOOL APIENTRY DllMain( HMODULE hModule,
					   DWORD  ul_reason_for_call,
					   LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		if ( CreateUserErrorMessageTable(
			hModule, NUMBER_OF_ERRORS, ErrorMessageTable ) )
		{
			CreateUserFunction( hModule, &createRecall );
			CreateUserFunction( hModule, &forgetRecall );
			CreateUserFunction( hModule, &cloneRecall );
			CreateUserFunction( hModule, &remember );
			CreateUserFunction( hModule, &getRecall );
			CreateUserFunction( hModule, &forgetAll );
			init_remmbr();
		}
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

