#pragma once

class CSampleLayerContextMenuExtension : public CRhinoContextMenuExtension
{
public:
  CSampleLayerContextMenuExtension(CRhinoPlugIn& thePlugIn);
  ~CSampleLayerContextMenuExtension();

  bool ShouldExtendContextMenu(CRhinoContextMenuContext& context);
  void ExtendContextMenu(CRhinoContextMenuContext& context, CRhinoContextMenu& context_menu);
  void OnCommand(CRhinoContextMenuContext& context, int iAddItemID, UINT nID, CRhinoContextMenu& context_menu);
  void OnInitPopupMenu(CRhinoContextMenuContext& context, HWND hWnd, HMENU hMenuOriginal, HMENU hMenuRuntime, CRhinoContextMenu& context_menu);

private:
  int m_iAddItemID0;
  int m_iAddItemID1;
  int m_iAddItemID2;
};