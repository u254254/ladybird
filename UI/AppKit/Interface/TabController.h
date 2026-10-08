/*
 * Copyright (c) 2023-2026, Tim Flynn <trflynn89@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Forward.h>
#include <LibWebCommon/Page/PageId.h>
#include <LibURL/URL.h>
#include <LibWebView/BrowsingSession.h>
#include <LibWebView/Forward.h>

#import <Cocoa/Cocoa.h>

@class Tab;

@interface TabController : NSWindowController <NSWindowDelegate>

- (instancetype)init:(WebView::IsPrivate)is_private;
- (instancetype)initAsChild:(Tab*)parent
                traversable:(WebView::CanonicalTraversable&)traversable;

- (WebView::IsPrivate)isPrivate;

- (void)loadURL:(URL::URL const&)url;

- (void)updatePerformanceMonitor;

- (void)onLoadStart;
- (void)onLoadFinish;
- (void)onFaviconChange:(NSImage*)favicon;

- (void)onURLChange:(URL::URL const&)url;

- (void)onEnterFullscreenWindow;
- (void)onExitFullscreenWindow;

- (void)focusWebViewWhenActivated;
- (void)focusWebView;
- (void)focusLocationToolbarItem;

@end
