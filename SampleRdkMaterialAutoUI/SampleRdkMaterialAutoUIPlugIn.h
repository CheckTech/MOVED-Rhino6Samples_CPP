// SampleRdkMaterialAutoUIPlugIn.h : main header file for the SampleRdkMaterialAutoUI plug-in.
//

#pragma once

// CSampleRdkMaterialAutoUIPlugIn
// See SampleRdkMaterialAutoUIPlugIn.cpp for the implementation of this class
//
class CSampleRdkMaterialAutoUIPlugIn : public CRhinoRenderPlugIn
{
public:
  CSampleRdkMaterialAutoUIPlugIn();
  virtual ~CSampleRdkMaterialAutoUIPlugIn();

  // Required overrides
  virtual const wchar_t* PlugInName() const override;
  virtual const wchar_t* PlugInVersion() const override;
  virtual GUID PlugInID() const override;
  virtual BOOL OnLoadPlugIn() override;
  virtual void OnUnloadPlugIn() override;
  virtual CRhinoCommand::result Render( const CRhinoCommandContext& context, bool render_preview) override;
  virtual plugin_load_time PlugInLoadTime() override { return load_plugin_at_startup; }

  // Online help overrides
  virtual BOOL AddToPlugInHelpMenu() const override;
  virtual BOOL OnDisplayPlugInHelp(HWND hWnd) const override;

private:
  ON_wString m_plugin_version;
  class CSampleRdkMaterialAutoUIRdkPlugIn* m_pRdkPlugIn = nullptr;

  // TODO: Add additional class information here
};

CSampleRdkMaterialAutoUIPlugIn& SampleRdkMaterialAutoUIPlugIn();
