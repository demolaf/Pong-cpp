#include "MediaQuery.h"

class UISizing
{
public:
	static float batWidth() {
		return MediaQuery::screenWidth() * 0.026;
	}

	static float batHeight() {
		return MediaQuery::screenHeight() * 0.013;
	}
};