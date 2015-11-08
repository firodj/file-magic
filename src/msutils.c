#include "msutils.h"

#if defined(WIN32) && defined(UNICODE)
const wchar_t* mb2wc(const char *mb)
{
	size_t wlen = MultiByteToWideChar(CP_UTF8, 0, mb, -1,  NULL, 0);
    wchar_t* wfn = (wchar_t*) calloc( wlen, sizeof(wchar_t) );

    if (wfn)
        wlen = MultiByteToWideChar(CP_UTF8, 0, mb, -1, wfn, wlen);

    return wfn;
}
#endif // WIN32 && UNICODE
