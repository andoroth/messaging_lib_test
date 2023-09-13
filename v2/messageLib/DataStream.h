#pragma once
#include <deque>

class DataStream
{
    public:
        DataStream();
        int peek();
        void push_back(int);
        void pop_front();

    private:
        std::deque<int>data;
};
