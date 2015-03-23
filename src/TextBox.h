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
**	Name:		TextBox.h
**	Project:	mNCWidgets
*/

#ifndef MNC_TEXTBOX_H
#define MNC_TEXTBOX_H

#include "include.h"

namespace mncw{

class TextBox{
public:
	TextBox(const char *id, const char *info = NULL, int x = 0, int y = 0, int contentLen = 12);
	~TextBox();

	int updateAll();
	int clearAll();

	int setInfo(const char *text);
	int setText(const char *text);
	int setPosition(int x, int y);
	int setSize(int s);
	int setColor(int colorPair);
	int setVisible(bool visible);
	int setSelected(bool selected);

	std::string getID();
	void getPosition(int &x, int &y);
	int getMaxSize();
	bool getVisible();
	bool getSelected();

	std::string getContent();

	bool cmpID(const char *id);

private:
	int setTarget(WINDOW *target);

	std::string mID;
	std::string mInfo;
	std::string mContent;
	int mX, mY, mLen;
	int mColorPair;
	bool mVisible;
	bool mChanged;
	bool mSelected;

	WINDOW *mTarget;

	friend class Window;
};

} // mncw

#endif // MNC_TEXTBOX_H
