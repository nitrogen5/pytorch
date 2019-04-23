#pragma once

#ifdef USE_FBGEMM
#include "fbgemm/Fbgemm.h"
#include "fbgemm/QuantUtils.h"

// The struct for the packed weight matrix (PackBMatrix) and the corresponding
// column offsets used for the fully connect layer, which are both prepared in
// the prepacking step to save the computations in the inference. Note the
// column offsets includes the sum of the B columns as well as the scalar term
// B_zero_point * K, whereas the row offsets created by
// PackAWithQuantRowOffset/PackAWithIm2Col/PackAWithRowOffset is only the sum of
// the A rows.
struct FBGEMM_API PackedFCWeight {
  std::unique_ptr<fbgemm::PackBMatrix<int8_t>> w;
  std::vector<int32_t> col_offsets;
};

#endif // USE_FBGEMM
