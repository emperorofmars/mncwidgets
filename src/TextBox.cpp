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
**	Name:		TextBox.cpp
**	Project:	mNCWidgets
*/

#include "TextBox.h"

namespace mncw{

TextBox::TextBox(const char *id, const char *info, int x, int y, int contentLen){
	if(!id){
		return;
	}
	mID = id;
	if(info){
		mInfo = info;
	}
	mX = x;
	mY = y;
	mLen = contentLen;
	mColorPair = 0;
	mChanged = true;
	mVisible = true;
	mSelected = false;

	LOG_F_TRACE(MNCW_LOG_FILE, "TextBox created: ", mID, " len: ", mLen, " info: ", mInfo);
}

TextBox::~TextBox(){
}

int TextBox::updateAll(){
	if(!mTarget){
		return -1;
	}
	if(!mChanged || !mVisible || mLen == 0){
		return -1;
	}
	int tmpLen = mLen;
	if(tmpLen < 0) tmpLen = mContent.size();

	if(has_colors()){
		if(mColorPair > 0) color_set(mColorPair, 0);
	}
	int tmpPos = mX;
	if(mInfo.size() > 0){
		mvwaddstr(mTarget, mY, mX, mInfo.c_str());
		tmpPos += mInfo.size();
	}

	if(mSelected) mvwaddstr(mTarget, mY, tmpPos, "<[");
	else mvwaddstr(mTarget, mY, tmpPos, " [");
	tmpPos += 2;

	if(mContent.size() > 0){
		mvwaddstr(mTarget, mY, tmpPos, mContent.c_str());
		tmpPos += mContent.size();
	}

	if(mSelected) mvwaddstr(mTarget, mY, tmpPos, "]>");
	else mvwaddstr(mTarget, mY, tmpPos, "] ");

	mChanged = false;
	return 0;
}

int TextBox::clearAll(){
	if(!mTarget){
		return -1;
	}
	std::string clr(mLen, ' ');
	waddstr(mTarget, clr.c_str());
	return 0;
}

int TextBox::setTarget(WINDOW *target){
	if(!mTarget){
		return -1;
	}
	mTarget = target;
	mChanged = true;
	return 0;
}

int TextBox::setInfo(const char *text){
	if(!mTarget){
		return -1;
	}
	mInfo = text;
	mChanged = true;
	return 0;
}

int TextBox::setText(const char *text){
	if(!mTarget){
		return -1;
	}
	mContent = text;
	mChanged = true;
	return 0;
}

int TextBox::setPosition(int x, int y){
	mX = x;
	mY = y;
	mChanged = true;
	return 0;
}

int TextBox::setSize(int s){
	mLen = s;
	mChanged = true;
	return 0;
}

int TextBox::setColor(int colorPair){
	mColorPair = colorPair;
	mChanged = true;
	return 0;
}

int TextBox::setVisible(bool visible){
	if(mVisible && !visible){
		clearAll();
	}
	else if(!mVisible && visible){
		mChanged = true;
	}
	mVisible = visible;
	return 0;
}

int TextBox::setSelected(bool selected){
	mSelected = selected;
	mChanged = true;
	return 0;
}

std::string TextBox::getContent(){
	return mContent;
}

std::string TextBox::getID(){
	return mID;
}

void TextBox::getPosition(int &x, int &y){
	x = mX;
	y = mY;
	return;
}

int TextBox::getMaxSize(){
	return mLen;
}

bool TextBox::getVisible(){
	return mVisible;
}

bool TextBox::getSelected(){
	return mSelected;
}

bool TextBox::cmpID(const char *id){
	if(!id) return false;
	if(std::string(id) == mID) return true;
	return false;
}

} // mncw




