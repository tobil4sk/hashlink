#define HL_NAME(n) mesa__##n
#include <hl_ffi.h>
#include <GL/osmesa.h>

HL_PRIM void *HL_NAME(create_context)( int *attribs, OSMesaContext shared ) {
	OSMesaContext ctx = OSMesaCreateContextAttribs(attribs, shared);
	return ctx;
}

HL_PRIM void HL_NAME(destroy_context)( OSMesaContext ctx ) {
	OSMesaDestroyContext(ctx);
}

HL_PRIM bool HL_NAME(make_current)( OSMesaContext ctx, void *buffer, int type, int width, int height ) {
	return OSMesaMakeCurrent(ctx,buffer,type,width,height);
}

#define _CTX HL_ABSTRACT(mesa_ctx)
HL_DEFINE_PRIM(_CTX, create_context, HL_BYTES _CTX);
HL_DEFINE_PRIM(HL_VOID, destroy_context, _CTX);
HL_DEFINE_PRIM(HL_BOOL, make_current, _CTX HL_BYTES HL_I32 HL_I32 HL_I32);
