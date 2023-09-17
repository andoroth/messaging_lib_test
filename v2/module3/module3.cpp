#include "module3.h"

// Message serialization library
#include "DataStreamReceiverInterface.h"
#include "DataStreamSenderInterface.h"
#include "ReceiveMsg2.h"
#include "ReceiveMsg4.h"
#include "SendMsg5.h"
#include "SendMsg6.h"
#include "messages.h"
#include "DataStream.h"

// Transport layer library
#include "TransportLayer.h"
#include "TransportLayerDataReceiver.h"

#include <iostream>

using namespace mod3;
class MsgSender : 
    public DataStreamSenderInterface
    ,public SendMsg5
    ,public SendMsg6
{
    public:
        MsgSender() :
            SendMsg5(this)
            ,SendMsg6(this)
            {};
        virtual void sendDataStream(DataStream*);
};

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

class MsgReceiver : 
    public DataStreamReceiverInterface,
    public TransportLayerDataReceiver,
    public ReceiveMsg2,
    public ReceiveMsg4
{
    public:
        MsgReceiver() :
            ReceiveMsg2(this),
            ReceiveMsg4(this){};
        virtual void receiveDataStream(std::deque<int>* data);
        virtual void receive(msg2 msg);
        virtual void receive(msg4 msg);
};

void MsgReceiver::receiveDataStream(std::deque<int>* in_data)
{
    DataStream* data = new DataStream(in_data);
    this->DataStreamReceiverInterface::receiveDataStream(data);
}
void MsgReceiver::receive(msg2 msg) 
{
    std::cout << "Mod3 Receive msg2: " << msg.data << std::endl;
}

void MsgReceiver::receive(msg4 msg) 
{
    std::cout << "Mod3 Receive msg4: " << msg.data << std::endl;
}

Module3::Module3()
{
    ms = new MsgSender();
    mr = new MsgReceiver();
    TransportLayer::registerReceiver(mr);
}

void Module3::sendMsg5(int data)
{
    msg5* msg = new msg5();
    msg->data = data;
    std::cout << "Sending msg5: " << msg->data << std::endl;
    ms->sendMsg5(msg);
}

void Module3::sendMsg6(int data)
{
    msg6* msg = new msg6();
    msg->data = data;
    std::cout << "Sending msg6: " << msg->data << std::endl;
    ms->sendMsg6(msg);
}
