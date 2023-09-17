#include "ReceiveMsg2.h"
#include "Msg2Adapter.h"
#include "DataStreamReceiverInterface.h"

#include <iostream>

ReceiveMsg2::ReceiveMsg2(DataStreamReceiverInterface* mr)
{
    Msg2Adapter* adapter = new Msg2Adapter(this);
    mr->registerMsgAdapter(adapter->getId(), adapter);
}

