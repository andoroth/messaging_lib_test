
#include "bar.h"

#include <iostream>

MsgReceiver_Bar::MsgReceiver_Bar(){};
void MsgReceiver_Bar::receiveMsg(msg1 msg){
    std::cout << "Bar Received msg1: " << msg.data << std::endl;
}
void MsgReceiver_Bar::receiveMsg(msg2 msg){
    std::cout << "Bar Received msg2: " << msg.data << std::endl;
}

Bar::Bar(){
    MsgReceiver_Bar* mr = new MsgReceiver_Bar();
    mp = new MessagePasser(mr);
}
void Bar::sendBarMsg1(int val){
    std::cout << "Bar Sending msg1: " << val << std::endl;
    msg1 msg;
    msg.data = val;
    mp->send(msg);
}
void Bar::sendBarMsg2(int val){
    std::cout << "Bar Sending msg2: " << val << std::endl;
    msg2 msg;
    msg.data = val;
    mp->send(msg);
}
