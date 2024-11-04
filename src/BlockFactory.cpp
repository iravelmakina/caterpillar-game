#include "BlockFactory.h"


std::unique_ptr<Block> BlockFactory::createBlock() {
  const BlockType type = static_cast<BlockType>(std::rand() % 4);

    switch (type) {
        case BlockType::SINGLE:
          return std::make_unique<SingleBlock>();
        case BlockType::HORIZONTAL:
          return std::make_unique<HorizontalBlock>();
        case BlockType::VERTICAL:
          return std::make_unique<VerticalBlock>();
        case BlockType::L_SHAPE:
          return std::make_unique<LShapeBlock>();
    }
    return std::make_unique<SingleBlock>();
}
