#!/usr/bin/bash
cd messageLib
g++ -c *.cpp
ar -rc ../lib/libMessaging.a *.o

cd ../transportService
g++ -c *.cpp
ar -rc ../lib/libTransport.a *.o

cd ../module1
g++ -c *.cpp -I../messageLib -I../transportService/
ar crsT ../lib/libModule1.a ../lib/libMessaging.a ../lib/libTransport.a module1.o

cd ../module2
g++ -c *.cpp -I../messageLib -I../transportService/
ar crsT ../lib/libModule2.a ../lib/libMessaging.a ../lib/libTransport.a module2.o

cd ../module3
g++ -c *.cpp -I../messageLib -I../transportService/
ar crsT ../lib/libModule3.a ../lib/libMessaging.a ../lib/libTransport.a module3.o

cd ../driver
g++ main.cpp -I../inc -L../lib -lModule1 -lModule2 -lModule3
