#ifndef __VIVADO_SYNTH__
#include <fstream>
using namespace std;

  // Debug utility
  ofstream* global_debug_handle;

#endif //__VIVADO_SYNTH__
#include "harris16_mini_opt_compute_units.h"

#include "hw_classes.h"

struct det_det_update_0_write0_merged_banks_1_cache {
	// RAM Box: {[0, 31], [0, 31]}
	// Capacity: 1
	// # of read delays: 1
	fifo<hw_uint<16>, 1> f;
	inline hw_uint<16> peek(const int offset) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.peek(0 - offset);
  }



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.push(value);
  }

};

struct det_cache {
  det_det_update_0_write0_merged_banks_1_cache det_det_update_0_write0_merged_banks_1;
};



inline void det_det_update_0_write0_write(hw_uint<16>& det_det_update_0_write0, det_cache& det, int d0, int d1) {
  det.det_det_update_0_write0_merged_banks_1.push(det_det_update_0_write0);
}

inline hw_uint<16> harris16_mini_rd0_select(det_cache& det, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // harris16_mini_rd0 read pattern: { harris16_mini_update_0[d0, d1] -> det[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { harris16_mini_update_0[d0, d1] -> [2 + d1, 2 + d0, 15] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { det_update_0[d0, d1] -> [2 + d1, 2 + d0, 13] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_det_det_update_0_write0 = det.det_det_update_0_write0_merged_banks_1.peek(/* one reader or all rams */ 0);
  return value_det_det_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 2
// det_update_0_write
//	det_det_update_0_write0
inline void det_det_update_0_write_bundle_write(hw_uint<16>& det_update_0_write, det_cache& det, int d0, int d1) {
	hw_uint<16> det_det_update_0_write0_res = det_update_0_write.extract<0, 15>();
	det_det_update_0_write0_write(det_det_update_0_write0_res, det, d0, d1);
}

// harris16_mini_update_0_read
//	harris16_mini_rd0
inline hw_uint<16> det_harris16_mini_update_0_read_bundle_read(det_cache& det, int d0, int d1) {
  // # of ports in bundle: 1
    // harris16_mini_rd0

	hw_uint<16> result;
	hw_uint<16> harris16_mini_rd0_res = harris16_mini_rd0_select(det, d0, d1);
	set_at<0, 16>(result, harris16_mini_rd0_res);
	return result;
}

#include "hw_classes.h"

struct grad_x_grad_x_update_0_write0_merged_banks_2_cache {
	// RAM Box: {[-1, 32], [-1, 32]}
	// Capacity: 1
	// # of read delays: 1
	hw_uint<16> f1;


	inline hw_uint<16> peek_0() {
		return f1;
	}



	inline void push(const hw_uint<16> value) {
    // cap: 1
    f1 = value;
	}

};

struct grad_x_cache {
  grad_x_grad_x_update_0_write0_merged_banks_2_cache grad_x_grad_x_update_0_write0_merged_banks_2;
};



inline void grad_x_grad_x_update_0_write0_write(hw_uint<16>& grad_x_grad_x_update_0_write0, grad_x_cache& grad_x, int d0, int d1) {
  grad_x.grad_x_grad_x_update_0_write0_merged_banks_2.push(grad_x_grad_x_update_0_write0);
}

inline hw_uint<16> lxx_rd0_select(grad_x_cache& grad_x, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lxx_rd0 read pattern: { lxx_update_0[d0, d1] -> grad_x[d0, d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { grad_x_update_0[d0, d1] -> [1 + d1, 1 + d0, 3] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: {  }
  auto value_grad_x_grad_x_update_0_write0 = grad_x.grad_x_grad_x_update_0_write0_merged_banks_2.peek_0();
  return value_grad_x_grad_x_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lxy_rd0_select(grad_x_cache& grad_x, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lxy_rd0 read pattern: { lxy_update_0[d0, d1] -> grad_x[d0, d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { grad_x_update_0[d0, d1] -> [1 + d1, 1 + d0, 3] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: {  }
  auto value_grad_x_grad_x_update_0_write0 = grad_x.grad_x_grad_x_update_0_write0_merged_banks_2.peek_0();
  return value_grad_x_grad_x_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 3
// grad_x_update_0_write
//	grad_x_grad_x_update_0_write0
inline void grad_x_grad_x_update_0_write_bundle_write(hw_uint<16>& grad_x_update_0_write, grad_x_cache& grad_x, int d0, int d1) {
	hw_uint<16> grad_x_grad_x_update_0_write0_res = grad_x_update_0_write.extract<0, 15>();
	grad_x_grad_x_update_0_write0_write(grad_x_grad_x_update_0_write0_res, grad_x, d0, d1);
}

// lxx_update_0_read
//	lxx_rd0
inline hw_uint<16> grad_x_lxx_update_0_read_bundle_read(grad_x_cache& grad_x, int d0, int d1) {
  // # of ports in bundle: 1
    // lxx_rd0

	hw_uint<16> result;
	hw_uint<16> lxx_rd0_res = lxx_rd0_select(grad_x, d0, d1);
	set_at<0, 16>(result, lxx_rd0_res);
	return result;
}

// lxy_update_0_read
//	lxy_rd0
inline hw_uint<16> grad_x_lxy_update_0_read_bundle_read(grad_x_cache& grad_x, int d0, int d1) {
  // # of ports in bundle: 1
    // lxy_rd0

	hw_uint<16> result;
	hw_uint<16> lxy_rd0_res = lxy_rd0_select(grad_x, d0, d1);
	set_at<0, 16>(result, lxy_rd0_res);
	return result;
}

#include "hw_classes.h"

struct grad_y_grad_y_update_0_write0_merged_banks_2_cache {
	// RAM Box: {[-1, 32], [-1, 32]}
	// Capacity: 1
	// # of read delays: 1
	hw_uint<16> f1;


	inline hw_uint<16> peek_0() {
		return f1;
	}



	inline void push(const hw_uint<16> value) {
    // cap: 1
    f1 = value;
	}

};

struct grad_y_cache {
  grad_y_grad_y_update_0_write0_merged_banks_2_cache grad_y_grad_y_update_0_write0_merged_banks_2;
};



inline void grad_y_grad_y_update_0_write0_write(hw_uint<16>& grad_y_grad_y_update_0_write0, grad_y_cache& grad_y, int d0, int d1) {
  grad_y.grad_y_grad_y_update_0_write0_merged_banks_2.push(grad_y_grad_y_update_0_write0);
}

inline hw_uint<16> lxy_rd0_select(grad_y_cache& grad_y, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lxy_rd0 read pattern: { lxy_update_0[d0, d1] -> grad_y[d0, d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { grad_y_update_0[d0, d1] -> [1 + d1, 1 + d0, 2] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: {  }
  auto value_grad_y_grad_y_update_0_write0 = grad_y.grad_y_grad_y_update_0_write0_merged_banks_2.peek_0();
  return value_grad_y_grad_y_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lyy_rd0_select(grad_y_cache& grad_y, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lyy_rd0 read pattern: { lyy_update_0[d0, d1] -> grad_y[d0, d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { grad_y_update_0[d0, d1] -> [1 + d1, 1 + d0, 2] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: {  }
  auto value_grad_y_grad_y_update_0_write0 = grad_y.grad_y_grad_y_update_0_write0_merged_banks_2.peek_0();
  return value_grad_y_grad_y_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 3
// grad_y_update_0_write
//	grad_y_grad_y_update_0_write0
inline void grad_y_grad_y_update_0_write_bundle_write(hw_uint<16>& grad_y_update_0_write, grad_y_cache& grad_y, int d0, int d1) {
	hw_uint<16> grad_y_grad_y_update_0_write0_res = grad_y_update_0_write.extract<0, 15>();
	grad_y_grad_y_update_0_write0_write(grad_y_grad_y_update_0_write0_res, grad_y, d0, d1);
}

// lxy_update_0_read
//	lxy_rd0
inline hw_uint<16> grad_y_lxy_update_0_read_bundle_read(grad_y_cache& grad_y, int d0, int d1) {
  // # of ports in bundle: 1
    // lxy_rd0

	hw_uint<16> result;
	hw_uint<16> lxy_rd0_res = lxy_rd0_select(grad_y, d0, d1);
	set_at<0, 16>(result, lxy_rd0_res);
	return result;
}

// lyy_update_0_read
//	lyy_rd0
inline hw_uint<16> grad_y_lyy_update_0_read_bundle_read(grad_y_cache& grad_y, int d0, int d1) {
  // # of ports in bundle: 1
    // lyy_rd0

	hw_uint<16> result;
	hw_uint<16> lyy_rd0_res = lyy_rd0_select(grad_y, d0, d1);
	set_at<0, 16>(result, lyy_rd0_res);
	return result;
}

#include "hw_classes.h"

struct img_img_update_0_write0_merged_banks_12_cache {
	// RAM Box: {[-2, 33], [-2, 33]}
	// Capacity: 75
	// # of read delays: 8
	hw_uint<16> f0;
	hw_uint<16> f2;
	hw_uint<16> f4;
	fifo<hw_uint<16>, 33> f5;
	hw_uint<16> f6;
	hw_uint<16> f7;
	hw_uint<16> f8;
	fifo<hw_uint<16>, 33> f9;
	hw_uint<16> f10;
	hw_uint<16> f12;
	hw_uint<16> f14;


	inline hw_uint<16> peek_0() {
		return f0;
	}

	inline hw_uint<16> peek_1() {
		return f2;
	}

	inline hw_uint<16> peek_2() {
		return f4;
	}

	inline hw_uint<16> peek_35() {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
		return f5.back();
	}

	inline hw_uint<16> peek_36() {
		return f6;
	}

	inline hw_uint<16> peek_37() {
		return f7;
	}

	inline hw_uint<16> peek_38() {
		return f8;
	}

	inline hw_uint<16> peek_71() {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
		return f9.back();
	}

	inline hw_uint<16> peek_72() {
		return f10;
	}

	inline hw_uint<16> peek_73() {
		return f12;
	}

	inline hw_uint<16> peek_74() {
		return f14;
	}



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f14 = f12;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f12 = f10;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 33
    f10 = f9.back();
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 33 reading from capacity: 1
    f9.push(f8);
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f8 = f7;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f7 = f6;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 33
    f6 = f5.back();
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 33 reading from capacity: 1
    f5.push(f4);
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f4 = f2;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f2 = f0;
    // cap: 1
    f0 = value;
	}

};

struct img_cache {
  img_img_update_0_write0_merged_banks_12_cache img_img_update_0_write0_merged_banks_12;
};



inline void img_img_update_0_write0_write(hw_uint<16>& img_img_update_0_write0, img_cache& img, int d0, int d1) {
  img.img_img_update_0_write0_merged_banks_12.push(img_img_update_0_write0);
}

inline hw_uint<16> grad_x_rd0_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_x_rd0 read pattern: { grad_x_update_0[d0, d1] -> img[-1 + d0, -1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_x_update_0[d0, d1] -> [1 + d1, 1 + d0, 3] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_x_update_0[d0, d1] -> 74 : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_74();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_x_rd1_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_x_rd1 read pattern: { grad_x_update_0[d0, d1] -> img[-1 + d0, d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_x_update_0[d0, d1] -> [1 + d1, 1 + d0, 3] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_x_update_0[d0, d1] -> 38 : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_38();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_x_rd2_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_x_rd2 read pattern: { grad_x_update_0[d0, d1] -> img[-1 + d0, 1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_x_update_0[d0, d1] -> [1 + d1, 1 + d0, 3] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_x_update_0[d0, d1] -> 2 : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_2();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_x_rd3_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_x_rd3 read pattern: { grad_x_update_0[d0, d1] -> img[1 + d0, -1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_x_update_0[d0, d1] -> [1 + d1, 1 + d0, 3] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_x_update_0[d0, d1] -> 72 : -1 <= d0 <= 31 and -1 <= d1 <= 32; grad_x_update_0[d0, d1] -> (40 + d0) : d0 = 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_72();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_x_rd4_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_x_rd4 read pattern: { grad_x_update_0[d0, d1] -> img[1 + d0, d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_x_update_0[d0, d1] -> [1 + d1, 1 + d0, 3] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_x_update_0[d0, d1] -> 36 : -1 <= d0 <= 31 and -1 <= d1 <= 32; grad_x_update_0[d0, d1] -> (4 + d0) : d0 = 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_36();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_x_rd5_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_x_rd5 read pattern: { grad_x_update_0[d0, d1] -> img[1 + d0, 1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_x_update_0[d0, d1] -> [1 + d1, 1 + d0, 3] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: {  }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_0();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_y_rd0_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_y_rd0 read pattern: { grad_y_update_0[d0, d1] -> img[-1 + d0, -1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_y_update_0[d0, d1] -> [1 + d1, 1 + d0, 2] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_y_update_0[d0, d1] -> 74 : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_74();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_y_rd1_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_y_rd1 read pattern: { grad_y_update_0[d0, d1] -> img[-1 + d0, 1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_y_update_0[d0, d1] -> [1 + d1, 1 + d0, 2] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_y_update_0[d0, d1] -> 2 : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_2();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_y_rd2_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_y_rd2 read pattern: { grad_y_update_0[d0, d1] -> img[d0, -1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_y_update_0[d0, d1] -> [1 + d1, 1 + d0, 2] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_y_update_0[d0, d1] -> 73 : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_73();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_y_rd3_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_y_rd3 read pattern: { grad_y_update_0[d0, d1] -> img[d0, 1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_y_update_0[d0, d1] -> [1 + d1, 1 + d0, 2] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_y_update_0[d0, d1] -> 1 : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_1();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_y_rd4_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_y_rd4 read pattern: { grad_y_update_0[d0, d1] -> img[1 + d0, -1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_y_update_0[d0, d1] -> [1 + d1, 1 + d0, 2] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: { grad_y_update_0[d0, d1] -> 72 : -1 <= d0 <= 31 and -1 <= d1 <= 32; grad_y_update_0[d0, d1] -> (40 + d0) : d0 = 32 and -1 <= d1 <= 32 }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_72();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> grad_y_rd5_select(img_cache& img, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // grad_y_rd5 read pattern: { grad_y_update_0[d0, d1] -> img[1 + d0, 1 + d1] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Read schedule : { grad_y_update_0[d0, d1] -> [1 + d1, 1 + d0, 2] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // Write schedule: { img_update_0[d0, d1] -> [d1, d0, 1] : -2 <= d0 <= 33 and -2 <= d1 <= 33 }
  // DD fold: {  }
  auto value_img_img_update_0_write0 = img.img_img_update_0_write0_merged_banks_12.peek_0();
  return value_img_img_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 3
// grad_x_update_0_read
//	grad_x_rd0
//	grad_x_rd1
//	grad_x_rd2
//	grad_x_rd3
//	grad_x_rd4
//	grad_x_rd5
inline hw_uint<96> img_grad_x_update_0_read_bundle_read(img_cache& img, int d0, int d1) {
  // # of ports in bundle: 6
    // grad_x_rd0
    // grad_x_rd1
    // grad_x_rd2
    // grad_x_rd3
    // grad_x_rd4
    // grad_x_rd5

	hw_uint<96> result;
	hw_uint<16> grad_x_rd0_res = grad_x_rd0_select(img, d0, d1);
	set_at<0, 96>(result, grad_x_rd0_res);
	hw_uint<16> grad_x_rd1_res = grad_x_rd1_select(img, d0, d1);
	set_at<16, 96>(result, grad_x_rd1_res);
	hw_uint<16> grad_x_rd2_res = grad_x_rd2_select(img, d0, d1);
	set_at<32, 96>(result, grad_x_rd2_res);
	hw_uint<16> grad_x_rd3_res = grad_x_rd3_select(img, d0, d1);
	set_at<48, 96>(result, grad_x_rd3_res);
	hw_uint<16> grad_x_rd4_res = grad_x_rd4_select(img, d0, d1);
	set_at<64, 96>(result, grad_x_rd4_res);
	hw_uint<16> grad_x_rd5_res = grad_x_rd5_select(img, d0, d1);
	set_at<80, 96>(result, grad_x_rd5_res);
	return result;
}

// grad_y_update_0_read
//	grad_y_rd0
//	grad_y_rd1
//	grad_y_rd2
//	grad_y_rd3
//	grad_y_rd4
//	grad_y_rd5
inline hw_uint<96> img_grad_y_update_0_read_bundle_read(img_cache& img, int d0, int d1) {
  // # of ports in bundle: 6
    // grad_y_rd0
    // grad_y_rd1
    // grad_y_rd2
    // grad_y_rd3
    // grad_y_rd4
    // grad_y_rd5

	hw_uint<96> result;
	hw_uint<16> grad_y_rd0_res = grad_y_rd0_select(img, d0, d1);
	set_at<0, 96>(result, grad_y_rd0_res);
	hw_uint<16> grad_y_rd1_res = grad_y_rd1_select(img, d0, d1);
	set_at<16, 96>(result, grad_y_rd1_res);
	hw_uint<16> grad_y_rd2_res = grad_y_rd2_select(img, d0, d1);
	set_at<32, 96>(result, grad_y_rd2_res);
	hw_uint<16> grad_y_rd3_res = grad_y_rd3_select(img, d0, d1);
	set_at<48, 96>(result, grad_y_rd3_res);
	hw_uint<16> grad_y_rd4_res = grad_y_rd4_select(img, d0, d1);
	set_at<64, 96>(result, grad_y_rd4_res);
	hw_uint<16> grad_y_rd5_res = grad_y_rd5_select(img, d0, d1);
	set_at<80, 96>(result, grad_y_rd5_res);
	return result;
}

// img_update_0_write
//	img_img_update_0_write0
inline void img_img_update_0_write_bundle_write(hw_uint<16>& img_update_0_write, img_cache& img, int d0, int d1) {
	hw_uint<16> img_img_update_0_write0_res = img_update_0_write.extract<0, 15>();
	img_img_update_0_write0_write(img_img_update_0_write0_res, img, d0, d1);
}

#include "hw_classes.h"

struct lgxx_lgxx_update_0_write0_merged_banks_1_cache {
	// RAM Box: {[0, 31], [0, 31]}
	// Capacity: 1
	// # of read delays: 1
	fifo<hw_uint<16>, 1> f;
	inline hw_uint<16> peek(const int offset) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.peek(0 - offset);
  }



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.push(value);
  }

};

struct lgxx_cache {
  lgxx_lgxx_update_0_write0_merged_banks_1_cache lgxx_lgxx_update_0_write0_merged_banks_1;
};



inline void lgxx_lgxx_update_0_write0_write(hw_uint<16>& lgxx_lgxx_update_0_write0, lgxx_cache& lgxx, int d0, int d1) {
  lgxx.lgxx_lgxx_update_0_write0_merged_banks_1.push(lgxx_lgxx_update_0_write0);
}

inline hw_uint<16> lgxx8_rd0_select(lgxx_cache& lgxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx8_rd0 read pattern: { lgxx8_update_0[d0, d1] -> lgxx[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx8_update_0[d0, d1] -> [2 + d1, 2 + d0, 12] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_lgxx_lgxx_update_0_write0 = lgxx.lgxx_lgxx_update_0_write0_merged_banks_1.peek(/* one reader or all rams */ 0);
  return value_lgxx_lgxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 2
// lgxx8_update_0_read
//	lgxx8_rd0
inline hw_uint<16> lgxx_lgxx8_update_0_read_bundle_read(lgxx_cache& lgxx, int d0, int d1) {
  // # of ports in bundle: 1
    // lgxx8_rd0

	hw_uint<16> result;
	hw_uint<16> lgxx8_rd0_res = lgxx8_rd0_select(lgxx, d0, d1);
	set_at<0, 16>(result, lgxx8_rd0_res);
	return result;
}

// lgxx_update_0_write
//	lgxx_lgxx_update_0_write0
inline void lgxx_lgxx_update_0_write_bundle_write(hw_uint<16>& lgxx_update_0_write, lgxx_cache& lgxx, int d0, int d1) {
	hw_uint<16> lgxx_lgxx_update_0_write0_res = lgxx_update_0_write.extract<0, 15>();
	lgxx_lgxx_update_0_write0_write(lgxx_lgxx_update_0_write0_res, lgxx, d0, d1);
}

#include "hw_classes.h"

struct lgxx8_lgxx8_update_0_write0_merged_banks_2_cache {
	// RAM Box: {[0, 31], [0, 31]}
	// Capacity: 1
	// # of read delays: 1
	hw_uint<16> f1;


	inline hw_uint<16> peek_0() {
		return f1;
	}



	inline void push(const hw_uint<16> value) {
    // cap: 1
    f1 = value;
	}

};

struct lgxx8_cache {
  lgxx8_lgxx8_update_0_write0_merged_banks_2_cache lgxx8_lgxx8_update_0_write0_merged_banks_2;
};



inline void lgxx8_lgxx8_update_0_write0_write(hw_uint<16>& lgxx8_lgxx8_update_0_write0, lgxx8_cache& lgxx8, int d0, int d1) {
  lgxx8.lgxx8_lgxx8_update_0_write0_merged_banks_2.push(lgxx8_lgxx8_update_0_write0);
}

inline hw_uint<16> det_rd0_select(lgxx8_cache& lgxx8, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // det_rd0 read pattern: { det_update_0[d0, d1] -> lgxx8[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { det_update_0[d0, d1] -> [2 + d1, 2 + d0, 13] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lgxx8_update_0[d0, d1] -> [2 + d1, 2 + d0, 12] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_lgxx8_lgxx8_update_0_write0 = lgxx8.lgxx8_lgxx8_update_0_write0_merged_banks_2.peek_0();
  return value_lgxx8_lgxx8_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> trace_rd0_select(lgxx8_cache& lgxx8, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // trace_rd0 read pattern: { trace_update_0[d0, d1] -> lgxx8[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { trace_update_0[d0, d1] -> [2 + d1, 2 + d0, 14] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lgxx8_update_0[d0, d1] -> [2 + d1, 2 + d0, 12] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_lgxx8_lgxx8_update_0_write0 = lgxx8.lgxx8_lgxx8_update_0_write0_merged_banks_2.peek_0();
  return value_lgxx8_lgxx8_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 3
// det_update_0_read
//	det_rd0
inline hw_uint<16> lgxx8_det_update_0_read_bundle_read(lgxx8_cache& lgxx8, int d0, int d1) {
  // # of ports in bundle: 1
    // det_rd0

	hw_uint<16> result;
	hw_uint<16> det_rd0_res = det_rd0_select(lgxx8, d0, d1);
	set_at<0, 16>(result, det_rd0_res);
	return result;
}

// lgxx8_update_0_write
//	lgxx8_lgxx8_update_0_write0
inline void lgxx8_lgxx8_update_0_write_bundle_write(hw_uint<16>& lgxx8_update_0_write, lgxx8_cache& lgxx8, int d0, int d1) {
	hw_uint<16> lgxx8_lgxx8_update_0_write0_res = lgxx8_update_0_write.extract<0, 15>();
	lgxx8_lgxx8_update_0_write0_write(lgxx8_lgxx8_update_0_write0_res, lgxx8, d0, d1);
}

// trace_update_0_read
//	trace_rd0
inline hw_uint<16> lgxx8_trace_update_0_read_bundle_read(lgxx8_cache& lgxx8, int d0, int d1) {
  // # of ports in bundle: 1
    // trace_rd0

	hw_uint<16> result;
	hw_uint<16> trace_rd0_res = trace_rd0_select(lgxx8, d0, d1);
	set_at<0, 16>(result, trace_rd0_res);
	return result;
}

#include "hw_classes.h"

struct lgxy_lgxy_update_0_write0_merged_banks_1_cache {
	// RAM Box: {[0, 31], [0, 31]}
	// Capacity: 1
	// # of read delays: 1
	fifo<hw_uint<16>, 1> f;
	inline hw_uint<16> peek(const int offset) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.peek(0 - offset);
  }



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.push(value);
  }

};

struct lgxy_cache {
  lgxy_lgxy_update_0_write0_merged_banks_1_cache lgxy_lgxy_update_0_write0_merged_banks_1;
};



inline void lgxy_lgxy_update_0_write0_write(hw_uint<16>& lgxy_lgxy_update_0_write0, lgxy_cache& lgxy, int d0, int d1) {
  lgxy.lgxy_lgxy_update_0_write0_merged_banks_1.push(lgxy_lgxy_update_0_write0);
}

inline hw_uint<16> lgxy8_rd0_select(lgxy_cache& lgxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy8_rd0 read pattern: { lgxy8_update_0[d0, d1] -> lgxy[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy8_update_0[d0, d1] -> [2 + d1, 2 + d0, 11] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_lgxy_lgxy_update_0_write0 = lgxy.lgxy_lgxy_update_0_write0_merged_banks_1.peek(/* one reader or all rams */ 0);
  return value_lgxy_lgxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 2
// lgxy8_update_0_read
//	lgxy8_rd0
inline hw_uint<16> lgxy_lgxy8_update_0_read_bundle_read(lgxy_cache& lgxy, int d0, int d1) {
  // # of ports in bundle: 1
    // lgxy8_rd0

	hw_uint<16> result;
	hw_uint<16> lgxy8_rd0_res = lgxy8_rd0_select(lgxy, d0, d1);
	set_at<0, 16>(result, lgxy8_rd0_res);
	return result;
}

// lgxy_update_0_write
//	lgxy_lgxy_update_0_write0
inline void lgxy_lgxy_update_0_write_bundle_write(hw_uint<16>& lgxy_update_0_write, lgxy_cache& lgxy, int d0, int d1) {
	hw_uint<16> lgxy_lgxy_update_0_write0_res = lgxy_update_0_write.extract<0, 15>();
	lgxy_lgxy_update_0_write0_write(lgxy_lgxy_update_0_write0_res, lgxy, d0, d1);
}

#include "hw_classes.h"

struct lgxy8_lgxy8_update_0_write0_merged_banks_1_cache {
	// RAM Box: {[0, 31], [0, 31]}
	// Capacity: 1
	// # of read delays: 1
	fifo<hw_uint<16>, 1> f;
	inline hw_uint<16> peek(const int offset) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.peek(0 - offset);
  }



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.push(value);
  }

};

struct lgxy8_cache {
  lgxy8_lgxy8_update_0_write0_merged_banks_1_cache lgxy8_lgxy8_update_0_write0_merged_banks_1;
};



inline void lgxy8_lgxy8_update_0_write0_write(hw_uint<16>& lgxy8_lgxy8_update_0_write0, lgxy8_cache& lgxy8, int d0, int d1) {
  lgxy8.lgxy8_lgxy8_update_0_write0_merged_banks_1.push(lgxy8_lgxy8_update_0_write0);
}

inline hw_uint<16> det_rd0_select(lgxy8_cache& lgxy8, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // det_rd0 read pattern: { det_update_0[d0, d1] -> lgxy8[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { det_update_0[d0, d1] -> [2 + d1, 2 + d0, 13] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lgxy8_update_0[d0, d1] -> [2 + d1, 2 + d0, 11] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_lgxy8_lgxy8_update_0_write0 = lgxy8.lgxy8_lgxy8_update_0_write0_merged_banks_1.peek(/* one reader or all rams */ 0);
  return value_lgxy8_lgxy8_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 2
// det_update_0_read
//	det_rd0
inline hw_uint<16> lgxy8_det_update_0_read_bundle_read(lgxy8_cache& lgxy8, int d0, int d1) {
  // # of ports in bundle: 1
    // det_rd0

	hw_uint<16> result;
	hw_uint<16> det_rd0_res = det_rd0_select(lgxy8, d0, d1);
	set_at<0, 16>(result, det_rd0_res);
	return result;
}

// lgxy8_update_0_write
//	lgxy8_lgxy8_update_0_write0
inline void lgxy8_lgxy8_update_0_write_bundle_write(hw_uint<16>& lgxy8_update_0_write, lgxy8_cache& lgxy8, int d0, int d1) {
	hw_uint<16> lgxy8_lgxy8_update_0_write0_res = lgxy8_update_0_write.extract<0, 15>();
	lgxy8_lgxy8_update_0_write0_write(lgxy8_lgxy8_update_0_write0_res, lgxy8, d0, d1);
}

#include "hw_classes.h"

struct lgyy_lgyy_update_0_write0_merged_banks_1_cache {
	// RAM Box: {[0, 31], [0, 31]}
	// Capacity: 1
	// # of read delays: 1
	fifo<hw_uint<16>, 1> f;
	inline hw_uint<16> peek(const int offset) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.peek(0 - offset);
  }



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.push(value);
  }

};

struct lgyy_cache {
  lgyy_lgyy_update_0_write0_merged_banks_1_cache lgyy_lgyy_update_0_write0_merged_banks_1;
};



inline void lgyy_lgyy_update_0_write0_write(hw_uint<16>& lgyy_lgyy_update_0_write0, lgyy_cache& lgyy, int d0, int d1) {
  lgyy.lgyy_lgyy_update_0_write0_merged_banks_1.push(lgyy_lgyy_update_0_write0);
}

inline hw_uint<16> lgyy8_rd0_select(lgyy_cache& lgyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy8_rd0 read pattern: { lgyy8_update_0[d0, d1] -> lgyy[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy8_update_0[d0, d1] -> [2 + d1, 2 + d0, 10] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_lgyy_lgyy_update_0_write0 = lgyy.lgyy_lgyy_update_0_write0_merged_banks_1.peek(/* one reader or all rams */ 0);
  return value_lgyy_lgyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 2
// lgyy8_update_0_read
//	lgyy8_rd0
inline hw_uint<16> lgyy_lgyy8_update_0_read_bundle_read(lgyy_cache& lgyy, int d0, int d1) {
  // # of ports in bundle: 1
    // lgyy8_rd0

	hw_uint<16> result;
	hw_uint<16> lgyy8_rd0_res = lgyy8_rd0_select(lgyy, d0, d1);
	set_at<0, 16>(result, lgyy8_rd0_res);
	return result;
}

// lgyy_update_0_write
//	lgyy_lgyy_update_0_write0
inline void lgyy_lgyy_update_0_write_bundle_write(hw_uint<16>& lgyy_update_0_write, lgyy_cache& lgyy, int d0, int d1) {
	hw_uint<16> lgyy_lgyy_update_0_write0_res = lgyy_update_0_write.extract<0, 15>();
	lgyy_lgyy_update_0_write0_write(lgyy_lgyy_update_0_write0_res, lgyy, d0, d1);
}

#include "hw_classes.h"

struct lgyy8_lgyy8_update_0_write0_merged_banks_2_cache {
	// RAM Box: {[0, 31], [0, 31]}
	// Capacity: 1
	// # of read delays: 1
	hw_uint<16> f1;


	inline hw_uint<16> peek_0() {
		return f1;
	}



	inline void push(const hw_uint<16> value) {
    // cap: 1
    f1 = value;
	}

};

struct lgyy8_cache {
  lgyy8_lgyy8_update_0_write0_merged_banks_2_cache lgyy8_lgyy8_update_0_write0_merged_banks_2;
};



inline void lgyy8_lgyy8_update_0_write0_write(hw_uint<16>& lgyy8_lgyy8_update_0_write0, lgyy8_cache& lgyy8, int d0, int d1) {
  lgyy8.lgyy8_lgyy8_update_0_write0_merged_banks_2.push(lgyy8_lgyy8_update_0_write0);
}

inline hw_uint<16> det_rd0_select(lgyy8_cache& lgyy8, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // det_rd0 read pattern: { det_update_0[d0, d1] -> lgyy8[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { det_update_0[d0, d1] -> [2 + d1, 2 + d0, 13] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lgyy8_update_0[d0, d1] -> [2 + d1, 2 + d0, 10] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_lgyy8_lgyy8_update_0_write0 = lgyy8.lgyy8_lgyy8_update_0_write0_merged_banks_2.peek_0();
  return value_lgyy8_lgyy8_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> trace_rd0_select(lgyy8_cache& lgyy8, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // trace_rd0 read pattern: { trace_update_0[d0, d1] -> lgyy8[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { trace_update_0[d0, d1] -> [2 + d1, 2 + d0, 14] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lgyy8_update_0[d0, d1] -> [2 + d1, 2 + d0, 10] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_lgyy8_lgyy8_update_0_write0 = lgyy8.lgyy8_lgyy8_update_0_write0_merged_banks_2.peek_0();
  return value_lgyy8_lgyy8_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 3
// det_update_0_read
//	det_rd0
inline hw_uint<16> lgyy8_det_update_0_read_bundle_read(lgyy8_cache& lgyy8, int d0, int d1) {
  // # of ports in bundle: 1
    // det_rd0

	hw_uint<16> result;
	hw_uint<16> det_rd0_res = det_rd0_select(lgyy8, d0, d1);
	set_at<0, 16>(result, det_rd0_res);
	return result;
}

// lgyy8_update_0_write
//	lgyy8_lgyy8_update_0_write0
inline void lgyy8_lgyy8_update_0_write_bundle_write(hw_uint<16>& lgyy8_update_0_write, lgyy8_cache& lgyy8, int d0, int d1) {
	hw_uint<16> lgyy8_lgyy8_update_0_write0_res = lgyy8_update_0_write.extract<0, 15>();
	lgyy8_lgyy8_update_0_write0_write(lgyy8_lgyy8_update_0_write0_res, lgyy8, d0, d1);
}

// trace_update_0_read
//	trace_rd0
inline hw_uint<16> lgyy8_trace_update_0_read_bundle_read(lgyy8_cache& lgyy8, int d0, int d1) {
  // # of ports in bundle: 1
    // trace_rd0

	hw_uint<16> result;
	hw_uint<16> trace_rd0_res = trace_rd0_select(lgyy8, d0, d1);
	set_at<0, 16>(result, trace_rd0_res);
	return result;
}

#include "hw_classes.h"

struct lxx_lxx_update_0_write0_merged_banks_9_cache {
	// RAM Box: {[-1, 32], [-1, 32]}
	// Capacity: 71
	// # of read delays: 9
	hw_uint<16> f0;
	hw_uint<16> f2;
	hw_uint<16> f4;
	fifo<hw_uint<16>, 31> f5;
	hw_uint<16> f6;
	hw_uint<16> f8;
	hw_uint<16> f10;
	fifo<hw_uint<16>, 31> f11;
	hw_uint<16> f12;
	hw_uint<16> f14;
	hw_uint<16> f16;


	inline hw_uint<16> peek_0() {
		return f0;
	}

	inline hw_uint<16> peek_1() {
		return f2;
	}

	inline hw_uint<16> peek_2() {
		return f4;
	}

	inline hw_uint<16> peek_33() {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
		return f5.back();
	}

	inline hw_uint<16> peek_34() {
		return f6;
	}

	inline hw_uint<16> peek_35() {
		return f8;
	}

	inline hw_uint<16> peek_36() {
		return f10;
	}

	inline hw_uint<16> peek_67() {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
		return f11.back();
	}

	inline hw_uint<16> peek_68() {
		return f12;
	}

	inline hw_uint<16> peek_69() {
		return f14;
	}

	inline hw_uint<16> peek_70() {
		return f16;
	}



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f16 = f14;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f14 = f12;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 31
    f12 = f11.back();
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 31 reading from capacity: 1
    f11.push(f10);
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f10 = f8;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f8 = f6;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 31
    f6 = f5.back();
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 31 reading from capacity: 1
    f5.push(f4);
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f4 = f2;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f2 = f0;
    // cap: 1
    f0 = value;
	}

};

struct lxx_cache {
  lxx_lxx_update_0_write0_merged_banks_9_cache lxx_lxx_update_0_write0_merged_banks_9;
};



inline void lxx_lxx_update_0_write0_write(hw_uint<16>& lxx_lxx_update_0_write0, lxx_cache& lxx, int d0, int d1) {
  lxx.lxx_lxx_update_0_write0_merged_banks_9.push(lxx_lxx_update_0_write0);
}

inline hw_uint<16> lgxx_rd0_select(lxx_cache& lxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx_rd0 read pattern: { lgxx_update_0[d0, d1] -> lxx[-1 + d0, -1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxx_update_0[d0, d1] -> 70 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxx_lxx_update_0_write0 = lxx.lxx_lxx_update_0_write0_merged_banks_9.peek_70();
  return value_lxx_lxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxx_rd1_select(lxx_cache& lxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx_rd1 read pattern: { lgxx_update_0[d0, d1] -> lxx[-1 + d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxx_update_0[d0, d1] -> 36 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxx_lxx_update_0_write0 = lxx.lxx_lxx_update_0_write0_merged_banks_9.peek_36();
  return value_lxx_lxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxx_rd2_select(lxx_cache& lxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx_rd2 read pattern: { lgxx_update_0[d0, d1] -> lxx[-1 + d0, 1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxx_update_0[d0, d1] -> 2 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxx_lxx_update_0_write0 = lxx.lxx_lxx_update_0_write0_merged_banks_9.peek_2();
  return value_lxx_lxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxx_rd3_select(lxx_cache& lxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx_rd3 read pattern: { lgxx_update_0[d0, d1] -> lxx[d0, -1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxx_update_0[d0, d1] -> 69 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxx_lxx_update_0_write0 = lxx.lxx_lxx_update_0_write0_merged_banks_9.peek_69();
  return value_lxx_lxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxx_rd4_select(lxx_cache& lxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx_rd4 read pattern: { lgxx_update_0[d0, d1] -> lxx[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxx_update_0[d0, d1] -> 35 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxx_lxx_update_0_write0 = lxx.lxx_lxx_update_0_write0_merged_banks_9.peek_35();
  return value_lxx_lxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxx_rd5_select(lxx_cache& lxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx_rd5 read pattern: { lgxx_update_0[d0, d1] -> lxx[d0, 1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxx_update_0[d0, d1] -> 1 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxx_lxx_update_0_write0 = lxx.lxx_lxx_update_0_write0_merged_banks_9.peek_1();
  return value_lxx_lxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxx_rd6_select(lxx_cache& lxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx_rd6 read pattern: { lgxx_update_0[d0, d1] -> lxx[1 + d0, -1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxx_update_0[d0, d1] -> 68 : 0 <= d0 <= 30 and 0 <= d1 <= 31; lgxx_update_0[d0, d1] -> (37 + d0) : d0 = 31 and 0 <= d1 <= 31 }
  auto value_lxx_lxx_update_0_write0 = lxx.lxx_lxx_update_0_write0_merged_banks_9.peek_68();
  return value_lxx_lxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxx_rd7_select(lxx_cache& lxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx_rd7 read pattern: { lgxx_update_0[d0, d1] -> lxx[1 + d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxx_update_0[d0, d1] -> 34 : 0 <= d0 <= 30 and 0 <= d1 <= 31; lgxx_update_0[d0, d1] -> (3 + d0) : d0 = 31 and 0 <= d1 <= 31 }
  auto value_lxx_lxx_update_0_write0 = lxx.lxx_lxx_update_0_write0_merged_banks_9.peek_34();
  return value_lxx_lxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxx_rd8_select(lxx_cache& lxx, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxx_rd8 read pattern: { lgxx_update_0[d0, d1] -> lxx[1 + d0, 1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxx_update_0[d0, d1] -> [2 + d1, 2 + d0, 9] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxx_update_0[d0, d1] -> [1 + d1, 1 + d0, 6] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: {  }
  auto value_lxx_lxx_update_0_write0 = lxx.lxx_lxx_update_0_write0_merged_banks_9.peek_0();
  return value_lxx_lxx_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 2
// lgxx_update_0_read
//	lgxx_rd0
//	lgxx_rd1
//	lgxx_rd2
//	lgxx_rd3
//	lgxx_rd4
//	lgxx_rd5
//	lgxx_rd6
//	lgxx_rd7
//	lgxx_rd8
inline hw_uint<144> lxx_lgxx_update_0_read_bundle_read(lxx_cache& lxx, int d0, int d1) {
  // # of ports in bundle: 9
    // lgxx_rd0
    // lgxx_rd1
    // lgxx_rd2
    // lgxx_rd3
    // lgxx_rd4
    // lgxx_rd5
    // lgxx_rd6
    // lgxx_rd7
    // lgxx_rd8

	hw_uint<144> result;
	hw_uint<16> lgxx_rd0_res = lgxx_rd0_select(lxx, d0, d1);
	set_at<0, 144>(result, lgxx_rd0_res);
	hw_uint<16> lgxx_rd1_res = lgxx_rd1_select(lxx, d0, d1);
	set_at<16, 144>(result, lgxx_rd1_res);
	hw_uint<16> lgxx_rd2_res = lgxx_rd2_select(lxx, d0, d1);
	set_at<32, 144>(result, lgxx_rd2_res);
	hw_uint<16> lgxx_rd3_res = lgxx_rd3_select(lxx, d0, d1);
	set_at<48, 144>(result, lgxx_rd3_res);
	hw_uint<16> lgxx_rd4_res = lgxx_rd4_select(lxx, d0, d1);
	set_at<64, 144>(result, lgxx_rd4_res);
	hw_uint<16> lgxx_rd5_res = lgxx_rd5_select(lxx, d0, d1);
	set_at<80, 144>(result, lgxx_rd5_res);
	hw_uint<16> lgxx_rd6_res = lgxx_rd6_select(lxx, d0, d1);
	set_at<96, 144>(result, lgxx_rd6_res);
	hw_uint<16> lgxx_rd7_res = lgxx_rd7_select(lxx, d0, d1);
	set_at<112, 144>(result, lgxx_rd7_res);
	hw_uint<16> lgxx_rd8_res = lgxx_rd8_select(lxx, d0, d1);
	set_at<128, 144>(result, lgxx_rd8_res);
	return result;
}

// lxx_update_0_write
//	lxx_lxx_update_0_write0
inline void lxx_lxx_update_0_write_bundle_write(hw_uint<16>& lxx_update_0_write, lxx_cache& lxx, int d0, int d1) {
	hw_uint<16> lxx_lxx_update_0_write0_res = lxx_update_0_write.extract<0, 15>();
	lxx_lxx_update_0_write0_write(lxx_lxx_update_0_write0_res, lxx, d0, d1);
}

#include "hw_classes.h"

struct lxy_lxy_update_0_write0_merged_banks_9_cache {
	// RAM Box: {[-1, 32], [-1, 32]}
	// Capacity: 71
	// # of read delays: 9
	hw_uint<16> f0;
	hw_uint<16> f2;
	hw_uint<16> f4;
	fifo<hw_uint<16>, 31> f5;
	hw_uint<16> f6;
	hw_uint<16> f8;
	hw_uint<16> f10;
	fifo<hw_uint<16>, 31> f11;
	hw_uint<16> f12;
	hw_uint<16> f14;
	hw_uint<16> f16;


	inline hw_uint<16> peek_0() {
		return f0;
	}

	inline hw_uint<16> peek_1() {
		return f2;
	}

	inline hw_uint<16> peek_2() {
		return f4;
	}

	inline hw_uint<16> peek_33() {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
		return f5.back();
	}

	inline hw_uint<16> peek_34() {
		return f6;
	}

	inline hw_uint<16> peek_35() {
		return f8;
	}

	inline hw_uint<16> peek_36() {
		return f10;
	}

	inline hw_uint<16> peek_67() {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
		return f11.back();
	}

	inline hw_uint<16> peek_68() {
		return f12;
	}

	inline hw_uint<16> peek_69() {
		return f14;
	}

	inline hw_uint<16> peek_70() {
		return f16;
	}



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f16 = f14;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f14 = f12;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 31
    f12 = f11.back();
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 31 reading from capacity: 1
    f11.push(f10);
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f10 = f8;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f8 = f6;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 31
    f6 = f5.back();
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 31 reading from capacity: 1
    f5.push(f4);
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f4 = f2;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f2 = f0;
    // cap: 1
    f0 = value;
	}

};

struct lxy_cache {
  lxy_lxy_update_0_write0_merged_banks_9_cache lxy_lxy_update_0_write0_merged_banks_9;
};



inline void lxy_lxy_update_0_write0_write(hw_uint<16>& lxy_lxy_update_0_write0, lxy_cache& lxy, int d0, int d1) {
  lxy.lxy_lxy_update_0_write0_merged_banks_9.push(lxy_lxy_update_0_write0);
}

inline hw_uint<16> lgxy_rd0_select(lxy_cache& lxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy_rd0 read pattern: { lgxy_update_0[d0, d1] -> lxy[-1 + d0, -1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxy_update_0[d0, d1] -> 70 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxy_lxy_update_0_write0 = lxy.lxy_lxy_update_0_write0_merged_banks_9.peek_70();
  return value_lxy_lxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxy_rd1_select(lxy_cache& lxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy_rd1 read pattern: { lgxy_update_0[d0, d1] -> lxy[-1 + d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxy_update_0[d0, d1] -> 36 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxy_lxy_update_0_write0 = lxy.lxy_lxy_update_0_write0_merged_banks_9.peek_36();
  return value_lxy_lxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxy_rd2_select(lxy_cache& lxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy_rd2 read pattern: { lgxy_update_0[d0, d1] -> lxy[-1 + d0, 1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxy_update_0[d0, d1] -> 2 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxy_lxy_update_0_write0 = lxy.lxy_lxy_update_0_write0_merged_banks_9.peek_2();
  return value_lxy_lxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxy_rd3_select(lxy_cache& lxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy_rd3 read pattern: { lgxy_update_0[d0, d1] -> lxy[d0, -1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxy_update_0[d0, d1] -> 69 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxy_lxy_update_0_write0 = lxy.lxy_lxy_update_0_write0_merged_banks_9.peek_69();
  return value_lxy_lxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxy_rd4_select(lxy_cache& lxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy_rd4 read pattern: { lgxy_update_0[d0, d1] -> lxy[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxy_update_0[d0, d1] -> 35 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxy_lxy_update_0_write0 = lxy.lxy_lxy_update_0_write0_merged_banks_9.peek_35();
  return value_lxy_lxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxy_rd5_select(lxy_cache& lxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy_rd5 read pattern: { lgxy_update_0[d0, d1] -> lxy[d0, 1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxy_update_0[d0, d1] -> 1 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lxy_lxy_update_0_write0 = lxy.lxy_lxy_update_0_write0_merged_banks_9.peek_1();
  return value_lxy_lxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxy_rd6_select(lxy_cache& lxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy_rd6 read pattern: { lgxy_update_0[d0, d1] -> lxy[1 + d0, -1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxy_update_0[d0, d1] -> 68 : 0 <= d0 <= 30 and 0 <= d1 <= 31; lgxy_update_0[d0, d1] -> (37 + d0) : d0 = 31 and 0 <= d1 <= 31 }
  auto value_lxy_lxy_update_0_write0 = lxy.lxy_lxy_update_0_write0_merged_banks_9.peek_68();
  return value_lxy_lxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxy_rd7_select(lxy_cache& lxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy_rd7 read pattern: { lgxy_update_0[d0, d1] -> lxy[1 + d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgxy_update_0[d0, d1] -> 34 : 0 <= d0 <= 30 and 0 <= d1 <= 31; lgxy_update_0[d0, d1] -> (3 + d0) : d0 = 31 and 0 <= d1 <= 31 }
  auto value_lxy_lxy_update_0_write0 = lxy.lxy_lxy_update_0_write0_merged_banks_9.peek_34();
  return value_lxy_lxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgxy_rd8_select(lxy_cache& lxy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgxy_rd8 read pattern: { lgxy_update_0[d0, d1] -> lxy[1 + d0, 1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgxy_update_0[d0, d1] -> [2 + d1, 2 + d0, 8] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lxy_update_0[d0, d1] -> [1 + d1, 1 + d0, 5] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: {  }
  auto value_lxy_lxy_update_0_write0 = lxy.lxy_lxy_update_0_write0_merged_banks_9.peek_0();
  return value_lxy_lxy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 2
// lgxy_update_0_read
//	lgxy_rd0
//	lgxy_rd1
//	lgxy_rd2
//	lgxy_rd3
//	lgxy_rd4
//	lgxy_rd5
//	lgxy_rd6
//	lgxy_rd7
//	lgxy_rd8
inline hw_uint<144> lxy_lgxy_update_0_read_bundle_read(lxy_cache& lxy, int d0, int d1) {
  // # of ports in bundle: 9
    // lgxy_rd0
    // lgxy_rd1
    // lgxy_rd2
    // lgxy_rd3
    // lgxy_rd4
    // lgxy_rd5
    // lgxy_rd6
    // lgxy_rd7
    // lgxy_rd8

	hw_uint<144> result;
	hw_uint<16> lgxy_rd0_res = lgxy_rd0_select(lxy, d0, d1);
	set_at<0, 144>(result, lgxy_rd0_res);
	hw_uint<16> lgxy_rd1_res = lgxy_rd1_select(lxy, d0, d1);
	set_at<16, 144>(result, lgxy_rd1_res);
	hw_uint<16> lgxy_rd2_res = lgxy_rd2_select(lxy, d0, d1);
	set_at<32, 144>(result, lgxy_rd2_res);
	hw_uint<16> lgxy_rd3_res = lgxy_rd3_select(lxy, d0, d1);
	set_at<48, 144>(result, lgxy_rd3_res);
	hw_uint<16> lgxy_rd4_res = lgxy_rd4_select(lxy, d0, d1);
	set_at<64, 144>(result, lgxy_rd4_res);
	hw_uint<16> lgxy_rd5_res = lgxy_rd5_select(lxy, d0, d1);
	set_at<80, 144>(result, lgxy_rd5_res);
	hw_uint<16> lgxy_rd6_res = lgxy_rd6_select(lxy, d0, d1);
	set_at<96, 144>(result, lgxy_rd6_res);
	hw_uint<16> lgxy_rd7_res = lgxy_rd7_select(lxy, d0, d1);
	set_at<112, 144>(result, lgxy_rd7_res);
	hw_uint<16> lgxy_rd8_res = lgxy_rd8_select(lxy, d0, d1);
	set_at<128, 144>(result, lgxy_rd8_res);
	return result;
}

// lxy_update_0_write
//	lxy_lxy_update_0_write0
inline void lxy_lxy_update_0_write_bundle_write(hw_uint<16>& lxy_update_0_write, lxy_cache& lxy, int d0, int d1) {
	hw_uint<16> lxy_lxy_update_0_write0_res = lxy_update_0_write.extract<0, 15>();
	lxy_lxy_update_0_write0_write(lxy_lxy_update_0_write0_res, lxy, d0, d1);
}

#include "hw_classes.h"

struct lyy_lyy_update_0_write0_merged_banks_9_cache {
	// RAM Box: {[-1, 32], [-1, 32]}
	// Capacity: 71
	// # of read delays: 9
	hw_uint<16> f0;
	hw_uint<16> f2;
	hw_uint<16> f4;
	fifo<hw_uint<16>, 31> f5;
	hw_uint<16> f6;
	hw_uint<16> f8;
	hw_uint<16> f10;
	fifo<hw_uint<16>, 31> f11;
	hw_uint<16> f12;
	hw_uint<16> f14;
	hw_uint<16> f16;


	inline hw_uint<16> peek_0() {
		return f0;
	}

	inline hw_uint<16> peek_1() {
		return f2;
	}

	inline hw_uint<16> peek_2() {
		return f4;
	}

	inline hw_uint<16> peek_33() {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
		return f5.back();
	}

	inline hw_uint<16> peek_34() {
		return f6;
	}

	inline hw_uint<16> peek_35() {
		return f8;
	}

	inline hw_uint<16> peek_36() {
		return f10;
	}

	inline hw_uint<16> peek_67() {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
		return f11.back();
	}

	inline hw_uint<16> peek_68() {
		return f12;
	}

	inline hw_uint<16> peek_69() {
		return f14;
	}

	inline hw_uint<16> peek_70() {
		return f16;
	}



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f16 = f14;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f14 = f12;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 31
    f12 = f11.back();
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 31 reading from capacity: 1
    f11.push(f10);
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f10 = f8;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f8 = f6;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 31
    f6 = f5.back();
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 31 reading from capacity: 1
    f5.push(f4);
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f4 = f2;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    // cap: 1 reading from capacity: 1
    f2 = f0;
    // cap: 1
    f0 = value;
	}

};

struct lyy_cache {
  lyy_lyy_update_0_write0_merged_banks_9_cache lyy_lyy_update_0_write0_merged_banks_9;
};



inline void lyy_lyy_update_0_write0_write(hw_uint<16>& lyy_lyy_update_0_write0, lyy_cache& lyy, int d0, int d1) {
  lyy.lyy_lyy_update_0_write0_merged_banks_9.push(lyy_lyy_update_0_write0);
}

inline hw_uint<16> lgyy_rd0_select(lyy_cache& lyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy_rd0 read pattern: { lgyy_update_0[d0, d1] -> lyy[-1 + d0, -1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgyy_update_0[d0, d1] -> 70 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lyy_lyy_update_0_write0 = lyy.lyy_lyy_update_0_write0_merged_banks_9.peek_70();
  return value_lyy_lyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgyy_rd1_select(lyy_cache& lyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy_rd1 read pattern: { lgyy_update_0[d0, d1] -> lyy[-1 + d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgyy_update_0[d0, d1] -> 36 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lyy_lyy_update_0_write0 = lyy.lyy_lyy_update_0_write0_merged_banks_9.peek_36();
  return value_lyy_lyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgyy_rd2_select(lyy_cache& lyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy_rd2 read pattern: { lgyy_update_0[d0, d1] -> lyy[-1 + d0, 1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgyy_update_0[d0, d1] -> 2 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lyy_lyy_update_0_write0 = lyy.lyy_lyy_update_0_write0_merged_banks_9.peek_2();
  return value_lyy_lyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgyy_rd3_select(lyy_cache& lyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy_rd3 read pattern: { lgyy_update_0[d0, d1] -> lyy[d0, -1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgyy_update_0[d0, d1] -> 69 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lyy_lyy_update_0_write0 = lyy.lyy_lyy_update_0_write0_merged_banks_9.peek_69();
  return value_lyy_lyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgyy_rd4_select(lyy_cache& lyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy_rd4 read pattern: { lgyy_update_0[d0, d1] -> lyy[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgyy_update_0[d0, d1] -> 35 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lyy_lyy_update_0_write0 = lyy.lyy_lyy_update_0_write0_merged_banks_9.peek_35();
  return value_lyy_lyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgyy_rd5_select(lyy_cache& lyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy_rd5 read pattern: { lgyy_update_0[d0, d1] -> lyy[d0, 1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgyy_update_0[d0, d1] -> 1 : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  auto value_lyy_lyy_update_0_write0 = lyy.lyy_lyy_update_0_write0_merged_banks_9.peek_1();
  return value_lyy_lyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgyy_rd6_select(lyy_cache& lyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy_rd6 read pattern: { lgyy_update_0[d0, d1] -> lyy[1 + d0, -1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgyy_update_0[d0, d1] -> 68 : 0 <= d0 <= 30 and 0 <= d1 <= 31; lgyy_update_0[d0, d1] -> (37 + d0) : d0 = 31 and 0 <= d1 <= 31 }
  auto value_lyy_lyy_update_0_write0 = lyy.lyy_lyy_update_0_write0_merged_banks_9.peek_68();
  return value_lyy_lyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgyy_rd7_select(lyy_cache& lyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy_rd7 read pattern: { lgyy_update_0[d0, d1] -> lyy[1 + d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: { lgyy_update_0[d0, d1] -> 34 : 0 <= d0 <= 30 and 0 <= d1 <= 31; lgyy_update_0[d0, d1] -> (3 + d0) : d0 = 31 and 0 <= d1 <= 31 }
  auto value_lyy_lyy_update_0_write0 = lyy.lyy_lyy_update_0_write0_merged_banks_9.peek_34();
  return value_lyy_lyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

inline hw_uint<16> lgyy_rd8_select(lyy_cache& lyy, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // lgyy_rd8 read pattern: { lgyy_update_0[d0, d1] -> lyy[1 + d0, 1 + d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { lgyy_update_0[d0, d1] -> [2 + d1, 2 + d0, 7] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { lyy_update_0[d0, d1] -> [1 + d1, 1 + d0, 4] : -1 <= d0 <= 32 and -1 <= d1 <= 32 }
  // DD fold: {  }
  auto value_lyy_lyy_update_0_write0 = lyy.lyy_lyy_update_0_write0_merged_banks_9.peek_0();
  return value_lyy_lyy_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 2
// lgyy_update_0_read
//	lgyy_rd0
//	lgyy_rd1
//	lgyy_rd2
//	lgyy_rd3
//	lgyy_rd4
//	lgyy_rd5
//	lgyy_rd6
//	lgyy_rd7
//	lgyy_rd8
inline hw_uint<144> lyy_lgyy_update_0_read_bundle_read(lyy_cache& lyy, int d0, int d1) {
  // # of ports in bundle: 9
    // lgyy_rd0
    // lgyy_rd1
    // lgyy_rd2
    // lgyy_rd3
    // lgyy_rd4
    // lgyy_rd5
    // lgyy_rd6
    // lgyy_rd7
    // lgyy_rd8

	hw_uint<144> result;
	hw_uint<16> lgyy_rd0_res = lgyy_rd0_select(lyy, d0, d1);
	set_at<0, 144>(result, lgyy_rd0_res);
	hw_uint<16> lgyy_rd1_res = lgyy_rd1_select(lyy, d0, d1);
	set_at<16, 144>(result, lgyy_rd1_res);
	hw_uint<16> lgyy_rd2_res = lgyy_rd2_select(lyy, d0, d1);
	set_at<32, 144>(result, lgyy_rd2_res);
	hw_uint<16> lgyy_rd3_res = lgyy_rd3_select(lyy, d0, d1);
	set_at<48, 144>(result, lgyy_rd3_res);
	hw_uint<16> lgyy_rd4_res = lgyy_rd4_select(lyy, d0, d1);
	set_at<64, 144>(result, lgyy_rd4_res);
	hw_uint<16> lgyy_rd5_res = lgyy_rd5_select(lyy, d0, d1);
	set_at<80, 144>(result, lgyy_rd5_res);
	hw_uint<16> lgyy_rd6_res = lgyy_rd6_select(lyy, d0, d1);
	set_at<96, 144>(result, lgyy_rd6_res);
	hw_uint<16> lgyy_rd7_res = lgyy_rd7_select(lyy, d0, d1);
	set_at<112, 144>(result, lgyy_rd7_res);
	hw_uint<16> lgyy_rd8_res = lgyy_rd8_select(lyy, d0, d1);
	set_at<128, 144>(result, lgyy_rd8_res);
	return result;
}

// lyy_update_0_write
//	lyy_lyy_update_0_write0
inline void lyy_lyy_update_0_write_bundle_write(hw_uint<16>& lyy_update_0_write, lyy_cache& lyy, int d0, int d1) {
	hw_uint<16> lyy_lyy_update_0_write0_res = lyy_update_0_write.extract<0, 15>();
	lyy_lyy_update_0_write0_write(lyy_lyy_update_0_write0_res, lyy, d0, d1);
}

#include "hw_classes.h"

struct trace_trace_update_0_write0_merged_banks_1_cache {
	// RAM Box: {[0, 31], [0, 31]}
	// Capacity: 1
	// # of read delays: 1
	fifo<hw_uint<16>, 1> f;
	inline hw_uint<16> peek(const int offset) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.peek(0 - offset);
  }



	inline void push(const hw_uint<16> value) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
    return f.push(value);
  }

};

struct trace_cache {
  trace_trace_update_0_write0_merged_banks_1_cache trace_trace_update_0_write0_merged_banks_1;
};



inline void trace_trace_update_0_write0_write(hw_uint<16>& trace_trace_update_0_write0, trace_cache& trace, int d0, int d1) {
  trace.trace_trace_update_0_write0_merged_banks_1.push(trace_trace_update_0_write0);
}

inline hw_uint<16> harris16_mini_rd0_select(trace_cache& trace, int d0, int d1) {
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  // harris16_mini_rd0 read pattern: { harris16_mini_update_0[d0, d1] -> trace[d0, d1] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Read schedule : { harris16_mini_update_0[d0, d1] -> [2 + d1, 2 + d0, 15] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // Write schedule: { trace_update_0[d0, d1] -> [2 + d1, 2 + d0, 14] : 0 <= d0 <= 31 and 0 <= d1 <= 31 }
  // DD fold: {  }
  auto value_trace_trace_update_0_write0 = trace.trace_trace_update_0_write0_merged_banks_1.peek(/* one reader or all rams */ 0);
  return value_trace_trace_update_0_write0;
#ifndef __VIVADO_SYNTH__
	cout << "Error: Unsupported offsets: " << " d0 = " << d0  << " d1 = " << d1  << endl;
	assert(false);
	return 0;
#endif //__VIVADO_SYNTH__
}

// # of bundles = 2
// harris16_mini_update_0_read
//	harris16_mini_rd0
inline hw_uint<16> trace_harris16_mini_update_0_read_bundle_read(trace_cache& trace, int d0, int d1) {
  // # of ports in bundle: 1
    // harris16_mini_rd0

	hw_uint<16> result;
	hw_uint<16> harris16_mini_rd0_res = harris16_mini_rd0_select(trace, d0, d1);
	set_at<0, 16>(result, harris16_mini_rd0_res);
	return result;
}

// trace_update_0_write
//	trace_trace_update_0_write0
inline void trace_trace_update_0_write_bundle_write(hw_uint<16>& trace_update_0_write, trace_cache& trace, int d0, int d1) {
	hw_uint<16> trace_trace_update_0_write0_res = trace_update_0_write.extract<0, 15>();
	trace_trace_update_0_write0_write(trace_trace_update_0_write0_res, trace, d0, d1);
}



// Operation logic
inline void lxy_update_0(grad_x_cache& grad_x, grad_y_cache& grad_y, lxy_cache& lxy, int d0, int d1) {
	// Consume: grad_x
	auto grad_x_0_c__0_value = grad_x_lxy_update_0_read_bundle_read(grad_x/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lxy_update_0_grad_x," << d0<< "," << d1<< "," <<  grad_x_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	// Consume: grad_y
	auto grad_y_0_c__0_value = grad_y_lxy_update_0_read_bundle_read(grad_y/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lxy_update_0_grad_y," << d0<< "," << d1<< "," <<  grad_y_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = lxy_generated_compute_unrolled_1(grad_x_0_c__0_value, grad_y_0_c__0_value);
	// Produce: lxy
	lxy_lxy_update_0_write_bundle_write(compute_result, lxy, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "lxy_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void lxx_update_0(grad_x_cache& grad_x, lxx_cache& lxx, int d0, int d1) {
	// Consume: grad_x
	auto grad_x_0_c__0_value = grad_x_lxx_update_0_read_bundle_read(grad_x/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lxx_update_0_grad_x," << d0<< "," << d1<< "," <<  grad_x_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = lxx_generated_compute_unrolled_1(grad_x_0_c__0_value);
	// Produce: lxx
	lxx_lxx_update_0_write_bundle_write(compute_result, lxx, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "lxx_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void lgyy_update_0(lyy_cache& lyy, lgyy_cache& lgyy, int d0, int d1) {
	// Consume: lyy
	auto lyy_0_c__0_value = lyy_lgyy_update_0_read_bundle_read(lyy/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lgyy_update_0_lyy," << d0<< "," << d1<< "," <<  lyy_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = lgyy_generated_compute_unrolled_1(lyy_0_c__0_value);
	// Produce: lgyy
	lgyy_lgyy_update_0_write_bundle_write(compute_result, lgyy, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "lgyy_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void lgxy_update_0(lxy_cache& lxy, lgxy_cache& lgxy, int d0, int d1) {
	// Consume: lxy
	auto lxy_0_c__0_value = lxy_lgxy_update_0_read_bundle_read(lxy/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lgxy_update_0_lxy," << d0<< "," << d1<< "," <<  lxy_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = lgxy_generated_compute_unrolled_1(lxy_0_c__0_value);
	// Produce: lgxy
	lgxy_lgxy_update_0_write_bundle_write(compute_result, lgxy, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "lgxy_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void lgxx_update_0(lxx_cache& lxx, lgxx_cache& lgxx, int d0, int d1) {
	// Consume: lxx
	auto lxx_0_c__0_value = lxx_lgxx_update_0_read_bundle_read(lxx/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lgxx_update_0_lxx," << d0<< "," << d1<< "," <<  lxx_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = lgxx_generated_compute_unrolled_1(lxx_0_c__0_value);
	// Produce: lgxx
	lgxx_lgxx_update_0_write_bundle_write(compute_result, lgxx, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "lgxx_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void lgyy8_update_0(lgyy_cache& lgyy, lgyy8_cache& lgyy8, int d0, int d1) {
	// Consume: lgyy
	auto lgyy_0_c__0_value = lgyy_lgyy8_update_0_read_bundle_read(lgyy/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lgyy8_update_0_lgyy," << d0<< "," << d1<< "," <<  lgyy_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = lgyy8_generated_compute_unrolled_1(lgyy_0_c__0_value);
	// Produce: lgyy8
	lgyy8_lgyy8_update_0_write_bundle_write(compute_result, lgyy8, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "lgyy8_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void lgxy8_update_0(lgxy_cache& lgxy, lgxy8_cache& lgxy8, int d0, int d1) {
	// Consume: lgxy
	auto lgxy_0_c__0_value = lgxy_lgxy8_update_0_read_bundle_read(lgxy/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lgxy8_update_0_lgxy," << d0<< "," << d1<< "," <<  lgxy_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = lgxy8_generated_compute_unrolled_1(lgxy_0_c__0_value);
	// Produce: lgxy8
	lgxy8_lgxy8_update_0_write_bundle_write(compute_result, lgxy8, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "lgxy8_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void lgxx8_update_0(lgxx_cache& lgxx, lgxx8_cache& lgxx8, int d0, int d1) {
	// Consume: lgxx
	auto lgxx_0_c__0_value = lgxx_lgxx8_update_0_read_bundle_read(lgxx/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lgxx8_update_0_lgxx," << d0<< "," << d1<< "," <<  lgxx_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = lgxx8_generated_compute_unrolled_1(lgxx_0_c__0_value);
	// Produce: lgxx8
	lgxx8_lgxx8_update_0_write_bundle_write(compute_result, lgxx8, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "lgxx8_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void det_update_0(lgxx8_cache& lgxx8, lgxy8_cache& lgxy8, lgyy8_cache& lgyy8, det_cache& det, int d0, int d1) {
	// Consume: lgxx8
	auto lgxx8_0_c__0_value = lgxx8_det_update_0_read_bundle_read(lgxx8/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "det_update_0_lgxx8," << d0<< "," << d1<< "," <<  lgxx8_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	// Consume: lgxy8
	auto lgxy8_0_c__0_value = lgxy8_det_update_0_read_bundle_read(lgxy8/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "det_update_0_lgxy8," << d0<< "," << d1<< "," <<  lgxy8_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	// Consume: lgyy8
	auto lgyy8_0_c__0_value = lgyy8_det_update_0_read_bundle_read(lgyy8/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "det_update_0_lgyy8," << d0<< "," << d1<< "," <<  lgyy8_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = det_generated_compute_unrolled_1(lgxx8_0_c__0_value, lgxy8_0_c__0_value, lgyy8_0_c__0_value);
	// Produce: det
	det_det_update_0_write_bundle_write(compute_result, det, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "det_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void img_update_0(HWStream<hw_uint<16> >& /* buffer_args num ports = 1 */img_oc, img_cache& img, int d0, int d1) {
	// Consume: img_oc
	auto img_oc_0_c__0_value = img_oc.read();
	auto compute_result = img_generated_compute_unrolled_1(img_oc_0_c__0_value);
	// Produce: img
	img_img_update_0_write_bundle_write(compute_result, img, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "img_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void grad_y_update_0(img_cache& img, grad_y_cache& grad_y, int d0, int d1) {
	// Consume: img
	auto img_0_c__0_value = img_grad_y_update_0_read_bundle_read(img/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "grad_y_update_0_img," << d0<< "," << d1<< "," <<  img_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = grad_y_generated_compute_unrolled_1(img_0_c__0_value);
	// Produce: grad_y
	grad_y_grad_y_update_0_write_bundle_write(compute_result, grad_y, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "grad_y_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void grad_x_update_0(img_cache& img, grad_x_cache& grad_x, int d0, int d1) {
	// Consume: img
	auto img_0_c__0_value = img_grad_x_update_0_read_bundle_read(img/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "grad_x_update_0_img," << d0<< "," << d1<< "," <<  img_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = grad_x_generated_compute_unrolled_1(img_0_c__0_value);
	// Produce: grad_x
	grad_x_grad_x_update_0_write_bundle_write(compute_result, grad_x, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "grad_x_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void lyy_update_0(grad_y_cache& grad_y, lyy_cache& lyy, int d0, int d1) {
	// Consume: grad_y
	auto grad_y_0_c__0_value = grad_y_lyy_update_0_read_bundle_read(grad_y/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "lyy_update_0_grad_y," << d0<< "," << d1<< "," <<  grad_y_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = lyy_generated_compute_unrolled_1(grad_y_0_c__0_value);
	// Produce: lyy
	lyy_lyy_update_0_write_bundle_write(compute_result, lyy, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "lyy_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void trace_update_0(lgxx8_cache& lgxx8, lgyy8_cache& lgyy8, trace_cache& trace, int d0, int d1) {
	// Consume: lgxx8
	auto lgxx8_0_c__0_value = lgxx8_trace_update_0_read_bundle_read(lgxx8/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "trace_update_0_lgxx8," << d0<< "," << d1<< "," <<  lgxx8_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	// Consume: lgyy8
	auto lgyy8_0_c__0_value = lgyy8_trace_update_0_read_bundle_read(lgyy8/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "trace_update_0_lgyy8," << d0<< "," << d1<< "," <<  lgyy8_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = trace_generated_compute_unrolled_1(lgxx8_0_c__0_value, lgyy8_0_c__0_value);
	// Produce: trace
	trace_trace_update_0_write_bundle_write(compute_result, trace, d0, d1);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "trace_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

inline void harris16_mini_update_0(det_cache& det, trace_cache& trace, HWStream<hw_uint<16> >& /* buffer_args num ports = 1 */harris16_mini, int d0, int d1) {
	// Consume: det
	auto det_0_c__0_value = det_harris16_mini_update_0_read_bundle_read(det/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "harris16_mini_update_0_det," << d0<< "," << d1<< "," <<  det_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	// Consume: trace
	auto trace_0_c__0_value = trace_harris16_mini_update_0_read_bundle_read(trace/* source_delay */, d0, d1);

#ifndef __VIVADO_SYNTH__
  *global_debug_handle << "harris16_mini_update_0_trace," << d0<< "," << d1<< "," <<  trace_0_c__0_value << endl;
#endif //__VIVADO_SYNTH__

	auto compute_result = harris16_mini_generated_compute_unrolled_1(det_0_c__0_value, trace_0_c__0_value);
	// Produce: harris16_mini
	harris16_mini.write(compute_result);

#ifndef __VIVADO_SYNTH__
  hw_uint<16> debug_compute_result(compute_result);
  hw_uint<16> debug_compute_result_lane_0;
  set_at<0, 16, 16>(debug_compute_result_lane_0, debug_compute_result.extract<0, 15>());
  *global_debug_handle << "harris16_mini_update_0," << (1*d0 + 0) << ", " << d1<< "," <<  debug_compute_result_lane_0 << endl;
#endif //__VIVADO_SYNTH__

}

// Driver function
void harris16_mini_opt(HWStream<hw_uint<16> >& /* get_args num ports = 1 */img_oc, HWStream<hw_uint<16> >& /* get_args num ports = 1 */harris16_mini, int num_epochs) {

#ifndef __VIVADO_SYNTH__
  ofstream debug_file("harris16_mini_opt_debug.csv");
  global_debug_handle = &debug_file;
#endif //__VIVADO_SYNTH__
  det_cache det;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  grad_x_cache grad_x;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  grad_y_cache grad_y;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  img_cache img;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  lgxx_cache lgxx;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  lgxx8_cache lgxx8;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  lgxy_cache lgxy;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  lgxy8_cache lgxy8;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  lgyy_cache lgyy;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  lgyy8_cache lgyy8;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  lxx_cache lxx;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  lxy_cache lxy;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  lyy_cache lyy;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  trace_cache trace;
#ifdef __VIVADO_SYNTH__
#endif //__VIVADO_SYNTH__
  for (int epoch = 0; epoch < num_epochs; epoch++) {
	#ifdef __VIVADO_SYNTH__
	#pragma HLS inline recursive
	#endif // __VIVADO_SYNTH__
	
	for (int c0 = -2; c0 <= 33; c0++) {
	  for (int c1 = -2; c1 <= 33; c1++) {
	
	#ifdef __VIVADO_SYNTH__
	#pragma HLS pipeline II=1
	#endif // __VIVADO_SYNTH__
	
	    if ((-2 <= c1 && c1 <= 33) && ((c1 - 0) % 1 == 0) && (-2 <= c0 && c0 <= 33) && ((c0 - 0) % 1 == 0)) {
	img_update_0(img_oc, img, (c1 - 0) / 1, (c0 - 0) / 1);
	    }
	
	    if ((0 <= c1 && c1 <= 33) && ((c1 - 1) % 1 == 0) && (0 <= c0 && c0 <= 33) && ((c0 - 1) % 1 == 0)) {
	grad_y_update_0(img, grad_y, (c1 - 1) / 1, (c0 - 1) / 1);
	    }
	
	    if ((0 <= c1 && c1 <= 33) && ((c1 - 1) % 1 == 0) && (0 <= c0 && c0 <= 33) && ((c0 - 1) % 1 == 0)) {
	grad_x_update_0(img, grad_x, (c1 - 1) / 1, (c0 - 1) / 1);
	    }
	
	    if ((0 <= c1 && c1 <= 33) && ((c1 - 1) % 1 == 0) && (0 <= c0 && c0 <= 33) && ((c0 - 1) % 1 == 0)) {
	lyy_update_0(grad_y, lyy, (c1 - 1) / 1, (c0 - 1) / 1);
	    }
	
	    if ((0 <= c1 && c1 <= 33) && ((c1 - 1) % 1 == 0) && (0 <= c0 && c0 <= 33) && ((c0 - 1) % 1 == 0)) {
	lxy_update_0(grad_x, grad_y, lxy, (c1 - 1) / 1, (c0 - 1) / 1);
	    }
	
	    if ((0 <= c1 && c1 <= 33) && ((c1 - 1) % 1 == 0) && (0 <= c0 && c0 <= 33) && ((c0 - 1) % 1 == 0)) {
	lxx_update_0(grad_x, lxx, (c1 - 1) / 1, (c0 - 1) / 1);
	    }
	
	    if ((2 <= c1 && c1 <= 33) && ((c1 - 2) % 1 == 0) && (2 <= c0 && c0 <= 33) && ((c0 - 2) % 1 == 0)) {
	lgyy_update_0(lyy, lgyy, (c1 - 2) / 1, (c0 - 2) / 1);
	    }
	
	    if ((2 <= c1 && c1 <= 33) && ((c1 - 2) % 1 == 0) && (2 <= c0 && c0 <= 33) && ((c0 - 2) % 1 == 0)) {
	lgxy_update_0(lxy, lgxy, (c1 - 2) / 1, (c0 - 2) / 1);
	    }
	
	    if ((2 <= c1 && c1 <= 33) && ((c1 - 2) % 1 == 0) && (2 <= c0 && c0 <= 33) && ((c0 - 2) % 1 == 0)) {
	lgxx_update_0(lxx, lgxx, (c1 - 2) / 1, (c0 - 2) / 1);
	    }
	
	    if ((2 <= c1 && c1 <= 33) && ((c1 - 2) % 1 == 0) && (2 <= c0 && c0 <= 33) && ((c0 - 2) % 1 == 0)) {
	lgyy8_update_0(lgyy, lgyy8, (c1 - 2) / 1, (c0 - 2) / 1);
	    }
	
	    if ((2 <= c1 && c1 <= 33) && ((c1 - 2) % 1 == 0) && (2 <= c0 && c0 <= 33) && ((c0 - 2) % 1 == 0)) {
	lgxy8_update_0(lgxy, lgxy8, (c1 - 2) / 1, (c0 - 2) / 1);
	    }
	
	    if ((2 <= c1 && c1 <= 33) && ((c1 - 2) % 1 == 0) && (2 <= c0 && c0 <= 33) && ((c0 - 2) % 1 == 0)) {
	lgxx8_update_0(lgxx, lgxx8, (c1 - 2) / 1, (c0 - 2) / 1);
	    }
	
	    if ((2 <= c1 && c1 <= 33) && ((c1 - 2) % 1 == 0) && (2 <= c0 && c0 <= 33) && ((c0 - 2) % 1 == 0)) {
	det_update_0(lgxx8, lgxy8, lgyy8, det, (c1 - 2) / 1, (c0 - 2) / 1);
	    }
	
	    if ((2 <= c1 && c1 <= 33) && ((c1 - 2) % 1 == 0) && (2 <= c0 && c0 <= 33) && ((c0 - 2) % 1 == 0)) {
	trace_update_0(lgxx8, lgyy8, trace, (c1 - 2) / 1, (c0 - 2) / 1);
	    }
	
	    if ((2 <= c1 && c1 <= 33) && ((c1 - 2) % 1 == 0) && (2 <= c0 && c0 <= 33) && ((c0 - 2) % 1 == 0)) {
	harris16_mini_update_0(det, trace, harris16_mini, (c1 - 2) / 1, (c0 - 2) / 1);
	    }
	
	  }
	}
	
  }

#ifndef __VIVADO_SYNTH__
  debug_file.close();
#endif //__VIVADO_SYNTH__
}

void harris16_mini_opt(HWStream<hw_uint<16> >& /* get_args num ports = 1 */img_oc, HWStream<hw_uint<16> >& /* get_args num ports = 1 */harris16_mini) {

  harris16_mini_opt(img_oc, harris16_mini, 1);
}
#ifdef __VIVADO_SYNTH__
#include "harris16_mini_opt.h"

const int harris16_mini_update_0_write_num_transfers = 1024;
const int img_update_0_read_num_transfers = 1296;

// TODO: Adapt to have one size for each edge buffer
#define INPUT_SIZE 1296
#define OUTPUT_SIZE 1024
extern "C" {

static void read_img_update_0_read(hw_uint<16>* input, HWStream<hw_uint<16> >& v, const int size) {
  hw_uint<16> burst_reg;
  for (int i = 0; i < img_update_0_read_num_transfers*size; i++) {
    #pragma HLS pipeline II=1
    burst_reg = input[i];
    v.write(burst_reg);
  }
}

static void write_harris16_mini_update_0_write(hw_uint<16>* output, HWStream<hw_uint<16> >& v, const int size) {
  hw_uint<16> burst_reg;
  for (int i = 0; i < harris16_mini_update_0_write_num_transfers*size; i++) {
    #pragma HLS pipeline II=1
    burst_reg = v.read();
    output[i] = burst_reg;
  }
}

void harris16_mini_opt_accel(hw_uint<16>* img_update_0_read, hw_uint<16>* harris16_mini_update_0_write, const int size) { 
#pragma HLS dataflow
#pragma HLS INTERFACE m_axi port = img_update_0_read offset = slave depth = 65536 bundle = gmem0
#pragma HLS INTERFACE m_axi port = harris16_mini_update_0_write offset = slave depth = 65536 bundle = gmem1

#pragma HLS INTERFACE s_axilite port = img_update_0_read bundle = control
#pragma HLS INTERFACE s_axilite port = harris16_mini_update_0_write bundle = control
#pragma HLS INTERFACE s_axilite port = size bundle = control
#pragma HLS INTERFACE s_axilite port = return bundle = control

  static HWStream<hw_uint<16> > img_update_0_read_channel;
  static HWStream<hw_uint<16> > harris16_mini_update_0_write_channel;

  read_img_update_0_read(img_update_0_read, img_update_0_read_channel, size);

  harris16_mini_opt(img_update_0_read_channel, harris16_mini_update_0_write_channel, size);

  write_harris16_mini_update_0_write(harris16_mini_update_0_write, harris16_mini_update_0_write_channel, size);
}

}
#endif //__VIVADO_SYNTH__

