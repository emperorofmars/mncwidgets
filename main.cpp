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
	//mncw::Window win("root", 2, 3, 4, 5, NULL);
	mncw::Window win("root");
	LOG_F_ERROR(MNCW_LOG_FILE, "INITED!");
	win.setSize(5, 5);
	LOG_F_ERROR(MNCW_LOG_FILE, "SET SIZE!");
	win.setColor(COLOR_BLUE, COLOR_YELLOW);
	win.refreshAll();
	LOG_F_ERROR(MNCW_LOG_FILE, "SET COLOR!");
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	LOG_F_ERROR(MNCW_LOG_FILE, "EXIT!");
	return 0;
}
