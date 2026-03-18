#define HL_NAME(n) dx12debug_##n
#define HL_DISABLE_LEGACY_FFI
#include <hl.h>
#include <hl_ffi.h>

#ifdef HL_WIN_DESKTOP
#include <d3d12.h>
#define USE_PIX
#include <pix3.h>
#endif

#define _RES HL_ABSTRACT(dx_resource)

HL_PRIM void HL_NAME(command_list_pix_begin_event)(ID3D12GraphicsCommandList* l, UINT64 color, wchar_t const* formatString) {
	PIXBeginEvent(l, color, formatString);
}

HL_PRIM void HL_NAME(command_list_pix_end_event)(ID3D12GraphicsCommandList* l) {
	PIXEndEvent(l);
}

HL_DEFINE_PRIM(HL_VOID, command_list_pix_begin_event, _RES HL_I64 HL_BYTES);
HL_DEFINE_PRIM(HL_VOID, command_list_pix_end_event, _RES);
