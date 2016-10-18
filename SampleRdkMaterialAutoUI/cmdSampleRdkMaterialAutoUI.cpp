// cmdSampleRdkMaterialAutoUI.cpp : command file
//

#include "StdAfx.h"
#include "SampleRdkMaterialAutoUIPlugIn.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN SampleRdkMaterialAutoUI command
//

#pragma region SampleRdkMaterialAutoUI command

// Do NOT put the definition of class CCommandSampleRdkMaterialAutoUI in a header
// file.  There is only ONE instance of a CCommandSampleRdkMaterialAutoUI class
// and that instance is the static theSampleRdkMaterialAutoUICommand that appears
// immediately below the class definition.

class CCommandSampleRdkMaterialAutoUI : public CRhinoCommand
{
public:
  // The one and only instance of CCommandSampleRdkMaterialAutoUI is created below.
  // No copy constructor or operator= is required.  Values of
  // member variables persist for the duration of the application.

  // CCommandSampleRdkMaterialAutoUI::CCommandSampleRdkMaterialAutoUI()
  // is called exactly once when static theSampleRdkMaterialAutoUICommand is created.
	CCommandSampleRdkMaterialAutoUI() {}

  // CCommandSampleRdkMaterialAutoUI::~CCommandSampleRdkMaterialAutoUI()
  // is called exactly once when static theSampleRdkMaterialAutoUICommand is
  // destroyed.  The destructor should not make any calls to
  // the Rhino SDK.  If your command has persistent settings,
  // then override CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CCommandSampleRdkMaterialAutoUI() {}

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work.  Use GUIDGEN.EXE to make unique UUID.
	UUID CommandUUID()
	{
		// {D9C87E8A-AB48-4D47-9051-1C7ADD13DF61}
    static const GUID SampleRdkMaterialAutoUICommand_UUID =
    { 0xD9C87E8A, 0xAB48, 0x4D47, { 0x90, 0x51, 0x1C, 0x7A, 0xDD, 0x13, 0xDF, 0x61 } };
    return SampleRdkMaterialAutoUICommand_UUID;
	}

  // Returns the English command name.
	const wchar_t* EnglishCommandName() { return L"SampleRdkMaterialAutoUI"; }

  // Returns the localized command name.
	const wchar_t* LocalCommandName() const { return L"SampleRdkMaterialAutoUI"; }

  // Rhino calls RunCommand to run the command.
	CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandSampleRdkMaterialAutoUI object
// Do NOT create any other instance of a CCommandSampleRdkMaterialAutoUI class.
static class CCommandSampleRdkMaterialAutoUI theSampleRdkMaterialAutoUICommand;

CRhinoCommand::result CCommandSampleRdkMaterialAutoUI::RunCommand( const CRhinoCommandContext& context )
{
  // CCommandSampleRdkMaterialAutoUI::RunCommand() is called when the user
  // runs the "SampleRdkMaterialAutoUI".

  // TODO: Add command code here.

  // Rhino command that display a dialog box interface should also support
  // a command-line, or scriptable interface.

  ON_wString str;
  str.Format( L"The \"%s\" command is under construction.\n", EnglishCommandName() );
  if( context.IsInteractive() )
    RhinoMessageBox( str, SampleRdkMaterialAutoUIPlugIn().PlugInName(), MB_OK );
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
// END SampleRdkMaterialAutoUI command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
