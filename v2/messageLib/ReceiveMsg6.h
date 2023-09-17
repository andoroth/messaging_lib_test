#pragma once
#include "messages.h"

class ReceiveMsg6
{
    public:
        ReceiveMsg6();
        virtual void receive(msg6 msg) = 0;
};
