#ifndef XWALK_RUNTIME_RENDERER_ANDROID_XWALK_WEB_GRAPHICS_CONTEXT3D_DIRECT_IMPL_H_
#define XWALK_RUNTIME_RENDERER_ANDROID_XWALK_WEB_GRAPHICS_CONTEXT3D_DIRECT_IMPL_H_

#include <KHR/khrplatform.h>

namespace content {
typedef khronos_int8_t XWGLByte;
typedef khronos_float_t XWGLclampf;
typedef khronos_int32_t XWGLfixed;
typedef short XWGLshort;
typedef unsigned short XWGLushort;
typedef void XWGLvoid;
typedef struct __XWGLsync *XWGLsync;
typedef khronos_int64_t XWGLint64;
typedef khronos_uint64_t XWGLuint64;
typedef unsigned int XWGLenum;
typedef unsigned int XWGLuint;
typedef char XWGLchar;
typedef khronos_float_t XWGLfloat;
typedef khronos_ssize_t XWGLsizeiptr;
typedef khronos_intptr_t XWGLintptr;
typedef unsigned int XWGLbitfield;
typedef int XWGLint;
typedef unsigned char XWGLbolean;
typedef int XWGLsizei;
typedef khronos_uint8_t XWGLubyte;

class XWalkWebGraphicsContext3DDirectImpl {

 public:

  XWalkWebGraphicsContext3DDirectImpl () {}
  virtual ~XWalkWebGraphicsContext3DDirectImpl() {}

  void  activeTexture (XWGLenum texture);
  void  attachShader (XWGLuint program, XWGLuint shader);
  void  bindAttribLocation (XWGLuint program, XWGLuint index, const XWGLchar *name);
  void  bindBuffer (XWGLenum target, XWGLuint buffer);
  void  bindFramebuffer (XWGLenum target, XWGLuint framebuffer);
  void  bindRenderbuffer (XWGLenum target, XWGLuint renderbuffer);
  void  bindTexture (XWGLenum target, XWGLuint texture);
  void  blendColor (XWGLfloat red, XWGLfloat green, XWGLfloat blue, XWGLfloat alpha);
  void  blendEquation (XWGLenum mode);
  void  blendEquationSeparate (XWGLenum modeRGB, XWGLenum modeAlpha);
  void  blendFunc (XWGLenum sfactor, XWGLenum dfactor);
  void  blendFuncSeparate (XWGLenum sfactorRGB, XWGLenum dfactorRGB, XWGLenum sfactorAlpha, XWGLenum dfactorAlpha);
  void  bufferData (XWGLenum target, XWGLsizeiptr size, const void *data, XWGLenum usage);
  void  bufferSubData (XWGLenum target, XWGLintptr offset, XWGLsizeiptr size, const void *data);
  XWGLenum  checkFramebufferStatus (XWGLenum target);
  void  clear (XWGLbitfield mask);
  void  clearColor (XWGLfloat red, XWGLfloat green, XWGLfloat blue, XWGLfloat alpha);
  void  clearDepthf (XWGLfloat d);
  void  clearStencil (XWGLint s);
  void  colorMask (XWGLbolean red, XWGLbolean green, XWGLbolean blue, XWGLbolean alpha);
  void  compileShader (XWGLuint shader);
  void  compressedTexImage2D (XWGLenum target, XWGLint level, XWGLenum internalformat, XWGLsizei width, XWGLsizei height, XWGLint border, XWGLsizei imageSize, const void *data);
  void  compressedTexSubImage2D (XWGLenum target, XWGLint level, XWGLint xoffset, XWGLint yoffset, XWGLsizei width, XWGLsizei height, XWGLenum format, XWGLsizei imageSize, const void *data);
  void  copyTexImage2D (XWGLenum target, XWGLint level, XWGLenum internalformat, XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height, XWGLint border);
  void  copyTexSubImage2D (XWGLenum target, XWGLint level, XWGLint xoffset, XWGLint yoffset, XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height);
  XWGLuint  createProgram (void);
  XWGLuint  createShader (XWGLenum type);
  void  cullFace (XWGLenum mode);
  void  deleteBuffers (XWGLsizei n, const XWGLuint *buffers);
  void  deleteFramebuffers (XWGLsizei n, const XWGLuint *framebuffers);
  void  deleteProgram (XWGLuint program);
  void  deleteRenderbuffers (XWGLsizei n, const XWGLuint *renderbuffers);
  void  deleteShader (XWGLuint shader);
  void  deleteTextures (XWGLsizei n, const XWGLuint *textures);
  void  depthFunc (XWGLenum func);
  void  depthMask (XWGLbolean flag);
  void  depthRangef (XWGLfloat n, XWGLfloat f);
  void  detachShader (XWGLuint program, XWGLuint shader);
  void  disable (XWGLenum cap);
  void  disableVertexAttribArray (XWGLuint index);
  void  drawArrays (XWGLenum mode, XWGLint first, XWGLsizei count);
  void  drawElements (XWGLenum mode, XWGLsizei count, XWGLenum type, const void *indices);
  void  enable (XWGLenum cap);
  void  enableVertexAttribArray (XWGLuint index);
  void  finish (void);
  void  flush (void);
  void  framebufferRenderbuffer (XWGLenum target, XWGLenum attachment, XWGLenum renderbuffertarget, XWGLuint renderbuffer);
  void  framebufferTexture2D (XWGLenum target, XWGLenum attachment, XWGLenum textarget, XWGLuint texture, XWGLint level);
  void  frontFace (XWGLenum mode);
  void  genBuffers (XWGLsizei n, XWGLuint *buffers);
  void  generateMipmap (XWGLenum target);
  void  genFramebuffers (XWGLsizei n, XWGLuint *framebuffers);
  void  genRenderbuffers (XWGLsizei n, XWGLuint *renderbuffers);
  void  genTextures (XWGLsizei n, XWGLuint *textures);
  void  getActiveAttrib (XWGLuint program, XWGLuint index, XWGLsizei bufSize, XWGLsizei *length, XWGLint *size, XWGLenum *type, XWGLchar *name);
  void  getActiveUniform (XWGLuint program, XWGLuint index, XWGLsizei bufSize, XWGLsizei *length, XWGLint *size, XWGLenum *type, XWGLchar *name);
  void  getAttachedShaders (XWGLuint program, XWGLsizei maxCount, XWGLsizei *count, XWGLuint *shaders);
  XWGLint  getAttribLocation (XWGLuint program, const XWGLchar *name);
  void  getBooleanv (XWGLenum pname, XWGLbolean *data);
  void  getBufferParameteriv (XWGLenum target, XWGLenum pname, XWGLint *params);
  XWGLenum  getError (void);
  void  getFloatv (XWGLenum pname, XWGLfloat *data);
  void  getFramebufferAttachmentParameteriv (XWGLenum target, XWGLenum attachment, XWGLenum pname, XWGLint *params);
  void  getIntegerv (XWGLenum pname, XWGLint *data);
  void  getProgramiv (XWGLuint program, XWGLenum pname, XWGLint *params);
  void  getProgramInfoLog (XWGLuint program, XWGLsizei bufSize, XWGLsizei *length, XWGLchar *infoLog);
  void  getRenderbufferParameteriv (XWGLenum target, XWGLenum pname, XWGLint *params);
  void  getShaderiv (XWGLuint shader, XWGLenum pname, XWGLint *params);
  void  getShaderInfoLog (XWGLuint shader, XWGLsizei bufSize, XWGLsizei *length, XWGLchar *infoLog);
  void  getShaderPrecisionFormat (XWGLenum shadertype, XWGLenum precisiontype, XWGLint *range, XWGLint *precision);
  void  getShaderSource (XWGLuint shader, XWGLsizei bufSize, XWGLsizei *length, XWGLchar *source);
  const XWGLubyte * getString (XWGLenum name);
  void  getTexParameterfv (XWGLenum target, XWGLenum pname, XWGLfloat *params);
  void  getTexParameteriv (XWGLenum target, XWGLenum pname, XWGLint *params);
  void  getUniformfv (XWGLuint program, XWGLint location, XWGLfloat *params);
  void  getUniformiv (XWGLuint program, XWGLint location, XWGLint *params);
  XWGLint  getUniformLocation (XWGLuint program, const XWGLchar *name);
  void  getVertexAttribfv (XWGLuint index, XWGLenum pname, XWGLfloat *params);
  void  getVertexAttribiv (XWGLuint index, XWGLenum pname, XWGLint *params);
  void  getVertexAttribPointerv (XWGLuint index, XWGLenum pname, void **pointer);
  void  hint (XWGLenum target, XWGLenum mode);
  XWGLbolean  isBuffer (XWGLuint buffer);
  XWGLbolean  isEnabled (XWGLenum cap);
 XWGLbolean  isFramebuffer (XWGLuint framebuffer);
 XWGLbolean  isProgram (XWGLuint program);
 XWGLbolean  isRenderbuffer (XWGLuint renderbuffer);
 XWGLbolean  isShader (XWGLuint shader);
 XWGLbolean  isTexture (XWGLuint texture);
 void  lineWidth (XWGLfloat width);
 void  linkProgram (XWGLuint program);
 void  pixelStorei (XWGLenum pname, XWGLint param);
 void  polygonOffset (XWGLfloat factor, XWGLfloat units);
 void  readPixels (XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height, XWGLenum format, XWGLenum type, void *pixels);
 void  releaseShaderCompiler (void);
 void  renderbufferStorage (XWGLenum target, XWGLenum internalformat, XWGLsizei width, XWGLsizei height);
 void  sampleCoverage (XWGLfloat value, XWGLbolean invert);
 void  scissor (XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height);
 void  shaderBinary (XWGLsizei count, const XWGLuint *shaders, XWGLenum binaryformat, const void *binary, XWGLsizei length);
 void  shaderSource (XWGLuint shader, XWGLsizei count, const XWGLchar *const*string, const XWGLint *length);
 void  stencilFunc (XWGLenum func, XWGLint ref, XWGLuint mask);
 void  stencilFuncSeparate (XWGLenum face, XWGLenum func, XWGLint ref, XWGLuint mask);
 void  stencilMask (XWGLuint mask);
 void  stencilMaskSeparate (XWGLenum face, XWGLuint mask);
 void  stencilOp (XWGLenum fail, XWGLenum zfail, XWGLenum zpass);
 void  stencilOpSeparate (XWGLenum face, XWGLenum sfail, XWGLenum dpfail, XWGLenum dppass);
 void  texImage2D (XWGLenum target, XWGLint level, XWGLint internalformat, XWGLsizei width, XWGLsizei height, XWGLint border, XWGLenum format, XWGLenum type, const void *pixels);
 void  texParameterf (XWGLenum target, XWGLenum pname, XWGLfloat param);
 void  texParameterfv (XWGLenum target, XWGLenum pname, const XWGLfloat *params);
 void  texParameteri (XWGLenum target, XWGLenum pname, XWGLint param);
 void  texParameteriv (XWGLenum target, XWGLenum pname, const XWGLint *params);
 void  texSubImage2D (XWGLenum target, XWGLint level, XWGLint xoffset, XWGLint yoffset, XWGLsizei width, XWGLsizei height, XWGLenum format, XWGLenum type, const void *pixels);
 void  uniform1f (XWGLint location, XWGLfloat v0);
 void  uniform1fv (XWGLint location, XWGLsizei count, const XWGLfloat *value);
 void  uniform1i (XWGLint location, XWGLint v0);
 void  uniform1iv (XWGLint location, XWGLsizei count, const XWGLint *value);
 void  uniform2f (XWGLint location, XWGLfloat v0, XWGLfloat v1);
 void  uniform2fv (XWGLint location, XWGLsizei count, const XWGLfloat *value);
 void  uniform2i (XWGLint location, XWGLint v0, XWGLint v1);
 void  uniform2iv (XWGLint location, XWGLsizei count, const XWGLint *value);
 void  uniform3f (XWGLint location, XWGLfloat v0, XWGLfloat v1, XWGLfloat v2);
 void  uniform3fv (XWGLint location, XWGLsizei count, const XWGLfloat *value);
 void  uniform3i (XWGLint location, XWGLint v0, XWGLint v1, XWGLint v2);
 void  uniform3iv (XWGLint location, XWGLsizei count, const XWGLint *value);
 void  uniform4f (XWGLint location, XWGLfloat v0, XWGLfloat v1, XWGLfloat v2, XWGLfloat v3);
 void  uniform4fv (XWGLint location, XWGLsizei count, const XWGLfloat *value);
 void  uniform4i (XWGLint location, XWGLint v0, XWGLint v1, XWGLint v2, XWGLint v3);
 void  uniform4iv (XWGLint location, XWGLsizei count, const XWGLint *value);
 void  uniformMatrix2fv (XWGLint location, XWGLsizei count, XWGLbolean transpose, const XWGLfloat *value);
 void  uniformMatrix3fv (XWGLint location, XWGLsizei count, XWGLbolean transpose, const XWGLfloat *value);
 void  uniformMatrix4fv (XWGLint location, XWGLsizei count, XWGLbolean transpose, const XWGLfloat *value);
 void  useProgram (XWGLuint program);
 void  validateProgram (XWGLuint program);
 void  vertexAttrib1f (XWGLuint index, XWGLfloat x);
 void  vertexAttrib1fv (XWGLuint index, const XWGLfloat *v);
 void  vertexAttrib2f (XWGLuint index, XWGLfloat x, XWGLfloat y);
 void  vertexAttrib2fv (XWGLuint index, const XWGLfloat *v);
 void  vertexAttrib3f (XWGLuint index, XWGLfloat x, XWGLfloat y, XWGLfloat z);
 void  vertexAttrib3fv (XWGLuint index, const XWGLfloat *v);
 void  vertexAttrib4f (XWGLuint index, XWGLfloat x, XWGLfloat y, XWGLfloat z, XWGLfloat w);
 void  vertexAttrib4fv (XWGLuint index, const XWGLfloat *v);
 void  vertexAttribPointer (XWGLuint index, XWGLint size, XWGLenum type, XWGLbolean normalized, XWGLsizei stride, const void *pointer);
 void  viewport (XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height);

 };

} // namespace content

#endif // XWALK_RUNTIME_RENDERER_ANDROID_XWALK_WEB_GRAPHICS_CONTEXT3D_DIRECT_H_