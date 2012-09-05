#pragma once

#include "yandex/contest/system/cgroup/SubsystemBase.hpp"

#include <string>
#include <unordered_map>

namespace yandex{namespace contest{namespace system{namespace cgroup
{
    template <typename Config, typename T>
    class Stat: public virtual SubsystemBase<Config>
    {
    public:
        typedef std::unordered_map<std::string, T> Map;

    public:
        Map stat()
        {
            Map map;
            readFieldByReader("stat",
                [&map](std::istream &in)
                {
                    std::string key;
                    T value;
                    while (in >> key >> value)
                        map.emplace(key, value);
                });
            return map;
        }
    };
}}}}
