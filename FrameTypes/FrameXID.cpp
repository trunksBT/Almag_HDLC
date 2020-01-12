#include <HDLC/FrameTypes/FrameXID.hpp>
#include <Utils/Functions.hpp>
#include <Utils/Utils.hpp>

using namespace convert;
using namespace defaultVals;

FrameXID::FrameXID()
   : HDLCFrameBody()
{
   setControlByte(BYTE_CONTROL::XID);
}

FrameXID& FrameXID::setAddressByte(Hex value)
{
   address_ = value;
   return *this;
}

FrameXID& FrameXID::setControlByte(Hex value)
{
   ctrl_ = value;
   return *this;
}

FrameXID& FrameXID::setFormatIdentifierByte(Hex value)
{
   formatIdentifier_ = value;
   return *this;
}

FrameXID& FrameXID::setGroupIdentifierByte(Hex value)
{
   groupIdentifier_ = value;
   return *this;
}

FrameXID& FrameXID::setGroupLengthByte(Hex value)
{
   groupLength_ = value;
   return *this;
}

FrameXID& FrameXID::addParameters(HDLCParametersValues value)
{
   parameters_.emplace_back(value);
   return *this;
}

Hexes FrameXID::build() const
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

   if (not ctrl_)
   {
      LOG(error) << "Empty control byte, returning empty frame";
      return {};
   }
   retVal.push_back(*ctrl_);
   LOG(debug) << toString("CTRL: ", *ctrl_);

   if (not formatIdentifier_)
   {
      LOG(error) << "Empty format identifier byte, returning empty frame";
      return {};
   }
   retVal.push_back(*formatIdentifier_);
   LOG(debug) << toString("FI: ", *formatIdentifier_);

   if (not groupIdentifier_)
   {
      LOG(error) << "Empty group identifier byte, returning empty frame";
      return {};
   }
   retVal.push_back(*groupIdentifier_);
   LOG(debug) << toString("GI: ", *groupIdentifier_);

   if (not groupLength_)
   {
      LOG(error) << "Empty group length byte, returning empty frame";
      return {};
   }
   retVal.push_back(*groupLength_);
   LOG(debug) << toString("GL: ", *groupLength_);

   for (const auto& it : parameters_)
   {
      retVal.push_back(it.parId);
      LOG(debug) << HDLC_PARAMETERS_SEPARATOR;
      LOG(debug) << toString("PI: ", it.parId);

      retVal.push_back(it.parLength);
      LOG(debug) << toString("PL: ", it.parLength);

      retVal.insert( retVal.end(), it.parValue.begin(), it.parValue.end() );
      LOG(debug) << toString("PV: ", it.parValue);
      LOG(debug) << HDLC_PARAMETERS_SEPARATOR;
   }

   LOG(info) << "HDLC': " << toString(retVal);
   return retVal;
}
