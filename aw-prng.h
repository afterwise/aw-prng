
/*
   Copyright (c) 2015 Malte Hildingsson, malte (at) afterwi.se

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
 */

#ifndef AW_PRNG_H
#define AW_PRNG_H

#ifdef __cplusplus
extern "C" {
#endif

static inline int prng_next(int *seed, int salt) {
	return *seed = (*seed + 35757 ^ salt) * 31313;
}

static inline float prng_plus_minus_one(int *seed, int salt) {
	return (float) prng_next(seed, salt) * (1.f / (float) 0x80000000);
}

static inline float prng_zero_to_one(int *seed, int salt) {
	return (prng_plus_minus_one(seed, salt) + 1.f) * .5f;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* AW_PRNG_H */

