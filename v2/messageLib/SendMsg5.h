#pragma once
#include "messages.h"

class DataStreamSenderInterface;
class SendMsg5
{
    public:
        SendMsg5(DataStreamSenderInterface*);
        void sendMsg5(msg5* msg);
    private:
        SendMsg5() = delete;
        DataStreamSenderInterface* dataSender;
};
