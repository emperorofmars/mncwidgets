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

Window::Window(const char *id, int x, int y, int h, int w, WINDOW *parent){
	mWindow = NULL;
	if(id != NULL) mID = id;
	if(!mNCInited){
		initNC(this);
	}
	else{
		LOG_F_ERROR(MNCW_LOG_FILE, "NEW WIN", mID);
		if(!parent)	mWindow = newwin(h, w, y, x);
		else mWindow = derwin(parent, h, w, y, x);
		if(mWindow == NULL){
			LOG_F_ERROR(MNCW_LOG_FILE, "Window creation failed: ", mID);
			return;
		}
		mX = x;
		mY = y;
		mW = w;
		mH = h;
	}
	if(mWindow)	keypad(mWindow, TRUE);
	mColorPair = 0;

	mInstances++;
	LOG_F_TRACE(MNCW_LOG_FILE, "Window created: ", mID, " ptr: ", mWindow);
}

Window::~Window(){
	if(mWindow){
		for(unsigned int i = 0; i < mElements.mWindows.size(); i++){
			mElements.mWindows.erase(mElements.mWindows.begin() + i);
			i--;
		}
	}
	mInstances--;
	if(mNCInited && mInstances <= 0){
		closeNC(this);
	}
	else{
		if(mWindow){
			delwin(mWindow);
			mWindow = NULL;
		}
		else LOG_F_ERROR(MNCW_LOG_FILE, "Window destruction failed (not created): ", mID);
	}
	LOG_F_TRACE(MNCW_LOG_FILE, "Window destroyed: ", mID);
}

int Window::refreshAll(){
	if(!mWindow){
		return -1;
	}
	wnoutrefresh(mWindow);
	for(unsigned int i = 0; i < mElements.mWindows.size(); i++){
		mElements.mWindows[i]->refreshAll();
	}
	for(unsigned int i = 0; i < mElements.mLabels.size(); i++){
		mElements.mLabels[i]->updateAll();
	}
	wrefresh(mWindow);
	return 0;
}

int Window::clearAll(){
	if(!mWindow){
		return -1;
	}
	wclear(mWindow);
	for(unsigned int i = 0; i < mElements.mWindows.size(); i++){
		mElements.mWindows[i]->clearAll();
	}
	for(unsigned int i = 0; i < mElements.mLabels.size(); i++){
		mElements.mLabels[i]->clearAll();
	}
	return 0;
}

int Window::setPosition(int x, int y){
	if(!mWindow){
		return -1;
	}
	if(mWindow == stdscr){
		LOG_F_WARNING(MNCW_LOG_FILE, "cannot set position of stdscr: ", mID);
		return -1;
	}
	mX = x;
	mY = y;
	wmove(mWindow, y, x);
	return 0;
}

int Window::setSize(int h, int w){
	if(!mWindow){
		return -1;
	}
	if(mWindow == stdscr){
		LOG_F_WARNING(MNCW_LOG_FILE, "cannot resize stdscr: ", mID);
		return -1;
	}
	if(h <= 0 || w <= 0){
		LOG_F_WARNING(MNCW_LOG_FILE, "cannot resize window (new size too small): ", mID);
		return -1;
	}
	mH = h;
	mW = w;
	wresize(mWindow, h, w);
	return 0;
}

int Window::setColor(int colorPair){
	if(!mWindow){
		return -1;
	}
	if(!has_colors()){
		LOG_F_WARNING(MNCW_LOG_FILE, "no colors supported: ", mID);
		return -1;
	}
	mColorPair = colorPair;
	wbkgd(mWindow, COLOR_PAIR(colorPair));
	LOG_F_WARNING(MNCW_LOG_FILE, "color pair set: ", mID, " pair: ", colorPair);
	return 0;
}

void Window::getPosition(int &x, int &y){
	x = mX;
	y = mY;
	return;
}

void Window::getSize(int &h, int &w){
	h = mH;
	w = mW;
	return;
}

int Window::addLabel(Label *label){
	if(!mWindow){
		return -1;
	}
	if(!label){
		LOG_F_WARNING(MNCW_LOG_FILE, "cannot add label: (label is null): ", mID);
		return -1;
	}
	label->setTarget(mWindow);
	label->setColor(mColorPair);
	mElements.mLabels.push_back(std::shared_ptr<Label>(label));
	return 0;
}

//int Window::addTextBox(TextBox *textBox);
//int Window::addCheckBox(CheckBox *checkBox);
//int Window::addRadioButton(RadioButton *radioButton);
//int Window::addButton(Button *button);
//int Window::addProgressBar(ProgressBar *progressBar);

int Window::addWindow(Window *window){
	if(!mWindow){
		return -1;
	}
	if(!window){
		LOG_F_WARNING(MNCW_LOG_FILE, "cannot add window: (window is null): ", mID);
		return -1;
	}
	if(window->mWindow == stdscr){
		LOG_F_WARNING(MNCW_LOG_FILE, "cannot add stdscr to another window: ", mID);
		return -1;
	}
	mElements.mWindows.push_back(std::shared_ptr<Window>(window));
	return 0;
}

Label *Window::getLabel(const char *id){
	if(!mWindow){
		return NULL;
	}
	for(unsigned int i = 0; i < mElements.mLabels.size(); i++){
		if(mElements.mLabels[i] && mElements.mLabels[i]->cmpID(id)) return mElements.mLabels[i].get();
	}
	return NULL;
}

//TextBox *Window::getTextBox(const char *id);
//CheckBox *Window::getCheckBox(const char *id);
//RadioButton *Window::getRadioButton(const char *id);
//Button *Window::getButton(const char id);
//ProgressBar *Window::getProgressBar(const char *id);

Window *Window::getWindow(const char *id){
	if(!mWindow){
		return NULL;
	}
	for(unsigned int i = 0; i < mElements.mWindows.size(); i++){
		if(mElements.mWindows[i] && mElements.mWindows[i]->cmpID(id)) return mElements.mWindows[i].get();
	}
	return NULL;
}

bool Window::cmpID(const char *id){
	if(!id) return false;
	if(std::string(id) == mID) return true;
	return false;
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
	curs_set(0);
	noecho();
	if(has_colors()) start_color();
	else LOG_F_INFO(MNCW_LOG_FILE, "Colors not supported!");
	clear();

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




