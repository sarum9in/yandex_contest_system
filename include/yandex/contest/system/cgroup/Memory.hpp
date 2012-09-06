#pragma once

#include "yandex/contest/system/cgroup/ResourceLimiter.hpp"
#include "yandex/contest/system/cgroup/Stat.hpp"

#include <boost/optional.hpp>

namespace yandex{namespace contest{namespace system{namespace cgroup
{
    class MemoryBase:
        public virtual ResourceLimiter<MemoryBase, Count>,
        public virtual Stat<MemoryBase, Count>
    {
    public:
        static const std::string SUBSYSTEM_NAME;
        static const boost::optional<std::string> UNITS;
    };

    typedef Subsystem<MemoryBase> Memory;
}}}}
