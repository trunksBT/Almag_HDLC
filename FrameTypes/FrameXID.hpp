#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameXID : public HDLCFrameBody 
{
public:
   FrameXID();

   FrameXID& setAddressByte(Hex value);
   FrameXID& setControlByte(Hex value);
   FrameXID& setFormatIdentifierByte(Hex value);
   FrameXID& setGroupIdentifierByte(Hex value);
   FrameXID& setGroupLengthByte(Hex value);
   FrameXID& addParameters(HDLCParametersValues value);

   Hexes build() const;
};

using FrameXIDPtr = std::shared_ptr<FrameXID>;
