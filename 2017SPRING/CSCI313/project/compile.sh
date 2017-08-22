#!/bin/bash

c++ master.cpp -o master
	
c++ -o checkOut checkOut.cpp $(mysql_config --libs)

c++ -o cancel cancel.cpp $(mysql_config --libs)
	
c++ -o reservation reservation.cpp $(mysql_config --libs)
	
