#pragma once
#include <deque>

class DataStream
{
    public:
        DataStream();
        DataStream(std::deque<int>*);
        int peek();
        void push_back(int);
        void pop_front();
        bool has_value();

    private:
        std::deque<int>* data;
};
