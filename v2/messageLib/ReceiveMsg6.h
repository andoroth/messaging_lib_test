#pragma once
#include "messages.h"

class DataStreamReceiverInterface;
class ReceiveMsg6
{
    public:
        ReceiveMsg6(DataStreamReceiverInterface*);
        virtual void receive(msg6 msg) = 0;
};
