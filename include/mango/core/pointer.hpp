/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2018 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "configure.hpp"
#include "endian.hpp"

namespace mango {

    // --------------------------------------------------------------
    // Pointer
    // --------------------------------------------------------------

    class Pointer
    {
    protected:
        u8* p;

    public:
        explicit Pointer(const Pointer& pointer)
            : p(pointer.p)
        {
        }

        explicit Pointer(u8* address)
            : p(address)
        {
        }

        Pointer() = default;
        ~Pointer() = default;

        const Pointer& operator = (u8* address)
        {
            p = address;
            return *this;
        }

        template <typename T>
        T* cast() const
        {
            return reinterpret_cast<T*>(p);
        }

        operator u8* () const
        {
            return p;
        }

        u8& operator * () const
        {
            return *p;
        }

        u8* operator ++ ()
        {
            return ++p;
        }

        u8* operator ++ (int)
        {
            return p++;
        }

        u8* operator -- ()
        {
            return --p;
        }

        u8* operator -- (int)
        {
            return p--;
        }

        u8* operator += (size_t count)
        {
            p += count;
            return p;
        }

        u8* operator -= (size_t count)
        {
            p -= count;
            return p;
        }
    };

    static inline ptrdiff_t operator - (const Pointer& a, const Pointer& b)
    {
        return static_cast<const u8 *>(a) - static_cast<const u8 *>(b);
    }

    // --------------------------------------------------------------
    // LittleEndianPointer
    // --------------------------------------------------------------

    class LittleEndianPointer : public Pointer
    {
    protected:
        using Pointer::p;

    public:
        LittleEndianPointer(u8* address)
            : Pointer(address)
        {
        }

        // read methods

        void read(u8* dest, size_t count)
        {
            std::memcpy(dest, p, count);
            p += count;
        }

        u8 read8()
        {
            return *p++;
        }

        u16 read16()
        {
            u16 value = uload16le(p);
            p += 2;
            return value;
        }

        u32 read32()
        {
            u32 value = uload32le(p);
            p += 4;
            return value;
        }

        u64 read64()
        {
            u64 value = uload64le(p);
            p += 8;
            return value;
        }

        float16 read16f()
        {
            Half value;
            value.u = uload16le(p);
            p += 2;
            return value;
        }

        float read32f()
        {
            Float value;
            value.u = uload32le(p);
            p += 4;
            return value;
        }

        double read64f()
        {
            Double value;
            value.u = uload64le(p);
            p += 8;
            return value;
        }

        // write methods

        void write(const u8* source, size_t count)
        {
            std::memcpy(p, source, count);
            p += count;
        }

        void write8(u8 value)
        {
            *p++ = value;
        }

        void write16(u16 value)
        {
            ustore16le(p, value);
            p += 2;
        }

        void write32(u32 value)
        {
            ustore32le(p, value);
            p += 4;
        }

        void write64(u64 value)
        {
            ustore64le(p, value);
            p += 8;
        }

        void write16f(Half value)
        {
            ustore16le(p, value.u);
            p += 2;
        }

        void write32f(Float value)
        {
            ustore32le(p, value.u);
            p += 4;
        }

        void write64f(Double value)
        {
            ustore64le(p, value.u);
            p += 8;
        }
    };

    // --------------------------------------------------------------
    // BigEndianPointer
    // --------------------------------------------------------------

    class BigEndianPointer : public Pointer
    {
    protected:
        using Pointer::p;

    public:
        BigEndianPointer(u8* address)
            : Pointer(address)
        {
        }

        // read methods

        void read(u8* dest, size_t count)
        {
            std::memcpy(dest, p, count);
            p += count;
        }

        u8 read8()
        {
            return *p++;
        }

        u16 read16()
        {
            u16 value = uload16be(p);
            p += 2;
            return value;
        }

        u32 read32()
        {
            u32 value = uload32be(p);
            p += 4;
            return value;
        }

        u64 read64()
        {
            u64 value = uload64be(p);
            p += 8;
            return value;
        }

        float16 read16f()
        {
            Half value;
            value.u = uload16be(p);
            p += 2;
            return value;
        }

        float read32f()
        {
            Float value;
            value.u = uload32be(p);
            p += 4;
            return value;
        }

        double read64f()
        {
            Double value;
            value.u = uload64be(p);
            p += 8;
            return value;
        }

        // write methods

        void write(const u8* source, size_t count)
        {
            std::memcpy(p, source, count);
            p += count;
        }

        void write8(u8 value)
        {
            *p++ = value;
        }

        void write16(u16 value)
        {
            ustore16be(p, value);
            p += 2;
        }

        void write32(u32 value)
        {
            ustore32be(p, value);
            p += 4;
        }

        void write64(u64 value)
        {
            ustore64be(p, value);
            p += 8;
        }

        void write16f(Half value)
        {
            ustore16be(p, value.u);
            p += 2;
        }

        void write32f(Float value)
        {
            ustore32be(p, value.u);
            p += 4;
        }

        void write64f(Double value)
        {
            ustore64be(p, value.u);
            p += 8;
        }
    };

} // namespace mango
