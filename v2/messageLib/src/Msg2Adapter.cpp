#include "Msg2Adapter.h"
#include "DataStream.h"
#include "ReceiveMsg2.h"

Msg2Adapter::Msg2Adapter(ReceiveMsg2* msg2Receiver_in)
{
    msgReceiver = msg2Receiver_in;
}

void Msg2Adapter::processDataStream(DataStream* data)
{
    msg2* msg = new msg2;
    data->pop_front();
    msg->data = data->peek();
    msgReceiver->receive(*msg);
}

DataStream* Msg2Adapter::createDataStream(msg2* msg)
{
    DataStream* data = new DataStream;
    MsgAdapterBase::writeHeader(id, data);
    data->push_back(msg->data);
    return data;
}

int Msg2Adapter::getId()
{
    return id;
}
