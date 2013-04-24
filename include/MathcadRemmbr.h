#include "MCADINCL.H"

#ifdef MATHCADREMMBR_EXPORTS
#define MATHCADREMMBR_API __declspec(dllexport)
#else
#define MATHCADREMMBR_API __declspec(dllimport)
#endif

#define  INTERRUPTED            1
#define  INSUFFICIENT_MEMORY    2
#define  INVALID_HANDLE         3
#define  NUMBER_OF_ERRORS       3

#pragma region Function definitions

LRESULT CreateRecall( COMPLEXSCALAR* const RecallHandle,
	const COMPLEXSCALAR* const Size );
LRESULT ForgetRecall( COMPLEXSCALAR* const DummyResult, 
	const COMPLEXSCALAR* const RecallHandle );
LRESULT CloneRecall( COMPLEXSCALAR* const RecallHandle,
	const COMPLEXSCALAR* const RecallSource );
LRESULT Remember( COMPLEXSCALAR* const DummyResult, 
	const COMPLEXSCALAR* const RecallHandle, const COMPLEXARRAY* const Data );
LRESULT GetRecall( COMPLEXARRAY* const Data,
	const COMPLEXSCALAR* const RecallHandle );
LRESULT ForgetAll( COMPLEXSCALAR* const DummyResult,
	const COMPLEXSCALAR* const DummyParam);

#pragma endregion

void init_remmbr();

void close_remmbr();