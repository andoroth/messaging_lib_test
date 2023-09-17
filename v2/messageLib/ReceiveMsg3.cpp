#include "ReceiveMsg3.h"
#include "Msg3Adapter.h"
#include "DataStreamReceiverInterface.h"

#include <iostream>

ReceiveMsg3::ReceiveMsg3(DataStreamReceiverInterface* mr)
{
    Msg3Adapter* adapter = new Msg3Adapter(this);
    mr->registerMsgAdapter(adapter->getId(), adapter);
}

