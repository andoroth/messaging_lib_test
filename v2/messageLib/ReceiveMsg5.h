#pragma once
#include "messages.h"

class DataStreamReceiverInterface;
class ReceiveMsg5
{
    public:
        ReceiveMsg5(DataStreamReceiverInterface*);
        virtual void receive(msg5 msg) = 0;
};
