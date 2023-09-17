#include "ReceiveMsg1.h"
#include "Msg1Adapter.h"
#include "DataStreamReceiverInterface.h"

#include <iostream>

ReceiveMsg1::ReceiveMsg1(DataStreamReceiverInterface* mr)
{
    Msg1Adapter* adapter = new Msg1Adapter(this);
    mr->registerMsgAdapter(adapter->getId(), adapter);
}

