#ifndef HLSYSTEM_H
#define HLSYSTEM_H

#ifndef HL_DISABLE_LEGACY_FFI
#	define HL_DISABLE_LEGACY_FFI
#endif

#include <hl.h>

/* System specific headers required internally */
#ifdef HL_WIN
#	if defined(HL_WIN_DESKTOP) || defined(HL_XBS)
#		include <windows.h>
#	else
#		include <xdk.h>
#	endif
#endif

#endif
