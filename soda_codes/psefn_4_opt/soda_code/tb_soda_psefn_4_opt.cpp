// AUTO GEN SODA TB
#include "psefn_4_opt_kernel.h"
#include <iostream>
#include <fstream>

#define PIXEL_WIDTH 16
#define BURST_WIDTH 64

#include "runtime/test_utils.h"

using namespace std;

int main() {
  const int nrows = 1927;
  const int ncols = 1932;
  uint64_t img_pixels = nrows*ncols;
  const uint64_t bits_per_pixel = PIXEL_WIDTH;
  uint64_t img_bits = bits_per_pixel*img_pixels;
  const uint64_t num_transfers = img_bits / BURST_WIDTH;
  const uint64_t pixels_per_burst = BURST_WIDTH / bits_per_pixel;

  cout << "num transfers    : " << num_transfers << endl;
  cout << "pixels / transfer: " << pixels_per_burst << endl;

  const uint64_t transfer_cols = ncols / pixels_per_burst;
  ap_uint<BURST_WIDTH>* psefn_4 = (ap_uint<BURST_WIDTH>*) malloc(sizeof(ap_uint<BURST_WIDTH>)*num_transfers);
  ap_uint<BURST_WIDTH>* in_off_chip = (ap_uint<BURST_WIDTH>*) malloc(sizeof(ap_uint<BURST_WIDTH>)*num_transfers);
  fill_array_decimal<bits_per_pixel>("in_off_chip_input_pixel.csv", in_off_chip, nrows, ncols, transfer_cols);
  psefn_4_opt_kernel(psefn_4, in_off_chip, num_transfers);
  write_results_decimal<bits_per_pixel>("soda_psefn_4_opt_regression_result.csv", psefn_4, nrows, ncols, transfer_cols);
  free(in_off_chip);
  free(psefn_4);
}
