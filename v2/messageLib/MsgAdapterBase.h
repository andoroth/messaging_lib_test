#pragma once

class DataStream;
class MsgAdapterBase
{
    public:
        static int getHeader(DataStream*);
        virtual void processDataStream(DataStream*) = 0;
        virtual int getId() = 0;
};

