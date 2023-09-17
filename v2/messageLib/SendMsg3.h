#pragma once
#include "messages.h"

class DataStreamSenderInterface;
class SendMsg3
{
    public:
        SendMsg3(DataStreamSenderInterface*);
        void sendMsg3(msg3* msg);
    private:
        SendMsg3() = delete;
        DataStreamSenderInterface* dataSender;
};
