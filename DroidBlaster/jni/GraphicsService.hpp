/*
 * GraphicsService.hpp
 *
 *  Created on: 2012-7-12
 *      Author: mcxiaoke
 */

#ifndef GRAPHICSSERVICE_HPP_
#define GRAPHICSSERVICE_HPP_

// eclipse not define __ANDROID__, this is a hack
#ifndef __ANDROID__
#define __ANDROID__ 1
#endif

#include "GraphicsSprite.hpp"
#include "GraphicsTexture.hpp"
#include "TimeService.hpp"
#include "Types.hpp"

#include <android_native_app_glue.h>
#include <EGL/egl.h>

namespace demo {
class GraphicsService {
public:
    GraphicsService(android_app *app, TimeService *ts);
    ~GraphicsService();

    const char* getPath();
    const int32_t& getHeight();
    const int32_t& getWidth();

    status start();
    void stop();
    status update();

    GraphicsTexture* registerTexture(const char* path);
    GraphicsSprite* registerSprite(GraphicsTexture* texture, int32_t height,
            int32_t width, Location* location);
protected:
    status loadResources();
    status unloadResources();
    void setup();
private:
    android_app *mApp;
    TimeService *mTimeService;
    int32_t mWidth;
    int32_t mHeight;
    EGLDisplay mDisplay;
    EGLSurface mSurface;
    EGLContext mContext;
    GraphicsTexture* mTextures[32];
    int32_t mTextureCount;
    GraphicsSprite* mSprites[256];
    int32_t mSpriteCount;
};
}

#endif /* GRAPHICSSERVICE_HPP_ */
