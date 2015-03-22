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
**	Name:		Window.cpp
**	Project:	mNCWidgets
*/

#include "Window.h"

namespace mncw{

bool Window::mNCInited = false;
int Window::mInstances = 0;

Window::Window(const char *id){
	mWindow = NULL;
	if(id != NULL) mID = id;
	if(!mNCInited){
		initNC(this);
	}
	mInstances++;
	LOG_F_TRACE(MNCW_LOG_FILE, "Window created: ", mID);
}

Window::~Window(){
	mInstances--;
	if(mNCInited && mInstances <= 0){
		closeNC(this);
	}
	LOG_F_TRACE(MNCW_LOG_FILE, "Window destroyed: ", mID);
}

int Window::refreshAll(){
	refresh();
	for(unsigned int i = 0; i < mElements.mWindows.size(); i++){
		mElements.mWindows[i]->refreshAll();
	}
	for(unsigned int i = 0; i < mElements.mLabels.size(); i++){
		mElements.mLabels[i]->refreshAll();
	}
	return 0;
}

int Window::clearAll(){
	clear();
	for(unsigned int i = 0; i < mElements.mWindows.size(); i++){
		mElements.mWindows[i]->clearAll();
	}
	for(unsigned int i = 0; i < mElements.mLabels.size(); i++){
		mElements.mLabels[i]->clearAll();
	}
	return 0;
}

int Window::setPosition(int x, int y){
	if(mWindow == stdscr){
		LOG_F_WARNING(MNCW_LOG_FILE, "cannot move stdscr: ", mID);
		return -1;
	}
	//do stuff
	return 0;
}

int Window::setSize(int x, int y){
	if(mWindow == stdscr){
		LOG_F_WARNING(MNCW_LOG_FILE, "cannot move stdscr: ", mID);
		return -1;
	}
	//do stuff
	return 0;
}

void Window::getPosition(int &x, int &y){
	x = mX;
	y = mY;
	return;
}

void Window::getSize(int &w, int &h){
	w = mW;
	h = mH;
	return;
}

int Window::addLabel(Label *label){
	return -1;
}

//int Window::addTextBox(TextBox *textBox);
//int Window::addCheckBox(CheckBox *checkBox);
//int Window::addRadioButton(RadioButton *radioButton);
//int Window::addButton(Button *button);
//int Window::addProgressBar(ProgressBar *progressBar);

int Window::addWindow(Window *window){
	return -1;
}

Label *Window::getLabel(const char *id){
	return NULL;
}

//TextBox *Window::getTextBox(const char *id);
//CheckBox *Window::getCheckBox(const char *id);
//RadioButton *Window::getRadioButton(const char *id);
//Button *Window::getButton(const char id);
//ProgressBar *Window::getProgressBar(const char *id);

Window *Window::getWindow(const char *id){
	return NULL;
}

int Window::initNC(Window *win){
	if(!win){
		LOG_F_ERROR(MNCW_LOG_FILE, "Failed to init NCurses! (window is null)");
		return -1;
	}

	LOG_ALL.setLogLevel(-1, 4);

	win->mWindow = initscr();
	if(!win->mWindow){
		LOG_F_ERROR(MNCW_LOG_FILE, "Failed to init NCurses! (initscr returned null)");
		return -1;
	}
	cbreak();
	keypad(win->mWindow, TRUE);
	curs_set(0);
	noecho();

	mNCInited = true;
	LOG_F_INFO(MNCW_LOG_FILE, "NCurses inited");
	return 0;
}

int Window::closeNC(Window *win){
	if(!win){
		LOG_F_ERROR(MNCW_LOG_FILE, "Failed to close NCurses! (window is null)");
		return -1;
	}

	if(!mNCInited){
		LOG_F_ERROR(MNCW_LOG_FILE, "Failed to close NCurses! (not inited)");
		return -1;
	}
	nocbreak();
	echo();
	endwin();

	mNCInited = false;
	LOG_F_INFO(MNCW_LOG_FILE, "NCurses closed");
	return 0;
}

} // mncw




