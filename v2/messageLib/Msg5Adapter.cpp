#include "Msg5Adapter.h"
#include "DataStream.h"
#include "ReceiveMsg5.h"

Msg5Adapter::Msg5Adapter(ReceiveMsg5* msg5Receiver_in)
{
    msgReceiver = msg5Receiver_in;
}

void Msg5Adapter::processDataStream(DataStream* data)
{
    msg5* msg = new msg5;
    data->pop_front();
    msg->data = data->peek();
    msgReceiver->receive(*msg);
}

DataStream* Msg5Adapter::createDataStream(msg5* msg)
{
    DataStream* data = new DataStream;
    MsgAdapterBase::writeHeader(id, data);
    data->push_back(msg->data);
    return data;
}

int Msg5Adapter::getId()
{
    return id;
}
