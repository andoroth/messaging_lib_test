#include "module1.h"

// Message serialization library
#include "DataStreamReceiverInterface.h"
#include "DataStreamSenderInterface.h"
#include "ReceiveMsg3.h"
#include "ReceiveMsg5.h"
#include "SendMsg1.h"
#include "SendMsg2.h"
#include "messages.h"
#include "DataStream.h"

// Transport layer library
#include "TransportLayer.h"
#include "TransportLayerDataReceiver.h"

#include <iostream>

using namespace mod1;
namespace mod1{
class MsgSender : 
    public DataStreamSenderInterface
    ,public SendMsg1
    ,public SendMsg2
{
    public:
        MsgSender() :
            SendMsg1(this)
            ,SendMsg2(this)
            {};
        virtual void sendDataStream(DataStream*);
};
}

void MsgSender::sendDataStream(DataStream* data_in)
{
    std::cout << "Sent data, msgType: " << data_in->peek() << std::endl;
    auto data = new std::deque<int>;
    while (data_in->has_value()) {
        data->push_back(data_in->peek());
        data_in->pop_front();
    }
    TransportLayer::broadcast(nullptr, data);
}

namespace mod1{
class MsgReceiver : 
    public DataStreamReceiverInterface,
    public TransportLayerDataReceiver,
    public ReceiveMsg3,
    public ReceiveMsg5
{
    public:
        MsgReceiver():
            ReceiveMsg3(this),
            ReceiveMsg5(this){};
        virtual void receiveDataStream(std::deque<int>* data);
        virtual void receive(msg3 msg);
        virtual void receive(msg5 msg);
};
}

void MsgReceiver::receiveDataStream(std::deque<int>* in_data)
{
    DataStream* data = new DataStream(in_data);
    //std::cout << "Calling receiver: " << this << std::endl;
    this->DataStreamReceiverInterface::receiveDataStream(data);
}
void MsgReceiver::receive(msg3 msg) 
{
    std::cout << "Mod1 Receive msg3: " << msg.data << std::endl;
}

void MsgReceiver::receive(msg5 msg) 
{
    std::cout << "Mod1 Receive msg5: " << msg.data << std::endl;
}

Module1::Module1()
{
    ms = new MsgSender();
    mr = new MsgReceiver();
    TransportLayer::registerReceiver(mr);
}

void Module1::sendMsg1(int data)
{
    msg1* msg = new msg1();
    msg->data = data;
    std::cout << "Sending msg1: " << msg->data << std::endl;
    ms->sendMsg1(msg);
}

void Module1::sendMsg2(int data)
{
    msg2* msg = new msg2();
    msg->data = data;
    std::cout << "Sending msg2: " << msg->data << std::endl;
    ms->sendMsg2(msg);
}
