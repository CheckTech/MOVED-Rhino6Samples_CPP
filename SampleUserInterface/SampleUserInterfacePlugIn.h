#pragma once

#include "SampleModelessDialog.h"
#include "SampleLayerContextMenuExtension.h"

class CSampleUserInterfacePlugIn : public CRhinoUtilityPlugIn
{
public:
  CSampleUserInterfacePlugIn();
  ~CSampleUserInterfacePlugIn();

  // Required overrides
  const wchar_t* PlugInName() const;
  const wchar_t* PlugInVersion() const;
  GUID PlugInID() const;
  BOOL OnLoadPlugIn();
  void OnUnloadPlugIn();

  // Online help overrides
  BOOL AddToPlugInHelpMenu() const;
  BOOL OnDisplayPlugInHelp(HWND hWnd) const;

  // Modeless dialog helpers
  bool IsDlgCreated();
  bool IsDlgVisible();
  bool SetDlgVisible();
  bool SetDlgHidden();
  bool DisplayDlg();
  void DestroyDlg();
  void ZeroDlg();
  void SetDlgPointValue(int item, const ON_3dPoint& pt);

private:
  ON_wString m_plugin_version;

  // TODO: Add additional class information here

  CSampleModelessDialog* m_dialog;
  CSampleLayerContextMenuExtension* m_extension_menu;
};

CSampleUserInterfacePlugIn& SampleUserInterfacePlugIn();



