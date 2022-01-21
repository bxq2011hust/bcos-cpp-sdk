/*
 *  Copyright (C) 2021 FISCO BCOS.
 *  SPDX-License-Identifier: Apache-2.0
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @file Common.h
 * @author: octopus
 * @date 2022-01-13
 */
#pragma once

namespace bcos
{
namespace cppsdk
{
namespace utilities
{
enum class CryptoSuiteType : int
{
    ECDSA_TYPE = 1,
    SM_TYPE = 2
};
}  // namespace utilities
}  // namespace cppsdk
}  // namespace bcos

const static int PRIVATE_KEY_LEN = 32;
const static int HEX_PRIVATE_KEY_LEN = PRIVATE_KEY_LEN * 2;
const static int PUBLIC_KEY_LEN = 64;
const static int HEX_PUBLIC_KEY_LEN = PUBLIC_KEY_LEN * 2;