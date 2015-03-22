/*
** Copyright (C) 2015 Martin Schwarz - All Rights Reserved
** You may use, distribute and modify this code under the
** terms of the Mozilla Public License 2.0.
**
** You should have received a copy of the Mozilla Public License 2.0 with
** this file. If not, please write to: martin.schwarz10@gmail.com
*/

/*
**	Author:		Martin Schwarz
**	Name:		main.cpp
**	Project:	mNCWidgets
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "src/mNCWidgets.h"

int main(){
	LOG_INIT("log.txt", false);
    mncw::Window win("root");
    win.setPosition(5, 5);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 0;
}
