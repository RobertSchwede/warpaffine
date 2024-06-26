// SPDX-FileCopyrightText: 2023 Carl Zeiss Microscopy GmbH
//
// SPDX-License-Identifier: MIT

#pragma once

/// Values that represent different "libCZI-input-stream" implementations.
enum class LibCziReaderImplementation
{
    kStock,  ///< The stock "ReadFile"-based stream implementation.
    kMmf     ///< A stream-implementation using memory mapped file.
};

/// Values that represent different "brick reader" implementations.
enum class BrickReaderImplementation
{
    kPlaneReader,    ///< The simplest "brick-reader" : reading and decoding is done serially.
    kPlaneReader2,   ///< This brick-reader decouples compression, it is done parallel, but reading is not "linearized".
    kLinearReading   ///< This brick-reader is reading the file in strict sequential order, and decompression is parallelized.
};

/// Values that represent "warp affine" implementations.
enum class WarpAffineImplementation
{
    kNull,       ///< The "null" implementation, i.e. no warp affine is performed, the output is just zero-filled.
    kIPP,        ///< The WarpAffine implementation using Intel kIPP.
    kReference   ///< The reference implementation, i.e. a non-optimized home-brew implementation.
};

enum class TestStopPipelineAfter
{
    kNone,
    kReadFromSource,
    kDecompress,
    kCombineBrick
};

/// Values that represent the interpolation mode. The numeric values correspond to the
/// values used in Intel IPP.
enum class Interpolation
{
    kNearestNeighbor = 1,   ///< An enum constant representing the nearest neighbor interpolation mode (aka: no interpolation).
    kBilinear = 2,          ///< An enum constant representing linear interpolation.
    kBicubic = 4,           ///< An enum constant representing cubic interpolation.
    kBSpline = 5,           ///< An enum constant representing a two-parameter cubic filter (B=1, C=0).
    kCatMullRom = 6,        ///< An enum constant representing a two-parameter cubic filter (B=0, C=0.5).
    kB05c03 = 7,            ///< An enum constant representing a two-parameter cubic filter (B=0.5, C=0.3).
};

/// Values that represent different "task arena implementations" (alas, there is only one left at the moment).
enum class TaskArenaImplementation
{
    kTBB,       ///< An enum constant representing the "task arena implementation" based on Intel TBB.
    /*IFB*/
};

/// Values that represent different levels of "print-out verbosity", i.e. how much
/// output (to stdout) is generated by the application.
/// The enums need to be ordered from "lowest level of verbosity" to "highest level of
/// verbosity", since their numerical values are being compared.
enum class MessagesPrintVerbosity
{
    kMinimal = 0,
    kNormal,
    kChatty,
    kMaximal
};
