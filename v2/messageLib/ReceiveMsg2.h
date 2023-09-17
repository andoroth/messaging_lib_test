#pragma once
#include "messages.h"

class DataStreamReceiverInterface;
class ReceiveMsg2
{
    public:
        ReceiveMsg2(DataStreamReceiverInterface*);
        virtual void receive(msg2 msg) = 0;
};
