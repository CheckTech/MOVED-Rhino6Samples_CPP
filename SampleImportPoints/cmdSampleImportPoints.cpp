// cmdSampleImportPoints.cpp : command file
//

#include "StdAfx.h"
#include "SampleImportPointsPlugIn.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN SampleImportPoints command
//

#pragma region SampleImportPoints command

// Do NOT put the definition of class CCommandSampleImportPoints in a header
// file.  There is only ONE instance of a CCommandSampleImportPoints class
// and that instance is the static theSampleImportPointsCommand that appears
// immediately below the class definition.

class CCommandSampleImportPoints : public CRhinoCommand
{
public:
  // The one and only instance of CCommandSampleImportPoints is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandSampleImportPoints::CCommandSampleImportPoints()
  // is called exactly once when static theSampleImportPointsCommand is created.
	CCommandSampleImportPoints() {}

  // CCommandSampleImportPoints::~CCommandSampleImportPoints()
  // is called exactly once when static theSampleImportPointsCommand is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CCommandSampleImportPoints() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
		// {AEFCA5A8-548C-470D-9AD5-1F2C7993237E}
    static const GUID SampleImportPointsCommand_UUID =
    { 0xAEFCA5A8, 0x548C, 0x470D, { 0x9A, 0xD5, 0x1F, 0x2C, 0x79, 0x93, 0x23, 0x7E } };
    return SampleImportPointsCommand_UUID;
	}

  // Returns the English command name.
	const wchar_t* EnglishCommandName() { return L"SampleImportPoints"; }

  // Returns the localized command name.
	const wchar_t* LocalCommandName() const { return L"SampleImportPoints"; }

  // Rhino calls RunCommand to run the command.
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandSampleImportPoints object
// Do NOT create any other instance of a CCommandSampleImportPoints class.
static class CCommandSampleImportPoints theSampleImportPointsCommand;

CRhinoCommand::result CCommandSampleImportPoints::RunCommand( const CRhinoCommandContext& context )
{
  // CCommandSampleImportPoints::RunCommand() is called when the user
  // runs the "SampleImportPoints".

  // TODO: Add command code here.

  // Rhino command that display a dialog box interface should also support
  // a command-line, or scriptable interface.

  ON_wString str;
  str.Format( L"The \"%s\" command is under construction.\n", EnglishCommandName() );
  if( context.IsInteractive() )
    RhinoMessageBox( str, SampleImportPointsPlugIn().PlugInName(), MB_OK );
  else
	  RhinoApp().Print( str );

  // TODO: Return one of the following values:
  //   CRhinoCommand::success:  The command worked.
  //   CRhinoCommand::failure:  The command failed because of invalid input, inability
  //                            to compute the desired result, or some other reason
  //                            computation reason.
  //   CRhinoCommand::cancel:   The user interactively canceled the command 
  //                            (by pressing ESCAPE, clicking a CANCEL button, etc.)
  //                            in a Get operation, dialog, time consuming computation, etc.
  return CRhinoCommand::success;
}

#pragma endregion

//
// END SampleImportPoints command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
