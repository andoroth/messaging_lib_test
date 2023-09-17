#include "MsgAdapterBase.h"

#include "DataStream.h"

int MsgAdapterBase::getHeader(DataStream* data)
{
    return data->peek();
}

void MsgAdapterBase::writeHeader(int id, DataStream* data)
{
    data->push_back(id);
}
