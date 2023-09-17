#pragma once
#include "MsgAdapterBase.h"

class DataStream;
class ReceiveMsg1;
class msg1;
class Msg1Adapter : public MsgAdapterBase
{
    public:
        Msg1Adapter(ReceiveMsg1* msg1Receiver_in);
        virtual void processDataStream(DataStream*);
        static DataStream* createDataStream(msg1*);
        virtual int getId();
    private:
        ReceiveMsg1* msgReceiver;
        static const int id = 1;
};
