#pragma once
#include "messages.h"

class DataStreamSenderInterface;
class SendMsg2
{
    public:
        SendMsg2(DataStreamSenderInterface*);
        void sendMsg2(msg2* msg);
    private:
        SendMsg2() = delete;
        DataStreamSenderInterface* dataSender;
};
