#pragma once

namespace mod1{
class MsgSender;
class MsgReceiver;
class Module1
{
    public:
        Module1();
        void sendMsg1(int);
        void sendMsg2(int);
    private:
        MsgSender* ms;
        MsgReceiver* mr;
};
}

