// MathcadRemmbr.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <malloc.h>
#include "MathcadRemmbr.h"

#define CheckRecall(h) if (h>recalls.size) return MAKELRESULT(INVALID_HANDLE,1)

struct Complex
{
	double im;
	double re;
};

struct Recall
{
	Complex* data;
	unsigned int datasize;
};

Recall init_recall( )
{
	Recall ret = 
	{
		0, 0
	};
	return ret;
}

void kill_recall(Recall r)
{

}

typedef struct
{
	Recall* array;
	unsigned int capacity;
	unsigned int size;
} Recalls;

Recalls recalls;

void init_remmbr()
{
	recalls.capacity = 4;
	recalls.size = 0;
	recalls.array = (Recall*)malloc(sizeof(Recall)*recalls.capacity);
}

void close_remmbr()
{
	for (int i = 0; i < recalls.size; i++)
	{
		kill_recall(recalls.array[i]);
	}
	free(recalls.array);
}

void expand()
{
	Recall* tarray = (Recall*)malloc(sizeof(Recall)*recalls.capacity);
	memcpy(tarray,recalls.array,sizeof(Recall)*recalls.capacity);
	recalls.capacity *= 2;
	recalls.array = (Recall*)malloc(sizeof(Recall)*recalls.capacity);
	memcpy(recalls.array,tarray,sizeof(Recall)*recalls.capacity/2);
}

LRESULT CreateRecall( COMPLEXSCALAR* const RecallHandle,
					 const COMPLEXSCALAR* const Size )
{
	if ( recalls.size > recalls.capacity )
		expand();
	recalls.array[recalls.size] = init_recall();
	RecallHandle->real = recalls.size;
	recalls.size++;
	return 0;
}

LRESULT ForgetRecall( COMPLEXSCALAR* const DummyResult, 
					 const COMPLEXSCALAR* const RecallHandle )
{
	// not needed right now
	return 0;
}

LRESULT CloneRecall( COMPLEXSCALAR* const RecallHandle,
					const COMPLEXSCALAR* const RecallSource )
{
	CheckRecall(RecallHandle->real);
	if ( recalls.size > recalls.capacity )
		expand();
	recalls.array[recalls.size] = init_recall();
	recalls.array[recalls.size].datasize = 0;
	RecallHandle->real = recalls.size;
	recalls.size++;
	return 0;
}

LRESULT Remember( COMPLEXSCALAR* const DummyResult, 
				 const COMPLEXSCALAR* const RecallHandle, 
				 const COMPLEXARRAY* const Data )
{
	CheckRecall(RecallHandle->real);

	return 0;
}

LRESULT GetRecall( COMPLEXARRAY* const Data,
				  const COMPLEXSCALAR* const RecallHandle )
{
	CheckRecall(RecallHandle->real);
	return 0;
}

LRESULT ForgetAll( COMPLEXSCALAR* const DummyResult,
				  const COMPLEXSCALAR* const DummyParam)
{
	// not needed right now
	return 0;
}