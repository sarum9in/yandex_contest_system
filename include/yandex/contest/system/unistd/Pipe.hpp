#pragma once

#include "yandex/contest/system/unistd/Descriptor.hpp"

#include <system_error>

#include <boost/noncopyable.hpp>

namespace yandex{namespace contest{namespace system{namespace unistd
{
    class Pipe: boost::noncopyable
    {
    public:
        Pipe();

        int readEnd() const noexcept;
        int writeEnd() const noexcept;
        void closeReadEnd(std::error_code &ec) noexcept;
        void closeReadEnd();
        void closeWriteEnd(std::error_code &ec) noexcept;
        void closeWriteEnd();
        bool readEndIsOpened() const noexcept;
        bool writeEndIsOpened() const noexcept;

    private:
        enum End: unsigned;

    private:
        Descriptor fd_[2];
    };
}}}}
