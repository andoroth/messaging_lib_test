#include "ReceiveMsg5.h"
#include "Msg5Adapter.h"
#include "DataStreamReceiverInterface.h"

#include <iostream>

ReceiveMsg5::ReceiveMsg5(DataStreamReceiverInterface* mr)
{
    Msg5Adapter* adapter = new Msg5Adapter(this);
    mr->registerMsgAdapter(adapter->getId(), adapter);
}

