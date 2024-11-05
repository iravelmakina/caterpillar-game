#pragma once
#include "Block.h"


enum class BlockType {
    SINGLE,
    HORIZONTAL,
    VERTICAL,
    L_SHAPE
};

namespace  BlockFactory {
    std::unique_ptr<Block> createBlock();
};
