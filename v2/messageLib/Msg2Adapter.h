#pragma once
#include "MsgAdapterBase.h"

class DataStream;
class ReceiveMsg2;
class Msg2Adapter : public MsgAdapterBase
{
    public:
        Msg2Adapter(ReceiveMsg2* msg2Receiver_in);
        virtual void processDataStream(DataStream*);
        virtual int getId();
    private:
        ReceiveMsg2* msgReceiver;
};
