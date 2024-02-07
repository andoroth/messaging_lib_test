
#include "baz.h"

#include <iostream>

MsgReceiver_Baz::MsgReceiver_Baz(){};
void MsgReceiver_Baz::receiveMsg(msg1 msg){
    std::cout << "Baz Received msg1: " << msg.data << std::endl;
}
void MsgReceiver_Baz::receiveMsg(msg2 msg){
    std::cout << "Baz Received msg2: " << msg.data << std::endl;
}

Baz::Baz(){
    MsgReceiver_Baz* mr = new MsgReceiver_Baz();
    mp = new MessagePasser(mr);
}
void Baz::sendBazMsg1(int val){
    std::cout << "Baz Sending msg1: " << val << std::endl;
    msg1 msg;
    msg.data = val;
    mp->send(msg);
}
void Baz::sendBazMsg2(int val){
    std::cout << "Baz Sending msg2: " << val << std::endl;
    msg2 msg;
    msg.data = val;
    mp->send(msg);
}


