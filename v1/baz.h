#pragma once

#include "messagePasser.h"

class MsgReceiver_Baz : public MsgReceiver {
    public:
        MsgReceiver_Baz();
        virtual void receiveMsg(msg1 msg);
        virtual void receiveMsg(msg2 msg);
};

class Baz {
    public:
        Baz();
        void sendBazMsg1(int val);
        void sendBazMsg2(int val);

    private:
        MessagePasser* mp;
};

