#pragma once
#include "MsgAdapterBase.h"

class DataStream;
class ReceiveMsg6;
class msg6;
class Msg6Adapter : public MsgAdapterBase
{
    public:
        Msg6Adapter(ReceiveMsg6* msg6Receiver_in);
        virtual void processDataStream(DataStream*);
        static DataStream* createDataStream(msg6*);
        virtual int getId();
    private:
        ReceiveMsg6* msgReceiver;
        static const int id = 6;
};
