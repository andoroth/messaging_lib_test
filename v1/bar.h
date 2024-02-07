#pragma once

#include "messagePasser.h"

class MsgReceiver_Bar : public MsgReceiver {
    public:
        MsgReceiver_Bar();
        virtual void receiveMsg(msg1 msg);
        virtual void receiveMsg(msg2 msg);
};

class Bar {
    public:
        Bar();
        void sendBarMsg1(int val);
        void sendBarMsg2(int val);

    private:
        MessagePasser* mp;
};

