#pragma once
#include "messages.h"

class ReceiveMsg3
{
    public:
        ReceiveMsg3();
        virtual void receive(msg3 msg) = 0;
};
