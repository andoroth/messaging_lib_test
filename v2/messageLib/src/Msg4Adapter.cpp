#include "Msg4Adapter.h"
#include "DataStream.h"
#include "ReceiveMsg4.h"

Msg4Adapter::Msg4Adapter(ReceiveMsg4* msg4Receiver_in)
{
    msgReceiver = msg4Receiver_in;
}

void Msg4Adapter::processDataStream(DataStream* data)
{
    msg4* msg = new msg4;
    data->pop_front();
    msg->data = data->peek();
    msgReceiver->receive(*msg);
}

DataStream* Msg4Adapter::createDataStream(msg4* msg)
{
    DataStream* data = new DataStream;
    MsgAdapterBase::writeHeader(id, data);
    data->push_back(msg->data);
    return data;
}

int Msg4Adapter::getId()
{
    return id;
}
