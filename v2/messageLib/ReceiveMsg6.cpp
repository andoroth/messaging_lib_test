#include "ReceiveMsg6.h"
#include "Msg6Adapter.h"
#include "DataStreamReceiverInterface.h"

#include <iostream>

ReceiveMsg6::ReceiveMsg6(DataStreamReceiverInterface* mr)
{
    Msg6Adapter* adapter = new Msg6Adapter(this);
    mr->registerMsgAdapter(adapter->getId(), adapter);
}

