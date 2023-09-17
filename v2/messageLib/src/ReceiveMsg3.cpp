#include "ReceiveMsg3.h"
#include "Msg3Adapter.h"
#include "DataStreamProcessor.h"

#include <iostream>

ReceiveMsg3::ReceiveMsg3()
{
    Msg3Adapter* adapter = new Msg3Adapter(this);
    DataStreamProcessor::Instance()->registerMsgAdapter(adapter->getId(), adapter);
}

