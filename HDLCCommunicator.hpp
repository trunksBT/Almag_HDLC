#pragma once

#include <memory>
#include <HDLC/IHDLCCommunicator.hpp>

class HDLCCommunicator : public IHDLCCommunicator
{
public:
   HDLCCommunicator() = default;
   bool send(const std::string& address, HDLCFrameBodyPtr frame) override;
   HDLCFramePtr receive(const std::string& address) override;
};
