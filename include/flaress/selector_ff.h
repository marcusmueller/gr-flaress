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


#ifndef INCLUDED_FLARESS_SELECTOR_FF_H
#define INCLUDED_FLARESS_SELECTOR_FF_H

#include <flaress/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace flaress {

    /*!
     * \brief <+description of block+>
     * \ingroup flaress
     *
     */
    class FLARESS_API selector_ff : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<selector_ff> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of flaress::selector_ff.
       *
       * To avoid accidental use of raw pointers, flaress::selector_ff's
       * constructor is in a private implementation
       * class. flaress::selector_ff::make is the public interface for
       * creating new instances.
       */
      static sptr make(int select, int n_inputs, int n_outputs);

      virtual int get_select() const=0;
      virtual void set_select(int select)=0;
    };

  } // namespace flaress
} // namespace gr

#endif /* INCLUDED_FLARESS_SELECTOR_FF_H */
