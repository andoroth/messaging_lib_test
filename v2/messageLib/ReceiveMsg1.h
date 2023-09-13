#pragma once
#include "messages.h"

class ReceiveMsg1
{
    public:
        ReceiveMsg1();
        virtual void receive(msg1 msg) = 0;
};
