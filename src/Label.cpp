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
**	Name:		Label.cpp
**	Project:	mNCWidgets
*/

#include "Label.h"

namespace mncw{

Label::Label(const char *id, const char *content, int x, int y, int len){
	if(!id){
		return;
	}
	mID = id;
	if(content){
		mContent = content;
	}
	mX = x;
	mY = y;
	mLen = len;
	mColorPair = 0;
	mChanged = true;
	mVisible = true;

	LOG_F_TRACE(MNCW_LOG_FILE, "Label created: ", mID, " len: ", mLen, " content: ", mContent);
}

Label::~Label(){
}

int Label::updateAll(){
	if(!mTarget){
		return -1;
	}
	if(!mChanged || !mVisible){
		return -1;
	}
	int tmpLen = mContent.size() - 1;
	if(tmpLen <= 0){
		return -1;
	}
	else if(tmpLen > mLen) tmpLen = mLen;

	if(has_colors()){
		if(mColorPair > 0) color_set(mColorPair, 0);
	}
	mvwaddstr(mTarget, mY, mX, mContent.substr(0, tmpLen).c_str());

	mChanged = false;
	return 0;
}

int Label::clearAll(){
	if(!mTarget){
		return -1;
	}
	std::string clr(mLen, ' ');
	waddstr(mTarget, clr.c_str());
	return 0;
}

int Label::setTarget(WINDOW *target){
	if(!mTarget){
		return -1;
	}
	mTarget = target;
	mChanged = true;
	return 0;
}

int Label::setText(const char *text){
	if(!mTarget){
		return -1;
	}
	mContent = text;
	mChanged = true;
	return 0;
}

int Label::setPosition(int x, int y){
	mX = x;
	mY = y;
	mChanged = true;
	return 0;
}

int Label::setMaxSize(int s){
	mLen = s;
	mChanged = true;
	return 0;
}

int Label::setColor(int colorPair){
	mColorPair = colorPair;
	mChanged = true;
	return 0;
}

int Label::setVisible(bool visible){
	if(mVisible && !visible){
		clearAll();
	}
	else if(!mVisible && visible){
		mChanged = true;
	}
	mVisible = visible;
	return 0;
}

std::string Label::getText(){
	return mContent;
}

std::string Label::getID(){
	return mID;
}

void Label::getPosition(int &x, int &y){
	x = mX;
	y = mY;
	return;
}

int Label::getMaxSize(){
	return mLen;
}

bool Label::getVisible(){
	return mVisible;
}

bool Label::cmpID(const char *id){
	if(!id) return false;
	if(std::string(id) == mID) return true;
	return false;
}

} // mncw




