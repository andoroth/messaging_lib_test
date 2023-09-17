#pragma once
#include "messages.h"

class DataStreamReceiverInterface;
class ReceiveMsg3
{
    public:
        ReceiveMsg3(DataStreamReceiverInterface*);
        virtual void receive(msg3 msg) = 0;
};
