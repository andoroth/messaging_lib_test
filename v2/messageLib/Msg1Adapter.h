#pragma once
#include "MsgAdapterBase.h"

class DataStream;
class ReceiveMsg1;
class Msg1Adapter : public MsgAdapterBase
{
    public:
        Msg1Adapter(ReceiveMsg1* msg1Receiver_in);
        virtual void processDataStream(DataStream*);
        virtual int getId();
    private:
        ReceiveMsg1* msgReceiver;
};
