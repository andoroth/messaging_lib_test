#include "Msg6Adapter.h"
#include "DataStream.h"
#include "ReceiveMsg6.h"

Msg6Adapter::Msg6Adapter(ReceiveMsg6* msg6Receiver_in)
{
    msgReceiver = msg6Receiver_in;
}

void Msg6Adapter::processDataStream(DataStream* data)
{
    msg6* msg = new msg6;
    data->pop_front();
    msg->data = data->peek();
    msgReceiver->receive(*msg);
}

DataStream* Msg6Adapter::createDataStream(msg6* msg)
{
    DataStream* data = new DataStream;
    MsgAdapterBase::writeHeader(id, data);
    data->push_back(msg->data);
    return data;
}

int Msg6Adapter::getId()
{
    return id;
}
