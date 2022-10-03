#include <gl\glew.h>

extern const int refWidth = 605;
extern const int refHeight = 689;

float GetGLCoordinate(int value, int max) {
	float r;
	r = (float)value / (float)max * 2.0f - 1.0f;
	return r;
}

float getERSymbolX(int x) {
	return GetGLCoordinate(x, refWidth);
}

float getERSymbolY(int y) {
	return GetGLCoordinate(refHeight - y, refHeight);
}

const GLfloat ERSymbol[] = {
		// Data
		// float x, float, y,
		// float r, float g, floar b

		// BG color
		// 1.0f, 198.0f/255.0f, 14.0f/255.0f,

		// Symbol color
		// 127.0f/255.0f, 211.0f / 255.0f, 42.0f / 255.0f

		// BG
		// 0 TR 
		+1.0f, +1.0f,
		1.0f, 198.0f / 255.0f, 14.0f / 255.0f,
		// 1 TL
		-1.0f, +1.0f,
		1.0f, 198.0f / 255.0f, 14.0f / 255.0f,
		// 2 BL
		-1.0f, -1.0f,
		1.0f, 198.0f / 255.0f, 14.0f / 255.0f,
		// 3 BR
		+1.0f, -1.0f,
		1.0f, 198.0f / 255.0f, 14.0f / 255.0f,

		// Symbol
		// 4
		getERSymbolX(269),
		getERSymbolY(326),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 5 
		getERSymbolX(313),
		getERSymbolY(326),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 6
		getERSymbolX(295),
		getERSymbolY(4),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 7
		getERSymbolX(289),
		getERSymbolY(639),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// R 
		// 8
		getERSymbolX(301),
		getERSymbolY(320),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 9
		getERSymbolX(300),
		getERSymbolY(383),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 10
		getERSymbolX(450),
		getERSymbolY(461),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 11
		getERSymbolX(432),
		getERSymbolY(470),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 12
		getERSymbolX(410),
		getERSymbolY(427),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 13
		getERSymbolX(331),
		getERSymbolY(511),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 14
		getERSymbolX(352),
		getERSymbolY(535),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 15
		getERSymbolX(347),
		getERSymbolY(495),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 16
		getERSymbolX(471),
		getERSymbolY(674),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// E
		// 17
		getERSymbolX(286),
		getERSymbolY(309),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 18
		getERSymbolX(150),
		getERSymbolY(251),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 19
		getERSymbolX(284),
		getERSymbolY(364),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 20
		getERSymbolX(171),
		getERSymbolY(237),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 21
		getERSymbolX(290),
		getERSymbolY(185),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 22
		getERSymbolX(290),
		getERSymbolY(165),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 23
		getERSymbolX(175),
		getERSymbolY(272),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 24
		getERSymbolX(256),
		getERSymbolY(195),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 25
		getERSymbolX(147),
		getERSymbolY(97),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 26
		getERSymbolX(159),
		getERSymbolY(92),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 27
		getERSymbolX(295),
		getERSymbolY(96),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 28
		getERSymbolX(294),
		getERSymbolY(51),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,

		// 29
		getERSymbolX(174),
		getERSymbolY(115),
		127.0f / 255.0f, 211.0f / 255.0f, 42.0f / 255.0f,
};

const GLushort ERSymbolIndices[] = {
	// BG
	0,1,2,
	0,2,3,
	// Symbol
	4,5,6,
	4,5,7,
	// R
	8,9,10,
	8, 9, 11,
	10,12,13,
	13,10,14,
	13, 16, 15,
	// E
	17, 18, 19,
	17, 18, 20,
	18,21,22,
	18,21,23,
	21,24,25,
	21, 25, 26,
	25,27,28,
	25,27,29,

};