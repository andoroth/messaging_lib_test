#include "SendMsg3.h"
#include "Msg3Adapter.h"
#include "DataStreamSenderInterface.h"

#include <iostream>

SendMsg3::SendMsg3(DataStreamSenderInterface* dataSender_in)
{
    dataSender = dataSender_in;
}

void SendMsg3::sendMsg3(msg3* msg)
{
    DataStream* data = Msg3Adapter::createDataStream(msg);
    dataSender->sendDataStream(data);
}
