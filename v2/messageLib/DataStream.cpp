#include "DataStream.h"

DataStream::DataStream()
{
    data = {};
}

int DataStream::peek()
{
    return data.front();
}

void DataStream::push_back(int val)
{
    data.push_back(val);
}

void DataStream::pop_front()
{
    if (!data.empty()) data.pop_front();
}
