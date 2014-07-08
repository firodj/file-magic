#ifndef __file_h__
#define __file_h__

#include <windows.h>
#include <wchar.h>

#if defined(WIN32) && defined(UNICODE)

const wchar_t* mb2wc(const char *mb);	// convert utf-8 const char to wchar_t unicode

#endif
#endif