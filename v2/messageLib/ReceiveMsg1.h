#pragma once
#include "messages.h"

class DataStreamReceiverInterface;
class ReceiveMsg1
{
    public:
        ReceiveMsg1(DataStreamReceiverInterface*);
        virtual void receive(msg1 msg) = 0;
};
