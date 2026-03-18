#define HL_NAME(n) heaps_##n
#include <meshoptimizer.h>
#include <hl_ffi.h>

HL_PRIM int HL_NAME(generate_vertex_remap)(unsigned int* pRemapOut, unsigned int* pIndices, int indexCount, float* pVertices, int vertexCount, int vertexSize) {
	return meshopt_generateVertexRemap(pRemapOut, pIndices, indexCount, pVertices, vertexCount, vertexSize);
}

HL_PRIM void HL_NAME(remap_index_buffer)(unsigned int* pIndicesOut, unsigned int* pIndicesIn, int indexCount, unsigned int* pRemap) {
	meshopt_remapIndexBuffer(pIndicesOut, pIndicesIn, indexCount, pRemap);
}

HL_PRIM void HL_NAME(remap_vertex_buffer)(void* pVerticesOut, void* pVerticexIn, int vertexCount, int vertexSize, unsigned int* pRemap) {
	meshopt_remapVertexBuffer(pVerticesOut, pVerticexIn, vertexCount, vertexSize, pRemap);
}

HL_PRIM int HL_NAME(simplify)(unsigned int* pIndicesOut, unsigned int* pIndicesIn, int indexCount, float* pVertices, int vertexCount, int vertexSize, int targetIndexCount, float targetError, int options, float* resultErrorOut) {
	return meshopt_simplify(pIndicesOut, pIndicesIn, indexCount, pVertices, vertexCount, vertexSize, targetIndexCount, (float)targetError, options, resultErrorOut);
}

HL_PRIM void HL_NAME(optimize_vertex_cache)(unsigned int* pIndicesOut, unsigned int* pIndicesIn, int indexCount, int vertexCount) {
	meshopt_optimizeVertexCache(pIndicesOut, pIndicesIn, indexCount, vertexCount);
}

HL_PRIM void HL_NAME(optimize_overdraw)(unsigned int* pIndicesOut, unsigned int* pIndicesIn, int indexCount, float* pVertices, int vertexCount, int vertexSize, float threshold) {
	meshopt_optimizeOverdraw(pIndicesOut, pIndicesIn, indexCount, pVertices, vertexCount, vertexSize, threshold);
}

HL_PRIM int HL_NAME(optimize_vertex_fetch)(float* pVerticesOut, unsigned int* pIndices, int indexCount, void* pVerticesIn, int vertexCount, int vertexSize) {
	return meshopt_optimizeVertexFetch(pVerticesOut, pIndices, indexCount, pVerticesIn, vertexCount, vertexSize);
}

HL_DEFINE_PRIM(HL_I32, generate_vertex_remap, HL_BYTES HL_BYTES HL_I32 HL_BYTES HL_I32 HL_I32);
HL_DEFINE_PRIM(HL_VOID, remap_index_buffer, HL_BYTES HL_BYTES HL_I32 HL_BYTES);
HL_DEFINE_PRIM(HL_VOID, remap_vertex_buffer, HL_BYTES HL_BYTES HL_I32 HL_I32 HL_BYTES);
HL_DEFINE_PRIM(HL_I32, simplify, HL_BYTES HL_BYTES HL_I32 HL_BYTES HL_I32 HL_I32 HL_I32 HL_F32 HL_I32 HL_BYTES);
HL_DEFINE_PRIM(HL_VOID, optimize_vertex_cache, HL_BYTES HL_BYTES HL_I32 HL_I32);
HL_DEFINE_PRIM(HL_VOID, optimize_overdraw, HL_BYTES HL_BYTES HL_I32 HL_BYTES HL_I32 HL_I32 HL_F32);
HL_DEFINE_PRIM(HL_I32, optimize_vertex_fetch, HL_BYTES HL_BYTES HL_I32 HL_BYTES HL_I32 HL_I32);
