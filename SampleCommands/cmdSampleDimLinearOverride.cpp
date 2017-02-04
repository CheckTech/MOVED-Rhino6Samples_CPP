#include "stdafx.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN SampleDimLinearOverride command
//

#pragma region SampleDimLinearOverride command

class CCommandSampleDimLinearOverride : public CRhinoCommand
{
public:
  CCommandSampleDimLinearOverride() {}
  ~CCommandSampleDimLinearOverride() {}
  UUID CommandUUID()
  {
    // {56236AC2-709A-4842-BC4B-41671E7179B8}
    static const GUID SampleDimLinearOverrideCommand_UUID =
    { 0x56236AC2, 0x709A, 0x4842, { 0xBC, 0x4B, 0x41, 0x67, 0x1E, 0x71, 0x79, 0xB8 } };
    return SampleDimLinearOverrideCommand_UUID;
  }
  const wchar_t* EnglishCommandName() { return L"SampleDimLinearOverride"; }
  const wchar_t* LocalCommandName() const { return L"SampleDimLinearOverride"; }
  CRhinoCommand::result RunCommand(const CRhinoCommandContext&);
};

// The one and only CCommandSampleDimLinearOverride object
static class CCommandSampleDimLinearOverride theSampleDimLinearOverrideCommand;

CRhinoCommand::result CCommandSampleDimLinearOverride::RunCommand(const CRhinoCommandContext& context)
{
  // Make a new linear dimension
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

    // To override a property of a dimension, you must first create a child
    // dimension style. In this example, we will create a child dimension
    // style of the current dimension style, override the text alignment
    // property, and then assign it to a new linear dimension.

    // Get reference to dimension style table
    CRhinoDimStyleTable& dimstyle_table = context.m_doc.m_dimstyle_table;

    // Get the current dimension style
    const CRhinoDimStyle& dimstyle = dimstyle_table.CurrentDimStyle();

    // Create a new dimenstion style based on the current dimension style
    ON_DimStyle child_dimstyle(dimstyle);

    // Override with the text alignment field
    child_dimstyle.SetFieldOverride(ON_DimStyle::field::TextAlignment, true);

    // Set text alignment field to horizontal
    child_dimstyle.SetTextAlignment(ON::TextDisplayMode::kHorizontalToScreen);

    // Add the new child dimension style
    // Make this dimstyle a child of the current dimension style
    int child_dimstyle_index = dimstyle_table.OverrideDimStyle(child_dimstyle, dimstyle.Index());

    const ON_DimStyle* style = &dimstyle_table[child_dimstyle_index];
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

  return CRhinoCommand::success;
}

#pragma endregion

//
// END SampleDimLinearOverride command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
