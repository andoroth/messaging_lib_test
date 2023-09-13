#include "DataStreamReceiver.h"
#include "ReceiveMsg1.h"
#include "ReceiveMsg2.h"
#include "messages.h"

#include "DataStream.h"

#include <iostream>

class MsgReceiver : 
    public DataStreamReceiver,
    public ReceiveMsg1,
    public ReceiveMsg2
{
    public:
        MsgReceiver(){};
        virtual void receive(msg1 msg);
        virtual void receive(msg2 msg);
};

void MsgReceiver::receive(msg1 msg) 
{
    std::cout << "Receive msg1: " << msg.data << std::endl;
}

void MsgReceiver::receive(msg2 msg) 
{
    std::cout << "Receive msg2: " << msg.data << std::endl;
}

int main(int argc, char *argv[]) {
    MsgReceiver* mr = new MsgReceiver();
    DataStream* dat = new DataStream();
    dat->push_back(1);
    dat->push_back(4);
    mr->processDataStream(dat);
    delete dat;
    dat = new DataStream();
    dat->push_back(2);
    dat->push_back(8);
    mr->processDataStream(dat);
}
