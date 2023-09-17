#pragma once

class MsgSender;
class MsgReceiver;

namespace mod3{
class Module3
{
    public:
        Module3();
        void sendMsg5(int);
        void sendMsg6(int);
    private:
        MsgSender* ms;
        MsgReceiver* mr;
};
}

