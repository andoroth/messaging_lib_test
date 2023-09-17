#pragma once
#include "messages.h"

class ReceiveMsg5
{
    public:
        ReceiveMsg5();
        virtual void receive(msg5 msg) = 0;
};
