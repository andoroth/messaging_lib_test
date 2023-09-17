#pragma once
#include "messages.h"

class DataStreamSenderInterface;
class SendMsg6
{
    public:
        SendMsg6(DataStreamSenderInterface*);
        void sendMsg6(msg6* msg);
    private:
        SendMsg6() = delete;
        DataStreamSenderInterface* dataSender;
};
