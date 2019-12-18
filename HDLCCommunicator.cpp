#include "HDLC/HDLCCommunicator.hpp"
#include <Utils/Functions.hpp>
#include <Utils/Logger.hpp>

using namespace convert;

bool HDLCCommunicator::send(const std::string& address, HDLCFrameBodyPtr frame)
{
   LOG(warning) << "Empty communicator";
   LOG(info) << "Sending on " << address << " " << toString(HDLCFrame(frame).build());
   return true;
}

HDLCFramePtr HDLCCommunicator::receive(const std::string& address)
{
   LOG(warning) << "Empty communicator";
   return nullptr;
}
