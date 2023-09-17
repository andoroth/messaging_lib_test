#include "ReceiveMsg6.h"
#include "Msg6Adapter.h"
#include "DataStreamProcessor.h"

#include <iostream>

ReceiveMsg6::ReceiveMsg6()
{
    Msg6Adapter* adapter = new Msg6Adapter(this);
    DataStreamProcessor::Instance()->registerMsgAdapter(adapter->getId(), adapter);
}

