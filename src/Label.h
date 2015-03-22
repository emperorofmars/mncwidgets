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
**	Name:		Label.h
**	Project:	mNCWidgets
*/

#ifndef MNC_LABEL_H
#define MNC_LABEL_H

#include "include.h"

namespace mncw{

class Label{
public:
	Label(const char *id, const char *content = NULL, int x = 0, int y = 0, int len = -1);
	~Label();

	int updateAll();
	int clearAll();

	int setText(const char *text);
	int setPosition(int x, int y);
	int setMaxSize(int s);
	int setColor(int colorPair);
	int setVisible(bool visible);

	std::string getText();
	std::string getID();
	void getPosition(int &x, int &y);
	int getMaxSize();
	bool getVisible();

	bool cmpID(const char *id);

private:
	int setTarget(WINDOW *target);

	std::string mID;
	std::string mContent;
	int mX, mY, mLen;
	int mColorPair;
	bool mVisible;
	bool mChanged;

	WINDOW *mTarget;

	friend class Window;
};

} // mncw

#endif // MNC_LABEL_H
