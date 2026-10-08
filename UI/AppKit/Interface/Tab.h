/*
 * Copyright (c) 2023-2026, Tim Flynn <trflynn89@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Types.h>
#include <LibWebCommon/Page/PageId.h>
#include <LibWebView/BrowsingSession.h>
#include <LibWebView/CanonicalTraversable.h>
#include <LibWebView/Forward.h>

#import <Cocoa/Cocoa.h>
#import <Interface/LadybirdWebViewWindow.h>

@class BookmarksBar;
@class LadybirdWebView;

@interface Tab : LadybirdWebViewWindow

- (instancetype)init:(WebView::IsPrivate)is_private;
- (instancetype)initAsChild:(Tab*)parent
                traversable:(WebView::CanonicalTraversable&)traversable;

- (WebView::IsPrivate)isPrivate;

- (BookmarksBar*)bookmarksBar;

- (void)rebuildBookmarksBar;
- (void)updateBookmarksBarDisplay:(bool)show_bookmarks_bar;

@end
