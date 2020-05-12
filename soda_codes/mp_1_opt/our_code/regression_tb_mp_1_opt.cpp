#include <fstream>
#include "mp_1_opt.h"

int main() {
  ofstream in_pix("input_pixels_regression_result_mp_1_opt.txt");
  ofstream fout("regression_result_mp_1_opt.txt");
  HWStream<hw_uint<32> > in_update_0_read;
  HWStream<hw_uint<32> > mp_1_update_0_write;


  // Loading input data
  // cmap    : { in_update_0[root = 0, in_0, in_1, in_2] -> in_oc[0, 0] : 0 <= in_0 <= 127 and 0 <= in_1 <= 127 and 0 <= in_2 <= 31 }
  // read map: { in_oc[0, 0] -> in_update_0[root = 0, in_0, in_1, in_2] : 0 <= in_0 <= 127 and 0 <= in_1 <= 127 and 0 <= in_2 <= 31 }
  // rng     : { in_update_0[root = 0, in_0, in_1, in_2] : 0 <= in_0 <= 127 and 0 <= in_1 <= 127 and 0 <= in_2 <= 31 }
  for (int i = 0; i < 524288; i++) {
    hw_uint<32> in_val;
    set_at<0*32, 32, 32>(in_val, 1*i + 0);
    in_pix << in_val << endl;
    in_update_0_read.write(in_val);
  }

  mp_1_opt(in_update_0_read, mp_1_update_0_write);

  for (int i = 0; i < 131072; i++) {
    hw_uint<32> actual = mp_1_update_0_write.read();
    auto actual_lane_0 = actual.extract<0*32, 31>();
    fout << actual_lane_0 << endl;
  }

  in_pix.close();
  fout.close();
  return 0;
}