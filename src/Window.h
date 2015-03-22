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
**	Name:		Wondow.h
**	Project:	mNCWidgets
*/

#ifndef MNC_WINDOW_H
#define MNC_WINDOW_H

#include "include.h"
#include "Label.h"
//#include "TextBox.h"
//#include "CheckBox.h"
//#include "RadioButton.h"
//#include "Button.h"
//#include "ProgressBar.h"

namespace mncw{

class Window{
public:
	Window(const char *id, int x = 0, int y = 0, int h = 6, int w = 20, WINDOW *parent = NULL);
	~Window();

	int refreshAll();
	int clearAll();

	int setPosition(int x, int y);
	int setSize(int h, int w);

	void getPosition(int &x, int &y);
	void getSize(int &h, int &w);
	int setColor(char colorF, char colorB);

	int addLabel(Label *label);
	//int addTextBox(TextBox *textBox);
	//int addCheckBox(CheckBox *checkBox);
	//int addRadioButton(RadioButton *radioButton);
	//int addButton(Button *button);
	//int addProgressBar(ProgressBar *progressBar);
	int addWindow(Window *window);

	Label *getLabel(const char *id);
	//TextBox *getTextBox(const char *id);
	//CheckBox *getCheckBox(const char *id);
	//RadioButton *getRadioButton(const char *id);
	//Button *getButton(const char id);
	//ProgressBar *getProgressBar(const char *id);
	Window *getWindow(const char *id);

private:
	static int initNC(Window *win);
	static int closeNC(Window *win);

	int updateAll();

	struct elements{
		std::vector<std::shared_ptr<Label>> mLabels;
		//std::vector<std::shared_ptr<TextBox>> mTextBox;
		//std::vector<std::shared_ptr<CheckBox>> mCheckBox;
		//std::vector<std::shared_ptr<RadioButton>> mRadioButton;
		//std::vector<std::shared_ptr<Button>> mButton;
		//std::vector<std::shared_ptr<ProgressBar>> mProgressBar;
		std::vector<std::shared_ptr<Window>> mWindows;
	};
	elements mElements;

	WINDOW *mWindow;
	WINDOW *tmpW;
	std::string mID;
	int mX, mY, mW, mH;
	int mColorF, mColorB;

	static bool mNCInited;
	static int mInstances;
};

} // mncw

#endif // MNC_WINDOW_H
