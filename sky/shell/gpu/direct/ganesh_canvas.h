// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKY_SHELL_GPU_DIRECT_GANESH_CANVAS_H_
#define SKY_SHELL_GPU_DIRECT_GANESH_CANVAS_H_

#include "lib/ftl/macros.h"
#include "third_party/skia/include/core/SkSize.h"
#include "third_party/skia/include/core/SkSurface.h"
#include "third_party/skia/include/gpu/gl/GrGLInterface.h"
#include "third_party/skia/include/gpu/gl/GrGLInterface.h"
#include "third_party/skia/include/gpu/GrContext.h"

namespace sky {
namespace shell {

class GaneshCanvas {
 public:
  GaneshCanvas();
  ~GaneshCanvas();

  bool SetupGrGLInterface();

  SkCanvas* GetCanvas(int32_t fbo, const SkISize& size);

  bool IsValid();

  GrContext* gr_context() { return gr_context_.get(); }

 private:
  bool SelectPixelConfig(GrPixelConfig* config);

  sk_sp<GrContext> gr_context_;
  sk_sp<SkSurface> sk_surface_;

  FTL_DISALLOW_COPY_AND_ASSIGN(GaneshCanvas);
};

}  // namespace shell
}  // namespace sky

#endif  // SKY_SHELL_GPU_DIRECT_GANESH_CANVAS_H_
