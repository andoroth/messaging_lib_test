#include "ReceiveMsg5.h"
#include "Msg5Adapter.h"
#include "DataStreamProcessor.h"

#include <iostream>

ReceiveMsg5::ReceiveMsg5()
{
    Msg5Adapter* adapter = new Msg5Adapter(this);
    DataStreamProcessor::Instance()->registerMsgAdapter(adapter->getId(), adapter);
}

