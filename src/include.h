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
**	Name:		include.h
**	Project:	mNCWidgets
*/

#ifndef MNCWIDGETS_INCLUDE
#define MNCWIDGETS_INCLUDE

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <mutex>

#include <ncurses.h>

#include "../libs/mlog/mlog.h"

#define MLOG_DISABLE 0
#define MLOG_DISABLE_CONSOLE_LOG 0
#define MLOG_DISABLE_FILE_LOG 0

#define MNCW_LOG_FILE "mncwidgets_log.txt"

#define TESTSTDSCR \
	if(mWindow == stdscr) {LOG_F_ERROR(MNCW_LOG_FILE, "IS STDSCR ", mID);} \
	else {LOG_F_ERROR(MNCW_LOG_FILE, "NOT STDSCR: ", mID);} \
	LOG_F_ERROR(MNCW_LOG_FILE, "window id: ", mID, " window ptr: ", mWindow); \
	LOG_F_ERROR(MNCW_LOG_FILE, "window id: ", mID, " stdscr ptr: ", stdscr); \
	LOG_F_ERROR(MNCW_LOG_FILE, "window id: ", mID, " tmpW ptr:   ", tmpW);

#endif // MNCWIDGETS_INCLUDE

