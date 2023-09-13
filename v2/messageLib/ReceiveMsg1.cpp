#include "ReceiveMsg1.h"
#include "Msg1Adapter.h"
#include "DataStreamProcessor.h"

#include <iostream>

ReceiveMsg1::ReceiveMsg1()
{
    Msg1Adapter* adapter = new Msg1Adapter(this);
    DataStreamProcessor::Instance()->registerMsgAdapter(adapter->getId(), adapter);
}

