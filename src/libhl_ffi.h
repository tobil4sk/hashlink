#ifndef LIBHL_FFI_H
#define LIBHL_FFI_H

#define HL_NAME(p) p
#define HL_DEFINE_PRIM(t,name,args)		HL_DEFINE_PRIM_WITH_NAME(t,hl_##name,args,name)

#include "hl_ffi.h"

#endif
