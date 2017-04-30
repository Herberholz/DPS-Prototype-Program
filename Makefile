#Makefile for CHocAn by Chocoholic Computing

#set up flags
CFLAGS = -std=c++11 -g -Wall 
CC = g++

#build target executable which accounts for all program files in the directory
ChocAn: hashTable.cpp cred.cpp node.cpp reports.cpp clientUI.cpp userMenus.cpp main.cpp profiles.cpp tests.cpp 
		$(CC) -o ChocAn hashTable.cpp cred.cpp node.cpp profiles.cpp reports.cpp clientUI.cpp userMenus.cpp main.cpp tests.cpp  $(CFLAGS) -I/. 

clean: 
	rm ChocAn
