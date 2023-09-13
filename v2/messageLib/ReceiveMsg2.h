#pragma once
#include "messages.h"

class ReceiveMsg2
{
    public:
        ReceiveMsg2();
        virtual void receive(msg2 msg) = 0;
};
