#include "xwalk_web_graphics_context3d_direct_impl.h"
#include "base/logging.h"

#define GPU_GLES2_GL2CHROMIUM_H_ // to avoid using chromium's gl wrappers
#include <GLES2/gl2.h>

namespace content {

 void  XWalkWebGraphicsContext3DDirectImpl::activeTexture (XWGLenum texture) {
       glActiveTexture(texture);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::attachShader (XWGLuint program, XWGLuint shader) {
       glAttachShader(program, shader);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::bindAttribLocation (XWGLuint program, XWGLuint index, const XWGLchar *name) {
       glBindAttribLocation(program, index, name);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::bindBuffer (XWGLenum target, XWGLuint buffer) {
       glBindBuffer(target, buffer);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::bindFramebuffer (XWGLenum target, XWGLuint framebuffer) {
       glBindFramebuffer(target, framebuffer);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::bindRenderbuffer (XWGLenum target, XWGLuint renderbuffer) {
       glBindRenderbuffer(target, renderbuffer);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::bindTexture (XWGLenum target, XWGLuint texture) {
       glBindTexture(target, texture);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::blendColor (XWGLfloat red, XWGLfloat green, XWGLfloat blue, XWGLfloat alpha) {
       glBlendColor(red, green, blue, alpha);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::blendEquation (XWGLenum mode) {
       glBlendEquation(mode);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::blendEquationSeparate (XWGLenum modeRGB, XWGLenum modeAlpha) {
       glBlendEquationSeparate(modeRGB, modeAlpha);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::blendFunc (XWGLenum sfactor, XWGLenum dfactor) {
       glBlendFunc(sfactor, dfactor);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::blendFuncSeparate (XWGLenum sfactorRGB, XWGLenum dfactorRGB, XWGLenum sfactorAlpha, XWGLenum dfactorAlpha) {
       glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::bufferData (XWGLenum target, XWGLsizeiptr size, const void *data, XWGLenum usage) {
       glBufferData(target, size, data, usage);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::bufferSubData (XWGLenum target, XWGLintptr offset, XWGLsizeiptr size, const void *data) {
       glBufferSubData(target, offset, size, data);
 }

 XWGLenum  XWalkWebGraphicsContext3DDirectImpl::checkFramebufferStatus (XWGLenum target) {
       return glCheckFramebufferStatus(target);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::clear (XWGLbitfield mask) {
       glClear(mask);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::clearColor (XWGLfloat red, XWGLfloat green, XWGLfloat blue, XWGLfloat alpha) {
       glClearColor(red, green, blue, alpha);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::clearDepthf (XWGLfloat d) {
       glClearDepthf(d);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::clearStencil (XWGLint s) {
       glClearStencil(s);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::colorMask (XWGLbolean red, XWGLbolean green, XWGLbolean blue, XWGLbolean alpha) {
       glColorMask(red, green, blue, alpha);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::compileShader (XWGLuint shader) {
       glCompileShader(shader);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::compressedTexImage2D (XWGLenum target, XWGLint level, XWGLenum internalformat, XWGLsizei width, XWGLsizei height, XWGLint border, XWGLsizei imageSize, const void *data) {
       glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::compressedTexSubImage2D (XWGLenum target, XWGLint level, XWGLint xoffset, XWGLint yoffset, XWGLsizei width, XWGLsizei height, XWGLenum format, XWGLsizei imageSize, const void *data) {
       glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::copyTexImage2D (XWGLenum target, XWGLint level, XWGLenum internalformat, XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height, XWGLint border) {
       glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::copyTexSubImage2D (XWGLenum target, XWGLint level, XWGLint xoffset, XWGLint yoffset, XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height) {
       glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
 }

 XWGLuint  XWalkWebGraphicsContext3DDirectImpl::createProgram (void) {
       return glCreateProgram();
 }

 XWGLuint  XWalkWebGraphicsContext3DDirectImpl::createShader (XWGLenum type) {
       return glCreateShader(type);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::cullFace (XWGLenum mode) {
       glCullFace(mode);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::deleteBuffers (XWGLsizei n, const XWGLuint *buffers) {
       glDeleteBuffers(n, buffers);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::deleteFramebuffers (XWGLsizei n, const XWGLuint *framebuffers) {
       glDeleteFramebuffers(n, framebuffers);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::deleteProgram (XWGLuint program) {
       glDeleteProgram(program);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::deleteRenderbuffers (XWGLsizei n, const XWGLuint *renderbuffers) {
       glDeleteRenderbuffers(n, renderbuffers);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::deleteShader (XWGLuint shader) {
       glDeleteShader(shader);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::deleteTextures (XWGLsizei n, const XWGLuint *textures) {
       glDeleteTextures(n, textures);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::depthFunc (XWGLenum func) {
       glDepthFunc(func);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::depthMask (XWGLbolean flag) {
       glDepthMask(flag);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::depthRangef (XWGLfloat n, XWGLfloat f) {
       glDepthRangef(n, f);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::detachShader (XWGLuint program, XWGLuint shader) {
       glDetachShader(program, shader);
}
 void  XWalkWebGraphicsContext3DDirectImpl::disable (XWGLenum cap) {
       glDisable(cap);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::disableVertexAttribArray (XWGLuint index) {
       glDisableVertexAttribArray(index);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::drawArrays (XWGLenum mode, XWGLint first, XWGLsizei count) {
       glDrawArrays(mode, first, count);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::drawElements (XWGLenum mode, XWGLsizei count, XWGLenum type, const void *indices) {
       glDrawElements(mode, count, type, indices);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::enable (XWGLenum cap) {
       glEnable(cap);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::enableVertexAttribArray (XWGLuint index) {
       glEnableVertexAttribArray(index);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::finish (void) {
       glFinish();
 }

 void  XWalkWebGraphicsContext3DDirectImpl::flush (void) {
       glFlush();
 }

 void  XWalkWebGraphicsContext3DDirectImpl::framebufferRenderbuffer (XWGLenum target, XWGLenum attachment, XWGLenum renderbuffertarget, XWGLuint renderbuffer) {
       glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::framebufferTexture2D (XWGLenum target, XWGLenum attachment, XWGLenum textarget, XWGLuint texture, XWGLint level) {
       glFramebufferTexture2D(target, attachment, textarget, texture, level);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::frontFace (XWGLenum mode) {
       glFrontFace(mode);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::genBuffers (XWGLsizei n, XWGLuint *buffers) {
       glGenBuffers(n, buffers);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::generateMipmap (XWGLenum target) {
       glGenerateMipmap(target);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::genFramebuffers (XWGLsizei n, XWGLuint *framebuffers) {
       glGenFramebuffers(n, framebuffers);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::genRenderbuffers (XWGLsizei n, XWGLuint *renderbuffers) {
       glGenRenderbuffers(n, renderbuffers);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::genTextures (XWGLsizei n, XWGLuint *textures) {
       glGenTextures(n, textures);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getActiveAttrib (XWGLuint program, XWGLuint index, XWGLsizei bufSize, XWGLsizei *length, XWGLint *size, XWGLenum *type, XWGLchar *name) {
       glGetActiveAttrib(program, index, bufSize, length, size, type, name);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::getActiveUniform (XWGLuint program, XWGLuint index, XWGLsizei bufSize, XWGLsizei *length, XWGLint *size, XWGLenum *type, XWGLchar *name)
 {
       glGetActiveUniform(program, index, bufSize, length, size, type, name);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getAttachedShaders (XWGLuint program, XWGLsizei maxCount, XWGLsizei *count, XWGLuint *shaders) {
       glGetAttachedShaders(program, maxCount, count, shaders);
 }
 XWGLint  XWalkWebGraphicsContext3DDirectImpl::getAttribLocation (XWGLuint program, const XWGLchar *name) {
       return glGetAttribLocation(program, name);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getBooleanv (XWGLenum pname, XWGLbolean *data) {
       glGetBooleanv(pname, data);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getBufferParameteriv (XWGLenum target, XWGLenum pname, XWGLint *params) {
       glGetBufferParameteriv(target, pname, params);
 }
 XWGLenum  XWalkWebGraphicsContext3DDirectImpl::getError (void) {
       return glGetError();
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getFloatv (XWGLenum pname, XWGLfloat *data) {
       glGetFloatv(pname, data);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getFramebufferAttachmentParameteriv (XWGLenum target, XWGLenum attachment, XWGLenum pname, XWGLint *params) {
       glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getIntegerv (XWGLenum pname, XWGLint *data) {
       glGetIntegerv(pname, data);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getProgramiv (XWGLuint program, XWGLenum pname, XWGLint *params) {
       glGetProgramiv(program, pname, params);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getProgramInfoLog (XWGLuint program, XWGLsizei bufSize, XWGLsizei *length, XWGLchar *infoLog) {
       glGetProgramInfoLog(program, bufSize, length, infoLog);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getRenderbufferParameteriv (XWGLenum target, XWGLenum pname, XWGLint *params)
 {
       glGetRenderbufferParameteriv(target, pname, params);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getShaderiv (XWGLuint shader, XWGLenum pname, XWGLint *params)
 {
       glGetShaderiv(shader, pname, params);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getShaderInfoLog (XWGLuint shader, XWGLsizei bufSize, XWGLsizei *length, XWGLchar *infoLog) {
       glGetShaderInfoLog(shader, bufSize, length, infoLog);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getShaderPrecisionFormat (XWGLenum shadertype, XWGLenum precisiontype, XWGLint *range, XWGLint *precision) {
       glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::getShaderSource (XWGLuint shader, XWGLsizei bufSize, XWGLsizei *length, XWGLchar *source) {
       glGetShaderSource(shader, bufSize, length, source);
 }
 const XWGLubyte * XWalkWebGraphicsContext3DDirectImpl::getString (XWGLenum name) {
       return glGetString(name);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::getTexParameterfv (XWGLenum target, XWGLenum pname, XWGLfloat *params) {
       glGetTexParameterfv(target, pname, params);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::getTexParameteriv (XWGLenum target, XWGLenum pname, XWGLint *params) {
       glTexParameteriv(target, pname, params);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::getUniformfv (XWGLuint program, XWGLint location, XWGLfloat *params) {
       glGetUniformfv(program, location, params);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::getUniformiv (XWGLuint program, XWGLint location, XWGLint *params) {
       glGetUniformiv(program, location, params);
 }

 XWGLint  XWalkWebGraphicsContext3DDirectImpl::getUniformLocation (XWGLuint program, const XWGLchar *name) {
       return glGetUniformLocation(program, name);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::getVertexAttribfv (XWGLuint index, XWGLenum pname, XWGLfloat *params) {
       glGetVertexAttribfv(index, pname, params);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::getVertexAttribiv (XWGLuint index, XWGLenum pname, XWGLint *params) {
       glGetVertexAttribiv(index, pname, params);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::getVertexAttribPointerv (XWGLuint index, XWGLenum pname, void **pointer) {
       glGetVertexAttribPointerv(index, pname, pointer);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::hint (XWGLenum target, XWGLenum mode) {
       glHint(target, mode);
 }

 XWGLbolean  XWalkWebGraphicsContext3DDirectImpl::isBuffer(XWGLuint buffer) {
       return glIsBuffer(buffer);
 }

 XWGLbolean  XWalkWebGraphicsContext3DDirectImpl::isEnabled(XWGLenum cap) {
       return glIsEnabled(cap);
 }

 XWGLbolean  XWalkWebGraphicsContext3DDirectImpl::isFramebuffer(XWGLuint framebuffer) {
       return glIsFramebuffer(framebuffer);
 }

 XWGLbolean  XWalkWebGraphicsContext3DDirectImpl::isProgram (XWGLuint program) {
       return glIsProgram(program);
 }

 XWGLbolean  XWalkWebGraphicsContext3DDirectImpl::isRenderbuffer (XWGLuint renderbuffer) {
       return glIsRenderbuffer(renderbuffer);
 }

 XWGLbolean  XWalkWebGraphicsContext3DDirectImpl::isShader (XWGLuint shader) {
       return glIsShader(shader);
 }

 XWGLbolean  XWalkWebGraphicsContext3DDirectImpl::isTexture (XWGLuint texture) {
      return glIsTexture(texture);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::lineWidth (XWGLfloat width) {
      glLineWidth(width);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::linkProgram (XWGLuint program) {
      glLinkProgram(program);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::pixelStorei (XWGLenum pname, XWGLint param) {
      glPixelStorei(pname, param);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::polygonOffset (XWGLfloat factor, XWGLfloat units) {
      glPolygonOffset(factor, units);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::readPixels (XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height, XWGLenum format, XWGLenum type, void *pixels) {
      glReadPixels(x, y, width, height, format, type, pixels);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::releaseShaderCompiler (void) {
      glReleaseShaderCompiler();
 }

 void  XWalkWebGraphicsContext3DDirectImpl::renderbufferStorage (XWGLenum target, XWGLenum internalformat, XWGLsizei width, XWGLsizei height) {
      glRenderbufferStorage(target, internalformat, width, height);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::sampleCoverage (XWGLfloat value, XWGLbolean invert) {
      glSampleCoverage(value, invert);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::scissor (XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height) {
      glScissor(x, y, width, height);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::shaderBinary (XWGLsizei count, const XWGLuint *shaders, XWGLenum binaryformat, const void *binary, XWGLsizei length) {
      glShaderBinary(count, shaders, binaryformat, binary, length);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::shaderSource (XWGLuint shader, XWGLsizei count, const XWGLchar *const*string, const XWGLint *length) {
      glShaderSource(shader, count, string, length);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::stencilFunc (XWGLenum func, XWGLint ref, XWGLuint mask) {
      glStencilFunc(func, ref, mask);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::stencilFuncSeparate (XWGLenum face, XWGLenum func, XWGLint ref, XWGLuint mask) {
      glStencilFuncSeparate(face, func, ref, mask);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::stencilMask (XWGLuint mask) {
      glStencilMask(mask);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::stencilMaskSeparate (XWGLenum face, XWGLuint mask) {
      glStencilMaskSeparate(face, mask);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::stencilOp (XWGLenum fail, XWGLenum zfail, XWGLenum zpass) {
      glStencilOp(fail, zfail, zpass);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::stencilOpSeparate (XWGLenum face, XWGLenum sfail, XWGLenum dpfail, XWGLenum dppass) {
      glStencilOpSeparate(face, sfail, dpfail, dppass);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::texImage2D (XWGLenum target, XWGLint level, XWGLint internalformat, XWGLsizei width, XWGLsizei height, XWGLint border, XWGLenum format, XWGLenum type, const void *pixels) {
      glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::texParameterf (XWGLenum target, XWGLenum pname, XWGLfloat param) {
      glTexParameterf(target, pname, param);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::texParameterfv (XWGLenum target, XWGLenum pname, const XWGLfloat *params) {
      glTexParameterfv(target, pname, params);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::texParameteri (XWGLenum target, XWGLenum pname, XWGLint param) {
      glTexParameteri(target, pname, param);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::texParameteriv (XWGLenum target, XWGLenum pname, const XWGLint *params) {
       glTexParameteriv(target, pname, params);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::texSubImage2D (XWGLenum target, XWGLint level, XWGLint xoffset, XWGLint yoffset, XWGLsizei width, XWGLsizei height, XWGLenum format, XWGLenum type, const void *pixels) {
       glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform1f (XWGLint location, XWGLfloat v0) {
       glUniform1f(location, v0);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform1fv (XWGLint location, XWGLsizei count, const XWGLfloat *value) {
       glUniform1fv(location, count, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform1i (XWGLint location, XWGLint v0) {
       glUniform1i(location, v0);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform1iv (XWGLint location, XWGLsizei count, const XWGLint *value) {
       glUniform1iv(location, count, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform2f (XWGLint location, XWGLfloat v0, XWGLfloat v1) {
       glUniform2f(location, v0, v1);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform2fv (XWGLint location, XWGLsizei count, const XWGLfloat *value) {
       glUniform2fv(location, count, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform2i (XWGLint location, XWGLint v0, XWGLint v1) {
       glUniform2i(location, v0, v1);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform2iv (XWGLint location, XWGLsizei count, const XWGLint *value) {
       glUniform2iv(location, count, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform3f (XWGLint location, XWGLfloat v0, XWGLfloat v1, XWGLfloat v2) {
       glUniform3f(location, v0, v1, v2);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform3fv (XWGLint location, XWGLsizei count, const XWGLfloat *value) {
       glUniform3fv(location, count, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform3i (XWGLint location, XWGLint v0, XWGLint v1, XWGLint v2) {
       glUniform3i(location, v0, v1, v2);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform3iv (XWGLint location, XWGLsizei count, const XWGLint *value) {
       glUniform3iv(location, count, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform4f (XWGLint location, XWGLfloat v0, XWGLfloat v1, XWGLfloat v2, XWGLfloat v3) {
       glUniform4f(location, v0, v1, v2, v3);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform4fv (XWGLint location, XWGLsizei count, const XWGLfloat *value) {
       glUniform4fv(location, count, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform4i (XWGLint location, XWGLint v0, XWGLint v1, XWGLint v2, XWGLint v3) {
       glUniform4i(location, v0, v1, v2, v3);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniform4iv (XWGLint location, XWGLsizei count, const XWGLint *value) {
       glUniform4iv(location, count, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniformMatrix2fv (XWGLint location, XWGLsizei count, XWGLbolean transpose, const XWGLfloat *value) {
       glUniformMatrix2fv(location, count, transpose, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniformMatrix3fv (XWGLint location, XWGLsizei count, XWGLbolean transpose, const XWGLfloat *value) {
       glUniformMatrix3fv(location, count, transpose, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::uniformMatrix4fv (XWGLint location, XWGLsizei count, XWGLbolean transpose, const XWGLfloat *value) {
       glUniformMatrix4fv(location, count, transpose, value);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::useProgram (XWGLuint program) {
       glUseProgram(program);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::validateProgram (XWGLuint program) {
       glValidateProgram(program);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::vertexAttrib1f (XWGLuint index, XWGLfloat x) {
       glVertexAttrib1f(index, x);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::vertexAttrib1fv (XWGLuint index, const XWGLfloat *v) {
       glVertexAttrib1fv(index, v);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::vertexAttrib2f (XWGLuint index, XWGLfloat x, XWGLfloat y) {
       glVertexAttrib2f(index, x, y);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::vertexAttrib2fv (XWGLuint index, const XWGLfloat *v) {
       glVertexAttrib2fv(index, v);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::vertexAttrib3f (XWGLuint index, XWGLfloat x, XWGLfloat y, XWGLfloat z) {
       glVertexAttrib3f(index, x, y, z);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::vertexAttrib3fv (XWGLuint index, const XWGLfloat *v) {
       glVertexAttrib3fv(index, v);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::vertexAttrib4f (XWGLuint index, XWGLfloat x, XWGLfloat y, XWGLfloat z, XWGLfloat w) {
       glVertexAttrib4f(index, x, y, z, w);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::vertexAttrib4fv (XWGLuint index, const XWGLfloat *v) {
       glVertexAttrib4fv(index, v);
 }

 void  XWalkWebGraphicsContext3DDirectImpl::vertexAttribPointer (XWGLuint index, XWGLint size, XWGLenum type, XWGLbolean normalized, XWGLsizei stride, const void *pointer) {
       glVertexAttribPointer(index, size, type, normalized, stride, pointer);
 }
 void  XWalkWebGraphicsContext3DDirectImpl::viewport (XWGLint x, XWGLint y, XWGLsizei width, XWGLsizei height) {
       glViewport(x, y, width, height);

 }

} // namespace content

