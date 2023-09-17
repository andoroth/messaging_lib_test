#include "Msg1Adapter.h"
#include "DataStream.h"
#include "ReceiveMsg1.h"

Msg1Adapter::Msg1Adapter(ReceiveMsg1* msg1Receiver_in)
{
    msgReceiver = msg1Receiver_in;
}

void Msg1Adapter::processDataStream(DataStream* data)
{
    msg1* msg = new msg1;
    data->pop_front();
    msg->data = data->peek();
    msgReceiver->receive(*msg);
}

DataStream* Msg1Adapter::createDataStream(msg1* msg)
{
    DataStream* data = new DataStream;
    MsgAdapterBase::writeHeader(id, data);
    data->push_back(msg->data);
    return data;
}

int Msg1Adapter::getId()
{
    return id;
}
