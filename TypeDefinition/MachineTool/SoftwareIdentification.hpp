#pragma once
#include "../TypeDefiniton.hpp"
#include "Constants.hpp"

namespace machineTool
{

struct SoftwareIdentification_t
{
  BindableMemberValue<std::string> SoftwareRevision;
  BindableMemberValue<std::string> Identifier;
};

} // namespace machineTool

REFL_TYPE(machineTool::SoftwareIdentification_t,
  UmatiServerLib::attribute::UaObjectType{
  .NodeId = UmatiServerLib::constexp::NodeId(constants::NsMachineToolUri, UA_MACHINETOOLID_SOFTWAREIDENTIFICATIONTYPE)}
})
REFL_FIELD(SoftwareRevision)
REFL_FIELD(Identifier)
REFL_END