#include "Msg3Adapter.h"
#include "DataStream.h"
#include "ReceiveMsg3.h"

Msg3Adapter::Msg3Adapter(ReceiveMsg3* msg3Receiver_in)
{
    msgReceiver = msg3Receiver_in;
}

void Msg3Adapter::processDataStream(DataStream* data)
{
    msg3* msg = new msg3;
    data->pop_front();
    msg->data = data->peek();
    msgReceiver->receive(*msg);
}

DataStream* Msg3Adapter::createDataStream(msg3* msg)
{
    DataStream* data = new DataStream;
    MsgAdapterBase::writeHeader(id, data);
    data->push_back(msg->data);
    return data;
}

int Msg3Adapter::getId()
{
    return id;
}
