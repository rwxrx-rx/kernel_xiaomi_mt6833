/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __MTK_DRM_TRACE__
#define __MTK_DRM_TRACE__

#include "mtk_drm_ddp_comp.h"
#include <linux/ftrace.h>
#include <linux/trace_events.h>

/* Kill event_trace_printk globally for all MTK DRM files to fix Clang build */
#undef event_trace_printk
#define event_trace_printk(mark, fmt, ...) do { } while (0)

#define DRM_TRACE_ID 0xFFFF0000
#define DRM_TRACE_FPS_ID (DRM_TRACE_ID + 1)
#define DRM_TRACE_FENCE_ID (DRM_TRACE_ID + 2)
#define DRM_TRACE_VSYNC_ID (DRM_TRACE_ID + 3)

extern int hwc_pid;

/* MTK_DRM FTRACE (Disabled for Lotus Kernel performance & Clang compatibility) */
extern bool g_trace_log;

#define mtk_drm_trace_begin(fmt, args...) do { } while (0)
#define mtk_drm_trace_end() do { } while (0)
#define mtk_drm_trace_async_begin(fmt, args...) do { } while (0)
#define mtk_drm_trace_async_end(fmt, args...) do { } while (0)
#define mtk_drm_trace_c(fmt, args...) do { } while (0)

unsigned long mtk_drm_get_tracing_mark(void);
void drm_trace_tag_start(const char *tag);
void drm_trace_tag_end(const char *tag);
void drm_trace_tag_mark(const char *tag);
void mtk_drm_refresh_tag_start(struct mtk_ddp_comp *ddp_comp);
void mtk_drm_refresh_tag_end(struct mtk_ddp_comp *ddp_comp);
void MMPathTraceDRM(struct mtk_ddp_comp *ddp_comp);
int MMPathTraceRDMA(struct mtk_ddp_comp *ddp_comp, char *str,
	unsigned int strlen, unsigned int n);
int MMPathTraceWDMA(struct mtk_ddp_comp *ddp_comp, char *str,
	unsigned int strlen, unsigned int n);
int MMPathTraceCrtcPlanes(struct drm_crtc *crtc,
	char *str, int strlen, int n);
#endif
