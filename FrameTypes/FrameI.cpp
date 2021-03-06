#include <HDLC/FrameTypes/FrameI.hpp>
#include <Utils/Functions.hpp>

using namespace convert;

FrameI::FrameI()
   : HDLCFrameBody()
{
   setControlByte(BYTE_CONTROL::RETAP);
}

FrameI& FrameI::setAddressByte(Hex value)
{
   address_ = value;
   return *this;
}

FrameI& FrameI::setControlByte(Hex value)
{
   ctrl_ = value;
   return *this;
}

FrameI& FrameI::setProcedureCode(Hex value)
{
   procedureCode_ = value;
   return *this;
}

FrameI& FrameI::setParameterLength(Hexes values)
{
   parLength_ = values;
   return *this;
}

FrameI& FrameI::setParameterValues(Hexes values)
{
   parValues_ = values;
   return *this;
}

Hexes FrameI::build() const
{
   Hexes retVal;
   LOG(trace) << "START";

   if (not address_)
   {
      LOG(error) << "Empty address byte, returning empty frame";
      return {};
   }
   retVal.push_back(*address_);
   LOG(debug) << toString("ADDR: ", *address_);

   if (not ctrl_)
   {
      LOG(error) << "Empty control byte, returning empty frame";
      return {};
   }
   retVal.push_back(*ctrl_);
   LOG(debug) << toString("CTRL: ", *ctrl_);

   if (not procedureCode_)
   {
      LOG(error) << "Empty procedureCode byte, returning empty frame";
      return {};
   }
   retVal.push_back(*procedureCode_);
   LOG(debug) << toString("PROC: ", *procedureCode_);

   for (const auto& it : parLength_)
   {
      retVal.push_back(it);
   }
   LOG(debug) << toString("PAR LENGTH: ", parLength_);

   if (not parValues_.empty())
   {
      for (const auto &it : parValues_)
      {
         retVal.push_back(it);
      }
      LOG(debug) << toString("PAR VALUES: ", parValues_);
   }

   LOG(debug) << "HDLC': " << toString(retVal);
   return retVal;
}
