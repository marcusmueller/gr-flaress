/* -*- c++ -*- */
/*
 * Copyright 2018 Antonio Miraglia - ISISpace.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
 
#ifndef INCLUDED_FLARESS_INTEGER_MATH_LL_IMPL_H
#define INCLUDED_FLARESS_INTEGER_MATH_LL_IMPL_H

#include <flaress/integer_math_ll.h>

namespace gr {
  namespace flaress {

    class integer_math_ll_impl : public integer_math_ll
    {
     private:
      size_t d_vlen;
      int d_N_int;
      int64_t max_value_pos;
      int64_t max_value_neg;

     public:
      integer_math_ll_impl(size_t vlen, int N_int);
      ~integer_math_ll_impl();

      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace flaress
} // namespace gr

#endif /* INCLUDED_FLARESS_INTEGER_MATH_LL_IMPL_H */

