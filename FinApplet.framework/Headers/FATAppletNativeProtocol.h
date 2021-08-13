//
//  FATAppletNativeProtocol.h
//  FinApplet
//
//  Created by hujianhui on 2020/11/26.
//  Copyright © 2020 finogeeks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "FATConstant.h"
#import "FATAppletInfo.h"

/*
 更多接口详细内容可参考微信文档
 https://developers.weixin.qq.com/miniprogram/dev/component/camera.html
 https://developers.weixin.qq.com/miniprogram/dev/component/live-player.html
 https://developers.weixin.qq.com/miniprogram/dev/component/live-pusher.html
 */

typedef void (^FATNativeCallback)(BOOL isSuccess, NSDictionary<NSString *, id> *result);

@protocol FATAppletNativeViewProtocol <NSObject>

@required
@property (nonatomic, strong) NSNumber *nativeViewId;
@property (nonatomic, strong) NSString *type;

+ (UIView *)onCreateView:(NSDictionary *)param;
- (void)onUpdateView:(NSDictionary *)param;

@optional
// 用户定义的组件id
@property (nonatomic, strong) NSString *ID;

- (void)onDestroyView:(NSDictionary *)param;
- (void)onInvokeNativeViewTask:(NSDictionary *)param;

@end

@protocol FATAppletNativeCameraProtocol <FATAppletNativeViewProtocol>

@optional
- (void)cameraFrameListenerStart:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)cameraFrameListenerStop:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)setCameraZoom:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)startCameraRecord:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)stopCameraRecord:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)takeCameraPhoto:(NSDictionary *)param completion:(FATNativeCallback)callBack;

@end

@protocol FATAppletNativeLivePlayerProtocol <FATAppletNativeViewProtocol>

/*
         id,    // 用户定义的组件id
         nativeViewId,
         src,     // 音视频地址
         mode,    // 模式
         autoplay,   // 自动播放
         muted,    // 是否静音
         orientation,     // 画面方向
         objectFit,    // 填充模式，可选值有 contain，fillCrop
         minCache,     // 最小缓冲区，单位s（RTC 模式推荐 0.2s）
         maxCache,     // 最大缓冲区，单位s（RTC 模式推荐 0.8s）。缓冲区用来抵抗网络波动，缓冲数据越多，网络抗性越好，但时延越大。
         soundMode,      // 声音输出方式
         autoPauseIfNavigate,    // 当跳转到本小程序的其他页面时，是否自动暂停本页面的实时音视频播放
         autoPauseIfOpenNative,     // 当跳转到其它微信原生页面时，是否自动暂停本页面的实时音视频播放
         pictureInPictureMode,    // 设置小窗模式： push, pop，空字符串或通过数组形式设置多种模式（如： ["push", "pop"]）
         type: 'live-player',
 */
@optional
- (void)livePlayerExitFullScreen:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePlayerExitPictureInPicture:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePlayerMute:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)liveplayerPause:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePlayerPlay:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)liveplayerRequestFullScreen:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)liveplayerResume:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)liveplayerSnapshot:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)liveplayerStop:(NSDictionary *)param completion:(FATNativeCallback)callBack;

@end

@protocol FATAppletNativeLivePusherProtocol <FATAppletNativeViewProtocol>
/*
 id,     // 用户定义的组件id
 url,     // 推流地址。目前仅支持 rtmp 格式
 mode,    // SD（标清）, HD（高清）, FHD（超清）, RTC（实时通话）
 autopush,     // 自动推流
 muted,      // 是否静音
 enableCamera,      // 开启摄像头
 autoFocus,      // 自动聚集
 orientation,       // 画面方向
 beauty,         // 美颜，取值范围 0-9 ，0 表示关闭
 whiteness,      // 美白，取值范围 0-9 ，0 表示关闭
 aspect,        // 宽高比，可选值有 3:4, 9:16
 minBitrate,        // 最小码率
 maxBitrate,          // 最大码率
 audioQuality,           // 高音质(48KHz)或低音质(16KHz)，值为high, low
 waitingImage,        // 进入后台时推流的等待画面
 waitingImageHash,        // 等待画面资源的MD5值
 zoom,        // 调整焦距
 devicePosition,        // 前置或后置，值为front, back
 mirror,       // 设置推流画面是否镜像，产生的效果在 live-player 反应到
 remoteMirror,      // 同 mirror 属性，后续 mirror 将废弃
 localMirror,      // 控制本地预览画面是否镜像
 audioReverbType,       // 音频混响类型
 enableMic,     // 开启或关闭麦克风
 enableAgc,        // 是否开启音频自动增益
 enableAns,      // 是否开启音频噪声抑制
 audioVolumeType,       // 音量类型
 videoWidth,       // 上推的视频流的分辨率宽度
 videoHeight,        // 上推的视频流的分辨率高度
 beautyStyle,       // 设置美颜类型
 filter,      // 设置色彩滤镜
 type: 'live-pusher',
  ...options   //  用户通过组件options配置的其他配置项
 */
@optional
- (void)livePusherPause:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherPauseBGM:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherPlayBGM:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherResume:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherResumeBGM:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherSetBGMVolume:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherSetMICVolume:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherSnapshot:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePlayerExitFullScreen:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherStart:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherStop:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherStopBGM:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherStopPreview:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherSwitchCamera:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherStartPreview:(NSDictionary *)param completion:(FATNativeCallback)callBack;
- (void)livePusherToggleTorch:(NSDictionary *)param completion:(FATNativeCallback)callBack;

@end
