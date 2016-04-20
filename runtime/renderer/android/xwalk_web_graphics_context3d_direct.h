#ifndef XWALK_RUNTIME_RENDERER_ANDROID_XWALK_WEB_GRAPHICS_CONTEXT3D_DIRECT_H_
#define XWALK_RUNTIME_RENDERER_ANDROID_XWALK_WEB_GRAPHICS_CONTEXT3D_DIRECT_H_

#include "xwalk_web_graphics_context3d_direct_impl.h"
#include "third_party/WebKit/public/platform/WebGraphicsContext3D.h"
#include "stdlib.h"

namespace blink {

class XWalkWebGraphicsContext3DDirect : public WebGraphicsContext3D {


public:
    void setImplementation(content::XWalkWebGraphicsContext3DDirectImpl* impl) {
       mImpl = impl;
    }

    // This destructor needs to be public so that using classes can destroy instances if initialization fails.
    virtual ~XWalkWebGraphicsContext3DDirect() { }

    // GL_CHROMIUM_setVisibility - Changes the visibility of the backbuffer
     void setVisibilityCHROMIUM(bool visible) { }

    // Copies the contents of the off-screen render target used by the WebGL
    // context to the corresponding texture used by the compositor.
     void prepareTexture() { }

    // GL_CHROMIUM_post_sub_buffer - Copies part of the back buffer to the front buffer.
     void postSubBufferCHROMIUM(int x, int y, int width, int height) { }

    // Synthesizes an OpenGL error which will be returned from a
    // later call to getError. This is used to emulate OpenGL ES
    // 2.0 behavior on the desktop and to enforce additional error
    // checking mandated by WebGL.
    //
    // Per the behavior of glGetError, this stores at most one
    // instance of any given error, and returns them from calls to
    // getError in the order they were added.
     void synthesizeGLError(WGC3Denum) { }

     bool isContextLost() { return false; }

    // GL_CHROMIUM_map_sub
     void* mapBufferSubDataCHROMIUM(WGC3Denum target, WGC3Dintptr offset, WGC3Dsizeiptr size, WGC3Denum access) { return NULL; }
     void unmapBufferSubDataCHROMIUM(const void*) { }
     void* mapTexSubImage2DCHROMIUM(WGC3Denum target, WGC3Dint level, WGC3Dint xoffset, WGC3Dint yoffset, 
           WGC3Dsizei width, WGC3Dsizei height, WGC3Denum format, WGC3Denum type, WGC3Denum access) { return NULL; }
     void unmapTexSubImage2DCHROMIUM(const void*) { }

    // GL_CHROMIUM_request_extension
     WebString getRequestableExtensionsCHROMIUM() { return WebString::fromUTF8("notimplemented"); }
     void requestExtensionCHROMIUM(const char*) { }

    // GL_CHROMIUM_framebuffer_multisample
     void blitFramebufferCHROMIUM(WGC3Dint srcX0, WGC3Dint srcY0, WGC3Dint srcX1, WGC3Dint srcY1, 
     WGC3Dint dstX0, WGC3Dint dstY0, WGC3Dint dstX1, WGC3Dint dstY1, WGC3Dbitfield mask, WGC3Denum filter) { }
     void renderbufferStorageMultisampleCHROMIUM(WGC3Denum target, WGC3Dsizei samples, 
        WGC3Denum internalformat, WGC3Dsizei width, WGC3Dsizei height) { }

    // GL_CHROMIUM_lose_context
     void loseContextCHROMIUM(WGC3Denum current, WGC3Denum other) { }

    // The entry points below map directly to the OpenGL ES 2.0 API.
    // See: http://www.khronos.org/registry/gles/
    // and: http://www.khronos.org/opengles/sdk/docs/man/
     void activeTexture(WGC3Denum texture){
        mImpl->activeTexture(texture);
    }

     void attachShader(WebGLId program, WebGLId shader){
        mImpl->attachShader(program, shader);
    }

     void bindAttribLocation(WebGLId program, WGC3Duint index, const WGC3Dchar* name) {
        mImpl->bindAttribLocation(program, index, name);
    }

     void bindBuffer(WGC3Denum target, WebGLId buffer) {
        mImpl->bindBuffer(target, buffer);
    }

     void bindFramebuffer(WGC3Denum target, WebGLId framebuffer) {
         mImpl->bindFramebuffer(target, framebuffer);
    }

     void bindRenderbuffer(WGC3Denum target, WebGLId renderbuffer) {
        mImpl->bindRenderbuffer(target, renderbuffer);
    }

     void bindTexture(WGC3Denum target, WebGLId texture) {
        mImpl->bindTexture(target, texture);
    }

     void blendColor(WGC3Dclampf red, WGC3Dclampf green, WGC3Dclampf blue, WGC3Dclampf alpha) {
        mImpl->blendColor(red, green, blue, alpha);
    }

     void blendEquation(WGC3Denum mode) {
        mImpl->blendEquation(mode);
    }

     void blendEquationSeparate(WGC3Denum modeRGB, WGC3Denum modeAlpha) {
        mImpl->blendEquationSeparate(modeRGB, modeAlpha);
    }
     void blendFunc(WGC3Denum sfactor, WGC3Denum dfactor) {
       mImpl->blendFunc(sfactor, dfactor);
    }
     void blendFuncSeparate(WGC3Denum srcRGB, WGC3Denum dstRGB, WGC3Denum srcAlpha, WGC3Denum dstAlpha) {
       mImpl->blendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
     }

     void bufferData(WGC3Denum target, WGC3Dsizeiptr size, const void* data, WGC3Denum usage) { mImpl->bufferData(target, size, data, usage);}
     void bufferSubData(WGC3Denum target, WGC3Dintptr offset, WGC3Dsizeiptr size, const void* data) { mImpl->bufferSubData(target, offset, size, data);}

     WGC3Denum checkFramebufferStatus(WGC3Denum target) { return mImpl->checkFramebufferStatus(target);}
     void clear(WGC3Dbitfield mask) { mImpl->clear(mask);}
     void clearColor(WGC3Dclampf red, WGC3Dclampf green, WGC3Dclampf blue, WGC3Dclampf alpha) { mImpl->clearColor(red, green, blue, alpha);}
     void clearDepth(WGC3Dclampf depth) { mImpl->clearDepthf(depth);}
     void clearStencil(WGC3Dint s) { mImpl->clearStencil(s);}
     void colorMask(WGC3Dboolean red, WGC3Dboolean green, WGC3Dboolean blue, WGC3Dboolean alpha) { mImpl->colorMask(red, green, blue, alpha);}
     void compileShader(WebGLId shader) { mImpl->compileShader(shader);}

     void compressedTexImage2D(WGC3Denum target, WGC3Dint level, WGC3Denum internalformat, WGC3Dsizei width,
        WGC3Dsizei height, WGC3Dint border, WGC3Dsizei imageSize, const void* data) {
        mImpl->compressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);}
     void compressedTexSubImage2D(WGC3Denum target, WGC3Dint level, WGC3Dint xoffset, WGC3Dint yoffset,
        WGC3Dsizei width, WGC3Dsizei height, WGC3Denum format, WGC3Dsizei imageSize, const void* data) {
        mImpl->compressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);}
     void copyTexImage2D(WGC3Denum target, WGC3Dint level, WGC3Denum internalformat, WGC3Dint x, WGC3Dint y, WGC3Dsizei width,
        WGC3Dsizei height, WGC3Dint border) {
        mImpl->copyTexImage2D(target, level, internalformat, x, y, width, height, border);}
     void copyTexSubImage2D(WGC3Denum target, WGC3Dint level, WGC3Dint xoffset, WGC3Dint yoffset,
        WGC3Dint x, WGC3Dint y, WGC3Dsizei width, WGC3Dsizei height) {
        mImpl->copyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
     void cullFace(WGC3Denum mode) {mImpl->cullFace(mode); }
     void depthFunc(WGC3Denum func) {mImpl->depthFunc(func); }
     void depthMask(WGC3Dboolean flag) {mImpl->depthMask(flag); }
     void depthRange(WGC3Dclampf zNear, WGC3Dclampf zFar) {mImpl->depthRangef(zNear, zFar); }
     void detachShader(WebGLId program, WebGLId shader) {mImpl->detachShader(program, shader); }
     void disable(WGC3Denum cap) {mImpl->disable(cap); }
     void disableVertexAttribArray(WGC3Duint index) {mImpl->disableVertexAttribArray(index); }
     void drawArrays(WGC3Denum mode, WGC3Dint first, WGC3Dsizei count) {mImpl->drawArrays(mode, first, count); }
     
     void drawElements(WGC3Denum mode, WGC3Dsizei count, WGC3Denum type, WGC3Dintptr offset) {
        mImpl->drawElements(mode, count, type, (const void*)offset);
     }
     
     void enable(WGC3Denum cap) {mImpl->enable(cap); }
     void enableVertexAttribArray(WGC3Duint index) {mImpl->enableVertexAttribArray(index); }
     void finish() {mImpl->finish(); }
     void flush() {mImpl->flush(); }
     void framebufferRenderbuffer(WGC3Denum target, WGC3Denum attachment, WGC3Denum renderbuffertarget, WebGLId renderbuffer) { 
        mImpl->framebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);}
     void framebufferTexture2D(WGC3Denum target, WGC3Denum attachment, WGC3Denum textarget, WebGLId texture, WGC3Dint level) {
        mImpl->framebufferTexture2D(target, attachment,textarget, texture, level);  }

     void frontFace(WGC3Denum mode) {mImpl->frontFace(mode); }
     void generateMipmap(WGC3Denum target) {mImpl->generateMipmap(target); }

     bool getActiveAttrib(WebGLId program, WGC3Duint index, ActiveInfo& info) {
        int bufSize = info.name.length();
        int length =0;
        mImpl->getActiveAttrib(program, index, bufSize, &length, &info.size, &info.type,  (char*)(info.name.utf8().data()));
        return true;
     }
     bool getActiveUniform(WebGLId program, WGC3Duint index, ActiveInfo& info) {
        int bufSize = info.name.length();
        int length =0;
        mImpl->getActiveUniform(program, index, bufSize, &length, &info.size, &info.type, (char*)(info.name.utf8().data()));
        return true;
     }
     void getAttachedShaders(WebGLId program, WGC3Dsizei maxCount, WGC3Dsizei* count, WebGLId* shaders) {
        mImpl->getAttachedShaders(program, maxCount, count, shaders); }
     WGC3Dint getAttribLocation(WebGLId program, const WGC3Dchar* name) {
        return mImpl->getAttribLocation(program, name); }
     void getBooleanv(WGC3Denum pname, WGC3Dboolean* value) {
        mImpl->getBooleanv(pname, value); }
     void getBufferParameteriv(WGC3Denum target, WGC3Denum pname, WGC3Dint* value) {
        mImpl->getBufferParameteriv(target, pname, value);}
     WGC3Denum getError() {return mImpl->getError(); }
     void getFloatv(WGC3Denum pname, WGC3Dfloat* value) {mImpl->getFloatv(pname, value); }
     void getFramebufferAttachmentParameteriv(WGC3Denum target, WGC3Denum attachment, WGC3Denum pname, WGC3Dint* value) {
          mImpl->getFramebufferAttachmentParameteriv(target, attachment, pname, value); }
     void getIntegerv(WGC3Denum pname, WGC3Dint* value) {mImpl->getIntegerv(pname, value); }
     void getProgramiv(WebGLId program, WGC3Denum pname, WGC3Dint* value) {mImpl->getProgramiv(program, pname, value); }

     
     WebString getProgramInfoLog(WebGLId program){
        char log[2048];
        int logLength=0;
        mImpl->getProgramInfoLog(program, 2048, &logLength, log); 
        return WebString::fromUTF8(log);
     }

     void getRenderbufferParameteriv(WGC3Denum target, WGC3Denum pname, WGC3Dint* value) {
          mImpl->getRenderbufferParameteriv(target, pname, value); }
     void getShaderiv(WebGLId shader, WGC3Denum pname, WGC3Dint* value) {
          mImpl->getShaderiv(shader, pname, value); }
          
     WebString getShaderInfoLog(WebGLId shader) {
        char log[2048];
        int logLength=0;
        mImpl->getShaderInfoLog(shader, 2048, &logLength, log);
        return WebString::fromUTF8(log);
     }

     
     void getShaderPrecisionFormat(WGC3Denum shadertype, WGC3Denum precisiontype, WGC3Dint* range, WGC3Dint* precision) {
         mImpl->getShaderPrecisionFormat(shadertype, precisiontype, range, precision); }
         
     WebString getShaderSource(WebGLId shader) {
        char* shaderSource = NULL;
        int sourceLength = 0;
        int shaderLength = 1;
        
        while(shaderLength >= sourceLength)
        {
            if(shaderSource != NULL)
                free(shaderSource);
            sourceLength += 2048;
            shaderSource = (char*) malloc(sourceLength);
            mImpl->getShaderInfoLog(shader, 2048, &shaderLength, shaderSource);
        }
        return WebString::fromUTF8((const char*)shaderSource);
     }


     
     WebString getString(WGC3Denum name) {return WebString::fromUTF8((const char*) (mImpl->getString(name))); }
     void getTexParameterfv(WGC3Denum target, WGC3Denum pname, WGC3Dfloat* value) {mImpl->getTexParameterfv(target, pname, value); }
     void getTexParameteriv(WGC3Denum target, WGC3Denum pname, WGC3Dint* value) {mImpl->getTexParameteriv(target, pname, value); }
     void getUniformfv(WebGLId program, WGC3Dint location, WGC3Dfloat* value) {mImpl->getUniformfv(program, location, value); }
     void getUniformiv(WebGLId program, WGC3Dint location, WGC3Dint* value) {mImpl->getUniformiv(program, location, value); }
     WGC3Dint getUniformLocation(WebGLId program, const WGC3Dchar* name) {return mImpl->getUniformLocation(program, name); }
     void getVertexAttribfv(WGC3Duint index, WGC3Denum pname, WGC3Dfloat* value) {mImpl->getVertexAttribfv(index, pname, value); }
     void getVertexAttribiv(WGC3Duint index, WGC3Denum pname, WGC3Dint* value) {mImpl->getVertexAttribiv(index, pname, value); }
     WGC3Dintptr getVertexAttribOffset(WGC3Duint index, WGC3Denum pname) {
         return 0;
        /*return mImpl->getVertexAttribOffset(index, pname);*/ }

     void hint(WGC3Denum target, WGC3Denum mode) { mImpl->hint(target, mode);}
     WGC3Dboolean isBuffer(WebGLId buffer) { return mImpl->isBuffer(buffer);}
     WGC3Dboolean isEnabled(WGC3Denum cap) { return mImpl->isEnabled(cap);}
     WGC3Dboolean isFramebuffer(WebGLId framebuffer) { return mImpl->isFramebuffer(framebuffer);}
     WGC3Dboolean isProgram(WebGLId program) { return mImpl->isProgram(program);}
     WGC3Dboolean isRenderbuffer(WebGLId renderbuffer) { return mImpl->isRenderbuffer(renderbuffer);}
     WGC3Dboolean isShader(WebGLId shader) { return mImpl->isShader(shader);}
     WGC3Dboolean isTexture(WebGLId texture) { return mImpl->isTexture(texture);}
     void lineWidth(WGC3Dfloat width) { mImpl->lineWidth(width);}
     void linkProgram(WebGLId program) { mImpl->linkProgram(program);}
     void pixelStorei(WGC3Denum pname, WGC3Dint param) { mImpl->pixelStorei(pname, param);}
     void polygonOffset(WGC3Dfloat factor, WGC3Dfloat units) { mImpl->polygonOffset(factor, units);}

     void readPixels(WGC3Dint x, WGC3Dint y, WGC3Dsizei width, WGC3Dsizei height, WGC3Denum format, WGC3Denum type, void* pixels) {
          mImpl->readPixels(x, y, width, height, format, type, pixels); }

     void releaseShaderCompiler() { mImpl->releaseShaderCompiler();}

     void renderbufferStorage(WGC3Denum target, WGC3Denum internalformat, WGC3Dsizei width, WGC3Dsizei height) {
          mImpl->renderbufferStorage(target, internalformat, width, height); }
     void sampleCoverage(WGC3Dclampf value, WGC3Dboolean invert) {
          mImpl->sampleCoverage(value, invert);}
     void scissor(WGC3Dint x, WGC3Dint y, WGC3Dsizei width, WGC3Dsizei height) {
          mImpl->scissor(x, y,width, height); }
     void shaderSource(WebGLId shader, const WGC3Dchar* string) {
          WGC3Dint length = strlen(string); mImpl->shaderSource(shader, 1, (const WGC3Dchar**)&string, (const WGC3Dint*)&length ); }
     void stencilFunc(WGC3Denum func, WGC3Dint ref, WGC3Duint mask) {
          mImpl->stencilFunc(func, ref, mask); }
     void stencilFuncSeparate(WGC3Denum face, WGC3Denum func, WGC3Dint ref, WGC3Duint mask) {
          mImpl->stencilFuncSeparate(face, func, ref, mask);}
     void stencilMask(WGC3Duint mask) { mImpl->stencilMask(mask);}
     void stencilMaskSeparate(WGC3Denum face, WGC3Duint mask) { mImpl->stencilMaskSeparate(face, mask);}
     void stencilOp(WGC3Denum fail, WGC3Denum zfail, WGC3Denum zpass) { mImpl->stencilOp(fail, zfail, zpass);}
     void stencilOpSeparate(WGC3Denum face, WGC3Denum fail, WGC3Denum zfail, WGC3Denum zpass) { mImpl->stencilOpSeparate(face, fail, zfail, zpass);}

     void texImage2D(WGC3Denum target, WGC3Dint level, WGC3Denum internalformat, WGC3Dsizei width, WGC3Dsizei height,
        WGC3Dint border, WGC3Denum format, WGC3Denum type, const void* pixels) {
        mImpl->texImage2D(target, level, internalformat,width, height, border, format, type, pixels);}

     void texParameterf(WGC3Denum target, WGC3Denum pname, WGC3Dfloat param) {
        mImpl->texParameterf(target, pname, param); }
     void texParameteri(WGC3Denum target, WGC3Denum pname, WGC3Dint param) { mImpl->texParameteri(target, pname, param);}

     void texSubImage2D(WGC3Denum target, WGC3Dint level, WGC3Dint xoffset, WGC3Dint yoffset, WGC3Dsizei width,
        WGC3Dsizei height, WGC3Denum format, WGC3Denum type, const void* pixels) {
        mImpl->texSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }

     void uniform1f(WGC3Dint location, WGC3Dfloat x) {mImpl->uniform1f(location, x); }
     void uniform1fv(WGC3Dint location, WGC3Dsizei count, const WGC3Dfloat* v) {mImpl->uniform1fv(location, count, v); }
     void uniform1i(WGC3Dint location, WGC3Dint x) { mImpl->uniform1i(location, x);}
     void uniform1iv(WGC3Dint location, WGC3Dsizei count, const WGC3Dint* v) { mImpl->uniform1iv(location, count, v);}
     void uniform2f(WGC3Dint location, WGC3Dfloat x, WGC3Dfloat y) { mImpl->uniform2f(location, x, y); }
     void uniform2fv(WGC3Dint location, WGC3Dsizei count, const WGC3Dfloat* v) { mImpl->uniform2fv(location, count, v);}
     void uniform2i(WGC3Dint location, WGC3Dint x, WGC3Dint y) { mImpl->uniform2i(location, x, y);}
     void uniform2iv(WGC3Dint location, WGC3Dsizei count, const WGC3Dint* v) { mImpl->uniform2iv(location, count, v); }
     void uniform3f(WGC3Dint location, WGC3Dfloat x, WGC3Dfloat y, WGC3Dfloat z) { mImpl->uniform3f(location, x, y, z);}
     void uniform3fv(WGC3Dint location, WGC3Dsizei count, const WGC3Dfloat* v) { mImpl->uniform3fv(location, count, v); }
     void uniform3i(WGC3Dint location, WGC3Dint x, WGC3Dint y, WGC3Dint z) { mImpl->uniform3i(location, x, y, z);}
     void uniform3iv(WGC3Dint location, WGC3Dsizei count, const WGC3Dint* v) { mImpl->uniform3iv(location, count, v);}
     void uniform4f(WGC3Dint location, WGC3Dfloat x, WGC3Dfloat y, WGC3Dfloat z, WGC3Dfloat w) { mImpl->uniform4f(location, x, y, z, w);}
     void uniform4fv(WGC3Dint location, WGC3Dsizei count, const WGC3Dfloat* v) { mImpl->uniform4fv(location, count, v);}
     void uniform4i(WGC3Dint location, WGC3Dint x, WGC3Dint y, WGC3Dint z, WGC3Dint w) { mImpl->uniform4i(location, x, y, z, w);}
     void uniform4iv(WGC3Dint location, WGC3Dsizei count, const WGC3Dint* v) { mImpl->uniform4iv(location, count, v);}
     void uniformMatrix2fv(WGC3Dint location, WGC3Dsizei count, WGC3Dboolean transpose, const WGC3Dfloat* value) {
        mImpl->uniformMatrix2fv(location, count, transpose, value); }
     void uniformMatrix3fv(WGC3Dint location, WGC3Dsizei count, WGC3Dboolean transpose, const WGC3Dfloat* value) {
        mImpl->uniformMatrix3fv(location, count, transpose, value); }
     void uniformMatrix4fv(WGC3Dint location, WGC3Dsizei count, WGC3Dboolean transpose, const WGC3Dfloat* value) {
        mImpl->uniformMatrix4fv(location, count, transpose, value); }

     void useProgram(WebGLId program) { mImpl->useProgram(program);}
     void validateProgram(WebGLId program) { mImpl->validateProgram(program);}

     void vertexAttrib1f(WGC3Duint index, WGC3Dfloat x) { mImpl->vertexAttrib1f(index,x);}
     void vertexAttrib1fv(WGC3Duint index, const WGC3Dfloat* values) { mImpl->vertexAttrib1fv(index, values);}
     void vertexAttrib2f(WGC3Duint index, WGC3Dfloat x, WGC3Dfloat y) { mImpl->vertexAttrib2f(index, x, y);}
     void vertexAttrib2fv(WGC3Duint index, const WGC3Dfloat* values) { mImpl->vertexAttrib2fv(index, values);}
     void vertexAttrib3f(WGC3Duint index, WGC3Dfloat x, WGC3Dfloat y, WGC3Dfloat z) { mImpl->vertexAttrib3f(index, x, y, z);}
     void vertexAttrib3fv(WGC3Duint index, const WGC3Dfloat* values) { mImpl->vertexAttrib3fv(index, values);}
     void vertexAttrib4f(WGC3Duint index, WGC3Dfloat x, WGC3Dfloat y, WGC3Dfloat z, WGC3Dfloat w) { mImpl->vertexAttrib4f(index, x, y, z, w); }
     void vertexAttrib4fv(WGC3Duint index, const WGC3Dfloat* values) { mImpl->vertexAttrib4fv(index, values);}
     void vertexAttribPointer(WGC3Duint index, WGC3Dint size, WGC3Denum type, WGC3Dboolean normalized,
                                     WGC3Dsizei stride, WGC3Dintptr offset) {  mImpl->vertexAttribPointer(index, size, type, normalized, stride, (const void*)offset);}

     void viewport(WGC3Dint x, WGC3Dint y, WGC3Dsizei width, WGC3Dsizei height) { mImpl->viewport(x, y, width, height);}

     WebGLId createBuffer() { WebGLId id; mImpl->genBuffers(1, &id);  return id; }
     WebGLId createFramebuffer() { WebGLId id; mImpl->genFramebuffers(1, &id); return id;}
     WebGLId createRenderbuffer() { WebGLId id; mImpl->genRenderbuffers(1, &id); return id;}
     WebGLId createTexture() { WebGLId id; mImpl->genTextures(1, &id); return id;}

     void deleteBuffer(WebGLId id) { mImpl->deleteBuffers(1, (const WebGLId*)&id);}
     void deleteFramebuffer(WebGLId id) { mImpl->deleteFramebuffers(1, (const WebGLId*)&id);}
     void deleteRenderbuffer(WebGLId id) { mImpl->deleteRenderbuffers(1, (const WebGLId*) &id);}
     void deleteTexture(WebGLId id) { mImpl->deleteTextures(1, (const WebGLId*)&id);}

     WebGLId createProgram() { return mImpl->createProgram();}
     WebGLId createShader(WGC3Denum type) { return mImpl->createShader(type);}

     void deleteShader(WebGLId id) { mImpl->deleteShader(id);}
     void deleteProgram(WebGLId id) { mImpl->deleteProgram(id);}

     void setContextLostCallback(WebGraphicsContextLostCallback* callback) {}
     void setErrorMessageCallback(WebGraphicsErrorMessageCallback* callback) {}
    // GL_ARB_robustness
    //
    // This entry point must provide slightly different semantics than
    // the GL_ARB_robustness extension; specifically, the lost context
    // state is sticky, rather than reported only once.
     WGC3Denum getGraphicsResetStatusARB() { return 0; /* GL_NO_ERROR */ }

     WebString getTranslatedShaderSourceANGLE(WebGLId shader)  { return WebString::fromUTF8("invalid"); }

    // GL_CHROMIUM_screen_space_antialiasing
     void applyScreenSpaceAntialiasingCHROMIUM() { }

    // GL_CHROMIUM_iosurface
     void texImageIOSurface2DCHROMIUM(WGC3Denum target, WGC3Dint width, WGC3Dint height, WGC3Duint ioSurfaceId, WGC3Duint plane) { }

    // GL_EXT_texture_storage
     void texStorage2DEXT(WGC3Denum target, WGC3Dint levels, WGC3Duint internalformat,
                                 WGC3Dint width, WGC3Dint height) { }

    // GL_EXT_occlusion_query
     WebGLId createQueryEXT() { return 0; }
     void deleteQueryEXT(WebGLId query) { }
     WGC3Dboolean isQueryEXT(WebGLId query) { return false; }
     void beginQueryEXT(WGC3Denum target, WebGLId query) { }
     void endQueryEXT(WGC3Denum target) { }
     void getQueryivEXT(WGC3Denum target, WGC3Denum pname, WGC3Dint* params) { }
     void getQueryObjectuivEXT(WebGLId query, WGC3Denum pname, WGC3Duint* params) { }

    // GL_EXT_disjoint_timer_query
     void queryCounterEXT(WebGLId query, WGC3Denum target) {}
     void getQueryObjectui64vEXT(WebGLId query, WGC3Denum pname, WGC3Duint64* params) {}

    // GL_CHROMIUM_bind_uniform_location
     void bindUniformLocationCHROMIUM(WebGLId program, WGC3Dint location, const WGC3Dchar* uniform) { }

    // GL_CHROMIUM_copy_texture
     void copyTextureCHROMIUM(WGC3Denum target, WGC3Duint sourceId,
        WGC3Duint destId, WGC3Denum internalFormat, WGC3Denum destType,
        WGC3Dboolean unpackFlipY, WGC3Dboolean unpackPremultiplyAlpha, WGC3Dboolean unpackUnmultiplyAlpha) { }
     void copySubTextureCHROMIUM(WGC3Denum target, WGC3Duint sourceId,
        WGC3Duint destId, WGC3Dint xoffset, WGC3Dint yoffset, WGC3Dint x,
        WGC3Dint y, WGC3Dsizei width, WGC3Dsizei height,
        WGC3Dboolean unpackFlipY, WGC3Dboolean unpackPremultiplyAlpha, WGC3Dboolean unpackUnmultiplyAlpha) { }

    // GL_CHROMIUM_shallow_flush
     void shallowFlushCHROMIUM() { }
     void shallowFinishCHROMIUM() { }

    // GL_CHROMIUM_subscribe_uniform
     void genValuebuffersCHROMIUM(WGC3Dsizei count, WebGLId* ids) { }
     WebGLId createValuebufferCHROMIUM() { return 0; }
     void deleteValuebuffersCHROMIUM(WGC3Dsizei count, WebGLId* ids) { }
     void deleteValuebufferCHROMIUM(WebGLId) { }
     WGC3Dboolean isValuebufferCHROMIUM(WebGLId renderbuffer) { return false; }
     void bindValuebufferCHROMIUM(WGC3Denum target, WebGLId valuebuffer) { }
     void subscribeValueCHROMIUM(WGC3Denum target, WGC3Denum subscription) { }
     void populateSubscribedValuesCHROMIUM(WGC3Denum target) { }
     void uniformValuebufferCHROMIUM(WGC3Dint location, WGC3Denum target, WGC3Denum subscription) { }

    // GL_CHROMIUM_texture_mailbox
     void genMailboxCHROMIUM(WGC3Dbyte* mailbox) { }
     void produceTextureCHROMIUM(WGC3Denum target, const WGC3Dbyte* mailbox) { }
     void produceTextureDirectCHROMIUM(WebGLId texture, WGC3Denum target, const WGC3Dbyte* mailbox) { }

     void consumeTextureCHROMIUM(WGC3Denum target, const WGC3Dbyte* mailbox) { }
     WebGLId createAndConsumeTextureCHROMIUM(WGC3Denum target, const WGC3Dbyte* mailbox) { return 0; }

    // GL_EXT_debug_marker
     void insertEventMarkerEXT(const WGC3Dchar* marker) { }
     void pushGroupMarkerEXT(const WGC3Dchar* marker) { }
     void popGroupMarkerEXT(void) { }

    // GL_CHROMIUM_trace_marker
     void traceBeginCHROMIUM(const WGC3Dchar* category, const WGC3Dchar* trace) { }
     void traceEndCHROMIUM() { }

    // GL_OES_vertex_array_object
     WebGLId createVertexArrayOES() { return 0; }
     void deleteVertexArrayOES(WebGLId array) { }
     WGC3Dboolean isVertexArrayOES(WebGLId array) { return false; }
     void bindVertexArrayOES(WebGLId array) { }

    // GL_CHROMIUM_texture_from_image
     void bindTexImage2DCHROMIUM(WGC3Denum target, WGC3Dint imageId) { }
     void releaseTexImage2DCHROMIUM(WGC3Denum target, WGC3Dint imageId) { }

    // GL_CHROMIUM_pixel_transfer_buffer_object
     void* mapBufferCHROMIUM(WGC3Denum target, WGC3Denum access) { return nullptr; }
     WGC3Dboolean unmapBufferCHROMIUM(WGC3Denum target) { return false; }

    // GL_CHROMIUM_async_pixel_transfers
     void asyncTexImage2DCHROMIUM(WGC3Denum target, WGC3Dint level, WGC3Denum internalformat, WGC3Dsizei width, WGC3Dsizei height, WGC3Dint border, WGC3Denum format, WGC3Denum type, const void* pixels) { }
     void asyncTexSubImage2DCHROMIUM(WGC3Denum target, WGC3Dint level, WGC3Dint xoffset, WGC3Dint yoffset, WGC3Dsizei width, WGC3Dsizei height, WGC3Denum format, WGC3Denum type, const void* pixels) { }
     void waitAsyncTexImage2DCHROMIUM(WGC3Denum) { }

    // GL_EXT_draw_buffers
     void drawBuffersEXT(WGC3Dsizei n, const WGC3Denum* bufs) { }

    // GL_CHROMIUM_image
     void destroyImageCHROMIUM(WGC3Duint imageId) { }

    // GL_CHROMIUM_gpu_memory_buffer_image
     WGC3Duint createGpuMemoryBufferImageCHROMIUM(WGC3Dsizei width, WGC3Dsizei height, WGC3Denum internalformat, WGC3Denum usage) { return 0; }

    // GL_ANGLE_instanced_arrays
     void drawArraysInstancedANGLE(WGC3Denum mode, WGC3Dint first, WGC3Dsizei count, WGC3Dsizei primcount) { }
     void drawElementsInstancedANGLE(WGC3Denum mode, WGC3Dsizei count, WGC3Denum type, WGC3Dintptr offset, WGC3Dsizei primcount) { }
     void vertexAttribDivisorANGLE(WGC3Duint index, WGC3Duint divisor) { }

    // GL_EXT_multisampled_render_to_texture
     void framebufferTexture2DMultisampleEXT(WGC3Denum target, WGC3Denum attachment, WGC3Denum textarget, WebGLId texture, WGC3Dint level, WGC3Dsizei samples) { }
     void renderbufferStorageMultisampleEXT(WGC3Denum target, WGC3Dsizei samples, WGC3Denum internalformat, WGC3Dsizei width, WGC3Dsizei height) { }

    // OpenGL ES 3.0 functions not represented by pre-existing extensions
     void beginTransformFeedback(WGC3Denum primitiveMode) {}
     void bindBufferBase(WGC3Denum target, WGC3Duint index, WebGLId buffer) { }
     void bindBufferRange(WGC3Denum target, WGC3Duint index, WebGLId buffer, WGC3Dintptr offset, WGC3Dsizeiptr size) { }
     void bindSampler(WGC3Duint unit, WebGLId sampler) { }
     void bindTransformFeedback(WGC3Denum target, WebGLId transformfeedback) { }
     void clearBufferfi(WGC3Denum buffer, WGC3Dint drawbuffer, WGC3Dfloat depth, WGC3Dint stencil) { }
     void clearBufferfv(WGC3Denum buffer, WGC3Dint drawbuffer, const WGC3Dfloat *value) { }
     void clearBufferiv(WGC3Denum buffer, WGC3Dint drawbuffer, const WGC3Dint *value) { }
     void clearBufferuiv(WGC3Denum buffer, WGC3Dint drawbuffer, const WGC3Duint *value) { }
     WGC3Denum clientWaitSync(WGC3Dsync sync, WGC3Dbitfield flags, WGC3Duint64 timeout) { return 0x911D; /* GL_WAIT_FAILED */ }
     void compressedTexImage3D(WGC3Denum target, WGC3Dint level, WGC3Denum internalformat, WGC3Dsizei width,
        WGC3Dsizei height, WGC3Dsizei depth, WGC3Dint border, WGC3Dsizei imageSize, const void *data) { }
     void compressedTexSubImage3D(WGC3Denum target, WGC3Dint level, WGC3Dint xoffset, WGC3Dint yoffset,
        WGC3Dint zoffset, WGC3Dsizei width, WGC3Dsizei height, WGC3Dsizei depth, WGC3Denum format, WGC3Dsizei imageSize, const void *data) {}
     void copyBufferSubData(WGC3Denum readTarget, WGC3Denum writeTarget, WGC3Dintptr readOffset, WGC3Dintptr writeOffset, WGC3Dsizeiptr size) { }
     void copyTexSubImage3D(WGC3Denum target, WGC3Dint level, WGC3Dint xoffset, WGC3Dint yoffset, WGC3Dint zoffset,
        WGC3Dint x, WGC3Dint y, WGC3Dsizei width, WGC3Dsizei height) { }
     WebGLId createSampler() { return -1;}
     WebGLId createTransformFeedback() { return -1; }
     void deleteSampler(WebGLId sampler) { }
     void deleteSync(WGC3Dsync sync) { }
     void deleteTransformFeedback(WebGLId transformfeedback) { }
     void drawRangeElements(WGC3Denum mode, WGC3Duint start, WGC3Duint end, WGC3Dsizei count, WGC3Denum type, WGC3Dintptr offset) { }
     void endTransformFeedback(void) { }
     WGC3Dsync fenceSync(WGC3Denum condition, WGC3Dbitfield flags) { return nullptr; }
     void framebufferTextureLayer(WGC3Denum target, WGC3Denum attachment, WGC3Duint texture, WGC3Dint level, WGC3Dint layer) { }
     void getActiveUniformBlockName(WebGLId program, WGC3Duint uniformBlockIndex, WGC3Dsizei bufSize, WGC3Dsizei *length,
        WGC3Dchar *uniformBlockName) {}
     void getActiveUniformBlockiv(WebGLId program, WGC3Duint uniformBlockIndex,
        WGC3Denum pname, WGC3Dint *params) { }
     void getActiveUniformsiv(WebGLId program, WGC3Dsizei uniformCount,
        const WGC3Duint *uniformIndices, WGC3Denum pname, WGC3Dint *params) { }
     void getBufferParameteri64v(WGC3Denum target, WGC3Denum pname, WGC3Dint64 *value) { }
     WGC3Dint getFragDataLocation(WebGLId program, const WGC3Dchar *name) { return -1; }
     void getInteger64v(WGC3Denum pname, WGC3Dint64 *data) { }
     void getIntegeri_v(WGC3Denum target, WGC3Duint index, WGC3Dint *data) { }
     void getInteger64i_v(WGC3Denum target, WGC3Duint index, WGC3Dint64 *data) { }
     void getInternalformativ(WGC3Denum target, WGC3Denum internalformat, WGC3Denum pname, WGC3Dsizei bufSize, WGC3Dint *params) { }
     void getSamplerParameterfv(WebGLId sampler, WGC3Denum pname, WGC3Dfloat *params) { }
     void getSamplerParameteriv(WebGLId sampler, WGC3Denum pname, WGC3Dint *params) { }
     void getSynciv(WGC3Dsync sync, WGC3Denum pname, WGC3Dsizei bufSize, WGC3Dsizei *length, WGC3Dint *params) { }
     void getTransformFeedbackVarying(WebGLId program, WGC3Duint index, WGC3Dsizei bufSize, WGC3Dsizei *length,
        WGC3Dsizei *size, WGC3Denum *type, WGC3Dchar *name) {}
     WGC3Duint getUniformBlockIndex(WebGLId program, const WGC3Dchar *uniformBlockName) { return  -1; }
     void getUniformIndices(WebGLId program, WGC3Dsizei uniformCount, const WGC3Dchar *const*uniformNames, WGC3Duint *uniformIndices) {
     }
     void getUniformuiv(WebGLId program, WGC3Dint location, WGC3Duint *params) {
     }
     void getVertexAttribIiv(WGC3Duint index, WGC3Denum pname, WGC3Dint *params) {
     }
     void getVertexAttribIuiv(WGC3Duint index, WGC3Denum pname, WGC3Duint *params) {
     }
     void invalidateFramebuffer(WGC3Denum target, WGC3Dsizei numAttachments, const WGC3Denum *attachments) {
     }
     void invalidateSubFramebuffer(WGC3Denum target, WGC3Dsizei numAttachments, const WGC3Denum *attachments,
        WGC3Dint x, WGC3Dint y, WGC3Dsizei width, WGC3Dsizei height) {
     }
     WGC3Dboolean isSampler(WebGLId sampler) { return false;}
     WGC3Dboolean isSync(WGC3Dsync sync) { return false;}
     WGC3Dboolean isTransformFeedback(WebGLId transformfeedback) { return false; }
     void* mapBufferRange(WGC3Denum target, WGC3Dintptr offset, WGC3Dsizeiptr length, WGC3Dbitfield access) { return NULL; }
     void pauseTransformFeedback(void) { }
     void programParameteri(WebGLId program, WGC3Denum pname, WGC3Dint value) { }
     void readBuffer(WGC3Denum src) { }
     void resumeTransformFeedback(void) { }
     void samplerParameterf(WebGLId sampler, WGC3Denum pname, WGC3Dfloat param) { }
     void samplerParameterfv(WebGLId sampler, WGC3Denum pname, const WGC3Dfloat *param) { }
     void samplerParameteri(WebGLId sampler, WGC3Denum pname, WGC3Dint param) { }
     void samplerParameteriv(WebGLId sampler, WGC3Denum pname, const WGC3Dint *param) { }
     void texImage3D(WGC3Denum target, WGC3Dint level, WGC3Dint internalformat, WGC3Dsizei width, WGC3Dsizei height, WGC3Dsizei depth, WGC3Dint border, WGC3Denum format, WGC3Denum type, const void *pixels) { }
     void texStorage3D(WGC3Denum target, WGC3Dsizei levels, WGC3Denum internalformat, WGC3Dsizei width, WGC3Dsizei height, WGC3Dsizei depth) { }
     void texSubImage3D(WGC3Denum target, WGC3Dint level, WGC3Dint xoffset, WGC3Dint yoffset, WGC3Dint zoffset, WGC3Dsizei width, WGC3Dsizei height, WGC3Dsizei depth, WGC3Denum format, WGC3Denum type, const void *pixels) { }
     void transformFeedbackVaryings(WebGLId program, WGC3Dsizei count, const WGC3Dchar *const*varyings, WGC3Denum bufferMode) { }
     void uniform1ui(WGC3Dint location, WGC3Duint x) { }
     void uniform1uiv(WGC3Dint location, WGC3Dsizei count, const WGC3Duint *value) { }
     void uniform2ui(WGC3Dint location, WGC3Duint x, WGC3Duint y) { }
     void uniform2uiv(WGC3Dint location, WGC3Dsizei count, const WGC3Duint *value) { }
     void uniform3ui(WGC3Dint location, WGC3Duint x, WGC3Duint y, WGC3Duint z) { }
     void uniform3uiv(WGC3Dint location, WGC3Dsizei count, const WGC3Duint *value) { }
     void uniform4ui(WGC3Dint location, WGC3Duint x, WGC3Duint y, WGC3Duint z, WGC3Duint w) { }
     void uniform4uiv(WGC3Dint location, WGC3Dsizei count, const WGC3Duint *value) { }
     void uniformBlockBinding(WebGLId program, WGC3Duint uniformBlockIndex, WGC3Duint uniformBlockBinding) { }
     void uniformMatrix2x3fv(WGC3Dint location, WGC3Dsizei count, WGC3Dboolean transpose, const WGC3Dfloat* value) { }
     void uniformMatrix2x4fv(WGC3Dint location, WGC3Dsizei count, WGC3Dboolean transpose, const WGC3Dfloat* value) { }
     void uniformMatrix3x2fv(WGC3Dint location, WGC3Dsizei count, WGC3Dboolean transpose, const WGC3Dfloat* value) { }
     void uniformMatrix3x4fv(WGC3Dint location, WGC3Dsizei count, WGC3Dboolean transpose, const WGC3Dfloat* value) { }
     void uniformMatrix4x2fv(WGC3Dint location, WGC3Dsizei count, WGC3Dboolean transpose, const WGC3Dfloat* value) { }
     void uniformMatrix4x3fv(WGC3Dint location, WGC3Dsizei count, WGC3Dboolean transpose, const WGC3Dfloat* value) { }
     WGC3Dboolean unmapBuffer(WGC3Denum target) { return false; }

     void vertexAttribI4i(WGC3Duint index, WGC3Dint x, WGC3Dint y, WGC3Dint z, WGC3Dint w) { }
     void vertexAttribI4iv(WGC3Duint index, const WGC3Dint *v) { }
     void vertexAttribI4ui(WGC3Duint index, WGC3Duint x, WGC3Duint y, WGC3Duint z, WGC3Duint w) { }
     void vertexAttribI4uiv(WGC3Duint index, const WGC3Duint *v) { }
     void vertexAttribIPointer(WGC3Duint index, WGC3Dint size, WGC3Denum type, WGC3Dsizei stride, WGC3Dintptr pointer) { }
     void waitSync(WGC3Dsync sync, WGC3Dbitfield flags, WGC3Duint64 timeout) { }

private:
     content::XWalkWebGraphicsContext3DDirectImpl* mImpl;

};
}
#endif // XWALK_RUNTIME_RENDERER_ANDROID_XWALK_WEB_GRAPHICS_CONTEXT3D_DIRECT_H_

