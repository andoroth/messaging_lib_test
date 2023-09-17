#include "module2.h"

// Message serialization library
#include "DataStreamReceiverInterface.h"
#include "DataStreamSenderInterface.h"
#include "ReceiveMsg1.h"
#include "ReceiveMsg6.h"
#include "SendMsg3.h"
#include "SendMsg4.h"
#include "messages.h"
#include "DataStream.h"

// Transport layer library
#include "TransportLayer.h"
#include "TransportLayerDataReceiver.h"

#include <iostream>

using namespace mod2;

namespace mod2{
class MsgSender : 
    public DataStreamSenderInterface
    ,public SendMsg3
    ,public SendMsg4
{
    public:
        MsgSender() :
            SendMsg3(this)
            ,SendMsg4(this)
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

namespace mod2{
class MsgReceiver : 
    public DataStreamReceiverInterface,
    public TransportLayerDataReceiver,
    public ReceiveMsg1,
    public ReceiveMsg6
{
    public:
        MsgReceiver() :
            ReceiveMsg1(this),
            ReceiveMsg6(this){};
        virtual void receiveDataStream(std::deque<int>* data);
        virtual void receive(msg1 msg);
        virtual void receive(msg6 msg);
};
}

void MsgReceiver::receiveDataStream(std::deque<int>* in_data)
{
    DataStream* data = new DataStream(in_data);
    this->DataStreamReceiverInterface::receiveDataStream(data);
}
void MsgReceiver::receive(msg1 msg) 
{
    std::cout << "Mod2 Receive msg1: " << msg.data << std::endl;
}

void MsgReceiver::receive(msg6 msg) 
{
    std::cout << "Mod2 Receive msg6: " << msg.data << std::endl;
}

Module2::Module2()
{
    ms = new MsgSender();
    mr = new MsgReceiver();
    TransportLayer::registerReceiver(mr);
}

void Module2::sendMsg3(int data)
{
    msg3* msg = new msg3();
    msg->data = data;
    std::cout << "Sending msg3: " << msg->data << std::endl;
    ms->sendMsg3(msg);
}

void Module2::sendMsg4(int data)
{
    msg4* msg = new msg4();
    msg->data = data;
    std::cout << "Sending msg4: " << msg->data << std::endl;
    ms->sendMsg4(msg);
}

