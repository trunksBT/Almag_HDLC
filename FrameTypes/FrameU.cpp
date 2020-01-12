#include <HDLC/FrameTypes/FrameU.hpp>
#include <Utils/Functions.hpp>

using namespace convert;

frameType::BYTE_CTRL FrameU::GET_TYPE=frameType::BYTE_CTRL::U;

FrameU::FrameU()
   : HDLCFrameBody()
{
   LOG(trace);
}

FrameU& FrameU::setAddressByte(Hex value)
{
   address_ = value;
   return *this;
}

FrameU& FrameU::setControlByte(Hex value)
{
   ctrl_ = value;
   return *this;
}

Hexes FrameU::build() const
{
   Hexes retVal;
   LOG(trace);

   if (not address_)
   {
      LOG(error) << "Empty address byte, returning empty frame";
      return {};
   }
   retVal.push_back(*address_);
   LOG(debug) << toString("ADDR: ", *address_);

   retVal.push_back(*ctrl_);
   LOG(debug) << toString("CTRL: ", *ctrl_);

   LOG(info) << "HDLC': " << toString(retVal);
   return retVal;
}
