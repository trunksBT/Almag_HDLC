#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameU : public HDLCFrameBody
{
public:
   FrameU();
   explicit FrameU(const std::string& value);

   FrameU& setAddressByte(Hex value);
   FrameU& setControlByte(Hex value);

   Hexes build() const;
};

using FrameUPtr = std::shared_ptr<FrameU>;
