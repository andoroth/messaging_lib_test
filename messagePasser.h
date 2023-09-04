#pragma once
#include "messages.h"
#include "dataStreamReceiver.h"

class MsgReceiver {
    public:
        virtual void receiveMsg(msg1 msg) = 0;
        virtual void receiveMsg(msg2 msg) = 0;
};

class MessagePasser : public DataStreamReceiver {
    public:
        MessagePasser(MsgReceiver* mr_in);
        virtual void receiveDataStream(int* dataStream);
        void send(msg1 msg);
        void send(msg2 msg);
    private:
        MsgReceiver* mr;
};
