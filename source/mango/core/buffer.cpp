/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2018 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#include <mango/core/buffer.hpp>
#include <mango/core/exception.hpp>

#define ID "[Buffer] "

namespace mango {

    Buffer::Buffer()
        : m_memory(nullptr, 0)
        , m_capacity(0)
        , m_offset(0)
    {
    }

    Buffer::Buffer(size_t bytes)
        : m_memory(new u8[bytes], bytes)
        , m_capacity(bytes)
        , m_offset(0)
    {
    }

    Buffer::Buffer(const u8* address, size_t bytes)
        : m_memory(new u8[bytes], bytes)
        , m_capacity(bytes)
        , m_offset(0)
    {
        std::memcpy(m_memory.address, address, bytes);
    }

    Buffer::Buffer(Memory memory)
        : m_memory(new u8[memory.size], memory.size)
        , m_capacity(memory.size)
        , m_offset(0)
    {
        std::memcpy(m_memory.address, memory.address, memory.size);
    }

    Buffer::~Buffer()
    {
        delete[] m_memory.address;
    }

    size_t Buffer::capacity() const
    {
        return m_capacity;        
    }

    void Buffer::reserve(size_t bytes)
    {
        if (bytes > m_capacity)
        {
            u8* storage = new u8[bytes];
            if (m_memory.address)
            {
                std::memcpy(storage, m_memory.address, m_memory.size);
                delete[] m_memory.address;
            }
            m_memory.address = storage;
            m_capacity = bytes;
        }
    }

    void Buffer::resize(size_t bytes)
    {
        reserve(bytes);
        m_memory.size = bytes;
        m_offset = std::min(m_offset, bytes);
    }

    u8* Buffer::data() const
    {
        return m_memory.address;
    }

    Buffer::operator Memory () const
    {
        return m_memory;
    }

	Buffer::operator u8* () const
	{
        return m_memory.address;
	}

    u64 Buffer::size() const
    {
        return m_memory.size;
    }

    u64 Buffer::offset() const
    {
        return m_offset;
    }

    void Buffer::seek(u64 distance, SeekMode mode)
    {
        switch (mode)
        {
            case BEGIN:
                m_offset = size_t(distance);
                break;

            case CURRENT:
                m_offset += size_t(distance);
                break;

            case END:
                m_offset = size_t(m_memory.size - distance);
                break;
        }
    }

    void Buffer::read(void* dest, size_t bytes)
    {
        const size_t left = m_memory.size - m_offset;
        if (left < bytes)
        {
            MANGO_EXCEPTION(ID"Reading past end of buffer.");
        }

        std::memcpy(dest, m_memory.address + m_offset, bytes);
        m_offset += bytes;
    }

    void Buffer::write(const void* data, size_t bytes)
    {
        size_t required = m_offset + bytes;
        if (required > m_capacity)
        {
            // grow 1.4x the required capacity
            reserve((required * 7) / 5);
        }

        std::memcpy(m_memory.address + m_offset, data, bytes);
        m_offset += bytes;
        m_memory.size = std::max(m_memory.size, m_offset);
    }

} // namespace mango
