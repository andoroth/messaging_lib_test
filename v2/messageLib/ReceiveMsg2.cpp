#include "ReceiveMsg2.h"
#include "Msg2Adapter.h"
#include "DataStreamProcessor.h"

#include <iostream>

ReceiveMsg2::ReceiveMsg2()
{
    Msg2Adapter* adapter = new Msg2Adapter(this);
    DataStreamProcessor::Instance()->registerMsgAdapter(adapter->getId(), adapter);
}

