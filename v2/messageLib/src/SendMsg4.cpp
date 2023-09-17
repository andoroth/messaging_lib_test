#include "SendMsg4.h"
#include "Msg4Adapter.h"
#include "DataStreamSenderInterface.h"

#include <iostream>

SendMsg4::SendMsg4(DataStreamSenderInterface* dataSender_in)
{
    dataSender = dataSender_in;
}

void SendMsg4::sendMsg4(msg4* msg)
{
    DataStream* data = Msg4Adapter::createDataStream(msg);
    dataSender->sendDataStream(data);
}
