// SampleRdkMaterialAutoUIPlugIn.h : main header file for the SampleRdkMaterialAutoUI plug-in.
//

#pragma once

// CSampleRdkMaterialAutoUIPlugIn
// See SampleRdkMaterialAutoUIPlugIn.cpp for the implementation of this class
//

class CSampleRdkMaterialAutoUIPlugIn : public CRhinoUtilityPlugIn
{
public:
  CSampleRdkMaterialAutoUIPlugIn();
  ~CSampleRdkMaterialAutoUIPlugIn();

  // Required overrides
  const wchar_t* PlugInName() const;
  const wchar_t* PlugInVersion() const;
  GUID PlugInID() const;
  BOOL OnLoadPlugIn();
  void OnUnloadPlugIn();

  // Online help overrides
  BOOL AddToPlugInHelpMenu() const;
  BOOL OnDisplayPlugInHelp(HWND hWnd) const;

private:
  ON_wString m_plugin_version;

  // TODO: Add additional class information here
};

CSampleRdkMaterialAutoUIPlugIn& SampleRdkMaterialAutoUIPlugIn();



