// MathcadRemmbr.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MathcadRemmbr.h"


// This is an example of an exported variable
MATHCADREMMBR_API int nMathcadRemmbr=0;

// This is an example of an exported function.
MATHCADREMMBR_API int fnMathcadRemmbr(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see MathcadRemmbr.h for the class definition
CMathcadRemmbr::CMathcadRemmbr()
{
	return;
}
