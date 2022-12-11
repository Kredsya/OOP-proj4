#include "Display.h"


Display::Display(const int windowWidth, const int windowHeight) {
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
}

Display::~Display() {
	for (unsigned int i = 0; i < 7; i++) {
		delete this->FontObjects[i];
	}

	delete[] this->FontObjects;
}

bool Display::create(const char* fontFamily, const int fontSize, IDirect3DDevice9* pDevice) {
	for (unsigned int i = 0; i < 7; i++) {
		this->FontObjects[i] = new CD3DFont(fontFamily, fontSize, 0);
		this->FontObjects[i]->InitDeviceObjects(pDevice);
		this->FontObjects[i]->RestoreDeviceObjects();
	}

	this->jumperName = "player";

	return true;
}

void Display::destory() {
	for (unsigned int i = 0; i < 2; i++) {
		this->FontObjects[i]->InvalidateDeviceObjects();
		this->FontObjects[i]->DeleteDeviceObjects();
		d3d::Delete<CD3DFont*>(this->FontObjects[i]);
	}
}




bool Display::update() {

	this->FontObjects[0]->DrawText(60, 20, 0xff0000FF, this->jumperName.c_str());
	this->FontObjects[1]->DrawText(windowWidth - 160, 20, 0xff000000, this->jumperName.c_str());


	this->FontObjects[2]->DrawText(60, 50, 0xff0000000, "forest of patience");
	this->FontObjects[3]->DrawText(windowWidth - 160, 50, 0xff000000, "doyeab");

	this->FontObjects[4]->DrawText(60, 80, 0xff0000000, "minjun");
	this->FontObjects[5]->DrawText(windowWidth - 160, 80, 0xff000000, "jimin");

	this->FontObjects[6]->DrawText(windowWidth / 2, 10, 0xff0000FF, "Stage 1");

	return false;
}