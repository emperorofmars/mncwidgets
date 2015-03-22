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

Label::Label(const char *id){
}

Label::Label(WINDOW *target, const char *id){
}

Label::Label(const char *content, int colorF, int colorB, WINDOW *target, const char *id){
}

Label::~Label(){
}

int Label::refreshAll(){
	return -1;
}

int Label::clearAll(){
	return -1;
}

int Label::setTarget(WINDOW *target){
	return -1;
}

int Label::setText(const char *text){
	return -1;
}

int Label::setPosition(int x, int y){
	return -1;
}

int Label::setMaxSize(int s){
	return -1;
}

int Label::setColor(char colorF, char colorB){
	return -1;
}

int Label::setVisible(bool visible){
	return -1;
}

std::string Label::getText(){
	return "ERROR";
}

std::string Label::getID(){
	return "ERROR";
}

void Label::getPosition(int &x, int &y){
	return;
}

int Label::getMaxSize(){
	return -1;
}

bool Label::getVisible(){
	return false;
}

bool Label::cmpID(const char *id){
	return false;
}

} // mncw




