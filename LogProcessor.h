/*****************************************************************************
 * $Workfile: LogProcessor.h $
 * $Revision: 2 $
 * $Modtime: 11/01/01 6:42p $
 * $Author: Lw $
 ******************************************************************************
 *
 *	COPYRIGHT (C) 2001 CMG NEDERLAND B.V. - ALL RIGHTS RESERVED
 *
 ******************************************************************************/

#ifndef LOGPROCESSOR_H
#define LOGPROCESSOR_H

// Includes
#include <map>
#include <string>
#include <vector>

using namespace std;

#include "DateTime.h"

// Forward declarations
class LogParser;
class LogStructure;
class LogTag;
class ReportList;

////////////////////////////////////////////////////////////////////////////////
// class LogProcessor
class LogProcessor
{
// Constants

// Construction and destruction
public:
	///////////////////////////////////////////////////////////////////////////////
	// constructor of LogProcessor
	///////////////////////////////////////////////////////////////////////////////		
	LogProcessor();

	LogProcessor(LogProcessor&);
	LogProcessor& operator=(LogProcessor&);
	///////////////////////////////////////////////////////////////////////////////
	// destructor of LogProcessor
	///////////////////////////////////////////////////////////////////////////////		
	~LogProcessor();

private:
	LogProcessor( const LogProcessor& src ){};	// Copy constructor

// Public interface
public:
	///////////////////////////////////////////////////////////////////////////////
	// function		:	StartProcessing()
	//
	// description	:	This function starts processing the specified log file,
	//					building the tree of LogStructures. The starting point of
	//					this tree is returned, the LogStructure of the main
	//					cluster.
	//				
	// parameters	:	strLog			log file to process
	//					pReportList		pointer to ReportList object
	//
	// returns		:	pointer to LogStructure of main cluster
	///////////////////////////////////////////////////////////////////////////////	
	LogStructure* StartProcessing( const string& strLog, ReportList* pReportList );

	///////////////////////////////////////////////////////////////////////////////
	// function		:	GetReports()
	//
	// description	:	This function returns the map of report files to create;
	//					with each report, its LogStructure that starts the report,
	//					is associated.
	//				
	// parameters	:	-
	//
	// returns		:	map of report files with their LogStructures
	///////////////////////////////////////////////////////////////////////////////	
	map<string, LogStructure*> GetReports() const;

// Implementation
private:
	///////////////////////////////////////////////////////////////////////////////
	// function		:	FillActionMap()
	//
	// description	:	This function maps LogTag keyword IDs onto LogProcessor
	//					member functions.
	//				
	// parameters	:	-
	//
	// returns		:	-
	///////////////////////////////////////////////////////////////////////////////	
	void FillActionMap();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	ProcessLine()
	//
	// description	:	This function determines the keyword of the current log
	//					line, and calls the corresponding member function.
	//				
	// parameters	:	-
	//
	// returns		:	-
	///////////////////////////////////////////////////////////////////////////////	
	void ProcessLine();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	SetLastTime()
	//
	// description	:	This function sets the last recorded time to be the time
	//					of the current log line.
	//				
	// parameters	:	-
	//
	// returns		:	-
	///////////////////////////////////////////////////////////////////////////////	
	void SetLastTime();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	SetStart()
	//
	// description	:	This function sets the starting time of the specified
	//					LogStructure to be the last recorded time.
	//				
	// parameters	:	pLogStruct		LogStructure for which to set start time
	//
	// returns		:	-
	///////////////////////////////////////////////////////////////////////////////	
	void SetStart( LogStructure* pLogStruct );

	///////////////////////////////////////////////////////////////////////////////
	// function		:	SetEnd()
	//
	// description	:	This function sets the end time of the specified
	//					LogStructure to be the last recorded time.
	//
	// parameters	:	pLogStruct		LogStructure for which to set end time
	//
	// returns		:	-
	///////////////////////////////////////////////////////////////////////////////	
	void SetEnd( LogStructure* pLogStruct );

	///////////////////////////////////////////////////////////////////////////////
	// function		:	LastStruct()
	//
	// description	:	This function returns the pointer to the last opened
	//					LogStructure; if none is opened, the null pointer is
	//					returned.
	//
	// parameters	:	-
	//
	// returns		:	pointer to last opened LogStructure
	///////////////////////////////////////////////////////////////////////////////	
	LogStructure* LastStruct() const;

	///////////////////////////////////////////////////////////////////////////////
	// function		:	AnyOpen()
	//
	// description	:	This function determines if there are any LogStructures
	//					open.
	//
	// parameters	:	-
	//
	// returns		:	true	one or more LogStructures open
	//					false	no LogStructures open
	///////////////////////////////////////////////////////////////////////////////	
	bool AnyOpen() const;

	///////////////////////////////////////////////////////////////////////////////
	// function		:	RemoveLastStruct()
	//
	// description	:	This function removes the last LogStructure from the vector
	//					of open ones.
	//
	// parameters	:	-
	//
	// returns		:	-
	///////////////////////////////////////////////////////////////////////////////	
	void RemoveLastStruct();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	HandleEndProcessing()
	//
	// description	:	This function handles the end of processing the log file,
	//					closing all (incomplete) LogStructures still open.
	//
	// parameters	:	-
	//
	// returns		:	-
	///////////////////////////////////////////////////////////////////////////////	
	void HandleEndProcessing();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	DetermineReport()
	//
	// description	:	This function determines if the specified report name is
	//					unique; if so, it is returned; if not, the charecter '#'
	//					is added to its name (before the extension).
	//
	// parameters	:	strReport	report to determine uniqueness of
	//
	// returns		:	name of report to use
	///////////////////////////////////////////////////////////////////////////////	
	string DetermineReport( const string& strReport );

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Clear()
	//
	// description	:	This function sets member variables to their default
	//					values.
	//
	// parameters	:	-
	//
	// returns		:	-
	///////////////////////////////////////////////////////////////////////////////	
	void Clear();

	// Action-map functions

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_Default()
	//
	// description	:	This action-map handles all log-keywords which do not have
	//					their own functions.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_Default();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_ActionWord()
	//
	// description	:	This action-map handles the log-keyword ACTIONWORD.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_ActionWord();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_Check()
	//
	// description	:	This action-map handles the log-keyword CHECK.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_Check();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_ClusterBegin()
	//
	// description	:	This action-map handles the log-keyword CLUSTER_BEGIN.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_ClusterBegin();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_ClusterEnd()
	//
	// description	:	This action-map handles the log-keyword CLUSTER_END.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_ClusterEnd();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_ClusterError()
	//
	// description	:	This action-map handles the log-keyword CLUSTER_ERROR.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_ClusterError();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_ClusterLine()
	//
	// description	:	This action-map handles the log-keyword CLUSTER_LINE.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_ClusterLine();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_Error()
	//
	// description	:	This action-map handles the log-keyword REPORT_ERROR.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_Error();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_HeaderAuthor()
	//
	// description	:	This action-map handles the log-keyword HEADER_AUTHOR.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_HeaderAuthor();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_HeaderCluster()
	//
	// description	:	This action-map handles the log-keyword HEADER_CLUSTER.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_HeaderCluster();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_HeaderDate()
	//
	// description	:	This action-map handles the log-keyword HEADER_DATE.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_HeaderDate();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_HeaderDocument()
	//
	// description	:	This action-map handles the log-keyword HEADER_DOCUMENT.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_HeaderDocument();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_HeaderSheet()
	//
	// description	:	This action-map handles the log-keyword HEADER_SHEET.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_HeaderSheet();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_HeaderVersion()
	//
	// description	:	This action-map handles the log-keyword HEADER_VERSION.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_HeaderVersion();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_HeaderWord()
	//
	// description	:	This action-map handles the log-keyword HEADERWORD.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_HeaderWord();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_NonTestLine()
	//
	// description	:	This action-map handles the log-keyword that specify non-
	//					test lines: COMMMENT_LINE and EMPTY_LINE.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_NonTestLine();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_InternalError()
	//
	// description	:	This action-map handles the log-keyword INTERNAL_ERROR.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_InternalError();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_StructureBegin()
	//
	// description	:	This action-map handles the log-keyword STRUCTURE_BEGIN.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_StructureBegin();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_StructureEnd()
	//
	// description	:	This action-map handles the log-keyword STRUCTURE_END.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_StructureEnd();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_TemplateBegin()
	//
	// description	:	This action-map handles the log-keyword TEMPLATE_BEGIN.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_TemplateBegin();

	///////////////////////////////////////////////////////////////////////////////
	// function		:	Action_TemplateEnd()
	//
	// description	:	This action-map handles the log-keyword TEMPLATE_END.
	///////////////////////////////////////////////////////////////////////////////	
	void Action_TemplateEnd();

// Member variables
private:
	typedef void (LogProcessor::*ActionFunction) ();
	typedef map<int, ActionFunction> ActionMap;
	ActionMap m_mAction;					// Map linking log-keywords to member functions
	
	LogParser* m_pLogParser;				// Pointer to the LogParser object
	LogTag* m_pLogTag;						// Pointer to the LogTag object
	ReportList* m_pReportList;				// Pointer to the ReportList object

	LogStructure* m_pMainCluster;			// Pointer to LogStructure of main cluster
	vector<LogStructure*> m_vpLogStructures;// Vector of currently open LogStructures
	map<string, LogStructure*> m_mReports;	// Map of report files and their starting LogStructures

	DateTime m_dtLast;						// Last recorded date/time
};

////////////////////////////////////////////////////////////////////////////////

#endif // !LOGPROCESSOR_H
