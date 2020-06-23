///
/// \file LocalizedText.hpp
/// \author Christian von Arnim
/// \date 12.02.2020
///

#pragma once
#include <refl.hpp>
#include <string>
#include <open62541/types.h>
#include <open62541/types_generated.h>
#include "ReflectionHelper.hpp"

namespace UmatiServerLib
{
  struct LocalizedText_t
  {
    std::string locale;
    std::string text;
    static LocalizedText_t fromUa(const ::UA_LocalizedText &other);
    bool operator==(const LocalizedText_t &other) const;
  };

  namespace internalTypes
  {
    //typedef struct {
    //    UA_String locale;
    //    UA_String text;
    //} UA_LocalizedText;
    static UA_DataTypeMember LocalizedText_members[] = {
        {
            UA_TYPENAME("locale") /* .memberName */
            UA_TYPES_STRING,      /* .memberTypeIndex, points into UA_TYPES since namespaceZero is true */
            0,                    /* .padding */
            true,                 /* .namespaceZero, see .memberTypeIndex */
            false                 /* .isArray */
        },
        {
            UA_TYPENAME("text")                                     /* .memberName */
            UA_TYPES_STRING,                                        /* .memberTypeIndex, points into UA_TYPES since namespaceZero is true */
            UMATISERVERLIB_PADDING(::UA_LocalizedText, text, locale), /* .padding */
            true,                                                   /* .namespaceZero, see .memberTypeIndex */
            false                                                   /* .isArray */
        }};

    static const UA_DataType UA_LocalizedText = {
        UA_TYPENAME("Point")              /* .typeName */
        {1, UA_NODEIDTYPE_NUMERIC, {21}}, /* .typeId */
        sizeof(::UA_LocalizedText),       /* .memSize */
        UA_TYPES_LOCALIZEDTEXT,           /* .typeIndex, in the array of custom types */
        UA_DATATYPEKIND_LOCALIZEDTEXT,    /* .typeKind */
        true,                             /* .pointerFree */
        false,                            /* .overlayable (depends on endianness and
                                         the absence of padding) */
        2,                                /* .membersSize */
        0,                                /* .binaryEncodingId, the numeric
                                         identifier used on the wire (the
                                         namespaceindex is from .typeId) */
        LocalizedText_members};
  } // namespace internalTypes

} // namespace UmatiServerLib

REFL_TYPE(UmatiServerLib::LocalizedText_t, UmatiServerLib::attribute::UaDataType(&UmatiServerLib::internalTypes::UA_LocalizedText))
REFL_FIELD(locale)
REFL_FIELD(text)
REFL_END
