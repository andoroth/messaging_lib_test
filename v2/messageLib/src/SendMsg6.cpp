#include "SendMsg6.h"
#include "Msg6Adapter.h"
#include "DataStreamSenderInterface.h"

#include <iostream>

SendMsg6::SendMsg6(DataStreamSenderInterface* dataSender_in)
{
    dataSender = dataSender_in;
}

void SendMsg6::sendMsg6(msg6* msg)
{
    DataStream* data = Msg6Adapter::createDataStream(msg);
    dataSender->sendDataStream(data);
}
