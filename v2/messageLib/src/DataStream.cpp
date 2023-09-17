#include "DataStream.h"

DataStream::DataStream()
{
    data = new std::deque<int>{};
}

DataStream::DataStream(std::deque<int>* data_in)
{
    data = data_in;
}

int DataStream::peek()
{
    return data->front();
}

void DataStream::push_back(int val)
{
    data->push_back(val);
}

void DataStream::pop_front()
{
    if (!data->empty()) data->pop_front();
}

bool DataStream::has_value()
{
    return !data->empty();
}
