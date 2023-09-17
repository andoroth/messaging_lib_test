#pragma once
#include "MsgAdapterBase.h"

class DataStream;
class ReceiveMsg3;
class msg3;
class Msg3Adapter : public MsgAdapterBase
{
    public:
        Msg3Adapter(ReceiveMsg3* msg3Receiver_in);
        virtual void processDataStream(DataStream*);
        static DataStream* createDataStream(msg3*);
        virtual int getId();
    private:
        ReceiveMsg3* msgReceiver;
        static const int id = 3;
};
