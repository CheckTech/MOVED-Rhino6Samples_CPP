#include "stdafx.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN SampleDimAngular command
//

#pragma region SampleDimAngular command

class CCommandSampleDimAngular : public CRhinoCommand
{
public:
  CCommandSampleDimAngular() {}
  ~CCommandSampleDimAngular() {}
  UUID CommandUUID()
  {
    // {D6AE4A0E-5056-452A-888C-B309E7CB12FF}
    static const GUID SampleDimAngularCommand_UUID =
    { 0xD6AE4A0E, 0x5056, 0x452A, { 0x88, 0x8C, 0xB3, 0x09, 0xE7, 0xCB, 0x12, 0xFF } };
    return SampleDimAngularCommand_UUID;
  }
  const wchar_t* EnglishCommandName() { return L"SampleDimAngular"; }
  const wchar_t* LocalCommandName() const { return L"SampleDimAngular"; }
  CRhinoCommand::result RunCommand(const CRhinoCommandContext&);
};

// The one and only CCommandSampleDimAngular object
static class CCommandSampleDimAngular theSampleDimAngularCommand;

CRhinoCommand::result CCommandSampleDimAngular::RunCommand(const CRhinoCommandContext& context)
{
  ON_DimAngular* dim = nullptr;
  CRhinoDimAngular::definition_mode def_mode = CRhinoDimAngular::definition_mode::None;
  bool picked_ob[3] = { false, false, false };
  CRhinoObjRef point_refs[3];
  ON_Line lines[2];
  ON_3dPoint pickpoints[2];
  ON_3dPoint centerpoint;
  ON_3dPoint arcpoint;
  bool rc = CRhinoDimAngular::GetDimAngular(
    context.m_rhino_doc_sn,
    dim,
    context.IsInteractive(),
    def_mode,
    picked_ob,
    point_refs,
    lines,
    pickpoints,
    centerpoint,
    arcpoint
  );

  if (rc && nullptr != dim)
  {
    ON_3dmObjectAttributes atts;
    context.m_doc.GetDefaultObjectAttributes(atts);

    ON_UUID style_id = dim->DimensionStyleId();
    int style_idx = context.m_doc.m_dimstyle_table.FindDimStyleFromId(style_id, true, false, ON_UNSET_INT_INDEX);
    if (ON_UNSET_INT_INDEX != style_idx)
    {
      const ON_DimStyle* style = &context.m_doc.m_dimstyle_table[style_idx];
      if (nullptr == style)
        return CRhinoCommand::result::failure;

      style = &dim->DimensionStyle(*style);
      if (style->DrawTextMask())
      {
        int fdn = CRhinoDimension::GetFrontDrawNumber(context.m_doc);
        atts.m_display_order = fdn + 1;
      }

      CRhinoDimAngular* dim_obj = new CRhinoDimAngular(atts);
      switch (def_mode)
      {
      case CRhinoDimAngular::definition_mode::Arc:
        dim->SetAngularDimensionType(ON::AnnotationType::Angular3pt);
        break;
      case CRhinoDimAngular::definition_mode::Points:
        dim->SetAngularDimensionType(ON::AnnotationType::Angular3pt);
        break;
      case CRhinoDimAngular::definition_mode::Lines:
        dim->SetAngularDimensionType(ON::AnnotationType::Angular);
        break;
      }
      dim_obj->SetDimension(dim);
      dim_obj->SetDefinitionMode(def_mode);

      context.m_doc.AddObject(dim_obj);

      context.m_doc.Redraw();
    }
  }

  return CRhinoCommand::success;
}

#pragma endregion

//
// END SampleDimAngular command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
