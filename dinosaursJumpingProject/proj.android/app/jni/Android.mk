LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := $(LOCAL_PATH)/hellocpp/main.cpp \
                   $(LOCAL_PATH)/../../../Classes/AppDelegate.cpp \
                   $(LOCAL_PATH)/../../../Classes/Character.cpp \
                   $(LOCAL_PATH)/../../../Classes/Sprites.cpp \        
                   $(LOCAL_PATH)/../../../Classes/SceneManager.cpp \
                   $(LOCAL_PATH)/../../../Classes/Player.cpp \ 
                   $(LOCAL_PATH)/../../../Classes/CScene.cpp \        
                   $(LOCAL_PATH)/../../../Classes/CObject.cpp \
                   $(LOCAL_PATH)/../../../Classes/Helper.cpp \
                   $(LOCAL_PATH)/../../../Classes/InfiniteParallaxNode.cpp\
                   $(LOCAL_PATH)/../../../Classes/HelloWorldScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cc_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module, cocos)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
