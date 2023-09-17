#include "SendMsg2.h"
#include "Msg2Adapter.h"
#include "DataStreamSenderInterface.h"

#include <iostream>

SendMsg2::SendMsg2(DataStreamSenderInterface* dataSender_in)
{
    dataSender = dataSender_in;
}

void SendMsg2::sendMsg2(msg2* msg)
{
    DataStream* data = Msg2Adapter::createDataStream(msg);
    dataSender->sendDataStream(data);
}
