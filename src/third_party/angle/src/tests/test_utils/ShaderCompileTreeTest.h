//
// Copyright (c) 2016 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// ShaderCompileTreeTest.h:
//   Test that shader validation results in the correct compile status.
//

#ifndef TESTS_TEST_UTILS_SHADER_COMPILE_TREE_TEST_H_
#define TESTS_TEST_UTILS_SHADER_COMPILE_TREE_TEST_H_

#include "angle_gl.h"
#include "compiler/translator/PoolAlloc.h"
#include "gtest/gtest.h"
#include "GLSLANG/ShaderLang.h"

namespace sh
{

class TIntermBlock;
class TranslatorESSL;

class ShaderCompileTreeTest : public testing::Test
{
  public:
    ShaderCompileTreeTest() : mExtraCompileOptions(0) {}

  protected:
    void SetUp() override;

    void TearDown() override;

    // Return true when compilation succeeds
    bool compile(const std::string &shaderString);
    void compileAssumeSuccess(const std::string &shaderString);

    bool hasWarning() const;

    const std::vector<sh::Uniform> getUniforms();

    virtual void initResources(ShBuiltInResources *resources) {}
    virtual ::GLenum getShaderType() const     = 0;
    virtual ShShaderSpec getShaderSpec() const = 0;

    std::string mInfoLog;
    ShCompileOptions mExtraCompileOptions;

    TIntermBlock *mASTRoot;

  private:
    TranslatorESSL *mTranslator;

    TPoolAllocator mAllocator;
};

}  // namespace sh

#endif  // TESTS_TEST_UTILS_SHADER_COMPILE_TREE_TEST_H_