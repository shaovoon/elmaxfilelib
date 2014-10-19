#pragma once

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "Enumeration.h"
#include "RAII_Array.h"

#ifdef _MICROSOFT
#define ELMAX_INT64 __int64
#include "../Microsoft/WinOperation.h"
#else
#define ELMAX_INT64 long long
#include "../Linux/LinuxOperation.h"
#endif

#include <stdexcept>
#include <cstring>
#include <cstdlib>
#include <wchar.h>
#include <sstream>

#include "../UTF16Utils/utf16.h"

void InitErrMap();

std::wstring GetErrorMsg(int errNum);
