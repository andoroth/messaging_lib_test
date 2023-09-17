#include "SendMsg1.h"
#include "Msg1Adapter.h"
#include "DataStreamSenderInterface.h"

#include <iostream>

SendMsg1::SendMsg1(DataStreamSenderInterface* dataSender_in)
{
    dataSender = dataSender_in;
}

void SendMsg1::sendMsg1(msg1* msg)
{
    DataStream* data = Msg1Adapter::createDataStream(msg);
    dataSender->sendDataStream(data);
}
