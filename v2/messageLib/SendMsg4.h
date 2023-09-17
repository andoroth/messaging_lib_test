#pragma once
#include "messages.h"

class DataStreamSenderInterface;
class SendMsg4
{
    public:
        SendMsg4(DataStreamSenderInterface*);
        void sendMsg4(msg4* msg);
    private:
        SendMsg4() = delete;
        DataStreamSenderInterface* dataSender;
};
