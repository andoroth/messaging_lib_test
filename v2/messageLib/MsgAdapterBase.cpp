#include "MsgAdapterBase.h"

#include "DataStream.h"

int MsgAdapterBase::getHeader(DataStream* data)
{
    return data->peek();
}
