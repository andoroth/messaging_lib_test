#include "ReceiveMsg4.h"
#include "Msg4Adapter.h"
#include "DataStreamProcessor.h"

#include <iostream>

ReceiveMsg4::ReceiveMsg4()
{
    Msg4Adapter* adapter = new Msg4Adapter(this);
    DataStreamProcessor::Instance()->registerMsgAdapter(adapter->getId(), adapter);
}

