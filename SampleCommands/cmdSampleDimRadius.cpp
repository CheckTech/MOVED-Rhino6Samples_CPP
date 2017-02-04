#include "stdafx.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN SampleDimRadius command
//

class CCommandSampleDimRadius : public CRhinoCommand
{
public:
  CCommandSampleDimRadius() {}
  ~CCommandSampleDimRadius() {}
  UUID CommandUUID()
  {
    // {53F63164-B4A6-4C5E-AA47-A4847569B5F1}
    static const GUID SampleDimRadiusCommand_UUID =
    { 0x53F63164, 0xB4A6, 0x4C5E, { 0xAA, 0x47, 0xA4, 0x84, 0x75, 0x69, 0xB5, 0xF1 } };
    return SampleDimRadiusCommand_UUID;
  }
  const wchar_t* EnglishCommandName() { return L"SampleDimRadius"; }
  const wchar_t* LocalCommandName() const { return L"SampleDimRadius"; }
  CRhinoCommand::result RunCommand( const CRhinoCommandContext& );
};

// The one and only CCommandSampleDimRadius object
static class CCommandSampleDimRadius theSampleDimRadiusCommand;

CRhinoCommand::result CCommandSampleDimRadius::RunCommand( const CRhinoCommandContext& context )
{
  ON_DimRadial* dim = nullptr;
  CRhinoObjRef point_ref;
  CRhinoCommand::result rc = CRhinoDimRadial::GetDimRadial(
    context.m_rhino_doc_sn,
    dim,
    point_ref,
    context.IsInteractive(),
    false
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

      CRhinoDimRadial* dim_obj = new CRhinoDimRadial(atts);
      dim_obj->SetDimension(dim);

      context.m_doc.AddObject(dim_obj);

      context.m_doc.Redraw();
    }
  }


  return rc;
}

//
// END SampleDimRadius command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
