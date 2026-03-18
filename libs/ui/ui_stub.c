#define HL_NAME(n) ui_##n
#define HL_DISABLE_LEGACY_FFI
#include <hl.h>
#include <hl_ffi.h>
#ifndef HL_WIN
#include <unistd.h>
#endif

#define wref void
#define vsentinel void

HL_PRIM void HL_NAME(ui_init)() {
}

HL_PRIM int HL_NAME(ui_dialog)( const uchar *title, const uchar *message, int flags ) {
	uprintf(USTR("[DIALOG] [%s]"), title);
	uprintf(USTR(" %s\n"), title);
	return 0;
}

HL_PRIM wref *HL_NAME(ui_winlog_new)( const uchar *title, int width, int height ) {
	return NULL;
}

HL_PRIM wref *HL_NAME(ui_button_new)( wref *w, const uchar *txt, vclosure *callb ) {
	return NULL;
}

HL_PRIM void HL_NAME(ui_winlog_set_text)( wref *w, const uchar *txt, bool autoScroll ) {
}

HL_PRIM void HL_NAME(ui_win_set_text)( wref *w, const uchar *txt ) {
}

HL_PRIM void HL_NAME(ui_win_set_enable)( wref *w, bool enable ) {
}

HL_PRIM void HL_NAME(ui_win_destroy)( wref *w ) {
}

HL_PRIM int HL_NAME(ui_loop)( bool blocking ) {
	return 1;
}

HL_PRIM void HL_NAME(ui_stop_loop)() {
	// TODO ?
}

HL_PRIM vsentinel *HL_NAME(ui_start_sentinel)( double timeout, vclosure *c ) {
	return NULL;
}

HL_PRIM void HL_NAME(ui_sentinel_tick)( vsentinel *s ) {
}

HL_PRIM void HL_NAME(ui_sentinel_pause)( vsentinel *s, bool pause ) {
}

HL_PRIM bool HL_NAME(ui_sentinel_is_paused)( vsentinel *s ) {
	return false;
}

HL_PRIM void HL_NAME(ui_close_console)() {
}

HL_PRIM vbyte *HL_NAME(ui_choose_file)( bool forSave, vdynamic *options ) {
	return NULL;
}

HL_PRIM bool HL_NAME(ui_set_clipboard_text)(char* text) {
	return false;
}

HL_PRIM vbyte* HL_NAME(ui_get_clipboard_text)() {
	return NULL;
}

#define _WIN HL_ABSTRACT(ui_window)
#define _SENTINEL HL_ABSTRACT(ui_sentinel)

HL_DEFINE_PRIM(HL_VOID, ui_init, HL_NO_ARG);
HL_DEFINE_PRIM(HL_I32, ui_dialog, HL_BYTES HL_BYTES HL_I32);
HL_DEFINE_PRIM(_WIN, ui_winlog_new, HL_BYTES HL_I32 HL_I32);
HL_DEFINE_PRIM(_WIN, ui_button_new, _WIN HL_BYTES HL_FUN(HL_VOID,HL_NO_ARG));
HL_DEFINE_PRIM(HL_VOID, ui_winlog_set_text, _WIN HL_BYTES HL_BOOL);
HL_DEFINE_PRIM(HL_VOID, ui_win_set_text, _WIN HL_BYTES);
HL_DEFINE_PRIM(HL_VOID, ui_win_set_enable, _WIN HL_BOOL);
HL_DEFINE_PRIM(HL_VOID, ui_win_destroy, _WIN);
HL_DEFINE_PRIM(HL_I32, ui_loop, HL_BOOL);
HL_DEFINE_PRIM(HL_VOID, ui_stop_loop, HL_NO_ARG);
HL_DEFINE_PRIM(HL_VOID, ui_close_console, HL_NO_ARG);

HL_DEFINE_PRIM(_SENTINEL, ui_start_sentinel, HL_F64 HL_FUN(HL_VOID,HL_NO_ARG));
HL_DEFINE_PRIM(HL_VOID, ui_sentinel_tick, _SENTINEL);
HL_DEFINE_PRIM(HL_VOID, ui_sentinel_pause, _SENTINEL HL_BOOL);
HL_DEFINE_PRIM(HL_BOOL, ui_sentinel_is_paused, _SENTINEL);

HL_DEFINE_PRIM(HL_BYTES, ui_choose_file, HL_BOOL HL_DYN);

HL_DEFINE_PRIM(HL_BOOL, ui_set_clipboard_text, HL_BYTES);
HL_DEFINE_PRIM(HL_BYTES, ui_get_clipboard_text, HL_NO_ARG);
