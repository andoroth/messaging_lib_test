#include "ReceiveMsg4.h"
#include "Msg4Adapter.h"
#include "DataStreamReceiverInterface.h"

#include <iostream>

ReceiveMsg4::ReceiveMsg4(DataStreamReceiverInterface* mr)
{
    Msg4Adapter* adapter = new Msg4Adapter(this);
    mr->registerMsgAdapter(adapter->getId(), adapter);
}

