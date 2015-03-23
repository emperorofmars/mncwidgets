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
**	Name:		util.cpp
**	Project:	mNCWidgets
*/

#include "util.h"

namespace mncw{

int enableColor(){
	if(!isendwin()){
		if(has_colors()){
			start_color();
			LOG_F_TRACE(MNCW_LOG_FILE, "Colors enabled!");
			return 0;
		}
		else{
			LOG_F_INFO(MNCW_LOG_FILE, "Colors not supported!");
			return -1;
		}
	}
	else LOG_F_WARNING(MNCW_LOG_FILE, "ncurses not inited");
	return -1;
}

} // mncw




