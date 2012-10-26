/*=============================================================================
    Copyright (c) 2012 Paul Fultz II
    last_or_default.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef LINQ_GUARD_EXTENSIONS_LAST_OR_DEFAULT_H
#define LINQ_GUARD_EXTENSIONS_LAST_OR_DEFAULT_H

#include <linq/extensions/extension.h>
#include <linq/extensions/detail/always.h>
#include <linq/extensions/last.h>
#include <boost/range.hpp>

namespace linq { 
namespace detail {
struct last_or_default_t
{
    template<class Range>
    auto operator()(Range && r) LINQ_RETURNS(r | linq::last(always(), typename boost::range_value<Range>::type()));

    template<class Range, class Predicate>
    auto operator()(Range && r, Predicate p) LINQ_RETURNS(r | linq::last(p, typename boost::range_value<Range>::type()));
};
}
namespace {
range_extension<detail::last_or_default_t> last_or_default = {};
}

}

#endif