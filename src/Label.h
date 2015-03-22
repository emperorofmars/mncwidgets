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
	Label(const char *id);
	Label(const char *id, WINDOW *target);
	~Label();

	int refresh();
	int clear();

	int setTarget(WINDOW *target);
	int setText(const char *text);
	int setPosition(int x, int y);
	int setMaxSize(int s);

	std::string getText();
	std::string getID();
	void getPosition(int *x, int *y);
	int getMaxSize();

	bool cmpID(std::string &id);

private:
	std::string mID;

	WINDOW *mTarget;
};

} // mncw

#endif // MNC_LABEL_H