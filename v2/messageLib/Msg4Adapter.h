#pragma once
#include "MsgAdapterBase.h"

class DataStream;
class ReceiveMsg4;
class msg4;
class Msg4Adapter : public MsgAdapterBase
{
    public:
        Msg4Adapter(ReceiveMsg4* msg4Receiver_in);
        virtual void processDataStream(DataStream*);
        static DataStream* createDataStream(msg4*);
        virtual int getId();
    private:
        ReceiveMsg4* msgReceiver;
        static const int id = 4;
};
