#pragma once


#include "minihls.h"
#include "ubuffer.h"

struct compute_kernel {
  string name;
  vector<pair<string, string> > input_buffers;
  vector<string> iteration_variables;
  string functional_unit;
  pair<string, string> output_buffer;
};

minihls::instruction_type* reduce(minihls::context& c, map<string, minihls::module_type*>& buffers, vector<string>& index_variables);

minihls::module_type* sr_buffer(minihls::block& blk, const int width, const int depth);

minihls::module_type* gen_bank(minihls::block& blk, const bank& bnk);

static inline
void ignore_inter_deps(std::ostream& out, const string& var) {
  out << "#ifdef __VIVADO_SYNTH__" << endl;
  out << "#pragma HLS dependence variable=" << var << " inter false" << endl;
  out << "#endif //__VIVADO_SYNTH__" << endl;
}

static inline
void ignore_inter_deps_array(std::ostream& out) {
  out << "#ifdef __VIVADO_SYNTH__" << endl;
  out << "#pragma HLS dependence array inter false" << endl;
  out << "#endif //__VIVADO_SYNTH__" << endl;
}


static inline
void open_debug_scope(std::ostream& out) {
  out << "#ifndef __VIVADO_SYNTH__" << endl;
}

static inline
void close_debug_scope(std::ostream& out) {
  out << "#endif //__VIVADO_SYNTH__" << endl;
}

static inline
string read_partition(const string& p, const int cap) {
  if (cap > 1) {
    return p + ".back()";
  } else {
    return p;
  }
}

static inline
string write_partition(const string& p, const int cap, const string& val) {
  if (cap > 1) {
    return p + ".push(" + val + ")";
  } else {
    return p + " = " + val;
  }
}
