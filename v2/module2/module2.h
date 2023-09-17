#pragma once

namespace mod2{
class MsgSender;
class MsgReceiver;
class Module2
{
    public:
        Module2();
        void sendMsg3(int);
        void sendMsg4(int);
    private:
        MsgSender* ms;
        MsgReceiver* mr;
};
}


