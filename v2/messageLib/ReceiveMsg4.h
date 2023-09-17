#pragma once
#include "messages.h"

class DataStreamReceiverInterface;
class ReceiveMsg4
{
    public:
        ReceiveMsg4(DataStreamReceiverInterface*);
        virtual void receive(msg4 msg) = 0;
};
