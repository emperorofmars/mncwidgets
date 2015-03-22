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
	win.setSize(5, 5);

	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);

	win.setColor(1);

	win.addLabel(new mncw::Label("label1", "MNCWIDGETS", 20, 3, 5));

	win.addWindow(new mncw::Window("sub", 10, 6));
	mncw::Window *tmp = win.getWindow("sub");
	if(tmp != NULL) tmp->setColor(2);
	else LOG_F_ERROR(MNCW_LOG_FILE, "GET WINDOW RETURNED NULL");

	win.refreshAll();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 0;
}
