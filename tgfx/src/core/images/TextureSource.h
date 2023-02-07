/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Tencent is pleased to support the open source community by making libpag available.
//
//  Copyright (C) 2021 THL A29 Limited, a Tencent company. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
//  except in compliance with the License. You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  unless required by applicable law or agreed to in writing, software distributed under the
//  license is distributed on an "as is" basis, without warranties or conditions of any kind,
//  either express or implied. see the license for the specific language governing permissions
//  and limitations under the license.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ImageSource.h"

namespace tgfx {
/**
 * TextureSource wraps an existing texture.
 */
class TextureSource : public ImageSource {
 public:
  int width() const override {
    return texture->width();
  }

  int height() const override {
    return texture->height();
  }

  bool hasMipmaps() const override {
    return texture->getSampler()->mipMapped();
  }

  bool isAlphaOnly() const override {
    return texture->getSampler()->format == PixelFormat::ALPHA_8;
  }

  bool isTextureBacked() const override {
    return true;
  }

  std::shared_ptr<Texture> getTexture() const override {
    return texture;
  }

 protected:
  std::shared_ptr<ImageSource> onMakeMipMapped() const override {
    return nullptr;
  }

  std::shared_ptr<TextureProxy> onMakeTextureProxy(Context* context) const override {
    return context->proxyProvider()->wrapTexture(texture);
  }

 private:
  std::shared_ptr<Texture> texture = nullptr;

  explicit TextureSource(std::shared_ptr<Texture> texture) : texture(std::move(texture)) {
  }

  friend class ImageSource;
};
}  // namespace tgfx