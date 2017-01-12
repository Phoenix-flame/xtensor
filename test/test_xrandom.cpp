/***************************************************************************
* Copyright (c) 2016, Johan Mabille and Sylvain Corlay                     *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#include "gtest/gtest.h"
#include "xtensor/xrandom.hpp"
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"

namespace xt
{
    using std::size_t;
    using shape_t = std::vector<std::size_t>;

    TEST(xbuilder, random)
    {
        auto r = rand<double>({3, 3});
        xarray<double> a = r;
        xarray<double> b = r;
        xarray<double> c = r;

        ASSERT_EQ(a, b); // Works
        ASSERT_EQ(a, c); // Fails

        xarray<double> other_rand = rand<double>({3, 3});
        ASSERT_NE(a, other_rand);
        // check if assignment works
        bool eq = std::equal(a.begin(), a.end(), r.begin());
        ASSERT_TRUE(eq);

        auto val = r(1, 1);
        std::cout << r << std::endl;
        ASSERT_EQ(val, r(1, 1));

        // check that it compiles
        xarray<int> q = randint<int>({3, 3});
        xarray<double> p = randn<double>({3, 3});
    }
}
