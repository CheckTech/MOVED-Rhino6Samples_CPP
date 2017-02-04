#include "stdafx.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN SampleDimLinear command
//

#pragma region SampleDimLinear command

class CCommandSampleDimLinear : public CRhinoCommand
{
public:
  CCommandSampleDimLinear() {}
  ~CCommandSampleDimLinear() {}
  UUID CommandUUID()
  {
    // {472985B0-C869-4513-A91B-E718450A55B0}
    static const GUID SampleDimLinearCommand_UUID =
    { 0x472985B0, 0xC869, 0x4513, { 0xA9, 0x1B, 0xE7, 0x18, 0x45, 0x0A, 0x55, 0xB0 } };
    return SampleDimLinearCommand_UUID;
  }
  const wchar_t* EnglishCommandName() { return L"SampleDimLinear"; }
  const wchar_t* LocalCommandName() const { return L"SampleDimLinear"; }
  CRhinoCommand::result RunCommand(const CRhinoCommandContext&);
};

// The one and only CCommandSampleDimLinear object
static class CCommandSampleDimLinear theSampleDimLinearCommand;

CRhinoCommand::result CCommandSampleDimLinear::RunCommand(const CRhinoCommandContext& context)
{
  CRhinoObjRef point_refs[2];
  ON_DimLinear* dim = nullptr;
  double rotation_angle = 0.0;
  CRhinoDimLinear::rotation_mode rotation_mode = CRhinoDimLinear::rotation_mode::Ortho;
  CRhinoDimLinear::continue_mode continue_mode = CRhinoDimLinear::continue_mode::None;

  int rc = CRhinoDimLinear::GetDimLinear(
    context.m_rhino_doc_sn,
    dim,
    point_refs,
    context.IsInteractive(),
    rotation_mode,
    rotation_angle,
    continue_mode
  );

  if (0 == rc && nullptr != dim)
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

      CRhinoDimLinear* dim_obj = new CRhinoDimLinear(atts);
      dim_obj->SetDimension(dim);

      context.m_doc.AddObject(dim_obj);

      context.m_doc.Redraw();
    }
  }

  return rc ? CRhinoCommand::success : CRhinoCommand::cancel;
}

#pragma endregion

//
// END SampleDimLinear command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
