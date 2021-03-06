/*****************************************************************************
 * $Workfile: GreaterEqualOperation.h $
 * $Revision: 1 $
 * $Modtime: 3/16/01 10:41a $
 * $Author: Lw $
 ******************************************************************************
 *
 *	COPYRIGHT (C) 1999-2001 CMG NEDERLAND B.V. - ALL RIGHTS RESERVED
 *
 ******************************************************************************/

#ifndef GREATEREQUALOPERATION_H
#define GREATEREQUALOPERATION_H

// Includes.
#include <string>

using namespace std;

#include "RelationalOperation.h"	// Base-class definition.

// Define base-class.
#undef BASECLASS
#define BASECLASS RelationalOperation

// Class definition.
// Derived from RelationalOperation.
class GreaterEqualOperation : public BASECLASS
{
public:
	////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTION AND DESTRUCTION

	///////////////////////////////////////////////////////////////////////////////
	// default constructor of GreaterEqualOperation
	///////////////////////////////////////////////////////////////////////////////
	GreaterEqualOperation();

	///////////////////////////////////////////////////////////////////////////////
	// destructor of GreaterEqualOperation
	///////////////////////////////////////////////////////////////////////////////
	~GreaterEqualOperation();

	////////////////////////////////////////////////////////////////////////////
	// PUBLIC INTERFACE

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Evaluate()
	//
	// description	:	This function evaluates a 'greater than or equal to'-
	//					operation. If both values can be interpreted as numbers,
	//					true is returned if	the numerical value of the left operand
	//					is greater than or equal to that of the right one; if they
	//					can only be interpreted as strings, true is returned if the
	//					string value of the left operand comes alphabetically after
	//					or is identical to that of the right one.
	//
	// parameters	:	strLeft		value of left operand
	//					strRight	value of right operand
	//
	// returns		:	true	'greater than or equal to' is true
	//					false	'greater than or equal to' is false
	///////////////////////////////////////////////////////////////////////////////
	bool Evaluate( const string& strLeft, const string& strRight );
};

#undef BASECLASS
#endif // !GREATEREQUALOPERATION_H
