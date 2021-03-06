/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2019 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "simd.hpp"

namespace mango {
namespace simd {

    // 128 bit gather

    static inline f32x4 gather4(const f32* address, s32x4 offset)
    {
        return _mm_i32gather_ps(reinterpret_cast<const float*>(address), offset, 4);
    }

    static inline f64x2 gather2(const f64* address, s32x4 offset)
    {
        return _mm_i32gather_pd(reinterpret_cast<const double*>(address), offset, 8);
    }

    static inline u32x4 gather4(const u32* address, s32x4 offset)
    {
        return _mm_i32gather_epi32(reinterpret_cast<const int*>(address), offset, 4);
    }

    static inline s32x4 gather4(const s32* address, s32x4 offset)
    {
        return _mm_i32gather_epi32(reinterpret_cast<const int*>(address), offset, 4);
    }

    static inline u64x2 gather2(const u64* address, s32x4 offset)
    {
        return _mm_i32gather_epi64(reinterpret_cast<const long long*>(address), offset, 8);
    }

    static inline s64x2 gather2(const s64* address, s32x4 offset)
    {
        return _mm_i32gather_epi64(reinterpret_cast<const long long*>(address), offset, 8);
    }

    // 256 bit gather

    static inline f32x8 gather8(const f32* address, s32x8 offset)
    {
        return _mm256_i32gather_ps(reinterpret_cast<const float*>(address), offset, 4);
    }

    static inline f64x4 gather4(const f64* address, s32x4 offset)
    {
        return _mm256_i32gather_pd(reinterpret_cast<const double*>(address), offset, 8);
    }

    static inline u32x8 gather8(const u32* address, s32x8 offset)
    {
        return _mm256_i32gather_epi32(reinterpret_cast<const int*>(address), offset, 4);
    }

    static inline s32x8 gather8(const s32* address, s32x8 offset)
    {
        return _mm256_i32gather_epi32(reinterpret_cast<const int*>(address), offset, 4);
    }

    static inline u64x4 gather4(const u64* address, s32x4 offset)
    {
        return _mm256_i32gather_epi64(reinterpret_cast<const long long*>(address), offset, 8);
    }

    static inline s64x4 gather4(const s64* address, s32x4 offset)
    {
        return _mm256_i32gather_epi64(reinterpret_cast<const long long*>(address), offset, 8);
    }

    // 512 bit gather

    static inline f32x16 gather16(const f32* address, s32x16 offset)
    {
        f32x16 result;
        result.lo = gather8(address, offset.lo);
        result.hi = gather8(address, offset.hi);
        return result;
    }

    static inline f64x8 gather8(const f64* address, s32x8 offset)
    {
        f64x8 result;
        result.lo = gather4(address, get_low(offset));
        result.hi = gather4(address, get_high(offset));
        return result;
    }

    static inline u32x16 gather16(const u32* address, s32x16 offset)
    {
        u32x16 result;
        result.lo = gather8(address, offset.lo);
        result.hi = gather8(address, offset.hi);
        return result;
    }

    static inline s32x16 gather16(const s32* address, s32x16 offset)
    {
        s32x16 result;
        result.lo = gather8(address, offset.lo);
        result.hi = gather8(address, offset.hi);
        return result;
    }

    static inline u64x8 gather8(const u64* address, s32x8 offset)
    {
        u64x8 result;
        result.lo = gather4(address, get_low(offset));
        result.hi = gather4(address, get_high(offset));
        return result;
    }

    static inline s64x8 gather8(const s64* address, s32x8 offset)
    {
        s64x8 result;
        result.lo = gather4(address, get_low(offset));
        result.hi = gather4(address, get_high(offset));
        return result;
    }

    // 128 bit masked gather

    static inline f32x4 gather4(const f32* address, s32x4 offset, f32x4 value, mask32x4 mask)
    {
        return _mm_mask_i32gather_ps(value, reinterpret_cast<const float*>(address), offset, _mm_castsi128_ps(mask), 4);
    }

    static inline f64x2 gather2(const f64* address, s32x4 offset, f64x2 value, mask64x2 mask)
    {
        return _mm_mask_i32gather_pd(value, reinterpret_cast<const double*>(address), offset, _mm_castsi128_pd(mask), 8);
    }

    static inline u32x4 gather4(const u32* address, s32x4 offset, u32x4 value, mask32x4 mask)
    {
        return _mm_mask_i32gather_epi32(value, reinterpret_cast<const int*>(address), offset, mask, 4);
    }

    static inline s32x4 gather4(const s32* address, s32x4 offset, s32x4 value, mask32x4 mask)
    {
        return _mm_mask_i32gather_epi32(value, reinterpret_cast<const int*>(address), offset, mask, 4);
    }

    static inline u64x2 gather2(const u64* address, s32x4 offset, u64x2 value, mask64x2 mask)
    {
        return _mm_mask_i32gather_epi64(value, reinterpret_cast<const long long*>(address), offset, mask, 8);
    }

    static inline s64x2 gather2(const s64* address, s32x4 offset, s64x2 value, mask64x2 mask)
    {
        return _mm_mask_i32gather_epi64(value, reinterpret_cast<const long long*>(address), offset, mask, 8);
    }

    // 256 bit masked gather

    static inline f32x8 gather8(const f32* address, s32x8 offset, f32x8 value, mask32x8 mask)
    {
        return _mm256_mask_i32gather_ps(value, reinterpret_cast<const float*>(address), offset, _mm256_castsi256_ps(mask), 4);
    }

    static inline f64x4 gather4(const f64* address, s32x4 offset, f64x4 value, mask64x4 mask)
    {
        return _mm256_mask_i32gather_pd(value, reinterpret_cast<const double*>(address), offset, _mm256_castsi256_pd(mask), 8);
    }

    static inline u32x8 gather8(const u32* address, s32x8 offset, u32x8 value, mask32x8 mask)
    {
        return _mm256_mask_i32gather_epi32(value, reinterpret_cast<const int*>(address), offset, mask, 4);
    }

    static inline s32x8 gather8(const s32* address, s32x8 offset, s32x8 value, mask32x8 mask)
    {
        return _mm256_mask_i32gather_epi32(value, reinterpret_cast<const int*>(address), offset, mask, 4);
    }

    static inline u64x4 gather4(const u64* address, s32x4 offset, u64x4 value, mask64x4 mask)
    {
        return _mm256_mask_i32gather_epi64(value, reinterpret_cast<const long long*>(address), offset, mask, 8);
    }

    static inline s64x4 gather4(const s64* address, s32x4 offset, s64x4 value, mask64x4 mask)
    {
        return _mm256_mask_i32gather_epi64(value, reinterpret_cast<const long long*>(address), offset, mask, 8);
    }

    // 512 bit masked gather

    static inline f32x16 gather16(const f32* address, s32x16 offset, f32x16 value, mask32x16 mask)
    {
        return select(mask, gather16(address, offset), value);
    }

    static inline f64x8 gather8(const f64* address, s32x8 offset, f64x8 value, mask64x8 mask)
    {
        return select(mask, gather8(address, offset), value);
    }

    static inline u32x16 gather16(const u32* address, s32x16 offset, u32x16 value, mask32x16 mask)
    {
        return select(mask, gather16(address, offset), value);
    }

    static inline s32x16 gather16(const s32* address, s32x16 offset, s32x16 value, mask32x16 mask)
    {
        return select(mask, gather16(address, offset), value);
    }

    static inline u64x8 gather8(const u64* address, s32x8 offset, u64x8 value, mask64x8 mask)
    {
        return select(mask, gather8(address, offset), value);
    }

    static inline s64x8 gather8(const s64* address, s32x8 offset, s64x8 value, mask64x8 mask)
    {
        return select(mask, gather8(address, offset), value);
    }

} // namespace simd
} // namespace mango
