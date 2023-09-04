
#include "foo.h"

#include <iostream>

MsgReceiver_Foo::MsgReceiver_Foo(){};
void MsgReceiver_Foo::receiveMsg(msg1 msg){
    std::cout << "Foo Received msg1: " << msg.data << std::endl;
}
void MsgReceiver_Foo::receiveMsg(msg2 msg){
    std::cout << "Foo Received msg2: " << msg.data << std::endl;
}

Foo::Foo(){
    MsgReceiver_Foo* mr = new MsgReceiver_Foo();
    mp = new MessagePasser(mr);
}
void Foo::sendFooMsg1(int val){
    std::cout << "Foo Sending msg1: " << val << std::endl;
    msg1 msg;
    msg.data = val;
    mp->send(msg);
}
void Foo::sendFooMsg2(int val){
    std::cout << "Foo Sending msg2: " << val << std::endl;
    msg2 msg;
    msg.data = val;
    mp->send(msg);
}


