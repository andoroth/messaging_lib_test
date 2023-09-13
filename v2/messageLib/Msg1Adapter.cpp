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

int Msg1Adapter::getId()
{
    return 1;
}
