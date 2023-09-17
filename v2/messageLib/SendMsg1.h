#pragma once
#include "messages.h"

class DataStreamSenderInterface;
class SendMsg1
{
    public:
        SendMsg1(DataStreamSenderInterface*);
        void sendMsg1(msg1* msg);
    private:
        SendMsg1() = delete;
        DataStreamSenderInterface* dataSender;
};
