#pragma once

#include "messagePasser.h"

class MsgReceiver_Foo : public MsgReceiver {
    public:
        MsgReceiver_Foo();
        virtual void receiveMsg(msg1 msg);
        virtual void receiveMsg(msg2 msg);
};

class Foo {
    public:
        Foo();
        void sendFooMsg1(int val);
        void sendFooMsg2(int val);

    private:
        MessagePasser* mp;
};

