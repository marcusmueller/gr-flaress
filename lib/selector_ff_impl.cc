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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "selector_ff_impl.h"

namespace gr {
  namespace flaress {

    selector_ff::sptr
    selector_ff::make(int select, int n_inputs, int n_outputs)
    {
      if ( n_inputs > 1 || n_outputs < 1)
        n_outputs = 1;
      if ( n_inputs < 1)
        n_outputs = 1;

      return gnuradio::get_initial_sptr
        (new selector_ff_impl(select, n_inputs, n_outputs));
    }

    /*
     * The private constructor
     */
    selector_ff_impl::selector_ff_impl(int select, int n_inputs, int n_outputs)
      : gr::block("selector_ff",
              gr::io_signature::make(0, n_inputs, sizeof(float)),
              gr::io_signature::make(0, n_outputs, sizeof(float))),
              d_select(select), d_n_inputs(n_inputs), d_n_outputs(n_outputs)
    {

    }

    /*
     * Our virtual destructor.
     */
    selector_ff_impl::~selector_ff_impl()
    {
    }

    int
    selector_ff_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const float *in[d_n_inputs];
      float *out[d_n_outputs];

      for(int x = 0; x < d_n_inputs; x++) {
        in[x] = (const float *) input_items[x];
      }
      for(int y = 0; y < d_n_outputs;y++) {
        out[y] = (float *) output_items[y];
      }

      sel_evaluation();
      for(int i = 0; i < noutput_items; i++) {
            out[out_sel][i]= in[in_sel][i];
      }

      for(int z = 0; z < d_n_inputs; z++) {
          consume(z, noutput_items);
      }

      for(int w = 0; w < d_n_outputs; w++) {
        if (w != out_sel )
          produce(w, 0);
        else
          produce(w, noutput_items);
      }

      return WORK_CALLED_PRODUCE;
    }

    void selector_ff_impl::sel_evaluation(){
      if ( d_n_inputs > 1)
      {
        out_sel = 0;
        in_sel = d_select;
      }
      else
      {
        out_sel = d_select;
        in_sel = 0;
      }
    }

    int selector_ff_impl::get_select() const   { return d_select;  }

    void selector_ff_impl::set_select(int select)
    {
      int max;
      if (d_n_inputs >= d_n_outputs)
        max = d_n_inputs;
      else
        max = d_n_outputs;
      if(select < 0 || select >= max) {
        throw std::out_of_range ("pll: invalid selector value.");
      }
      d_select = select;
    }


  } /* namespace flaress */
} /* namespace gr */
