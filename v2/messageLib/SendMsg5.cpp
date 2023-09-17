#include "SendMsg5.h"
#include "Msg5Adapter.h"
#include "DataStreamSenderInterface.h"

#include <iostream>

SendMsg5::SendMsg5(DataStreamSenderInterface* dataSender_in)
{
    dataSender = dataSender_in;
}

void SendMsg5::sendMsg5(msg5* msg)
{
    DataStream* data = Msg5Adapter::createDataStream(msg);
    dataSender->sendDataStream(data);
}
