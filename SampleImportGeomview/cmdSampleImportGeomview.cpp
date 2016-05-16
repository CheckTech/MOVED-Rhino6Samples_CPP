// cmdSampleImportGeomview.cpp : command file
//

#include "StdAfx.h"
#include "SampleImportGeomviewPlugIn.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN SampleImportGeomview command
//

#pragma region SampleImportGeomview command

// Do NOT put the definition of class CCommandSampleImportGeomview in a header
// file.  There is only ONE instance of a CCommandSampleImportGeomview class
// and that instance is the static theSampleImportGeomviewCommand that appears
// immediately below the class definition.

class CCommandSampleImportGeomview : public CRhinoCommand
{
public:
  // The one and only instance of CCommandSampleImportGeomview is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandSampleImportGeomview::CCommandSampleImportGeomview()
  // is called exactly once when static theSampleImportGeomviewCommand is created.
	CCommandSampleImportGeomview() {}

  // CCommandSampleImportGeomview::~CCommandSampleImportGeomview()
  // is called exactly once when static theSampleImportGeomviewCommand is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CCommandSampleImportGeomview() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
		// {5C73D7E9-570D-4529-8715-D5058B1058C2}
    static const GUID SampleImportGeomviewCommand_UUID =
    { 0x5C73D7E9, 0x570D, 0x4529, { 0x87, 0x15, 0xD5, 0x5, 0x8B, 0x10, 0x58, 0xC2 } };
    return SampleImportGeomviewCommand_UUID;
	}

  // Returns the English command name.
	const wchar_t* EnglishCommandName() { return L"SampleImportGeomview"; }

  // Returns the localized command name.
	const wchar_t* LocalCommandName() const { return L"SampleImportGeomview"; }

  // Rhino calls RunCommand to run the command.
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandSampleImportGeomview object
// Do NOT create any other instance of a CCommandSampleImportGeomview class.
static class CCommandSampleImportGeomview theSampleImportGeomviewCommand;

CRhinoCommand::result CCommandSampleImportGeomview::RunCommand( const CRhinoCommandContext& context )
{
  // CCommandSampleImportGeomview::RunCommand() is called when the user
  // runs the "SampleImportGeomview".

  // TODO: Add command code here.

  // Rhino command that display a dialog box interface should also support
  // a command-line, or scriptable interface.

  ON_wString str;
  str.Format( L"The \"%s\" command is under construction.\n", EnglishCommandName() );
  if( context.IsInteractive() )
    RhinoMessageBox( str, SampleImportGeomviewPlugIn().PlugInName(), MB_OK );
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
// END SampleImportGeomview command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
