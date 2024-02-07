#pragma once

#include <iostream>

class DataStreamReceiver;
class TransportLayer {
    public:
        static void broadcast(DataStreamReceiver* sender, int* dataStream);
        static void registerReceiver(DataStreamReceiver* receiver);
        static DataStreamReceiver* receiver_list[4];
        static int receiver_count;
};
