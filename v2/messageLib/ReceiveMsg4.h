#pragma once
#include "messages.h"

class ReceiveMsg4
{
    public:
        ReceiveMsg4();
        virtual void receive(msg4 msg) = 0;
};
