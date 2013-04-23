// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MATHCADREMMBR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MATHCADREMMBR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MATHCADREMMBR_EXPORTS
#define MATHCADREMMBR_API __declspec(dllexport)
#else
#define MATHCADREMMBR_API __declspec(dllimport)
#endif

// This class is exported from the MathcadRemmbr.dll
class MATHCADREMMBR_API CMathcadRemmbr {
public:
	CMathcadRemmbr(void);
	// TODO: add your methods here.
};

extern MATHCADREMMBR_API int nMathcadRemmbr;

MATHCADREMMBR_API int fnMathcadRemmbr(void);
